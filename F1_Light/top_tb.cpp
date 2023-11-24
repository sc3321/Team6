#include "verilated.h"
#include "verilated_vcd_c.h"

#include "Vtop.h"
#include "Vf1_fsm.h"
#include "Vclktick.h"
#include "Vlfsr.h"
#include "Vmux.h"
#include "Vdelay.h"
#include <iostream>

#include "vbuddy.cpp"
#define MAX_SIM_CYC 1000

// FSM can be triggered again when trigger flag is low
// trigger is used to start the sequence
// trigger also used for starting timer and 

// when all lights off start the timer
// then read the time and display


int main(int argc, char **argv, char **env) {
    int simcyc;
    int tick;

    Verilated::commandArgs(argc, argv);
    Vtop* top = new Vtop;
    
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;

    top->trace(tfp, 99);
    tfp->open("top.vcd");

    if(vbdOpen() != 1) return(-1);
    vbdHeader("F1 Light");
    vbdSetMode(1);

    top->clk = 1;
    top->en = 0;
    top->rst = 0;
    top->trigger = 0;
    vbdInitWatch();

    bool lightOff = false;
    bool latched = false;

    int preInt = 0;
    int curInt = 0;


    for(simcyc = 0; simcyc < MAX_SIM_CYC; simcyc++) {
        for(tick = 0; tick < 2; tick++) {
            tfp->dump (2*simcyc + tick);
            top->clk = !top->clk;
            top->eval();
        }

        
        vbdBar(int(top->out));

        top->caliN = 4; // init 22

        top->en = simcyc > 2;
        top->rst = simcyc < 2;
        top->trigger = vbdFlag();

        preInt = curInt;
        curInt = (int(top->out) & 0xFF);

        // std::cout << "cur int: " << curInt << std::endl;
        // std::cout << "pre int: " << preInt << std::endl;

        if( curInt == 0 && preInt == 255 && !latched) {
            vbdInitWatch();
            std::cout << "Start Timer!" << std::endl;
            latched = true;
        }

        if(top->trigger && latched) {
            int time = vbdElapsed();
            std::cout << "Stop Timer!" << std::endl;
            std::cout << "Time is " << time << std::endl;

            vbdHex(3, (int(time) >> 8) & 0xFFF);
            vbdHex(2, (int(time) >> 4) & 0xFFF);
            vbdHex(1, int(time) & 0xFF);
            latched = false;
        }
        
        // vbdHex(4, time);
        // vbdHex(3, time);
        // vbdHex(2, time);
        // vbdHex(1, time);

        vbdCycle(simcyc);
        if(Verilated::gotFinish()) exit(0);
    }

    vbdClose();
    tfp->close();
    printf("Exiting\n");
    exit(0);
}
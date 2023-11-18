#include "verilated.h"
#include "verilated_vcd_c.h"

#include <iostream>

#include "VregFile.h"

int main(int argc, char **argv, char **env) {

    Verilated::commandArgs(argc, argv);

    VregFile* top = new VregFile;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;

    top->trace(tfp, 99);
    tfp->open("regFile.vcd");

    top->clk = 1;

    for(int i = 0; i < 50; i++) {
        for(int clk = 0; clk < 2; clk++) {
            tfp->dump(2*i+clk);
            top->clk = !top->clk;
            top->eval();
        }

        // test by writing to register and outputing the result
        if(i == 2) {
            top->WD3 = 15;                   // 'b01111 | load value into reg4
            top->AD3 = 4;                    // 'b00100 | store value here
        } else if(i == 3) {
            top->WE3 = (i==3);               // exxecute write command
        } else if(i == 4) {
            top->AD1 = 4;                    // reading value from register 4
        }

        if(Verilated::gotFinish()) exit(0);
    }

    tfp->close();
    exit(0);
}
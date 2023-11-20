#include "verilated.h"
#include "verilated_vcd_c.h"

#include <iostream>

#include "Vtop.h"
#include "VregFile.h"
#include "Vmux2.h"
#include "Valu.h"

int main(int argc, char **argv, char **env) {

    Verilated::commandArgs(argc, argv);

    Vtop* top = new Vtop;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;

    top->trace(tfp, 99);
    tfp->open("top.vcd");

    top->clk = 1;
    top->ALUctrl = 1;
    // rs1
    // rs2
    // rd
    // RegWrite
    // ImmOp
    // ALUsrc
    // ALUctrl
    // a0
    // EQ

    bool resetCount = false;

    top->ALUsrc = 1;
    top->RegWrite = 1;

    // initialise values
    top->rd = 5;
    top->rs1 = 0;
    top->ImmOp = 255;

    top->rd = 10;
    top->rs1 = 0;
    top->ImmOp = 0;

    for(int i = 0; i < 50; i++) {
        for(int clk = 0; clk < 2; clk++) {
            tfp->dump(2*i+clk);
            top->clk = !top->clk;
            top->eval();
        }

        if(resetCount) {
            top->rd = 11;
            top->rs1 = 0;
            top->ImmOp = 0;

            resetCount = false;
        } else {

            if(top->rd == 10) {
                top->rd = 11;
                top->rs1 = 10;
                top->ImmOp = 1;
            } else {
                top->rd = 10;
                top->rs1 = 11;
                top->ImmOp = 0;
            }

            if(top->a0 == 255) {
                resetCount = true;
            }
        }

        

        if(Verilated::gotFinish()) exit(0);
    }

    tfp->close();
    exit(0);
}
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "VPCReg.h"

//#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 1000

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges
  int lights = 0; // state to toggle LED lights

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  VPCReg * top = new VPCReg;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("PCReg.vcd");
 
  // init Vbuddy
  // if (vbdOpen()!=1) return(-1);
  // vbdHeader("L4");
  // //vbdSetMode(1);        // Flag mode set to one-shot
  // vbdSetMode(0);

  // initialize simulation inputs
  top->clk = 1;
  top->rst = 0;
  
  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }

    // vbdHex(4,(int(top->data_out)>>16)& 0xF);
    // vbdHex(3,(int(top->data_out)>>8)& 0xF);
    // vbdHex(2,(int(top->data_out)>>4)& 0xF);
    // vbdHex(1, top->data_out & 0xF);
    // // Display toggle neopixel
    // vbdBar(top->data_out & 0xFF);
    
    // set up input signals of testbench
   // top->rst = (simcyc < 2);    // assert reset for 1st cycle
//    vbdCycle(simcyc);

    if (Verilated::gotFinish())  exit(0);
  }

//  vbdClose();     // ++++
  tfp->close(); 
  exit(0);
}

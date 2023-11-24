// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VProgramCounter.h for the primary calling header

#ifndef VERILATED_VPROGRAMCOUNTER___024ROOT_H_
#define VERILATED_VPROGRAMCOUNTER___024ROOT_H_  // guard

#include "verilated.h"


class VProgramCounter__Syms;

class alignas(VL_CACHE_LINE_BYTES) VProgramCounter___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(PCsrc,0,0);
    CData/*0:0*/ __Vtrigprevexpr___TOP__PCsrc__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(ImmOp,31,0);
    VL_IN(PC,31,0);
    VL_OUT(next_PC,31,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VProgramCounter__Syms* const vlSymsp;

    // CONSTRUCTORS
    VProgramCounter___024root(VProgramCounter__Syms* symsp, const char* v__name);
    ~VProgramCounter___024root();
    VL_UNCOPYABLE(VProgramCounter___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

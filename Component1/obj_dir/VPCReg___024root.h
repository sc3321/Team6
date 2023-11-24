// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VPCReg.h for the primary calling header

#ifndef VERILATED_VPCREG___024ROOT_H_
#define VERILATED_VPCREG___024ROOT_H_  // guard

#include "verilated.h"


class VPCReg__Syms;

class alignas(VL_CACHE_LINE_BYTES) VPCReg___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ PCReg__DOT____Vcellinp__counter__PCsrc;
    CData/*0:0*/ __Vtrigprevexpr___TOP__PCReg__DOT____Vcellinp__counter__PCsrc__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(PCsrc,31,0);
    VL_IN(ImmOp,31,0);
    VL_OUT(PC,31,0);
    IData/*31:0*/ PCReg__DOT__next_PC;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VPCReg__Syms* const vlSymsp;

    // CONSTRUCTORS
    VPCReg___024root(VPCReg__Syms* symsp, const char* v__name);
    ~VPCReg___024root();
    VL_UNCOPYABLE(VPCReg___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

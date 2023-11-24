// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPCReg.h for the primary calling header

#include "verilated.h"

#include "VPCReg__Syms.h"
#include "VPCReg__Syms.h"
#include "VPCReg___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VPCReg___024root___dump_triggers__ico(VPCReg___024root* vlSelf);
#endif  // VL_DEBUG

void VPCReg___024root___eval_triggers__ico(VPCReg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (0U == vlSelf->__VicoIterCount));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VPCReg___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPCReg___024root___dump_triggers__act(VPCReg___024root* vlSelf);
#endif  // VL_DEBUG

void VPCReg___024root___eval_triggers__act(VPCReg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((((IData)(vlSelf->PCReg__DOT____Vcellinp__counter__PCsrc) 
                                       & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__PCReg__DOT____Vcellinp__counter__PCsrc__0))) 
                                      | ((IData)(vlSelf->clk) 
                                         & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0)))) 
                                     | ((IData)(vlSelf->rst) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__rst__0)))));
    vlSelf->__Vtrigprevexpr___TOP__PCReg__DOT____Vcellinp__counter__PCsrc__0 
        = vlSelf->PCReg__DOT____Vcellinp__counter__PCsrc;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = vlSelf->rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VPCReg___024root___dump_triggers__act(vlSelf);
    }
#endif
}

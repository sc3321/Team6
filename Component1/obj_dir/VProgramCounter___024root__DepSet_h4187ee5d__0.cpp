// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VProgramCounter.h for the primary calling header

#include "verilated.h"

#include "VProgramCounter__Syms.h"
#include "VProgramCounter__Syms.h"
#include "VProgramCounter___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VProgramCounter___024root___dump_triggers__act(VProgramCounter___024root* vlSelf);
#endif  // VL_DEBUG

void VProgramCounter___024root___eval_triggers__act(VProgramCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VProgramCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProgramCounter___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((((IData)(vlSelf->PCsrc) 
                                       & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__PCsrc__0))) 
                                      | ((IData)(vlSelf->clk) 
                                         & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0)))) 
                                     | ((IData)(vlSelf->rst) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__rst__0)))));
    vlSelf->__Vtrigprevexpr___TOP__PCsrc__0 = vlSelf->PCsrc;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = vlSelf->rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VProgramCounter___024root___dump_triggers__act(vlSelf);
    }
#endif
}

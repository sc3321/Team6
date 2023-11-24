// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPCReg.h for the primary calling header

#include "verilated.h"

#include "VPCReg__Syms.h"
#include "VPCReg___024root.h"

VL_ATTR_COLD void VPCReg___024root___eval_static(VPCReg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root___eval_static\n"); );
}

VL_ATTR_COLD void VPCReg___024root___eval_initial(VPCReg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__PCReg__DOT____Vcellinp__counter__PCsrc__0 
        = vlSelf->PCReg__DOT____Vcellinp__counter__PCsrc;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = vlSelf->rst;
}

VL_ATTR_COLD void VPCReg___024root___eval_final(VPCReg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root___eval_final\n"); );
}

VL_ATTR_COLD void VPCReg___024root___eval_triggers__stl(VPCReg___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VPCReg___024root___dump_triggers__stl(VPCReg___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VPCReg___024root___eval_stl(VPCReg___024root* vlSelf);

VL_ATTR_COLD void VPCReg___024root___eval_settle(VPCReg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        VPCReg___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                VPCReg___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("PCReg.sv", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            VPCReg___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPCReg___024root___dump_triggers__stl(VPCReg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void VPCReg___024root___ico_sequent__TOP__0(VPCReg___024root* vlSelf);

VL_ATTR_COLD void VPCReg___024root___eval_stl(VPCReg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VPCReg___024root___ico_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPCReg___024root___dump_triggers__ico(VPCReg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VPCReg___024root___dump_triggers__act(VPCReg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge PCReg.__Vcellinp__counter__PCsrc or posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VPCReg___024root___dump_triggers__nba(VPCReg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge PCReg.__Vcellinp__counter__PCsrc or posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VPCReg___024root___ctor_var_reset(VPCReg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->PCsrc = VL_RAND_RESET_I(32);
    vlSelf->ImmOp = VL_RAND_RESET_I(32);
    vlSelf->PC = VL_RAND_RESET_I(32);
    vlSelf->PCReg__DOT__next_PC = VL_RAND_RESET_I(32);
    vlSelf->PCReg__DOT____Vcellinp__counter__PCsrc = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__PCReg__DOT____Vcellinp__counter__PCsrc__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = VL_RAND_RESET_I(1);
}

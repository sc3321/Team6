// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VProgramCounter.h for the primary calling header

#include "verilated.h"

#include "VProgramCounter__Syms.h"
#include "VProgramCounter___024root.h"

VL_ATTR_COLD void VProgramCounter___024root___eval_static(VProgramCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VProgramCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProgramCounter___024root___eval_static\n"); );
}

VL_ATTR_COLD void VProgramCounter___024root___eval_initial(VProgramCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VProgramCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProgramCounter___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__PCsrc__0 = vlSelf->PCsrc;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = vlSelf->rst;
}

VL_ATTR_COLD void VProgramCounter___024root___eval_final(VProgramCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VProgramCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProgramCounter___024root___eval_final\n"); );
}

VL_ATTR_COLD void VProgramCounter___024root___eval_settle(VProgramCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VProgramCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProgramCounter___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VProgramCounter___024root___dump_triggers__act(VProgramCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VProgramCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProgramCounter___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge PCsrc or posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VProgramCounter___024root___dump_triggers__nba(VProgramCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VProgramCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProgramCounter___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge PCsrc or posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VProgramCounter___024root___ctor_var_reset(VProgramCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VProgramCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProgramCounter___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->PCsrc = VL_RAND_RESET_I(1);
    vlSelf->ImmOp = VL_RAND_RESET_I(32);
    vlSelf->PC = VL_RAND_RESET_I(32);
    vlSelf->next_PC = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__PCsrc__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = VL_RAND_RESET_I(1);
}

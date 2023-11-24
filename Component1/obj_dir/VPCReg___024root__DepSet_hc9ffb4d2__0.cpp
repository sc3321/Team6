// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPCReg.h for the primary calling header

#include "verilated.h"

#include "VPCReg__Syms.h"
#include "VPCReg___024root.h"

VL_INLINE_OPT void VPCReg___024root___ico_sequent__TOP__0(VPCReg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->PCReg__DOT____Vcellinp__counter__PCsrc 
        = (1U & vlSelf->PCsrc);
}

void VPCReg___024root___eval_ico(VPCReg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VPCReg___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VPCReg___024root___eval_act(VPCReg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root___eval_act\n"); );
}

VL_INLINE_OPT void VPCReg___024root___nba_sequent__TOP__0(VPCReg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdly__PC;
    __Vdly__PC = 0;
    // Body
    __Vdly__PC = vlSelf->PC;
    if (vlSelf->rst) {
        __Vdly__PC = 0U;
    }
    __Vdly__PC = ((IData)(vlSelf->PCReg__DOT____Vcellinp__counter__PCsrc)
                   ? (vlSelf->PC + vlSelf->ImmOp) : 
                  ((IData)(4U) + vlSelf->PC));
    vlSelf->PC = __Vdly__PC;
}

void VPCReg___024root___eval_nba(VPCReg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VPCReg___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void VPCReg___024root___eval_triggers__ico(VPCReg___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VPCReg___024root___dump_triggers__ico(VPCReg___024root* vlSelf);
#endif  // VL_DEBUG
void VPCReg___024root___eval_triggers__act(VPCReg___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VPCReg___024root___dump_triggers__act(VPCReg___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VPCReg___024root___dump_triggers__nba(VPCReg___024root* vlSelf);
#endif  // VL_DEBUG

void VPCReg___024root___eval(VPCReg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        VPCReg___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                VPCReg___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("PCReg.sv", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            VPCReg___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            VPCReg___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VPCReg___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("PCReg.sv", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
                VPCReg___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VPCReg___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("PCReg.sv", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VPCReg___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VPCReg___024root___eval_debug_assertions(VPCReg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG

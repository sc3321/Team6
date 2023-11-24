// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VPCReg__Syms.h"


void VPCReg___024root__trace_chg_sub_0(VPCReg___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VPCReg___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root__trace_chg_top_0\n"); );
    // Init
    VPCReg___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPCReg___024root*>(voidSelf);
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VPCReg___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void VPCReg___024root__trace_chg_sub_0(VPCReg___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->clk));
    bufp->chgBit(oldp+1,(vlSelf->rst));
    bufp->chgIData(oldp+2,(vlSelf->PCsrc),32);
    bufp->chgIData(oldp+3,(vlSelf->ImmOp),32);
    bufp->chgIData(oldp+4,(vlSelf->PC),32);
    bufp->chgBit(oldp+5,(vlSelf->PCReg__DOT____Vcellinp__counter__PCsrc));
}

void VPCReg___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCReg___024root__trace_cleanup\n"); );
    // Init
    VPCReg___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPCReg___024root*>(voidSelf);
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VProgramCounter__Syms.h"


VL_ATTR_COLD void VProgramCounter___024root__trace_init_sub__TOP__0(VProgramCounter___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VProgramCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProgramCounter___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+2,"rst", false,-1);
    tracep->declBit(c+3,"PCsrc", false,-1);
    tracep->declBus(c+4,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+5,"PC", false,-1, 31,0);
    tracep->declBus(c+6,"next_PC", false,-1, 31,0);
    tracep->pushNamePrefix("ProgramCounter ");
    tracep->declBus(c+7,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+2,"rst", false,-1);
    tracep->declBit(c+3,"PCsrc", false,-1);
    tracep->declBus(c+4,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+5,"PC", false,-1, 31,0);
    tracep->declBus(c+6,"next_PC", false,-1, 31,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void VProgramCounter___024root__trace_init_top(VProgramCounter___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VProgramCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProgramCounter___024root__trace_init_top\n"); );
    // Body
    VProgramCounter___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VProgramCounter___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VProgramCounter___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VProgramCounter___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VProgramCounter___024root__trace_register(VProgramCounter___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VProgramCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProgramCounter___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VProgramCounter___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VProgramCounter___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VProgramCounter___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VProgramCounter___024root__trace_full_sub_0(VProgramCounter___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VProgramCounter___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProgramCounter___024root__trace_full_top_0\n"); );
    // Init
    VProgramCounter___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VProgramCounter___024root*>(voidSelf);
    VProgramCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VProgramCounter___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VProgramCounter___024root__trace_full_sub_0(VProgramCounter___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VProgramCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProgramCounter___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->clk));
    bufp->fullBit(oldp+2,(vlSelf->rst));
    bufp->fullBit(oldp+3,(vlSelf->PCsrc));
    bufp->fullIData(oldp+4,(vlSelf->ImmOp),32);
    bufp->fullIData(oldp+5,(vlSelf->PC),32);
    bufp->fullIData(oldp+6,(vlSelf->next_PC),32);
    bufp->fullIData(oldp+7,(0x20U),32);
}

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VProgramCounter.h for the primary calling header

#include "verilated.h"

#include "VProgramCounter__Syms.h"
#include "VProgramCounter__Syms.h"
#include "VProgramCounter___024root.h"

void VProgramCounter___024root___ctor_var_reset(VProgramCounter___024root* vlSelf);

VProgramCounter___024root::VProgramCounter___024root(VProgramCounter__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VProgramCounter___024root___ctor_var_reset(this);
}

void VProgramCounter___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VProgramCounter___024root::~VProgramCounter___024root() {
}

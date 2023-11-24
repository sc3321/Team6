// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VPCReg.h"
#include "VPCReg__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VPCReg::VPCReg(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VPCReg__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , PCsrc{vlSymsp->TOP.PCsrc}
    , ImmOp{vlSymsp->TOP.ImmOp}
    , PC{vlSymsp->TOP.PC}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VPCReg::VPCReg(const char* _vcname__)
    : VPCReg(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VPCReg::~VPCReg() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VPCReg___024root___eval_debug_assertions(VPCReg___024root* vlSelf);
#endif  // VL_DEBUG
void VPCReg___024root___eval_static(VPCReg___024root* vlSelf);
void VPCReg___024root___eval_initial(VPCReg___024root* vlSelf);
void VPCReg___024root___eval_settle(VPCReg___024root* vlSelf);
void VPCReg___024root___eval(VPCReg___024root* vlSelf);

void VPCReg::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VPCReg::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VPCReg___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VPCReg___024root___eval_static(&(vlSymsp->TOP));
        VPCReg___024root___eval_initial(&(vlSymsp->TOP));
        VPCReg___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VPCReg___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VPCReg::eventsPending() { return false; }

uint64_t VPCReg::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VPCReg::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VPCReg___024root___eval_final(VPCReg___024root* vlSelf);

VL_ATTR_COLD void VPCReg::final() {
    VPCReg___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VPCReg::hierName() const { return vlSymsp->name(); }
const char* VPCReg::modelName() const { return "VPCReg"; }
unsigned VPCReg::threads() const { return 1; }
void VPCReg::prepareClone() const { contextp()->prepareClone(); }
void VPCReg::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VPCReg::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VPCReg___024root__trace_init_top(VPCReg___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VPCReg___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPCReg___024root*>(voidSelf);
    VPCReg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    VPCReg___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void VPCReg___024root__trace_register(VPCReg___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VPCReg::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VPCReg::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VPCReg___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}

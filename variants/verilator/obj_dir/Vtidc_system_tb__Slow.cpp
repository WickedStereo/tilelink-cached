// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtidc_system_tb.h for the primary calling header

#include "Vtidc_system_tb.h"
#include "Vtidc_system_tb__Syms.h"

//==========
CData/*1:0*/ Vtidc_system_tb::__Vtable1_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state[16];

VL_CTOR_IMP(Vtidc_system_tb) {
    Vtidc_system_tb__Syms* __restrict vlSymsp = __VlSymsp = new Vtidc_system_tb__Syms(this, name());
    Vtidc_system_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtidc_system_tb::__Vconfigure(Vtidc_system_tb__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vtidc_system_tb::~Vtidc_system_tb() {
#ifdef VM_TRACE
    if (VL_UNLIKELY(__VlSymsp->__Vm_dumping)) _traceDumpClose();
#endif  // VM_TRACE
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vtidc_system_tb::_initial__TOP__1(Vtidc_system_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtidc_system_tb::_initial__TOP__1\n"); );
    Vtidc_system_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*159:0*/ __Vtemp1[5];
    // Body
    __Vtemp1[0U] = 0x2e766364U;
    __Vtemp1[1U] = 0x6d5f7462U;
    __Vtemp1[2U] = 0x79737465U;
    __Vtemp1[3U] = 0x64635f73U;
    __Vtemp1[4U] = 0x7469U;
    vl_dumpctl_filenamep(true, VL_CVT_PACK_STR_NW(5, __Vtemp1));
    vlSymsp->TOPp->_traceDumpOpen();
    vlTOPp->tidc_system_tb__DOT__reset_counter = 0U;
    vlTOPp->tidc_system_tb__DOT__rst_n = 0U;
}

void Vtidc_system_tb::_settle__TOP__5(Vtidc_system_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtidc_system_tb::_settle__TOP__5\n"); );
    Vtidc_system_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->tidc_system_tb__DOT__dut__DOT__d_ready 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_ready)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__d_ready));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__d_ready 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_ready)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__d_ready) 
              << 1U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__d_ready 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_ready)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__d_ready) 
              << 2U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__d_ready 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_ready)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__d_ready) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_addr_array[0U] 
        = vlTOPp->tidc_system_tb__DOT__l1_0_request_addr;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_addr_array[1U] 
        = vlTOPp->tidc_system_tb__DOT__l1_1_request_addr;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_addr_array[2U] 
        = (IData)((((QData)((IData)(vlTOPp->tidc_system_tb__DOT__l1_3_request_addr)) 
                    << 0x20U) | (QData)((IData)(vlTOPp->tidc_system_tb__DOT__l1_2_request_addr))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_addr_array[3U] 
        = (IData)(((((QData)((IData)(vlTOPp->tidc_system_tb__DOT__l1_3_request_addr)) 
                     << 0x20U) | (QData)((IData)(vlTOPp->tidc_system_tb__DOT__l1_2_request_addr))) 
                   >> 0x20U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0U] 
        = vlTOPp->tidc_system_tb__DOT__l1_0_request_data[0U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[1U] 
        = vlTOPp->tidc_system_tb__DOT__l1_0_request_data[1U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[2U] 
        = vlTOPp->tidc_system_tb__DOT__l1_0_request_data[2U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[3U] 
        = vlTOPp->tidc_system_tb__DOT__l1_0_request_data[3U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[4U] 
        = vlTOPp->tidc_system_tb__DOT__l1_0_request_data[4U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[5U] 
        = vlTOPp->tidc_system_tb__DOT__l1_0_request_data[5U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[6U] 
        = vlTOPp->tidc_system_tb__DOT__l1_0_request_data[6U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[7U] 
        = vlTOPp->tidc_system_tb__DOT__l1_0_request_data[7U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[8U] 
        = vlTOPp->tidc_system_tb__DOT__l1_1_request_data[0U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[9U] 
        = vlTOPp->tidc_system_tb__DOT__l1_1_request_data[1U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0xaU] 
        = vlTOPp->tidc_system_tb__DOT__l1_1_request_data[2U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0xbU] 
        = vlTOPp->tidc_system_tb__DOT__l1_1_request_data[3U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0xcU] 
        = vlTOPp->tidc_system_tb__DOT__l1_1_request_data[4U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0xdU] 
        = vlTOPp->tidc_system_tb__DOT__l1_1_request_data[5U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0xeU] 
        = vlTOPp->tidc_system_tb__DOT__l1_1_request_data[6U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0xfU] 
        = vlTOPp->tidc_system_tb__DOT__l1_1_request_data[7U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x10U] 
        = vlTOPp->tidc_system_tb__DOT__l1_2_request_data[0U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x11U] 
        = vlTOPp->tidc_system_tb__DOT__l1_2_request_data[1U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x12U] 
        = vlTOPp->tidc_system_tb__DOT__l1_2_request_data[2U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x13U] 
        = vlTOPp->tidc_system_tb__DOT__l1_2_request_data[3U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x14U] 
        = vlTOPp->tidc_system_tb__DOT__l1_2_request_data[4U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x15U] 
        = vlTOPp->tidc_system_tb__DOT__l1_2_request_data[5U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x16U] 
        = vlTOPp->tidc_system_tb__DOT__l1_2_request_data[6U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x17U] 
        = vlTOPp->tidc_system_tb__DOT__l1_2_request_data[7U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x18U] 
        = vlTOPp->tidc_system_tb__DOT__l1_3_request_data[0U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x19U] 
        = vlTOPp->tidc_system_tb__DOT__l1_3_request_data[1U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x1aU] 
        = vlTOPp->tidc_system_tb__DOT__l1_3_request_data[2U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x1bU] 
        = vlTOPp->tidc_system_tb__DOT__l1_3_request_data[3U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x1cU] 
        = vlTOPp->tidc_system_tb__DOT__l1_3_request_data[4U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x1dU] 
        = vlTOPp->tidc_system_tb__DOT__l1_3_request_data[5U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x1eU] 
        = vlTOPp->tidc_system_tb__DOT__l1_3_request_data[6U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x1fU] 
        = vlTOPp->tidc_system_tb__DOT__l1_3_request_data[7U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_permissions_array 
        = (((IData)(vlTOPp->tidc_system_tb__DOT__l1_3_request_permissions) 
            << 9U) | (((IData)(vlTOPp->tidc_system_tb__DOT__l1_2_request_permissions) 
                       << 6U) | (((IData)(vlTOPp->tidc_system_tb__DOT__l1_1_request_permissions) 
                                  << 3U) | (IData)(vlTOPp->tidc_system_tb__DOT__l1_0_request_permissions))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_addr_array[0U] 
        = vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_addr;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_addr_array[1U] 
        = vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_addr;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_addr_array[2U] 
        = (IData)((((QData)((IData)(vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_addr)) 
                    << 0x20U) | (QData)((IData)(vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_addr))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_addr_array[3U] 
        = (IData)(((((QData)((IData)(vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_addr)) 
                     << 0x20U) | (QData)((IData)(vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_addr))) 
                   >> 0x20U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_permissions_array 
        = (((IData)(vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_permissions) 
            << 9U) | (((IData)(vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_permissions) 
                       << 6U) | (((IData)(vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_permissions) 
                                  << 3U) | (IData)(vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_permissions))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0U] 
        = vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_dirty_data[0U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[1U] 
        = vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_dirty_data[1U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[2U] 
        = vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_dirty_data[2U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[3U] 
        = vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_dirty_data[3U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[4U] 
        = vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_dirty_data[4U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[5U] 
        = vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_dirty_data[5U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[6U] 
        = vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_dirty_data[6U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[7U] 
        = vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_dirty_data[7U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[8U] 
        = vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_dirty_data[0U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[9U] 
        = vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_dirty_data[1U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0xaU] 
        = vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_dirty_data[2U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0xbU] 
        = vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_dirty_data[3U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0xcU] 
        = vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_dirty_data[4U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0xdU] 
        = vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_dirty_data[5U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0xeU] 
        = vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_dirty_data[6U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0xfU] 
        = vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_dirty_data[7U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x10U] 
        = vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_dirty_data[0U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x11U] 
        = vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_dirty_data[1U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x12U] 
        = vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_dirty_data[2U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x13U] 
        = vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_dirty_data[3U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x14U] 
        = vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_dirty_data[4U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x15U] 
        = vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_dirty_data[5U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x16U] 
        = vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_dirty_data[6U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x17U] 
        = vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_dirty_data[7U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x18U] 
        = vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_dirty_data[0U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x19U] 
        = vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_dirty_data[1U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x1aU] 
        = vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_dirty_data[2U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x1bU] 
        = vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_dirty_data[3U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x1cU] 
        = vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_dirty_data[4U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x1dU] 
        = vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_dirty_data[5U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x1eU] 
        = vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_dirty_data[6U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x1fU] 
        = vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_dirty_data[7U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array 
        = (((IData)(vlTOPp->tidc_system_tb__DOT__l1_3_request_type) 
            << 9U) | (((IData)(vlTOPp->tidc_system_tb__DOT__l1_2_request_type) 
                       << 6U) | (((IData)(vlTOPp->tidc_system_tb__DOT__l1_1_request_type) 
                                  << 3U) | (IData)(vlTOPp->tidc_system_tb__DOT__l1_0_request_type))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_valid_array 
        = (((IData)(vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_valid) 
            << 3U) | (((IData)(vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_valid) 
                       << 2U) | (((IData)(vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_valid) 
                                  << 1U) | (IData)(vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_valid))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_error 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_error)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_error));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_size = 
        ((0xfff0U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_size)) 
         | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_size));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__b_ready 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_ready)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__b_ready));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_mask = 
        ((0xffffff00U & vlTOPp->tidc_system_tb__DOT__dut__DOT__a_mask) 
         | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_mask));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_size = 
        ((0xfff0U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_size)) 
         | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_size));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array 
        = ((0xff8U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_permissions));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_addr_array[0U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_addr;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_valid));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_error));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[0U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[1U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[1U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[2U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[2U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[3U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[3U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[4U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[4U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[5U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[5U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[6U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[6U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[7U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[7U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_valid));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_error 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_error)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_error) 
              << 1U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_size = 
        ((0xff0fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_size)) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_size) 
            << 4U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__b_ready 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_ready)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__b_ready) 
              << 1U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_mask = 
        ((0xffff00ffU & vlTOPp->tidc_system_tb__DOT__dut__DOT__a_mask) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_mask) 
            << 8U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_size = 
        ((0xff0fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_size)) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_size) 
            << 4U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array 
        = ((0xfc7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_permissions) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_addr_array[1U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_addr;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_valid) 
              << 1U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_error) 
              << 1U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[8U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[0U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[9U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[1U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0xaU] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[2U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0xbU] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[3U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0xcU] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[4U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0xdU] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[5U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0xeU] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[6U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0xfU] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[7U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_valid) 
              << 1U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_error 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_error)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_error) 
              << 2U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_size = 
        ((0xf0ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_size)) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_size) 
            << 8U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__b_ready 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_ready)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__b_ready) 
              << 2U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_mask = 
        ((0xff00ffffU & vlTOPp->tidc_system_tb__DOT__dut__DOT__a_mask) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_mask) 
            << 0x10U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_size = 
        ((0xf0ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_size)) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_size) 
            << 8U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array 
        = ((0xe3fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_permissions) 
              << 6U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_addr_array[2U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_addr;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_valid) 
              << 2U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_error) 
              << 2U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x10U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[0U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x11U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[1U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x12U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[2U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x13U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[3U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x14U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[4U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x15U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[5U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x16U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[6U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x17U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[7U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_valid) 
              << 2U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_error 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_error)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_error) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_size = 
        ((0xfffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_size)) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_size) 
            << 0xcU));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__b_ready 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_ready)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__b_ready) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_mask = 
        ((0xffffffU & vlTOPp->tidc_system_tb__DOT__dut__DOT__a_mask) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_mask) 
            << 0x18U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_size = 
        ((0xfffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_size)) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_size) 
            << 0xcU));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array 
        = ((0x1ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_permissions) 
              << 9U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_addr_array[3U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_addr;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_valid) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_error) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x18U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[0U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x19U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[1U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x1aU] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[2U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x1bU] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[3U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x1cU] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[4U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x1dU] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[5U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x1eU] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[6U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x1fU] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[7U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_valid) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_valid));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_valid) 
              << 1U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_valid) 
              << 2U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_valid) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[0U] 
        = (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_data);
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[1U] 
        = (IData)((vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_data 
                   >> 0x20U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_address[0U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_address;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_source 
        = ((0xfff0U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_source)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_source));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_param 
        = ((0xff8U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_param)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_param));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode 
        = ((0xff8U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_opcode));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_data[0U] 
        = (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_data);
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_data[1U] 
        = (IData)((vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_data 
                   >> 0x20U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_address[0U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_address;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_source 
        = ((0xfff0U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_source)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_source));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_param 
        = ((0xff8U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_param)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_param));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_opcode 
        = ((0xff8U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_opcode)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_opcode));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[2U] 
        = (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_data);
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[3U] 
        = (IData)((vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_data 
                   >> 0x20U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_address[1U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_address;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_source 
        = ((0xff0fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_source)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_source) 
              << 4U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_param 
        = ((0xfc7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_param)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_param) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode 
        = ((0xfc7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_opcode) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_data[2U] 
        = (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_data);
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_data[3U] 
        = (IData)((vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_data 
                   >> 0x20U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_address[1U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_address;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_source 
        = ((0xff0fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_source)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_source) 
              << 4U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_param 
        = ((0xfc7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_param)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_param) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_opcode 
        = ((0xfc7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_opcode)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_opcode) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[4U] 
        = (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_data);
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[5U] 
        = (IData)((vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_data 
                   >> 0x20U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_address[2U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_address;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_source 
        = ((0xf0ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_source)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_source) 
              << 8U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_param 
        = ((0xe3fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_param)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_param) 
              << 6U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode 
        = ((0xe3fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_opcode) 
              << 6U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_data[4U] 
        = (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_data);
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_data[5U] 
        = (IData)((vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_data 
                   >> 0x20U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_address[2U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_address;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_source 
        = ((0xf0ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_source)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_source) 
              << 8U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_param 
        = ((0xe3fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_param)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_param) 
              << 6U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_opcode 
        = ((0xe3fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_opcode)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_opcode) 
              << 6U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[6U] 
        = (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_data);
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[7U] 
        = (IData)((vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_data 
                   >> 0x20U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_address[3U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_address;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_source 
        = ((0xfffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_source)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_source) 
              << 0xcU));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_param 
        = ((0x1ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_param)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_param) 
              << 9U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode 
        = ((0x1ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_opcode) 
              << 9U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_data[6U] 
        = (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_data);
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_data[7U] 
        = (IData)((vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_data 
                   >> 0x20U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_address[3U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_address;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_source 
        = ((0xfffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_source)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_source) 
              << 0xcU));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_param 
        = ((0x1ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_param)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_param) 
              << 9U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_opcode 
        = ((0x1ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_opcode)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_opcode) 
              << 9U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink = 
        ((0xfff0U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink)) 
         | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__e_sink));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__e_valid));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink = 
        ((0xff0fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink)) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__e_sink) 
            << 4U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__e_valid) 
              << 1U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink = 
        ((0xf0ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink)) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__e_sink) 
            << 8U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__e_valid) 
              << 2U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink = 
        ((0xfffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink)) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__e_sink) 
            << 0xcU));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__e_valid) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array 
        = (((IData)(vlTOPp->tidc_system_tb__DOT__l1_3_request_valid) 
            << 3U) | (((IData)(vlTOPp->tidc_system_tb__DOT__l1_2_request_valid) 
                       << 2U) | (((IData)(vlTOPp->tidc_system_tb__DOT__l1_1_request_valid) 
                                  << 1U) | (IData)(vlTOPp->tidc_system_tb__DOT__l1_0_request_valid))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__next_state 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__state;
    if ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__state))) {
        if (vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_req) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__next_state = 1U;
        } else {
            if (vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_req) {
                vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__next_state = 2U;
            }
        }
    } else {
        if ((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__state))) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__next_state = 0U;
        } else {
            if ((2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__state))) {
                vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__next_state = 0U;
            }
        }
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_valid));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_valid) 
              << 1U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_valid) 
              << 2U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_valid) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__any_id_available 
        = (0xffffU != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__any_id_available 
        = (0xffffU != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__any_id_available 
        = (0xffffU != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__any_id_available 
        = (0xffffU != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__any_id_available 
        = (0xffffU != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_alloc_req 
        = (((6U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state)) 
            & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                  >> (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id)))) 
           & (IData)(vlTOPp->tidc_system_tb__DOT__l2_response_valid));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__dealloc_source_id_req 
        = ((((((2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state)) 
               & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid)) 
              & ((4U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode))) 
                 | (5U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode))))) 
             & ((0xfU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source)) 
                == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id))) 
            | ((((5U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state)) 
                 & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid)) 
                & (6U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode)))) 
               & ((0xfU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source)) 
                  == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id)))) 
           | ((((0xaU == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state)) 
                & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid)) 
               & ((0U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode))) 
                  | (1U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode))))) 
              & ((0xfU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source)) 
                 == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__dealloc_source_id_req 
        = ((((((2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state)) 
               & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                  >> 1U)) & ((4U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                           >> 3U))) 
                             | (5U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                             >> 3U))))) 
             & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                         >> 4U)) == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id))) 
            | ((((5U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state)) 
                 & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                    >> 1U)) & (6U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                            >> 3U)))) 
               & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                           >> 4U)) == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id)))) 
           | ((((0xaU == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state)) 
                & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                   >> 1U)) & ((0U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                            >> 3U))) 
                              | (1U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                              >> 3U))))) 
              & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                          >> 4U)) == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__dealloc_source_id_req 
        = ((((((2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state)) 
               & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                  >> 2U)) & ((4U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                           >> 6U))) 
                             | (5U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                             >> 6U))))) 
             & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                         >> 8U)) == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id))) 
            | ((((5U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state)) 
                 & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                    >> 2U)) & (6U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                            >> 6U)))) 
               & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                           >> 8U)) == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id)))) 
           | ((((0xaU == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state)) 
                & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                   >> 2U)) & ((0U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                            >> 6U))) 
                              | (1U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                              >> 6U))))) 
              & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                          >> 8U)) == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__dealloc_source_id_req 
        = ((((((2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state)) 
               & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                  >> 3U)) & ((4U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                           >> 9U))) 
                             | (5U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                             >> 9U))))) 
             & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                         >> 0xcU)) == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id))) 
            | ((((5U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state)) 
                 & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                    >> 3U)) & (6U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                            >> 9U)))) 
               & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                           >> 0xcU)) == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id)))) 
           | ((((0xaU == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state)) 
                & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                   >> 3U)) & ((0U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                            >> 9U))) 
                              | (1U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                              >> 9U))))) 
              & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                          >> 0xcU)) == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id))));
    vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__2__one_hot 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_oh;
    vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__2__Vfuncout = 0U;
    if ((1U & (IData)(vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__2__one_hot))) {
        vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__2__Vfuncout = 0U;
    }
    if ((2U & (IData)(vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__2__one_hot))) {
        vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__2__Vfuncout = 1U;
    }
    if ((4U & (IData)(vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__2__one_hot))) {
        vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__2__Vfuncout = 2U;
    }
    if ((8U & (IData)(vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__2__one_hot))) {
        vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__2__Vfuncout = 3U;
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id 
        = vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__2__Vfuncout;
    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__l1_request_ready 
        = ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state)) 
           & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__allocated_source_id_valid) 
              | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r)));
    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__l1_request_ready 
        = ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state)) 
           & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__allocated_source_id_valid) 
              | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r)));
    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__l1_request_ready 
        = ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state)) 
           & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__allocated_source_id_valid) 
              | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r)));
    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__l1_request_ready 
        = ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state)) 
           & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__allocated_source_id_valid) 
              | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r)));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready)) 
           | (((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__state)) 
               & (0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel))) 
              & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_oh)));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready)) 
           | (((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__state)) 
               & (1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel))) 
              & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_oh)));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready)) 
           | (0xfffffffeU & ((((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__state)) 
                               & (0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel))) 
                              << 1U) & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_oh))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready)) 
           | (0xfffffffeU & ((((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__state)) 
                               & (1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel))) 
                              << 1U) & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_oh))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready)) 
           | (0xfffffffcU & ((((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__state)) 
                               & (0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel))) 
                              << 2U) & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_oh))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready)) 
           | (0xfffffffcU & ((((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__state)) 
                               & (1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel))) 
                              << 2U) & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_oh))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready)) 
           | (0xfffffff8U & ((((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__state)) 
                               & (0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel))) 
                              << 3U) & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_oh))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready)) 
           | (0xfffffff8U & ((((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__state)) 
                               & (1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel))) 
                              << 3U) & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_oh))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_req_masked 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_req_masked)) 
           | (8U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid)));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_req_masked 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_req_masked)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid) 
              & (0U >= (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_rr_ptr))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_req_masked 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_req_masked)) 
           | (0xfffffffeU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid) 
                             & ((1U >= (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_rr_ptr)) 
                                << 1U))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_req_masked 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_req_masked)) 
           | (0xfffffffcU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid) 
                             & ((2U >= (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_rr_ptr)) 
                                << 2U))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__next_state 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state;
    if (((((((((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state)) 
               | (1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) 
              | (2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) 
             | (3U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) 
            | (4U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) 
           | (5U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) 
          | (6U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) 
         | (7U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state)))) {
        if ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) {
            if (vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_valid) {
                vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__next_state = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) {
                if (vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_valid) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__next_state 
                        = ((6U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode))
                            ? 2U : (((6U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode)) 
                                     | (7U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode)))
                                     ? 7U : (((4U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode)) 
                                              | (0U 
                                                 == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode)))
                                              ? 0xaU
                                              : 0U)));
                }
            } else {
                if ((2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__next_state 
                        = ((0U != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent))
                            ? 3U : 5U);
                } else {
                    if ((3U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__next_state = 4U;
                    } else {
                        if ((4U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) {
                            if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent) 
                                  & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked)) 
                                 == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__next_state = 5U;
                            }
                        } else {
                            if ((5U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) {
                                if (vlTOPp->tidc_system_tb__DOT__l2_response_valid) {
                                    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__next_state = 6U;
                                }
                            } else {
                                if ((6U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) {
                                    if ((1U & (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                                                & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_ready)) 
                                               >> (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id)))) {
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__next_state = 9U;
                                    }
                                } else {
                                    if (vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_done) {
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__next_state = 8U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((8U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) {
            if ((1U & (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                        & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_ready)) 
                       >> (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id)))) {
                vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__next_state = 0U;
            }
        } else {
            if ((9U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) {
                if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid) 
                      >> (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id)) 
                     & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink) 
                                 >> (0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                             << 2U)))) 
                        == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_sink)))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__next_state = 0U;
                }
            } else {
                if ((0xaU == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) {
                    if (((4U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode)) 
                         & (IData)(vlTOPp->tidc_system_tb__DOT__l2_response_valid))) {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__next_state = 0U;
                    } else {
                        if ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode))) {
                            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__next_state = 0U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__alloc_source_id_req 
        = (((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state)) 
            & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array)) 
           & (~ (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r)));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__alloc_source_id_req 
        = (((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state)) 
            & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array) 
               >> 1U)) & (~ (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r)));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__alloc_source_id_req 
        = (((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state)) 
            & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array) 
               >> 2U)) & (~ (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r)));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__alloc_source_id_req 
        = (((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state)) 
            & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array) 
               >> 3U)) & (~ (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r)));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_req_masked 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_req_masked)) 
           | (8U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid)));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_req_masked 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_req_masked)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid) 
              & (0U >= (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_rr_ptr))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_req_masked 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_req_masked)) 
           | (0xfffffffeU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid) 
                             & ((1U >= (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_rr_ptr)) 
                                << 1U))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_req_masked 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_req_masked)) 
           | (0xfffffffcU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid) 
                             & ((2U >= (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_rr_ptr)) 
                                << 2U))));
    vlTOPp->__Vtableidx1 = (((IData)((0U != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid))) 
                             << 3U) | (((IData)((0U 
                                                 != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid))) 
                                        << 2U) | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__state)));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state 
        = vlTOPp->__Vtable1_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state
        [vlTOPp->__Vtableidx1];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_ready_array 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_ready_array)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__l1_request_ready));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_ready_array 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_ready_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__l1_request_ready) 
              << 1U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_ready_array 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_ready_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__l1_request_ready) 
              << 2U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_ready_array 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_ready_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__l1_request_ready) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__next_state 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state;
    if (((((((((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state)) 
               | (1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) 
              | (2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) 
             | (3U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) 
            | (4U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) 
           | (5U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) 
          | (6U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) 
         | (7U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state)))) {
        if ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) {
            if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array) 
                 & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__l1_request_ready))) {
                vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__next_state 
                    = (((0U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array))) 
                        | (1U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array))))
                        ? 1U : ((2U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array)))
                                 ? 4U : (((3U == (7U 
                                                  & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array))) 
                                          | (4U == 
                                             (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array))))
                                          ? 9U : 0U)));
            } else {
                if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid) 
                     & (6U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode))))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__next_state = 6U;
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) {
                if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_valid) 
                     & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__next_state = 2U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) {
                    if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                          & ((4U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode))) 
                             | (5U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode))))) 
                         & ((0xfU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source)) 
                            == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__next_state = 3U;
                    }
                } else {
                    if ((3U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) {
                        if (vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__e_valid) {
                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__next_state = 0U;
                        }
                    } else {
                        if ((4U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) {
                            if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_valid) 
                                 & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__next_state = 5U;
                            }
                        } else {
                            if ((5U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) {
                                if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                                      & (6U == (7U 
                                                & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode)))) 
                                     & ((0xfU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source)) 
                                        == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                                    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__next_state = 0U;
                                }
                            } else {
                                if ((6U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) {
                                    if (vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_valid) {
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__next_state = 7U;
                                    }
                                } else {
                                    if ((1U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_valid_array))) {
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__next_state = 8U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((8U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) {
            if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_valid) 
                 & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready))) {
                vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__next_state = 0U;
            }
        } else {
            if ((9U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) {
                if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_valid) 
                     & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__next_state = 0xaU;
                }
            } else {
                if ((0xaU == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) {
                    if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                          & ((0U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode))) 
                             | (1U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode))))) 
                         & ((0xfU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source)) 
                            == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__next_state = 0U;
                    }
                }
            }
        }
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__next_state 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state;
    if (((((((((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state)) 
               | (1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) 
              | (2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) 
             | (3U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) 
            | (4U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) 
           | (5U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) 
          | (6U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) 
         | (7U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state)))) {
        if ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) {
            if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array) 
                  >> 1U) & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__l1_request_ready))) {
                vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__next_state 
                    = (((0U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                      >> 3U))) | (1U 
                                                  == 
                                                  (7U 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                                      >> 3U))))
                        ? 1U : ((2U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                              >> 3U)))
                                 ? 4U : (((3U == (7U 
                                                  & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                                     >> 3U))) 
                                          | (4U == 
                                             (7U & 
                                              ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                               >> 3U))))
                                          ? 9U : 0U)));
            } else {
                if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid) 
                      >> 1U) & (6U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode) 
                                             >> 3U))))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__next_state = 6U;
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) {
                if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_valid) 
                     & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready) 
                        >> 1U))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__next_state = 2U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) {
                    if (((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                           >> 1U) & ((4U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                   >> 3U))) 
                                     | (5U == (7U & 
                                               ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                >> 3U))))) 
                         & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                     >> 4U)) == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__next_state = 3U;
                    }
                } else {
                    if ((3U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) {
                        if (vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__e_valid) {
                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__next_state = 0U;
                        }
                    } else {
                        if ((4U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) {
                            if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_valid) 
                                 & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready) 
                                    >> 1U))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__next_state = 5U;
                            }
                        } else {
                            if ((5U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) {
                                if (((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                                       >> 1U) & (6U 
                                                 == 
                                                 (7U 
                                                  & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                     >> 3U)))) 
                                     & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                                 >> 4U)) 
                                        == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                                    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__next_state = 0U;
                                }
                            } else {
                                if ((6U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) {
                                    if (vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_valid) {
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__next_state = 7U;
                                    }
                                } else {
                                    if ((2U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_valid_array))) {
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__next_state = 8U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((8U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) {
            if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_valid) 
                 & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready) 
                    >> 1U))) {
                vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__next_state = 0U;
            }
        } else {
            if ((9U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) {
                if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_valid) 
                     & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready) 
                        >> 1U))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__next_state = 0xaU;
                }
            } else {
                if ((0xaU == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) {
                    if (((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                           >> 1U) & ((0U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                   >> 3U))) 
                                     | (1U == (7U & 
                                               ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                >> 3U))))) 
                         & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                     >> 4U)) == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__next_state = 0U;
                    }
                }
            }
        }
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__next_state 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state;
    if (((((((((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state)) 
               | (1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) 
              | (2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) 
             | (3U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) 
            | (4U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) 
           | (5U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) 
          | (6U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) 
         | (7U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state)))) {
        if ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) {
            if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array) 
                  >> 2U) & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__l1_request_ready))) {
                vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__next_state 
                    = (((0U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                      >> 6U))) | (1U 
                                                  == 
                                                  (7U 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                                      >> 6U))))
                        ? 1U : ((2U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                              >> 6U)))
                                 ? 4U : (((3U == (7U 
                                                  & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                                     >> 6U))) 
                                          | (4U == 
                                             (7U & 
                                              ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                               >> 6U))))
                                          ? 9U : 0U)));
            } else {
                if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid) 
                      >> 2U) & (6U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode) 
                                             >> 6U))))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__next_state = 6U;
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) {
                if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_valid) 
                     & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready) 
                        >> 2U))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__next_state = 2U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) {
                    if (((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                           >> 2U) & ((4U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                   >> 6U))) 
                                     | (5U == (7U & 
                                               ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                >> 6U))))) 
                         & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                     >> 8U)) == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__next_state = 3U;
                    }
                } else {
                    if ((3U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) {
                        if (vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__e_valid) {
                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__next_state = 0U;
                        }
                    } else {
                        if ((4U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) {
                            if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_valid) 
                                 & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready) 
                                    >> 2U))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__next_state = 5U;
                            }
                        } else {
                            if ((5U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) {
                                if (((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                                       >> 2U) & (6U 
                                                 == 
                                                 (7U 
                                                  & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                     >> 6U)))) 
                                     & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                                 >> 8U)) 
                                        == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                                    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__next_state = 0U;
                                }
                            } else {
                                if ((6U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) {
                                    if (vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_valid) {
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__next_state = 7U;
                                    }
                                } else {
                                    if ((4U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_valid_array))) {
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__next_state = 8U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((8U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) {
            if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_valid) 
                 & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready) 
                    >> 2U))) {
                vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__next_state = 0U;
            }
        } else {
            if ((9U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) {
                if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_valid) 
                     & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready) 
                        >> 2U))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__next_state = 0xaU;
                }
            } else {
                if ((0xaU == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) {
                    if (((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                           >> 2U) & ((0U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                   >> 6U))) 
                                     | (1U == (7U & 
                                               ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                >> 6U))))) 
                         & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                     >> 8U)) == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__next_state = 0U;
                    }
                }
            }
        }
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__next_state 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state;
    if (((((((((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state)) 
               | (1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) 
              | (2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) 
             | (3U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) 
            | (4U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) 
           | (5U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) 
          | (6U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) 
         | (7U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state)))) {
        if ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) {
            if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array) 
                  >> 3U) & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__l1_request_ready))) {
                vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__next_state 
                    = (((0U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                      >> 9U))) | (1U 
                                                  == 
                                                  (7U 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                                      >> 9U))))
                        ? 1U : ((2U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                              >> 9U)))
                                 ? 4U : (((3U == (7U 
                                                  & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                                     >> 9U))) 
                                          | (4U == 
                                             (7U & 
                                              ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                               >> 9U))))
                                          ? 9U : 0U)));
            } else {
                if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid) 
                      >> 3U) & (6U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode) 
                                             >> 9U))))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__next_state = 6U;
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) {
                if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_valid) 
                     & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready) 
                        >> 3U))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__next_state = 2U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) {
                    if (((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                           >> 3U) & ((4U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                   >> 9U))) 
                                     | (5U == (7U & 
                                               ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                >> 9U))))) 
                         & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                     >> 0xcU)) == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__next_state = 3U;
                    }
                } else {
                    if ((3U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) {
                        if (vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__e_valid) {
                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__next_state = 0U;
                        }
                    } else {
                        if ((4U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) {
                            if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_valid) 
                                 & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready) 
                                    >> 3U))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__next_state = 5U;
                            }
                        } else {
                            if ((5U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) {
                                if (((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                                       >> 3U) & (6U 
                                                 == 
                                                 (7U 
                                                  & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                     >> 9U)))) 
                                     & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                                 >> 0xcU)) 
                                        == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                                    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__next_state = 0U;
                                }
                            } else {
                                if ((6U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) {
                                    if (vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_valid) {
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__next_state = 7U;
                                    }
                                } else {
                                    if ((8U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_valid_array))) {
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__next_state = 8U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((8U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) {
            if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_valid) 
                 & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready) 
                    >> 3U))) {
                vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__next_state = 0U;
            }
        } else {
            if ((9U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) {
                if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_valid) 
                     & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready) 
                        >> 3U))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__next_state = 0xaU;
                }
            } else {
                if ((0xaU == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) {
                    if (((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                           >> 3U) & ((0U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                   >> 9U))) 
                                     | (1U == (7U & 
                                               ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                >> 9U))))) 
                         & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                     >> 0xcU)) == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__next_state = 0U;
                    }
                }
            }
        }
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_selected_oh 
        = ((0U != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_req_masked))
            ? ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_req_masked) 
               & (- (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_req_masked)))
            : ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid) 
               & (- (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid))));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_selected_oh 
        = ((0U != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_req_masked))
            ? ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_req_masked) 
               & (- (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_req_masked)))
            : ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid) 
               & (- (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid))));
    vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__0__one_hot 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_selected_oh;
    vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__0__Vfuncout = 0U;
    if ((1U & (IData)(vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__0__one_hot))) {
        vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__0__Vfuncout = 0U;
    }
    if ((2U & (IData)(vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__0__one_hot))) {
        vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__0__Vfuncout = 1U;
    }
    if ((4U & (IData)(vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__0__one_hot))) {
        vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__0__Vfuncout = 2U;
    }
    if ((8U & (IData)(vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__0__one_hot))) {
        vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__0__Vfuncout = 3U;
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_selected_id 
        = vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__0__Vfuncout;
    vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__1__one_hot 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_selected_oh;
    vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__1__Vfuncout = 0U;
    if ((1U & (IData)(vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__1__one_hot))) {
        vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__1__Vfuncout = 0U;
    }
    if ((2U & (IData)(vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__1__one_hot))) {
        vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__1__Vfuncout = 1U;
    }
    if ((4U & (IData)(vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__1__one_hot))) {
        vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__1__Vfuncout = 2U;
    }
    if ((8U & (IData)(vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__1__one_hot))) {
        vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__1__Vfuncout = 3U;
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_selected_id 
        = vlTOPp->__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__1__Vfuncout;
}

void Vtidc_system_tb::_eval_initial(Vtidc_system_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtidc_system_tb::_eval_initial\n"); );
    Vtidc_system_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[4U] = 1U;
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__tidc_system_tb__DOT__rst_n 
        = vlTOPp->__VinpClk__TOP__tidc_system_tb__DOT__rst_n;
}

void Vtidc_system_tb::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtidc_system_tb::final\n"); );
    // Variables
    Vtidc_system_tb__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtidc_system_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtidc_system_tb::_eval_settle(Vtidc_system_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtidc_system_tb::_eval_settle\n"); );
    Vtidc_system_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__5(vlSymsp);
    vlTOPp->__Vm_traceActivity[4U] = 1U;
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vtidc_system_tb::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtidc_system_tb::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__rst_n = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__l1_0_request_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__l1_0_request_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__l1_0_request_type = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__l1_0_request_data);
    tidc_system_tb__DOT__l1_0_request_permissions = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__l1_0_probe_ack_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__l1_0_probe_ack_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__l1_0_probe_ack_permissions = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__l1_0_probe_ack_dirty_data);
    tidc_system_tb__DOT__l1_1_request_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__l1_1_request_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__l1_1_request_type = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__l1_1_request_data);
    tidc_system_tb__DOT__l1_1_request_permissions = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__l1_1_probe_ack_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__l1_1_probe_ack_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__l1_1_probe_ack_permissions = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__l1_1_probe_ack_dirty_data);
    tidc_system_tb__DOT__l1_2_request_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__l1_2_request_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__l1_2_request_type = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__l1_2_request_data);
    tidc_system_tb__DOT__l1_2_request_permissions = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__l1_2_probe_ack_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__l1_2_probe_ack_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__l1_2_probe_ack_permissions = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__l1_2_probe_ack_dirty_data);
    tidc_system_tb__DOT__l1_3_request_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__l1_3_request_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__l1_3_request_type = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__l1_3_request_data);
    tidc_system_tb__DOT__l1_3_request_permissions = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__l1_3_probe_ack_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__l1_3_probe_ack_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__l1_3_probe_ack_permissions = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__l1_3_probe_ack_dirty_data);
    tidc_system_tb__DOT__l2_cmd_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__l2_cmd_type = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__l2_cmd_addr = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__l2_cmd_data);
    tidc_system_tb__DOT__l2_cmd_size = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__l2_cmd_dirty = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__l2_response_valid = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__l2_response_data);
    tidc_system_tb__DOT__l2_response_error = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__test_state = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__wait_counter = VL_RAND_RESET_I(16);
    tidc_system_tb__DOT__timeout_counter = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__reset_counter = VL_RAND_RESET_I(8);
    tidc_system_tb__DOT__dut__DOT__a_valid = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__a_opcode = VL_RAND_RESET_I(12);
    tidc_system_tb__DOT__dut__DOT__a_param = VL_RAND_RESET_I(12);
    tidc_system_tb__DOT__dut__DOT__a_size = VL_RAND_RESET_I(16);
    tidc_system_tb__DOT__dut__DOT__a_source = VL_RAND_RESET_I(16);
    VL_RAND_RESET_W(128, tidc_system_tb__DOT__dut__DOT__a_address);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__dut__DOT__a_data);
    tidc_system_tb__DOT__dut__DOT__a_mask = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT__a_ready = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__b_valid = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__b_opcode = VL_RAND_RESET_I(12);
    tidc_system_tb__DOT__dut__DOT__b_param = VL_RAND_RESET_I(12);
    tidc_system_tb__DOT__dut__DOT__b_size = VL_RAND_RESET_I(16);
    tidc_system_tb__DOT__dut__DOT__b_source = VL_RAND_RESET_I(16);
    VL_RAND_RESET_W(128, tidc_system_tb__DOT__dut__DOT__b_address);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__dut__DOT__b_data);
    tidc_system_tb__DOT__dut__DOT__b_mask = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT__b_ready = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__c_valid = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__c_opcode = VL_RAND_RESET_I(12);
    tidc_system_tb__DOT__dut__DOT__c_param = VL_RAND_RESET_I(12);
    tidc_system_tb__DOT__dut__DOT__c_size = VL_RAND_RESET_I(16);
    tidc_system_tb__DOT__dut__DOT__c_source = VL_RAND_RESET_I(16);
    VL_RAND_RESET_W(128, tidc_system_tb__DOT__dut__DOT__c_address);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__dut__DOT__c_data);
    tidc_system_tb__DOT__dut__DOT__c_error = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__c_ready = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__d_valid = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__d_opcode = VL_RAND_RESET_I(12);
    tidc_system_tb__DOT__dut__DOT__d_param = VL_RAND_RESET_I(12);
    tidc_system_tb__DOT__dut__DOT__d_size = VL_RAND_RESET_I(16);
    tidc_system_tb__DOT__dut__DOT__d_source = VL_RAND_RESET_I(16);
    tidc_system_tb__DOT__dut__DOT__d_sink = VL_RAND_RESET_I(16);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__dut__DOT__d_data);
    tidc_system_tb__DOT__dut__DOT__d_error = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__d_ready = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__e_valid = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__e_sink = VL_RAND_RESET_I(16);
    tidc_system_tb__DOT__dut__DOT__l1_request_valid_array = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(128, tidc_system_tb__DOT__dut__DOT__l1_request_addr_array);
    tidc_system_tb__DOT__dut__DOT__l1_request_type_array = VL_RAND_RESET_I(12);
    VL_RAND_RESET_W(1024, tidc_system_tb__DOT__dut__DOT__l1_request_data_array);
    tidc_system_tb__DOT__dut__DOT__l1_request_permissions_array = VL_RAND_RESET_I(12);
    tidc_system_tb__DOT__dut__DOT__l1_request_ready_array = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__l1_data_valid_array = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(1024, tidc_system_tb__DOT__dut__DOT__l1_data_array);
    tidc_system_tb__DOT__dut__DOT__l1_data_error_array = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(128, tidc_system_tb__DOT__dut__DOT__l1_probe_req_addr_array);
    tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array = VL_RAND_RESET_I(12);
    tidc_system_tb__DOT__dut__DOT__l1_probe_ack_valid_array = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(128, tidc_system_tb__DOT__dut__DOT__l1_probe_ack_addr_array);
    tidc_system_tb__DOT__dut__DOT__l1_probe_ack_permissions_array = VL_RAND_RESET_I(12);
    VL_RAND_RESET_W(1024, tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__e_sink = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__e_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__d_ready = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_error = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_data = VL_RAND_RESET_Q(64);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_address = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_source = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_size = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_param = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_opcode = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__b_ready = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_mask = VL_RAND_RESET_I(8);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_data = VL_RAND_RESET_Q(64);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_address = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_source = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_size = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_param = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_opcode = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_permissions = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_error = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__l1_request_ready = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__e_sink = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__e_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__d_ready = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_error = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_data = VL_RAND_RESET_Q(64);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_address = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_source = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_size = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_param = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_opcode = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__b_ready = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_mask = VL_RAND_RESET_I(8);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_data = VL_RAND_RESET_Q(64);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_address = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_source = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_size = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_param = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_opcode = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_permissions = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_error = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__l1_request_ready = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__e_sink = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__e_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__d_ready = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_error = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_data = VL_RAND_RESET_Q(64);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_address = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_source = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_size = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_param = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_opcode = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__b_ready = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_mask = VL_RAND_RESET_I(8);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_data = VL_RAND_RESET_Q(64);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_address = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_source = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_size = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_param = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_opcode = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_permissions = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_error = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__l1_request_ready = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__e_sink = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__e_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__d_ready = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_error = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_data = VL_RAND_RESET_Q(64);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_address = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_source = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_size = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_param = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_opcode = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__b_ready = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_mask = VL_RAND_RESET_I(8);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_data = VL_RAND_RESET_Q(64);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_address = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_source = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_size = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_param = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_opcode = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_permissions = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_error = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__l1_request_ready = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel = VL_RAND_RESET_I(2);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_oh = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id = VL_RAND_RESET_I(2);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_busy = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_req = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_state = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_presence = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_tip_state = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_req = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_state = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_presence = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_tip_state = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_done = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_alloc_req = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_dealloc_sink_id = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__next_state = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id = VL_RAND_RESET_I(2);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_source = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_sink = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__i = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__j = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound2 = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound3 = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound4 = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound5 = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound6 = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound7 = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound8 = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__state = VL_RAND_RESET_I(2);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state = VL_RAND_RESET_I(2);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_rr_ptr = VL_RAND_RESET_I(2);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_rr_ptr = VL_RAND_RESET_I(2);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_req_masked = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_req_masked = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_selected_oh = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_selected_oh = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_selected_id = VL_RAND_RESET_I(2);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_selected_id = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
            tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tags[__Vi0] = VL_RAND_RESET_I(26);
    }}
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
            tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_states[__Vi0] = VL_RAND_RESET_I(3);
    }}
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
            tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_presence[__Vi0] = VL_RAND_RESET_I(4);
    }}
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
            tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tip_state[__Vi0] = VL_RAND_RESET_I(4);
    }}
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
            tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__state = VL_RAND_RESET_I(2);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__next_state = VL_RAND_RESET_I(2);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__req_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__i = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use = VL_RAND_RESET_I(16);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__any_id_available = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__alloc_gnt_r = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__next_state = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_req_type = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_permissions = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_has_data = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_param = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_source = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__grant_sink = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__alloc_source_id_req = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__dealloc_source_id_req = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__dealloc_source_id = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__allocated_source_id_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__allocated_source_id = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use = VL_RAND_RESET_I(16);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__any_id_available = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__next_state = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_req_type = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_permissions = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_has_data = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_param = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_source = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__grant_sink = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__alloc_source_id_req = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__dealloc_source_id_req = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__dealloc_source_id = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__allocated_source_id_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__allocated_source_id = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use = VL_RAND_RESET_I(16);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__any_id_available = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__next_state = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_req_type = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_permissions = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_has_data = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_param = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_source = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__grant_sink = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__alloc_source_id_req = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__dealloc_source_id_req = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__dealloc_source_id = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__allocated_source_id_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__allocated_source_id = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use = VL_RAND_RESET_I(16);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__any_id_available = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__next_state = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_req_type = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_permissions = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(256, tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_has_data = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_addr = VL_RAND_RESET_I(32);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_param = VL_RAND_RESET_I(3);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_source = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__grant_sink = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__alloc_source_id_req = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__dealloc_source_id_req = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__dealloc_source_id = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__allocated_source_id_valid = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__allocated_source_id = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use = VL_RAND_RESET_I(16);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id = VL_RAND_RESET_I(4);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__any_id_available = VL_RAND_RESET_I(1);
    tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r = VL_RAND_RESET_I(1);
    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__0__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__0__one_hot = VL_RAND_RESET_I(4);
    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__1__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__1__one_hot = VL_RAND_RESET_I(4);
    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__2__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__2__one_hot = VL_RAND_RESET_I(4);
    __Vtableidx1 = 0;
    __Vtable1_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state[0] = 0U;
    __Vtable1_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state[1] = 0U;
    __Vtable1_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state[2] = 0U;
    __Vtable1_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state[3] = 3U;
    __Vtable1_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state[4] = 1U;
    __Vtable1_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state[5] = 1U;
    __Vtable1_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state[6] = 1U;
    __Vtable1_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state[7] = 3U;
    __Vtable1_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state[8] = 1U;
    __Vtable1_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state[9] = 1U;
    __Vtable1_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state[10] = 1U;
    __Vtable1_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state[11] = 3U;
    __Vtable1_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state[12] = 1U;
    __Vtable1_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state[13] = 1U;
    __Vtable1_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state[14] = 1U;
    __Vtable1_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state[15] = 3U;
    __Vdly__tidc_system_tb__DOT__l2_response_valid = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(256, __Vdly__tidc_system_tb__DOT__l2_response_data);
    __Vdly__tidc_system_tb__DOT__l2_response_error = VL_RAND_RESET_I(1);
    __VinpClk__TOP__tidc_system_tb__DOT__rst_n = VL_RAND_RESET_I(1);
    __Vchglast__TOP__tidc_system_tb__DOT__rst_n = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<5; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}

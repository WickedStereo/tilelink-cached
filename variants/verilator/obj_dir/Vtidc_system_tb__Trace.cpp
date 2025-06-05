// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtidc_system_tb__Syms.h"


void Vtidc_system_tb::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vtidc_system_tb__Syms* __restrict vlSymsp = static_cast<Vtidc_system_tb__Syms*>(userp);
    Vtidc_system_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vtidc_system_tb::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vtidc_system_tb__Syms* __restrict vlSymsp = static_cast<Vtidc_system_tb__Syms*>(userp);
    Vtidc_system_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Variables
    WData/*255:0*/ __Vtemp70[8];
    WData/*255:0*/ __Vtemp71[8];
    WData/*255:0*/ __Vtemp72[8];
    WData/*255:0*/ __Vtemp73[8];
    WData/*255:0*/ __Vtemp74[8];
    WData/*255:0*/ __Vtemp75[8];
    WData/*255:0*/ __Vtemp76[8];
    WData/*255:0*/ __Vtemp77[8];
    WData/*255:0*/ __Vtemp78[8];
    WData/*255:0*/ __Vtemp79[8];
    WData/*255:0*/ __Vtemp80[8];
    WData/*255:0*/ __Vtemp81[8];
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->tidc_system_tb__DOT__l1_0_request_valid));
            tracep->chgIData(oldp+1,(vlTOPp->tidc_system_tb__DOT__l1_0_request_addr),32);
            tracep->chgCData(oldp+2,(vlTOPp->tidc_system_tb__DOT__l1_0_request_type),3);
            tracep->chgWData(oldp+3,(vlTOPp->tidc_system_tb__DOT__l1_0_request_data),256);
            tracep->chgCData(oldp+11,(vlTOPp->tidc_system_tb__DOT__l1_0_request_permissions),3);
            tracep->chgBit(oldp+12,(vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_valid));
            tracep->chgIData(oldp+13,(vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_addr),32);
            tracep->chgCData(oldp+14,(vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_permissions),3);
            tracep->chgWData(oldp+15,(vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_dirty_data),256);
            tracep->chgBit(oldp+23,(vlTOPp->tidc_system_tb__DOT__l1_1_request_valid));
            tracep->chgIData(oldp+24,(vlTOPp->tidc_system_tb__DOT__l1_1_request_addr),32);
            tracep->chgCData(oldp+25,(vlTOPp->tidc_system_tb__DOT__l1_1_request_type),3);
            tracep->chgWData(oldp+26,(vlTOPp->tidc_system_tb__DOT__l1_1_request_data),256);
            tracep->chgCData(oldp+34,(vlTOPp->tidc_system_tb__DOT__l1_1_request_permissions),3);
            tracep->chgBit(oldp+35,(vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_valid));
            tracep->chgIData(oldp+36,(vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_addr),32);
            tracep->chgCData(oldp+37,(vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_permissions),3);
            tracep->chgWData(oldp+38,(vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_dirty_data),256);
            tracep->chgBit(oldp+46,(vlTOPp->tidc_system_tb__DOT__l1_2_request_valid));
            tracep->chgIData(oldp+47,(vlTOPp->tidc_system_tb__DOT__l1_2_request_addr),32);
            tracep->chgCData(oldp+48,(vlTOPp->tidc_system_tb__DOT__l1_2_request_type),3);
            tracep->chgWData(oldp+49,(vlTOPp->tidc_system_tb__DOT__l1_2_request_data),256);
            tracep->chgCData(oldp+57,(vlTOPp->tidc_system_tb__DOT__l1_2_request_permissions),3);
            tracep->chgBit(oldp+58,(vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_valid));
            tracep->chgIData(oldp+59,(vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_addr),32);
            tracep->chgCData(oldp+60,(vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_permissions),3);
            tracep->chgWData(oldp+61,(vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_dirty_data),256);
            tracep->chgBit(oldp+69,(vlTOPp->tidc_system_tb__DOT__l1_3_request_valid));
            tracep->chgIData(oldp+70,(vlTOPp->tidc_system_tb__DOT__l1_3_request_addr),32);
            tracep->chgCData(oldp+71,(vlTOPp->tidc_system_tb__DOT__l1_3_request_type),3);
            tracep->chgWData(oldp+72,(vlTOPp->tidc_system_tb__DOT__l1_3_request_data),256);
            tracep->chgCData(oldp+80,(vlTOPp->tidc_system_tb__DOT__l1_3_request_permissions),3);
            tracep->chgBit(oldp+81,(vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_valid));
            tracep->chgIData(oldp+82,(vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_addr),32);
            tracep->chgCData(oldp+83,(vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_permissions),3);
            tracep->chgWData(oldp+84,(vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_dirty_data),256);
            tracep->chgCData(oldp+92,(vlTOPp->tidc_system_tb__DOT__test_state),4);
            tracep->chgSData(oldp+93,(vlTOPp->tidc_system_tb__DOT__wait_counter),16);
            tracep->chgIData(oldp+94,(vlTOPp->tidc_system_tb__DOT__timeout_counter),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgBit(oldp+95,((1U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_ready_array))));
            tracep->chgBit(oldp+96,((1U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array))));
            __Vtemp70[0U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0U];
            __Vtemp70[1U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[1U];
            __Vtemp70[2U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[2U];
            __Vtemp70[3U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[3U];
            __Vtemp70[4U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[4U];
            __Vtemp70[5U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[5U];
            __Vtemp70[6U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[6U];
            __Vtemp70[7U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[7U];
            tracep->chgWData(oldp+97,(__Vtemp70),256);
            tracep->chgBit(oldp+105,((1U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array))));
            tracep->chgBit(oldp+106,((1U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array))));
            tracep->chgIData(oldp+107,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_addr_array[0U]),32);
            tracep->chgCData(oldp+108,((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array))),3);
            tracep->chgBit(oldp+109,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_ready_array) 
                                            >> 1U))));
            tracep->chgBit(oldp+110,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array) 
                                            >> 1U))));
            __Vtemp71[0U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[8U];
            __Vtemp71[1U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[9U];
            __Vtemp71[2U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0xaU];
            __Vtemp71[3U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0xbU];
            __Vtemp71[4U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0xcU];
            __Vtemp71[5U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0xdU];
            __Vtemp71[6U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0xeU];
            __Vtemp71[7U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0xfU];
            tracep->chgWData(oldp+111,(__Vtemp71),256);
            tracep->chgBit(oldp+119,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array) 
                                            >> 1U))));
            tracep->chgBit(oldp+120,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array) 
                                            >> 1U))));
            tracep->chgIData(oldp+121,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_addr_array[1U]),32);
            tracep->chgCData(oldp+122,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array) 
                                              >> 3U))),3);
            tracep->chgBit(oldp+123,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_ready_array) 
                                            >> 2U))));
            tracep->chgBit(oldp+124,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array) 
                                            >> 2U))));
            __Vtemp72[0U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x10U];
            __Vtemp72[1U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x11U];
            __Vtemp72[2U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x12U];
            __Vtemp72[3U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x13U];
            __Vtemp72[4U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x14U];
            __Vtemp72[5U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x15U];
            __Vtemp72[6U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x16U];
            __Vtemp72[7U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x17U];
            tracep->chgWData(oldp+125,(__Vtemp72),256);
            tracep->chgBit(oldp+133,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array) 
                                            >> 2U))));
            tracep->chgBit(oldp+134,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array) 
                                            >> 2U))));
            tracep->chgIData(oldp+135,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_addr_array[2U]),32);
            tracep->chgCData(oldp+136,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array) 
                                              >> 6U))),3);
            tracep->chgBit(oldp+137,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_ready_array) 
                                            >> 3U))));
            tracep->chgBit(oldp+138,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array) 
                                            >> 3U))));
            __Vtemp73[0U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x18U];
            __Vtemp73[1U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x19U];
            __Vtemp73[2U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x1aU];
            __Vtemp73[3U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x1bU];
            __Vtemp73[4U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x1cU];
            __Vtemp73[5U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x1dU];
            __Vtemp73[6U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x1eU];
            __Vtemp73[7U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x1fU];
            tracep->chgWData(oldp+139,(__Vtemp73),256);
            tracep->chgBit(oldp+147,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array) 
                                            >> 3U))));
            tracep->chgBit(oldp+148,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array) 
                                            >> 3U))));
            tracep->chgIData(oldp+149,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_addr_array[3U]),32);
            tracep->chgCData(oldp+150,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array) 
                                              >> 9U))),3);
            tracep->chgBit(oldp+151,(vlTOPp->tidc_system_tb__DOT__l2_cmd_valid));
            tracep->chgCData(oldp+152,(vlTOPp->tidc_system_tb__DOT__l2_cmd_type),3);
            tracep->chgIData(oldp+153,(vlTOPp->tidc_system_tb__DOT__l2_cmd_addr),32);
            tracep->chgWData(oldp+154,(vlTOPp->tidc_system_tb__DOT__l2_cmd_data),256);
            tracep->chgCData(oldp+162,(vlTOPp->tidc_system_tb__DOT__l2_cmd_size),4);
            tracep->chgBit(oldp+163,(vlTOPp->tidc_system_tb__DOT__l2_cmd_dirty));
            tracep->chgCData(oldp+164,(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid),4);
            tracep->chgSData(oldp+165,(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_opcode),12);
            tracep->chgSData(oldp+166,(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_param),12);
            tracep->chgSData(oldp+167,(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_size),16);
            tracep->chgSData(oldp+168,(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_source),16);
            tracep->chgWData(oldp+169,(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_address),128);
            tracep->chgWData(oldp+173,(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_data),256);
            tracep->chgIData(oldp+181,(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_mask),32);
            tracep->chgCData(oldp+182,(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready),4);
            tracep->chgCData(oldp+183,(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid),4);
            tracep->chgSData(oldp+184,(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode),12);
            tracep->chgSData(oldp+185,(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param),12);
            tracep->chgSData(oldp+186,(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_size),16);
            tracep->chgSData(oldp+187,(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_source),16);
            tracep->chgWData(oldp+188,(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address),128);
            tracep->chgWData(oldp+192,(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data),256);
            tracep->chgIData(oldp+200,(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_mask),32);
            tracep->chgCData(oldp+201,(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_ready),4);
            tracep->chgCData(oldp+202,(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid),4);
            tracep->chgSData(oldp+203,(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode),12);
            tracep->chgSData(oldp+204,(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_param),12);
            tracep->chgSData(oldp+205,(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_size),16);
            tracep->chgSData(oldp+206,(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_source),16);
            tracep->chgWData(oldp+207,(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_address),128);
            tracep->chgWData(oldp+211,(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data),256);
            tracep->chgCData(oldp+219,(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_error),4);
            tracep->chgCData(oldp+220,(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready),4);
            tracep->chgCData(oldp+221,(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid),4);
            tracep->chgSData(oldp+222,(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode),12);
            tracep->chgSData(oldp+223,(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_param),12);
            tracep->chgSData(oldp+224,(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_size),16);
            tracep->chgSData(oldp+225,(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source),16);
            tracep->chgSData(oldp+226,(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_sink),16);
            tracep->chgWData(oldp+227,(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data),256);
            tracep->chgCData(oldp+235,(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_error),4);
            tracep->chgCData(oldp+236,(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_ready),4);
            tracep->chgCData(oldp+237,(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid),4);
            tracep->chgSData(oldp+238,(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink),16);
            tracep->chgCData(oldp+239,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_ready_array),4);
            tracep->chgCData(oldp+240,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array),4);
            tracep->chgWData(oldp+241,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array),1024);
            tracep->chgCData(oldp+273,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array),4);
            tracep->chgCData(oldp+274,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array),4);
            tracep->chgWData(oldp+275,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_addr_array),128);
            tracep->chgSData(oldp+279,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array),12);
            tracep->chgBit(oldp+280,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_valid));
            tracep->chgCData(oldp+281,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel),2);
            tracep->chgCData(oldp+282,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_oh),4);
            tracep->chgCData(oldp+283,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id),2);
            tracep->chgBit(oldp+284,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_busy));
            tracep->chgBit(oldp+285,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_req));
            tracep->chgIData(oldp+286,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_addr),32);
            tracep->chgBit(oldp+287,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_valid));
            tracep->chgCData(oldp+288,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_state),3);
            tracep->chgCData(oldp+289,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_presence),4);
            tracep->chgCData(oldp+290,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_tip_state),4);
            tracep->chgBit(oldp+291,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_req));
            tracep->chgIData(oldp+292,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_addr),32);
            tracep->chgCData(oldp+293,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_state),3);
            tracep->chgCData(oldp+294,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_presence),4);
            tracep->chgCData(oldp+295,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_tip_state),4);
            tracep->chgBit(oldp+296,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_done));
            tracep->chgBit(oldp+297,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__alloc_gnt_r));
            tracep->chgCData(oldp+298,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id),4);
            tracep->chgBit(oldp+299,((((9U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state)) 
                                       & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid) 
                                          >> (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))) 
                                      & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink) 
                                                  >> 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                                      << 2U)))) 
                                         == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_sink)))));
            tracep->chgCData(oldp+300,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_dealloc_sink_id),4);
            tracep->chgCData(oldp+301,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state),4);
            tracep->chgIData(oldp+302,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr),32);
            tracep->chgCData(oldp+303,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id),2);
            tracep->chgCData(oldp+304,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode),3);
            tracep->chgCData(oldp+305,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param),3);
            tracep->chgCData(oldp+306,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_source),4);
            tracep->chgCData(oldp+307,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_sink),4);
            tracep->chgWData(oldp+308,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data),256);
            tracep->chgCData(oldp+316,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent),4);
            tracep->chgCData(oldp+317,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked),4);
            tracep->chgIData(oldp+318,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__i),32);
            tracep->chgIData(oldp+319,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__j),32);
            tracep->chgCData(oldp+320,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__state),2);
            tracep->chgCData(oldp+321,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state),2);
            tracep->chgCData(oldp+322,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_rr_ptr),2);
            tracep->chgCData(oldp+323,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_rr_ptr),2);
            tracep->chgBit(oldp+324,((0U != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid))));
            tracep->chgBit(oldp+325,((0U != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid))));
            tracep->chgCData(oldp+326,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_req_masked),4);
            tracep->chgCData(oldp+327,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_req_masked),4);
            tracep->chgCData(oldp+328,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_selected_oh),4);
            tracep->chgCData(oldp+329,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_selected_oh),4);
            tracep->chgCData(oldp+330,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_selected_id),2);
            tracep->chgCData(oldp+331,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_selected_id),2);
            tracep->chgCData(oldp+332,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__state),2);
            tracep->chgCData(oldp+333,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__next_state),2);
            tracep->chgIData(oldp+334,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__req_addr),32);
            tracep->chgIData(oldp+335,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__i),32);
            tracep->chgSData(oldp+336,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use),16);
            tracep->chgBit(oldp+337,((0xffffU != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use))));
            tracep->chgBit(oldp+338,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__l1_request_ready));
            tracep->chgBit(oldp+339,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_valid));
            tracep->chgWData(oldp+340,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data),256);
            tracep->chgBit(oldp+348,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_error));
            tracep->chgBit(oldp+349,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_valid));
            tracep->chgIData(oldp+350,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_addr),32);
            tracep->chgCData(oldp+351,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_permissions),3);
            tracep->chgBit(oldp+352,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_valid));
            tracep->chgCData(oldp+353,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_opcode),3);
            tracep->chgCData(oldp+354,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_param),3);
            tracep->chgCData(oldp+355,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_size),4);
            tracep->chgCData(oldp+356,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_source),4);
            tracep->chgIData(oldp+357,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_address),32);
            tracep->chgQData(oldp+358,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_data),64);
            tracep->chgCData(oldp+360,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_mask),8);
            tracep->chgBit(oldp+361,((1U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready))));
            tracep->chgBit(oldp+362,((1U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid))));
            tracep->chgCData(oldp+363,((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode))),3);
            tracep->chgCData(oldp+364,((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param))),3);
            tracep->chgCData(oldp+365,((0xfU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_size))),4);
            tracep->chgCData(oldp+366,((0xfU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_source))),4);
            tracep->chgIData(oldp+367,(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address[0U]),32);
            tracep->chgQData(oldp+368,((((QData)((IData)(
                                                         vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[0U])))),64);
            tracep->chgCData(oldp+370,((0xffU & vlTOPp->tidc_system_tb__DOT__dut__DOT__b_mask)),8);
            tracep->chgBit(oldp+371,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__b_ready));
            tracep->chgBit(oldp+372,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_valid));
            tracep->chgCData(oldp+373,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_opcode),3);
            tracep->chgCData(oldp+374,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_param),3);
            tracep->chgCData(oldp+375,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_size),4);
            tracep->chgCData(oldp+376,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_source),4);
            tracep->chgIData(oldp+377,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_address),32);
            tracep->chgQData(oldp+378,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_data),64);
            tracep->chgBit(oldp+380,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_error));
            tracep->chgBit(oldp+381,((1U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready))));
            tracep->chgBit(oldp+382,((1U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid))));
            tracep->chgCData(oldp+383,((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode))),3);
            tracep->chgCData(oldp+384,((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_param))),3);
            tracep->chgCData(oldp+385,((0xfU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_size))),4);
            tracep->chgCData(oldp+386,((0xfU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source))),4);
            tracep->chgCData(oldp+387,((0xfU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_sink))),4);
            tracep->chgQData(oldp+388,((((QData)((IData)(
                                                         vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[0U])))),64);
            tracep->chgBit(oldp+390,((1U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_error))));
            tracep->chgBit(oldp+391,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__d_ready));
            tracep->chgBit(oldp+392,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__e_valid));
            tracep->chgCData(oldp+393,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__e_sink),4);
            tracep->chgCData(oldp+394,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state),4);
            tracep->chgIData(oldp+395,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_addr),32);
            tracep->chgCData(oldp+396,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_req_type),3);
            tracep->chgCData(oldp+397,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_permissions),3);
            tracep->chgWData(oldp+398,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data),256);
            tracep->chgBit(oldp+406,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_has_data));
            tracep->chgIData(oldp+407,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_addr),32);
            tracep->chgCData(oldp+408,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_param),3);
            tracep->chgCData(oldp+409,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_source),4);
            tracep->chgCData(oldp+410,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__grant_sink),4);
            tracep->chgBit(oldp+411,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r));
            tracep->chgCData(oldp+412,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id),4);
            tracep->chgBit(oldp+413,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__dealloc_source_id_req));
            tracep->chgCData(oldp+414,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__dealloc_source_id),4);
            tracep->chgCData(oldp+415,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id),4);
            tracep->chgBit(oldp+416,((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))));
            tracep->chgBit(oldp+417,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__allocated_source_id_valid));
            tracep->chgCData(oldp+418,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__allocated_source_id),4);
            tracep->chgSData(oldp+419,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use),16);
            tracep->chgBit(oldp+420,((0xffffU != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use))));
            tracep->chgBit(oldp+421,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__l1_request_ready));
            tracep->chgBit(oldp+422,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_valid));
            tracep->chgWData(oldp+423,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data),256);
            tracep->chgBit(oldp+431,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_error));
            tracep->chgBit(oldp+432,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_valid));
            tracep->chgIData(oldp+433,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_addr),32);
            tracep->chgCData(oldp+434,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_permissions),3);
            tracep->chgBit(oldp+435,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_valid));
            tracep->chgCData(oldp+436,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_opcode),3);
            tracep->chgCData(oldp+437,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_param),3);
            tracep->chgCData(oldp+438,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_size),4);
            tracep->chgCData(oldp+439,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_source),4);
            tracep->chgIData(oldp+440,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_address),32);
            tracep->chgQData(oldp+441,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_data),64);
            tracep->chgCData(oldp+443,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_mask),8);
            tracep->chgBit(oldp+444,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready) 
                                            >> 1U))));
            tracep->chgBit(oldp+445,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid) 
                                            >> 1U))));
            tracep->chgCData(oldp+446,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode) 
                                              >> 3U))),3);
            tracep->chgCData(oldp+447,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param) 
                                              >> 3U))),3);
            tracep->chgCData(oldp+448,((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_size) 
                                                >> 4U))),4);
            tracep->chgCData(oldp+449,((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_source) 
                                                >> 4U))),4);
            tracep->chgIData(oldp+450,(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address[1U]),32);
            tracep->chgQData(oldp+451,((((QData)((IData)(
                                                         vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[3U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[2U])))),64);
            tracep->chgCData(oldp+453,((0xffU & (vlTOPp->tidc_system_tb__DOT__dut__DOT__b_mask 
                                                 >> 8U))),8);
            tracep->chgBit(oldp+454,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__b_ready));
            tracep->chgBit(oldp+455,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_valid));
            tracep->chgCData(oldp+456,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_opcode),3);
            tracep->chgCData(oldp+457,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_param),3);
            tracep->chgCData(oldp+458,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_size),4);
            tracep->chgCData(oldp+459,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_source),4);
            tracep->chgIData(oldp+460,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_address),32);
            tracep->chgQData(oldp+461,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_data),64);
            tracep->chgBit(oldp+463,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_error));
            tracep->chgBit(oldp+464,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready) 
                                            >> 1U))));
            tracep->chgBit(oldp+465,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                                            >> 1U))));
            tracep->chgCData(oldp+466,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                              >> 3U))),3);
            tracep->chgCData(oldp+467,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_param) 
                                              >> 3U))),3);
            tracep->chgCData(oldp+468,((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_size) 
                                                >> 4U))),4);
            tracep->chgCData(oldp+469,((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                                >> 4U))),4);
            tracep->chgCData(oldp+470,((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_sink) 
                                                >> 4U))),4);
            tracep->chgQData(oldp+471,((((QData)((IData)(
                                                         vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[3U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[2U])))),64);
            tracep->chgBit(oldp+473,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_error) 
                                            >> 1U))));
            tracep->chgBit(oldp+474,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__d_ready));
            tracep->chgBit(oldp+475,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__e_valid));
            tracep->chgCData(oldp+476,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__e_sink),4);
            tracep->chgCData(oldp+477,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state),4);
            tracep->chgIData(oldp+478,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_addr),32);
            tracep->chgCData(oldp+479,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_req_type),3);
            tracep->chgCData(oldp+480,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_permissions),3);
            tracep->chgWData(oldp+481,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data),256);
            tracep->chgBit(oldp+489,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_has_data));
            tracep->chgIData(oldp+490,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_addr),32);
            tracep->chgCData(oldp+491,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_param),3);
            tracep->chgCData(oldp+492,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_source),4);
            tracep->chgCData(oldp+493,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__grant_sink),4);
            tracep->chgBit(oldp+494,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r));
            tracep->chgCData(oldp+495,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id),4);
            tracep->chgBit(oldp+496,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__dealloc_source_id_req));
            tracep->chgCData(oldp+497,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__dealloc_source_id),4);
            tracep->chgCData(oldp+498,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id),4);
            tracep->chgBit(oldp+499,((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))));
            tracep->chgBit(oldp+500,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__allocated_source_id_valid));
            tracep->chgCData(oldp+501,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__allocated_source_id),4);
            tracep->chgSData(oldp+502,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use),16);
            tracep->chgBit(oldp+503,((0xffffU != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use))));
            tracep->chgBit(oldp+504,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__l1_request_ready));
            tracep->chgBit(oldp+505,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_valid));
            tracep->chgWData(oldp+506,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data),256);
            tracep->chgBit(oldp+514,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_error));
            tracep->chgBit(oldp+515,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_valid));
            tracep->chgIData(oldp+516,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_addr),32);
            tracep->chgCData(oldp+517,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_permissions),3);
            tracep->chgBit(oldp+518,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_valid));
            tracep->chgCData(oldp+519,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_opcode),3);
            tracep->chgCData(oldp+520,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_param),3);
            tracep->chgCData(oldp+521,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_size),4);
            tracep->chgCData(oldp+522,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_source),4);
            tracep->chgIData(oldp+523,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_address),32);
            tracep->chgQData(oldp+524,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_data),64);
            tracep->chgCData(oldp+526,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_mask),8);
            tracep->chgBit(oldp+527,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready) 
                                            >> 2U))));
            tracep->chgBit(oldp+528,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid) 
                                            >> 2U))));
            tracep->chgCData(oldp+529,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode) 
                                              >> 6U))),3);
            tracep->chgCData(oldp+530,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param) 
                                              >> 6U))),3);
            tracep->chgCData(oldp+531,((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_size) 
                                                >> 8U))),4);
            tracep->chgCData(oldp+532,((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_source) 
                                                >> 8U))),4);
            tracep->chgIData(oldp+533,(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address[2U]),32);
            tracep->chgQData(oldp+534,((((QData)((IData)(
                                                         vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[5U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[4U])))),64);
            tracep->chgCData(oldp+536,((0xffU & (vlTOPp->tidc_system_tb__DOT__dut__DOT__b_mask 
                                                 >> 0x10U))),8);
            tracep->chgBit(oldp+537,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__b_ready));
            tracep->chgBit(oldp+538,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_valid));
            tracep->chgCData(oldp+539,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_opcode),3);
            tracep->chgCData(oldp+540,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_param),3);
            tracep->chgCData(oldp+541,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_size),4);
            tracep->chgCData(oldp+542,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_source),4);
            tracep->chgIData(oldp+543,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_address),32);
            tracep->chgQData(oldp+544,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_data),64);
            tracep->chgBit(oldp+546,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_error));
            tracep->chgBit(oldp+547,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready) 
                                            >> 2U))));
            tracep->chgBit(oldp+548,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                                            >> 2U))));
            tracep->chgCData(oldp+549,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                              >> 6U))),3);
            tracep->chgCData(oldp+550,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_param) 
                                              >> 6U))),3);
            tracep->chgCData(oldp+551,((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_size) 
                                                >> 8U))),4);
            tracep->chgCData(oldp+552,((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                                >> 8U))),4);
            tracep->chgCData(oldp+553,((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_sink) 
                                                >> 8U))),4);
            tracep->chgQData(oldp+554,((((QData)((IData)(
                                                         vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[5U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[4U])))),64);
            tracep->chgBit(oldp+556,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_error) 
                                            >> 2U))));
            tracep->chgBit(oldp+557,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__d_ready));
            tracep->chgBit(oldp+558,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__e_valid));
            tracep->chgCData(oldp+559,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__e_sink),4);
            tracep->chgCData(oldp+560,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state),4);
            tracep->chgIData(oldp+561,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_addr),32);
            tracep->chgCData(oldp+562,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_req_type),3);
            tracep->chgCData(oldp+563,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_permissions),3);
            tracep->chgWData(oldp+564,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data),256);
            tracep->chgBit(oldp+572,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_has_data));
            tracep->chgIData(oldp+573,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_addr),32);
            tracep->chgCData(oldp+574,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_param),3);
            tracep->chgCData(oldp+575,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_source),4);
            tracep->chgCData(oldp+576,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__grant_sink),4);
            tracep->chgBit(oldp+577,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r));
            tracep->chgCData(oldp+578,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id),4);
            tracep->chgBit(oldp+579,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__dealloc_source_id_req));
            tracep->chgCData(oldp+580,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__dealloc_source_id),4);
            tracep->chgCData(oldp+581,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id),4);
            tracep->chgBit(oldp+582,((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))));
            tracep->chgBit(oldp+583,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__allocated_source_id_valid));
            tracep->chgCData(oldp+584,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__allocated_source_id),4);
            tracep->chgSData(oldp+585,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use),16);
            tracep->chgBit(oldp+586,((0xffffU != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use))));
            tracep->chgBit(oldp+587,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__l1_request_ready));
            tracep->chgBit(oldp+588,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_valid));
            tracep->chgWData(oldp+589,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data),256);
            tracep->chgBit(oldp+597,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_error));
            tracep->chgBit(oldp+598,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_valid));
            tracep->chgIData(oldp+599,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_addr),32);
            tracep->chgCData(oldp+600,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_permissions),3);
            tracep->chgBit(oldp+601,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_valid));
            tracep->chgCData(oldp+602,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_opcode),3);
            tracep->chgCData(oldp+603,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_param),3);
            tracep->chgCData(oldp+604,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_size),4);
            tracep->chgCData(oldp+605,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_source),4);
            tracep->chgIData(oldp+606,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_address),32);
            tracep->chgQData(oldp+607,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_data),64);
            tracep->chgCData(oldp+609,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_mask),8);
            tracep->chgBit(oldp+610,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_ready) 
                                            >> 3U))));
            tracep->chgBit(oldp+611,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid) 
                                            >> 3U))));
            tracep->chgCData(oldp+612,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode) 
                                              >> 9U))),3);
            tracep->chgCData(oldp+613,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param) 
                                              >> 9U))),3);
            tracep->chgCData(oldp+614,((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_size) 
                                                >> 0xcU))),4);
            tracep->chgCData(oldp+615,((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_source) 
                                                >> 0xcU))),4);
            tracep->chgIData(oldp+616,(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address[3U]),32);
            tracep->chgQData(oldp+617,((((QData)((IData)(
                                                         vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[7U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[6U])))),64);
            tracep->chgCData(oldp+619,((0xffU & (vlTOPp->tidc_system_tb__DOT__dut__DOT__b_mask 
                                                 >> 0x18U))),8);
            tracep->chgBit(oldp+620,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__b_ready));
            tracep->chgBit(oldp+621,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_valid));
            tracep->chgCData(oldp+622,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_opcode),3);
            tracep->chgCData(oldp+623,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_param),3);
            tracep->chgCData(oldp+624,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_size),4);
            tracep->chgCData(oldp+625,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_source),4);
            tracep->chgIData(oldp+626,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_address),32);
            tracep->chgQData(oldp+627,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_data),64);
            tracep->chgBit(oldp+629,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_error));
            tracep->chgBit(oldp+630,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_ready) 
                                            >> 3U))));
            tracep->chgBit(oldp+631,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                                            >> 3U))));
            tracep->chgCData(oldp+632,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                              >> 9U))),3);
            tracep->chgCData(oldp+633,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_param) 
                                              >> 9U))),3);
            tracep->chgCData(oldp+634,((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_size) 
                                                >> 0xcU))),4);
            tracep->chgCData(oldp+635,((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                                >> 0xcU))),4);
            tracep->chgCData(oldp+636,((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_sink) 
                                                >> 0xcU))),4);
            tracep->chgQData(oldp+637,((((QData)((IData)(
                                                         vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[7U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[6U])))),64);
            tracep->chgBit(oldp+639,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_error) 
                                            >> 3U))));
            tracep->chgBit(oldp+640,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__d_ready));
            tracep->chgBit(oldp+641,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__e_valid));
            tracep->chgCData(oldp+642,(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__e_sink),4);
            tracep->chgCData(oldp+643,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state),4);
            tracep->chgIData(oldp+644,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_addr),32);
            tracep->chgCData(oldp+645,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_req_type),3);
            tracep->chgCData(oldp+646,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_permissions),3);
            tracep->chgWData(oldp+647,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data),256);
            tracep->chgBit(oldp+655,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_has_data));
            tracep->chgIData(oldp+656,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_addr),32);
            tracep->chgCData(oldp+657,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_param),3);
            tracep->chgCData(oldp+658,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_source),4);
            tracep->chgCData(oldp+659,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__grant_sink),4);
            tracep->chgBit(oldp+660,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r));
            tracep->chgCData(oldp+661,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id),4);
            tracep->chgBit(oldp+662,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__dealloc_source_id_req));
            tracep->chgCData(oldp+663,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__dealloc_source_id),4);
            tracep->chgCData(oldp+664,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id),4);
            tracep->chgBit(oldp+665,((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))));
            tracep->chgBit(oldp+666,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__allocated_source_id_valid));
            tracep->chgCData(oldp+667,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__allocated_source_id),4);
            tracep->chgSData(oldp+668,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use),16);
            tracep->chgBit(oldp+669,((0xffffU != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use))));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgBit(oldp+670,(vlTOPp->tidc_system_tb__DOT__rst_n));
            tracep->chgBit(oldp+671,(vlTOPp->tidc_system_tb__DOT__l2_response_valid));
            tracep->chgWData(oldp+672,(vlTOPp->tidc_system_tb__DOT__l2_response_data),256);
            tracep->chgBit(oldp+680,(vlTOPp->tidc_system_tb__DOT__l2_response_error));
            tracep->chgCData(oldp+681,(vlTOPp->tidc_system_tb__DOT__reset_counter),8);
            tracep->chgCData(oldp+682,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array),4);
            tracep->chgWData(oldp+683,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_addr_array),128);
            tracep->chgSData(oldp+687,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array),12);
            tracep->chgWData(oldp+688,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array),1024);
            tracep->chgSData(oldp+720,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_permissions_array),12);
            tracep->chgCData(oldp+721,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_valid_array),4);
            tracep->chgWData(oldp+722,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_addr_array),128);
            tracep->chgSData(oldp+726,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_permissions_array),12);
            tracep->chgWData(oldp+727,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array),1024);
            tracep->chgBit(oldp+759,((1U & (~ (IData)(vlTOPp->tidc_system_tb__DOT__rst_n)))));
            tracep->chgBit(oldp+760,((1U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array))));
            tracep->chgIData(oldp+761,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_addr_array[0U]),32);
            tracep->chgCData(oldp+762,((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array))),3);
            __Vtemp74[0U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0U];
            __Vtemp74[1U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[1U];
            __Vtemp74[2U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[2U];
            __Vtemp74[3U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[3U];
            __Vtemp74[4U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[4U];
            __Vtemp74[5U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[5U];
            __Vtemp74[6U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[6U];
            __Vtemp74[7U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[7U];
            tracep->chgWData(oldp+763,(__Vtemp74),256);
            tracep->chgCData(oldp+771,((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_permissions_array))),3);
            tracep->chgBit(oldp+772,((1U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_valid_array))));
            tracep->chgIData(oldp+773,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_addr_array[0U]),32);
            tracep->chgCData(oldp+774,((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_permissions_array))),3);
            __Vtemp75[0U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0U];
            __Vtemp75[1U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[1U];
            __Vtemp75[2U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[2U];
            __Vtemp75[3U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[3U];
            __Vtemp75[4U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[4U];
            __Vtemp75[5U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[5U];
            __Vtemp75[6U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[6U];
            __Vtemp75[7U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[7U];
            tracep->chgWData(oldp+775,(__Vtemp75),256);
            tracep->chgBit(oldp+783,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array) 
                                            >> 1U))));
            tracep->chgIData(oldp+784,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_addr_array[1U]),32);
            tracep->chgCData(oldp+785,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                              >> 3U))),3);
            __Vtemp76[0U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[8U];
            __Vtemp76[1U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[9U];
            __Vtemp76[2U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0xaU];
            __Vtemp76[3U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0xbU];
            __Vtemp76[4U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0xcU];
            __Vtemp76[5U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0xdU];
            __Vtemp76[6U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0xeU];
            __Vtemp76[7U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0xfU];
            tracep->chgWData(oldp+786,(__Vtemp76),256);
            tracep->chgCData(oldp+794,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_permissions_array) 
                                              >> 3U))),3);
            tracep->chgBit(oldp+795,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_valid_array) 
                                            >> 1U))));
            tracep->chgIData(oldp+796,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_addr_array[1U]),32);
            tracep->chgCData(oldp+797,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_permissions_array) 
                                              >> 3U))),3);
            __Vtemp77[0U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[8U];
            __Vtemp77[1U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[9U];
            __Vtemp77[2U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0xaU];
            __Vtemp77[3U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0xbU];
            __Vtemp77[4U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0xcU];
            __Vtemp77[5U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0xdU];
            __Vtemp77[6U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0xeU];
            __Vtemp77[7U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0xfU];
            tracep->chgWData(oldp+798,(__Vtemp77),256);
            tracep->chgBit(oldp+806,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array) 
                                            >> 2U))));
            tracep->chgIData(oldp+807,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_addr_array[2U]),32);
            tracep->chgCData(oldp+808,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                              >> 6U))),3);
            __Vtemp78[0U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x10U];
            __Vtemp78[1U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x11U];
            __Vtemp78[2U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x12U];
            __Vtemp78[3U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x13U];
            __Vtemp78[4U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x14U];
            __Vtemp78[5U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x15U];
            __Vtemp78[6U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x16U];
            __Vtemp78[7U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x17U];
            tracep->chgWData(oldp+809,(__Vtemp78),256);
            tracep->chgCData(oldp+817,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_permissions_array) 
                                              >> 6U))),3);
            tracep->chgBit(oldp+818,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_valid_array) 
                                            >> 2U))));
            tracep->chgIData(oldp+819,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_addr_array[2U]),32);
            tracep->chgCData(oldp+820,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_permissions_array) 
                                              >> 6U))),3);
            __Vtemp79[0U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x10U];
            __Vtemp79[1U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x11U];
            __Vtemp79[2U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x12U];
            __Vtemp79[3U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x13U];
            __Vtemp79[4U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x14U];
            __Vtemp79[5U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x15U];
            __Vtemp79[6U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x16U];
            __Vtemp79[7U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x17U];
            tracep->chgWData(oldp+821,(__Vtemp79),256);
            tracep->chgBit(oldp+829,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array) 
                                            >> 3U))));
            tracep->chgIData(oldp+830,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_addr_array[3U]),32);
            tracep->chgCData(oldp+831,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                              >> 9U))),3);
            __Vtemp80[0U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x18U];
            __Vtemp80[1U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x19U];
            __Vtemp80[2U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x1aU];
            __Vtemp80[3U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x1bU];
            __Vtemp80[4U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x1cU];
            __Vtemp80[5U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x1dU];
            __Vtemp80[6U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x1eU];
            __Vtemp80[7U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x1fU];
            tracep->chgWData(oldp+832,(__Vtemp80),256);
            tracep->chgCData(oldp+840,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_permissions_array) 
                                              >> 9U))),3);
            tracep->chgBit(oldp+841,((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_valid_array) 
                                            >> 3U))));
            tracep->chgIData(oldp+842,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_addr_array[3U]),32);
            tracep->chgCData(oldp+843,((7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_permissions_array) 
                                              >> 9U))),3);
            __Vtemp81[0U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x18U];
            __Vtemp81[1U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x19U];
            __Vtemp81[2U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x1aU];
            __Vtemp81[3U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x1bU];
            __Vtemp81[4U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x1cU];
            __Vtemp81[5U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x1dU];
            __Vtemp81[6U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x1eU];
            __Vtemp81[7U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x1fU];
            tracep->chgWData(oldp+844,(__Vtemp81),256);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[4U])) {
            tracep->chgBit(oldp+852,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_alloc_req));
            tracep->chgCData(oldp+853,(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__next_state),4);
            tracep->chgCData(oldp+854,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__next_state),4);
            tracep->chgBit(oldp+855,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__alloc_source_id_req));
            tracep->chgCData(oldp+856,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__next_state),4);
            tracep->chgBit(oldp+857,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__alloc_source_id_req));
            tracep->chgCData(oldp+858,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__next_state),4);
            tracep->chgBit(oldp+859,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__alloc_source_id_req));
            tracep->chgCData(oldp+860,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__next_state),4);
            tracep->chgBit(oldp+861,(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__alloc_source_id_req));
        }
        tracep->chgBit(oldp+862,(vlTOPp->clk));
    }
}

void Vtidc_system_tb::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vtidc_system_tb__Syms* __restrict vlSymsp = static_cast<Vtidc_system_tb__Syms*>(userp);
    Vtidc_system_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
        vlTOPp->__Vm_traceActivity[3U] = 0U;
        vlTOPp->__Vm_traceActivity[4U] = 0U;
    }
}

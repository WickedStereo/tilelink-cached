// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTIDC_SYSTEM_TB_H_
#define _VTIDC_SYSTEM_TB_H_  // guard

#include "verilated_heavy.h"

//==========

class Vtidc_system_tb__Syms;
class Vtidc_system_tb_VerilatedVcd;


//----------

VL_MODULE(Vtidc_system_tb) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tidc_system_tb__DOT__rst_n;
        CData/*0:0*/ tidc_system_tb__DOT__l1_0_request_valid;
        CData/*2:0*/ tidc_system_tb__DOT__l1_0_request_type;
        CData/*2:0*/ tidc_system_tb__DOT__l1_0_request_permissions;
        CData/*0:0*/ tidc_system_tb__DOT__l1_0_probe_ack_valid;
        CData/*2:0*/ tidc_system_tb__DOT__l1_0_probe_ack_permissions;
        CData/*0:0*/ tidc_system_tb__DOT__l1_1_request_valid;
        CData/*2:0*/ tidc_system_tb__DOT__l1_1_request_type;
        CData/*2:0*/ tidc_system_tb__DOT__l1_1_request_permissions;
        CData/*0:0*/ tidc_system_tb__DOT__l1_1_probe_ack_valid;
        CData/*2:0*/ tidc_system_tb__DOT__l1_1_probe_ack_permissions;
        CData/*0:0*/ tidc_system_tb__DOT__l1_2_request_valid;
        CData/*2:0*/ tidc_system_tb__DOT__l1_2_request_type;
        CData/*2:0*/ tidc_system_tb__DOT__l1_2_request_permissions;
        CData/*0:0*/ tidc_system_tb__DOT__l1_2_probe_ack_valid;
        CData/*2:0*/ tidc_system_tb__DOT__l1_2_probe_ack_permissions;
        CData/*0:0*/ tidc_system_tb__DOT__l1_3_request_valid;
        CData/*2:0*/ tidc_system_tb__DOT__l1_3_request_type;
        CData/*2:0*/ tidc_system_tb__DOT__l1_3_request_permissions;
        CData/*0:0*/ tidc_system_tb__DOT__l1_3_probe_ack_valid;
        CData/*2:0*/ tidc_system_tb__DOT__l1_3_probe_ack_permissions;
        CData/*0:0*/ tidc_system_tb__DOT__l2_cmd_valid;
        CData/*2:0*/ tidc_system_tb__DOT__l2_cmd_type;
        CData/*3:0*/ tidc_system_tb__DOT__l2_cmd_size;
        CData/*0:0*/ tidc_system_tb__DOT__l2_cmd_dirty;
        CData/*0:0*/ tidc_system_tb__DOT__l2_response_valid;
        CData/*0:0*/ tidc_system_tb__DOT__l2_response_error;
        CData/*3:0*/ tidc_system_tb__DOT__test_state;
        CData/*7:0*/ tidc_system_tb__DOT__reset_counter;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__a_valid;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__a_ready;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__b_valid;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__b_ready;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__c_valid;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__c_error;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__c_ready;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__d_valid;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__d_error;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__d_ready;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__e_valid;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l1_request_valid_array;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l1_request_ready_array;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l1_data_valid_array;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l1_data_error_array;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l1_probe_ack_valid_array;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_valid;
        CData/*1:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_oh;
        CData/*1:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_busy;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_req;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_valid;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_state;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_presence;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_tip_state;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_req;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_state;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_presence;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_tip_state;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_done;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_alloc_req;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_dealloc_sink_id;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state;
    };
    struct {
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__next_state;
        CData/*1:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_source;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_sink;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked;
        CData/*1:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__state;
        CData/*1:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state;
        CData/*1:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_rr_ptr;
        CData/*1:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_rr_ptr;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_req_masked;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_req_masked;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_selected_oh;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_selected_oh;
        CData/*1:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_selected_id;
        CData/*1:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_selected_id;
        CData/*1:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__state;
        CData/*1:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__next_state;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__any_id_available;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__alloc_gnt_r;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__next_state;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_req_type;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_permissions;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_has_data;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_param;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_source;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__grant_sink;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__alloc_source_id_req;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__dealloc_source_id_req;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__dealloc_source_id;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__allocated_source_id_valid;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__allocated_source_id;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__any_id_available;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__next_state;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_req_type;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_permissions;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_has_data;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_param;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_source;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__grant_sink;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__alloc_source_id_req;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__dealloc_source_id_req;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__dealloc_source_id;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__allocated_source_id_valid;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__allocated_source_id;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__any_id_available;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__next_state;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_req_type;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_permissions;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_has_data;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_param;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_source;
    };
    struct {
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__grant_sink;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__alloc_source_id_req;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__dealloc_source_id_req;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__dealloc_source_id;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__allocated_source_id_valid;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__allocated_source_id;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__any_id_available;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__next_state;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_req_type;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_permissions;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_has_data;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_param;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_source;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__grant_sink;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__alloc_source_id_req;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__dealloc_source_id_req;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__dealloc_source_id;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__allocated_source_id_valid;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__allocated_source_id;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__any_id_available;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r;
        SData/*15:0*/ tidc_system_tb__DOT__wait_counter;
        SData/*11:0*/ tidc_system_tb__DOT__dut__DOT__a_opcode;
        SData/*11:0*/ tidc_system_tb__DOT__dut__DOT__a_param;
        SData/*15:0*/ tidc_system_tb__DOT__dut__DOT__a_size;
        SData/*15:0*/ tidc_system_tb__DOT__dut__DOT__a_source;
        SData/*11:0*/ tidc_system_tb__DOT__dut__DOT__b_opcode;
        SData/*11:0*/ tidc_system_tb__DOT__dut__DOT__b_param;
        SData/*15:0*/ tidc_system_tb__DOT__dut__DOT__b_size;
        SData/*15:0*/ tidc_system_tb__DOT__dut__DOT__b_source;
        SData/*11:0*/ tidc_system_tb__DOT__dut__DOT__c_opcode;
        SData/*11:0*/ tidc_system_tb__DOT__dut__DOT__c_param;
        SData/*15:0*/ tidc_system_tb__DOT__dut__DOT__c_size;
        SData/*15:0*/ tidc_system_tb__DOT__dut__DOT__c_source;
        SData/*11:0*/ tidc_system_tb__DOT__dut__DOT__d_opcode;
        SData/*11:0*/ tidc_system_tb__DOT__dut__DOT__d_param;
        SData/*15:0*/ tidc_system_tb__DOT__dut__DOT__d_size;
        SData/*15:0*/ tidc_system_tb__DOT__dut__DOT__d_source;
        SData/*15:0*/ tidc_system_tb__DOT__dut__DOT__d_sink;
        SData/*15:0*/ tidc_system_tb__DOT__dut__DOT__e_sink;
        SData/*11:0*/ tidc_system_tb__DOT__dut__DOT__l1_request_type_array;
        SData/*11:0*/ tidc_system_tb__DOT__dut__DOT__l1_request_permissions_array;
        SData/*11:0*/ tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array;
        SData/*11:0*/ tidc_system_tb__DOT__dut__DOT__l1_probe_ack_permissions_array;
        SData/*15:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use;
        SData/*15:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use;
        SData/*15:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use;
        SData/*15:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use;
        SData/*15:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use;
        IData/*31:0*/ tidc_system_tb__DOT__l1_0_request_addr;
        WData/*255:0*/ tidc_system_tb__DOT__l1_0_request_data[8];
        IData/*31:0*/ tidc_system_tb__DOT__l1_0_probe_ack_addr;
        WData/*255:0*/ tidc_system_tb__DOT__l1_0_probe_ack_dirty_data[8];
        IData/*31:0*/ tidc_system_tb__DOT__l1_1_request_addr;
        WData/*255:0*/ tidc_system_tb__DOT__l1_1_request_data[8];
        IData/*31:0*/ tidc_system_tb__DOT__l1_1_probe_ack_addr;
        WData/*255:0*/ tidc_system_tb__DOT__l1_1_probe_ack_dirty_data[8];
        IData/*31:0*/ tidc_system_tb__DOT__l1_2_request_addr;
    };
    struct {
        WData/*255:0*/ tidc_system_tb__DOT__l1_2_request_data[8];
        IData/*31:0*/ tidc_system_tb__DOT__l1_2_probe_ack_addr;
        WData/*255:0*/ tidc_system_tb__DOT__l1_2_probe_ack_dirty_data[8];
        IData/*31:0*/ tidc_system_tb__DOT__l1_3_request_addr;
        WData/*255:0*/ tidc_system_tb__DOT__l1_3_request_data[8];
        IData/*31:0*/ tidc_system_tb__DOT__l1_3_probe_ack_addr;
        WData/*255:0*/ tidc_system_tb__DOT__l1_3_probe_ack_dirty_data[8];
        IData/*31:0*/ tidc_system_tb__DOT__l2_cmd_addr;
        WData/*255:0*/ tidc_system_tb__DOT__l2_cmd_data[8];
        WData/*255:0*/ tidc_system_tb__DOT__l2_response_data[8];
        IData/*31:0*/ tidc_system_tb__DOT__timeout_counter;
        WData/*127:0*/ tidc_system_tb__DOT__dut__DOT__a_address[4];
        WData/*255:0*/ tidc_system_tb__DOT__dut__DOT__a_data[8];
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT__a_mask;
        WData/*127:0*/ tidc_system_tb__DOT__dut__DOT__b_address[4];
        WData/*255:0*/ tidc_system_tb__DOT__dut__DOT__b_data[8];
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT__b_mask;
        WData/*127:0*/ tidc_system_tb__DOT__dut__DOT__c_address[4];
        WData/*255:0*/ tidc_system_tb__DOT__dut__DOT__c_data[8];
        WData/*255:0*/ tidc_system_tb__DOT__dut__DOT__d_data[8];
        WData/*127:0*/ tidc_system_tb__DOT__dut__DOT__l1_request_addr_array[4];
        WData/*1023:0*/ tidc_system_tb__DOT__dut__DOT__l1_request_data_array[32];
        WData/*1023:0*/ tidc_system_tb__DOT__dut__DOT__l1_data_array[32];
        WData/*127:0*/ tidc_system_tb__DOT__dut__DOT__l1_probe_req_addr_array[4];
        WData/*127:0*/ tidc_system_tb__DOT__dut__DOT__l1_probe_ack_addr_array[4];
        WData/*1023:0*/ tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[32];
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_addr;
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_addr;
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr;
        WData/*255:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[8];
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__i;
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__j;
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__req_addr;
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__i;
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_addr;
        WData/*255:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[8];
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_addr;
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_addr;
        WData/*255:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[8];
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_addr;
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_addr;
        WData/*255:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[8];
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_addr;
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_addr;
        WData/*255:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[8];
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_addr;
        IData/*25:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tags[64];
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_states[64];
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_presence[64];
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tip_state[64];
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid[64];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__e_sink;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__e_valid;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__d_ready;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_error;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_source;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_size;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_param;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_opcode;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_valid;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__b_ready;
        CData/*7:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_mask;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_source;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_size;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_param;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_opcode;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_valid;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_permissions;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_valid;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_error;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_valid;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__l1_request_ready;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__e_sink;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__e_valid;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__d_ready;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_error;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_source;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_size;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_param;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_opcode;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_valid;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__b_ready;
        CData/*7:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_mask;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_source;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_size;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_param;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_opcode;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_valid;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_permissions;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_valid;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_error;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_valid;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__l1_request_ready;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__e_sink;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__e_valid;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__d_ready;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_error;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_source;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_size;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_param;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_opcode;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_valid;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__b_ready;
        CData/*7:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_mask;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_source;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_size;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_param;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_opcode;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_valid;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_permissions;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_valid;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_error;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_valid;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__l1_request_ready;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__e_sink;
    };
    struct {
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__e_valid;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__d_ready;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_error;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_source;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_size;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_param;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_opcode;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_valid;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__b_ready;
        CData/*7:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_mask;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_source;
        CData/*3:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_size;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_param;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_opcode;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_valid;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_permissions;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_valid;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_error;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_valid;
        CData/*0:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__l1_request_ready;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound2;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound3;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound4;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound5;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound6;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound7;
        CData/*2:0*/ tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound8;
        CData/*1:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__0__Vfuncout;
        CData/*3:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__0__one_hot;
        CData/*1:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__1__Vfuncout;
        CData/*3:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__1__one_hot;
        CData/*1:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__2__Vfuncout;
        CData/*3:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__oh_to_binary__2__one_hot;
        CData/*3:0*/ __Vtableidx1;
        CData/*0:0*/ __Vdly__tidc_system_tb__DOT__l2_response_valid;
        CData/*0:0*/ __Vdly__tidc_system_tb__DOT__l2_response_error;
        CData/*0:0*/ __VinpClk__TOP__tidc_system_tb__DOT__rst_n;
        CData/*0:0*/ __Vclklast__TOP__clk;
        CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__tidc_system_tb__DOT__rst_n;
        CData/*0:0*/ __Vchglast__TOP__tidc_system_tb__DOT__rst_n;
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_address;
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_address;
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_addr;
        WData/*255:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[8];
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_address;
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_address;
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_addr;
        WData/*255:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[8];
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_address;
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_address;
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_addr;
        WData/*255:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[8];
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_address;
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_address;
        IData/*31:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_addr;
        WData/*255:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[8];
        WData/*255:0*/ __Vdly__tidc_system_tb__DOT__l2_response_data[8];
        QData/*63:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_data;
        QData/*63:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_data;
        QData/*63:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_data;
        QData/*63:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_data;
        QData/*63:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_data;
        QData/*63:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_data;
        QData/*63:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_data;
    };
    struct {
        QData/*63:0*/ tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_data;
        CData/*0:0*/ __Vm_traceActivity[5];
    };
    static CData/*1:0*/ __Vtable1_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state[16];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtidc_system_tb__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtidc_system_tb);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtidc_system_tb(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtidc_system_tb();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); eval_end_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtidc_system_tb__Syms* __restrict vlSymsp);
    void _traceDump();void _traceDumpOpen();void _traceDumpClose();public:
    void __Vconfigure(Vtidc_system_tb__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtidc_system_tb__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtidc_system_tb__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtidc_system_tb__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtidc_system_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtidc_system_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vtidc_system_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vtidc_system_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vtidc_system_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vtidc_system_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vtidc_system_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vtidc_system_tb__Syms* __restrict vlSymsp);
    static void _settle__TOP__5(Vtidc_system_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard

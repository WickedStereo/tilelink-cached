// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtidc_system_tb.h for the primary calling header

#include "Vtidc_system_tb.h"
#include "Vtidc_system_tb__Syms.h"

//==========

void Vtidc_system_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtidc_system_tb::eval\n"); );
    Vtidc_system_tb__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtidc_system_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("tb/tidc_system_tb_verilator.v", 10, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtidc_system_tb::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vtidc_system_tb::eval_end_step\n"); );
#ifdef VM_TRACE
    Vtidc_system_tb__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtidc_system_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) _traceDump();
#endif  // VM_TRACE
}

void Vtidc_system_tb::_eval_initial_loop(Vtidc_system_tb__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("tb/tidc_system_tb_verilator.v", 10, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtidc_system_tb::_sequent__TOP__2(Vtidc_system_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtidc_system_tb::_sequent__TOP__2\n"); );
    Vtidc_system_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__tidc_system_tb__DOT__l1_0_request_valid;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__test_state;
    SData/*15:0*/ __Vdly__tidc_system_tb__DOT__wait_counter;
    IData/*31:0*/ __Vdly__tidc_system_tb__DOT__timeout_counter;
    WData/*255:0*/ __Vtemp2[8];
    WData/*255:0*/ __Vtemp3[8];
    WData/*255:0*/ __Vtemp4[8];
    WData/*255:0*/ __Vtemp5[8];
    // Body
    __Vdly__tidc_system_tb__DOT__timeout_counter = vlTOPp->tidc_system_tb__DOT__timeout_counter;
    __Vdly__tidc_system_tb__DOT__test_state = vlTOPp->tidc_system_tb__DOT__test_state;
    __Vdly__tidc_system_tb__DOT__wait_counter = vlTOPp->tidc_system_tb__DOT__wait_counter;
    __Vdly__tidc_system_tb__DOT__l1_0_request_valid 
        = vlTOPp->tidc_system_tb__DOT__l1_0_request_valid;
    vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_error 
        = vlTOPp->tidc_system_tb__DOT__l2_response_error;
    vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_valid 
        = vlTOPp->tidc_system_tb__DOT__l2_response_valid;
    vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[0U] 
        = vlTOPp->tidc_system_tb__DOT__l2_response_data[0U];
    vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[1U] 
        = vlTOPp->tidc_system_tb__DOT__l2_response_data[1U];
    vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[2U] 
        = vlTOPp->tidc_system_tb__DOT__l2_response_data[2U];
    vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[3U] 
        = vlTOPp->tidc_system_tb__DOT__l2_response_data[3U];
    vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[4U] 
        = vlTOPp->tidc_system_tb__DOT__l2_response_data[4U];
    vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[5U] 
        = vlTOPp->tidc_system_tb__DOT__l2_response_data[5U];
    vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[6U] 
        = vlTOPp->tidc_system_tb__DOT__l2_response_data[6U];
    vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[7U] 
        = vlTOPp->tidc_system_tb__DOT__l2_response_data[7U];
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        __Vdly__tidc_system_tb__DOT__timeout_counter 
            = ((IData)(1U) + vlTOPp->tidc_system_tb__DOT__timeout_counter);
        if (VL_UNLIKELY((0x7a120U <= vlTOPp->tidc_system_tb__DOT__timeout_counter))) {
            VL_WRITEF("ERROR: Simulation timeout reached!\n");
            VL_FINISH_MT("tb/tidc_system_tb_verilator.v", 275, "");
        }
    } else {
        __Vdly__tidc_system_tb__DOT__timeout_counter = 0U;
    }
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        __Vdly__tidc_system_tb__DOT__l1_0_request_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_request_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_request_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_request_valid = 0U;
        if (((((((((0U == (IData)(vlTOPp->tidc_system_tb__DOT__test_state)) 
                   | (1U == (IData)(vlTOPp->tidc_system_tb__DOT__test_state))) 
                  | (2U == (IData)(vlTOPp->tidc_system_tb__DOT__test_state))) 
                 | (3U == (IData)(vlTOPp->tidc_system_tb__DOT__test_state))) 
                | (4U == (IData)(vlTOPp->tidc_system_tb__DOT__test_state))) 
               | (5U == (IData)(vlTOPp->tidc_system_tb__DOT__test_state))) 
              | (6U == (IData)(vlTOPp->tidc_system_tb__DOT__test_state))) 
             | (7U == (IData)(vlTOPp->tidc_system_tb__DOT__test_state)))) {
            if ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__test_state))) {
                __Vdly__tidc_system_tb__DOT__wait_counter 
                    = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->tidc_system_tb__DOT__wait_counter)));
                if (VL_UNLIKELY((0x14U <= (IData)(vlTOPp->tidc_system_tb__DOT__wait_counter)))) {
                    VL_WRITEF("=== TileLink Direct Adapter Testing ===\nTEST 1: L1_0 Read Miss (Acquire NtoB) to address 00001000\n");
                    __Vdly__tidc_system_tb__DOT__test_state = 1U;
                    __Vdly__tidc_system_tb__DOT__wait_counter = 0U;
                } else {
                    if (VL_UNLIKELY((0xaU == (IData)(vlTOPp->tidc_system_tb__DOT__wait_counter)))) {
                        VL_WRITEF("Reset phase: wait_counter = %5#, rst_n = %b\n",
                                  16,vlTOPp->tidc_system_tb__DOT__wait_counter,
                                  1,(IData)(vlTOPp->tidc_system_tb__DOT__rst_n));
                    }
                }
            } else {
                if (VL_UNLIKELY((1U == (IData)(vlTOPp->tidc_system_tb__DOT__test_state)))) {
                    VL_WRITEF("L1_0 requesting: valid=%b, ready=%b, addr=%x\n",
                              1,vlTOPp->tidc_system_tb__DOT__l1_0_request_valid,
                              1,(1U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_ready_array)),
                              32,vlTOPp->tidc_system_tb__DOT__l1_0_request_addr);
                    vlTOPp->tidc_system_tb__DOT__l1_0_request_type = 0U;
                    vlTOPp->tidc_system_tb__DOT__l1_0_request_permissions = 0U;
                    vlTOPp->tidc_system_tb__DOT__l1_0_request_data[0U] = 0U;
                    vlTOPp->tidc_system_tb__DOT__l1_0_request_data[1U] = 0U;
                    vlTOPp->tidc_system_tb__DOT__l1_0_request_data[2U] = 0U;
                    vlTOPp->tidc_system_tb__DOT__l1_0_request_data[3U] = 0U;
                    vlTOPp->tidc_system_tb__DOT__l1_0_request_data[4U] = 0U;
                    vlTOPp->tidc_system_tb__DOT__l1_0_request_data[5U] = 0U;
                    vlTOPp->tidc_system_tb__DOT__l1_0_request_data[6U] = 0U;
                    vlTOPp->tidc_system_tb__DOT__l1_0_request_data[7U] = 0U;
                    if (VL_UNLIKELY((1U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_ready_array)))) {
                        VL_WRITEF("L1_0 request accepted, moving to wait state\n");
                        __Vdly__tidc_system_tb__DOT__test_state = 2U;
                        __Vdly__tidc_system_tb__DOT__wait_counter = 0U;
                    }
                    __Vdly__tidc_system_tb__DOT__l1_0_request_valid = 1U;
                    vlTOPp->tidc_system_tb__DOT__l1_0_request_addr = 0x1000U;
                } else {
                    if ((2U == (IData)(vlTOPp->tidc_system_tb__DOT__test_state))) {
                        if (VL_UNLIKELY((1U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array)))) {
                            __Vtemp2[0U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0U];
                            __Vtemp2[1U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[1U];
                            __Vtemp2[2U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[2U];
                            __Vtemp2[3U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[3U];
                            __Vtemp2[4U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[4U];
                            __Vtemp2[5U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[5U];
                            __Vtemp2[6U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[6U];
                            __Vtemp2[7U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[7U];
                            VL_WRITEF("L1_0 received data: %x\n",
                                      256,__Vtemp2);
                            VL_WRITEF("TEST 2: L1_1 Read Miss (Acquire NtoB) to same address 00001000\n");
                            __Vdly__tidc_system_tb__DOT__test_state = 3U;
                            __Vdly__tidc_system_tb__DOT__wait_counter = 0U;
                        } else {
                            __Vdly__tidc_system_tb__DOT__wait_counter 
                                = (0xffffU & ((IData)(1U) 
                                              + (IData)(vlTOPp->tidc_system_tb__DOT__wait_counter)));
                            if (VL_UNLIKELY((0x3e8U 
                                             <= (IData)(vlTOPp->tidc_system_tb__DOT__wait_counter)))) {
                                VL_WRITEF("ERROR: Timeout waiting for L1_0 data response\n");
                                VL_FINISH_MT("tb/tidc_system_tb_verilator.v", 374, "");
                            }
                        }
                    } else {
                        if ((3U == (IData)(vlTOPp->tidc_system_tb__DOT__test_state))) {
                            vlTOPp->tidc_system_tb__DOT__l1_1_request_valid = 1U;
                            vlTOPp->tidc_system_tb__DOT__l1_1_request_addr = 0x1000U;
                            vlTOPp->tidc_system_tb__DOT__l1_1_request_type = 0U;
                            vlTOPp->tidc_system_tb__DOT__l1_1_request_permissions = 0U;
                            vlTOPp->tidc_system_tb__DOT__l1_1_request_data[0U] = 0U;
                            vlTOPp->tidc_system_tb__DOT__l1_1_request_data[1U] = 0U;
                            vlTOPp->tidc_system_tb__DOT__l1_1_request_data[2U] = 0U;
                            vlTOPp->tidc_system_tb__DOT__l1_1_request_data[3U] = 0U;
                            vlTOPp->tidc_system_tb__DOT__l1_1_request_data[4U] = 0U;
                            vlTOPp->tidc_system_tb__DOT__l1_1_request_data[5U] = 0U;
                            vlTOPp->tidc_system_tb__DOT__l1_1_request_data[6U] = 0U;
                            vlTOPp->tidc_system_tb__DOT__l1_1_request_data[7U] = 0U;
                            if ((2U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_ready_array))) {
                                __Vdly__tidc_system_tb__DOT__test_state = 4U;
                                __Vdly__tidc_system_tb__DOT__wait_counter = 0U;
                            }
                        } else {
                            if ((4U == (IData)(vlTOPp->tidc_system_tb__DOT__test_state))) {
                                if (VL_UNLIKELY((2U 
                                                 & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array)))) {
                                    __Vtemp3[0U] = 
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[8U];
                                    __Vtemp3[1U] = 
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[9U];
                                    __Vtemp3[2U] = 
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0xaU];
                                    __Vtemp3[3U] = 
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0xbU];
                                    __Vtemp3[4U] = 
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0xcU];
                                    __Vtemp3[5U] = 
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0xdU];
                                    __Vtemp3[6U] = 
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0xeU];
                                    __Vtemp3[7U] = 
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0xfU];
                                    VL_WRITEF("L1_1 received data: %x\n",
                                              256,__Vtemp3);
                                    VL_WRITEF("TEST 3: L1_0 Write Miss (Acquire NtoT) to address 00002000\n");
                                    __Vdly__tidc_system_tb__DOT__test_state = 5U;
                                    __Vdly__tidc_system_tb__DOT__wait_counter = 0U;
                                } else {
                                    __Vdly__tidc_system_tb__DOT__wait_counter 
                                        = (0xffffU 
                                           & ((IData)(1U) 
                                              + (IData)(vlTOPp->tidc_system_tb__DOT__wait_counter)));
                                    if (VL_UNLIKELY(
                                                    (0x3e8U 
                                                     <= (IData)(vlTOPp->tidc_system_tb__DOT__wait_counter)))) {
                                        VL_WRITEF("ERROR: Timeout waiting for L1_1 data response\n");
                                        VL_FINISH_MT("tb/tidc_system_tb_verilator.v", 402, "");
                                    }
                                }
                            } else {
                                if ((5U == (IData)(vlTOPp->tidc_system_tb__DOT__test_state))) {
                                    __Vdly__tidc_system_tb__DOT__l1_0_request_valid = 1U;
                                    vlTOPp->tidc_system_tb__DOT__l1_0_request_addr = 0x2000U;
                                    vlTOPp->tidc_system_tb__DOT__l1_0_request_type = 1U;
                                    vlTOPp->tidc_system_tb__DOT__l1_0_request_permissions = 1U;
                                    vlTOPp->tidc_system_tb__DOT__l1_0_request_data[0U] = 0U;
                                    vlTOPp->tidc_system_tb__DOT__l1_0_request_data[1U] = 0U;
                                    vlTOPp->tidc_system_tb__DOT__l1_0_request_data[2U] = 0U;
                                    vlTOPp->tidc_system_tb__DOT__l1_0_request_data[3U] = 0U;
                                    vlTOPp->tidc_system_tb__DOT__l1_0_request_data[4U] = 0U;
                                    vlTOPp->tidc_system_tb__DOT__l1_0_request_data[5U] = 0U;
                                    vlTOPp->tidc_system_tb__DOT__l1_0_request_data[6U] = 0U;
                                    vlTOPp->tidc_system_tb__DOT__l1_0_request_data[7U] = 0U;
                                    if ((1U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_ready_array))) {
                                        __Vdly__tidc_system_tb__DOT__test_state = 6U;
                                        __Vdly__tidc_system_tb__DOT__wait_counter = 0U;
                                    }
                                } else {
                                    if ((6U == (IData)(vlTOPp->tidc_system_tb__DOT__test_state))) {
                                        if (VL_UNLIKELY(
                                                        (1U 
                                                         & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array)))) {
                                            __Vtemp4[0U] 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0U];
                                            __Vtemp4[1U] 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[1U];
                                            __Vtemp4[2U] 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[2U];
                                            __Vtemp4[3U] 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[3U];
                                            __Vtemp4[4U] 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[4U];
                                            __Vtemp4[5U] 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[5U];
                                            __Vtemp4[6U] 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[6U];
                                            __Vtemp4[7U] 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[7U];
                                            VL_WRITEF("L1_0 received exclusive data: %x\n",
                                                      256,
                                                      __Vtemp4);
                                            VL_WRITEF("TEST 4: L1_2 Read Miss to address 00003000\n");
                                            __Vdly__tidc_system_tb__DOT__test_state = 7U;
                                            __Vdly__tidc_system_tb__DOT__wait_counter = 0U;
                                        } else {
                                            __Vdly__tidc_system_tb__DOT__wait_counter 
                                                = (0xffffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlTOPp->tidc_system_tb__DOT__wait_counter)));
                                            if (VL_UNLIKELY(
                                                            (0x3e8U 
                                                             <= (IData)(vlTOPp->tidc_system_tb__DOT__wait_counter)))) {
                                                VL_WRITEF("ERROR: Timeout waiting for L1_0 data response\n");
                                                VL_FINISH_MT("tb/tidc_system_tb_verilator.v", 430, "");
                                            }
                                        }
                                    } else {
                                        vlTOPp->tidc_system_tb__DOT__l1_2_request_valid = 1U;
                                        vlTOPp->tidc_system_tb__DOT__l1_2_request_addr = 0x3000U;
                                        vlTOPp->tidc_system_tb__DOT__l1_2_request_type = 0U;
                                        vlTOPp->tidc_system_tb__DOT__l1_2_request_permissions = 0U;
                                        vlTOPp->tidc_system_tb__DOT__l1_2_request_data[0U] = 0U;
                                        vlTOPp->tidc_system_tb__DOT__l1_2_request_data[1U] = 0U;
                                        vlTOPp->tidc_system_tb__DOT__l1_2_request_data[2U] = 0U;
                                        vlTOPp->tidc_system_tb__DOT__l1_2_request_data[3U] = 0U;
                                        vlTOPp->tidc_system_tb__DOT__l1_2_request_data[4U] = 0U;
                                        vlTOPp->tidc_system_tb__DOT__l1_2_request_data[5U] = 0U;
                                        vlTOPp->tidc_system_tb__DOT__l1_2_request_data[6U] = 0U;
                                        vlTOPp->tidc_system_tb__DOT__l1_2_request_data[7U] = 0U;
                                        if ((4U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_ready_array))) {
                                            __Vdly__tidc_system_tb__DOT__test_state = 8U;
                                            __Vdly__tidc_system_tb__DOT__wait_counter = 0U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((8U == (IData)(vlTOPp->tidc_system_tb__DOT__test_state))) {
                if (VL_UNLIKELY((4U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array)))) {
                    __Vtemp5[0U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x10U];
                    __Vtemp5[1U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x11U];
                    __Vtemp5[2U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x12U];
                    __Vtemp5[3U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x13U];
                    __Vtemp5[4U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x14U];
                    __Vtemp5[5U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x15U];
                    __Vtemp5[6U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x16U];
                    __Vtemp5[7U] = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_array[0x17U];
                    VL_WRITEF("L1_2 received data: %x\n",
                              256,__Vtemp5);
                    __Vdly__tidc_system_tb__DOT__test_state = 9U;
                    __Vdly__tidc_system_tb__DOT__wait_counter = 0U;
                } else {
                    __Vdly__tidc_system_tb__DOT__wait_counter 
                        = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->tidc_system_tb__DOT__wait_counter)));
                    if (VL_UNLIKELY((0x3e8U <= (IData)(vlTOPp->tidc_system_tb__DOT__wait_counter)))) {
                        VL_WRITEF("ERROR: Timeout waiting for L1_2 data response\n");
                        VL_FINISH_MT("tb/tidc_system_tb_verilator.v", 457, "");
                    }
                }
            } else {
                if ((9U == (IData)(vlTOPp->tidc_system_tb__DOT__test_state))) {
                    __Vdly__tidc_system_tb__DOT__wait_counter 
                        = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->tidc_system_tb__DOT__wait_counter)));
                    if (VL_UNLIKELY((0x64U <= (IData)(vlTOPp->tidc_system_tb__DOT__wait_counter)))) {
                        VL_WRITEF("=== TileLink Direct Testing Complete ===\nAll basic TileLink transactions tested successfully\n");
                        VL_FINISH_MT("tb/tidc_system_tb_verilator.v", 467, "");
                    }
                }
            }
        }
    } else {
        __Vdly__tidc_system_tb__DOT__l1_0_request_valid = 0U;
        __Vdly__tidc_system_tb__DOT__test_state = 0U;
        __Vdly__tidc_system_tb__DOT__wait_counter = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_request_addr = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_request_type = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_request_data[0U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_request_data[1U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_request_data[2U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_request_data[3U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_request_data[4U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_request_data[5U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_request_data[6U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_request_data[7U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_request_permissions = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_addr = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_permissions = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_dirty_data[0U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_dirty_data[1U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_dirty_data[2U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_dirty_data[3U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_dirty_data[4U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_dirty_data[5U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_dirty_data[6U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_0_probe_ack_dirty_data[7U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_request_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_request_addr = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_request_type = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_request_data[0U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_request_data[1U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_request_data[2U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_request_data[3U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_request_data[4U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_request_data[5U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_request_data[6U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_request_data[7U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_request_permissions = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_addr = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_permissions = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_dirty_data[0U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_dirty_data[1U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_dirty_data[2U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_dirty_data[3U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_dirty_data[4U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_dirty_data[5U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_dirty_data[6U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_1_probe_ack_dirty_data[7U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_request_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_request_addr = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_request_type = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_request_data[0U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_request_data[1U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_request_data[2U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_request_data[3U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_request_data[4U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_request_data[5U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_request_data[6U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_request_data[7U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_request_permissions = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_addr = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_permissions = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_dirty_data[0U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_dirty_data[1U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_dirty_data[2U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_dirty_data[3U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_dirty_data[4U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_dirty_data[5U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_dirty_data[6U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_2_probe_ack_dirty_data[7U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_request_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_request_addr = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_request_type = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_request_data[0U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_request_data[1U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_request_data[2U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_request_data[3U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_request_data[4U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_request_data[5U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_request_data[6U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_request_data[7U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_request_permissions = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_addr = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_permissions = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_dirty_data[0U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_dirty_data[1U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_dirty_data[2U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_dirty_data[3U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_dirty_data[4U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_dirty_data[5U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_dirty_data[6U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l1_3_probe_ack_dirty_data[7U] = 0U;
    }
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        if (vlTOPp->tidc_system_tb__DOT__l2_cmd_valid) {
            vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_error = 0U;
        }
    } else {
        vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_error = 0U;
    }
    vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_valid 
        = ((IData)(vlTOPp->tidc_system_tb__DOT__rst_n) 
           & (IData)(vlTOPp->tidc_system_tb__DOT__l2_cmd_valid));
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        if (vlTOPp->tidc_system_tb__DOT__l2_cmd_valid) {
            if ((0x1000U == vlTOPp->tidc_system_tb__DOT__l2_cmd_addr)) {
                vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[0U] = 0xffffffffU;
                vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[1U] = 0xffffffffU;
                vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[2U] = 0xffffffffU;
                vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[3U] = 0xffffffffU;
                vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[4U] = 0xffffffffU;
                vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[5U] = 0xffffffffU;
                vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[6U] = 0xffffffffU;
                vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[7U] = 0xffffffffU;
            } else {
                vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[0U] 
                    = ((0x2000U == vlTOPp->tidc_system_tb__DOT__l2_cmd_addr)
                        ? 0U : 0U);
                vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[1U] 
                    = ((0x2000U == vlTOPp->tidc_system_tb__DOT__l2_cmd_addr)
                        ? 0U : 0U);
                vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[2U] 
                    = ((0x2000U == vlTOPp->tidc_system_tb__DOT__l2_cmd_addr)
                        ? 0U : ((0x3000U == vlTOPp->tidc_system_tb__DOT__l2_cmd_addr)
                                 ? 0xffffffffU : 0U));
                vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[3U] 
                    = ((0x2000U == vlTOPp->tidc_system_tb__DOT__l2_cmd_addr)
                        ? 0U : ((0x3000U == vlTOPp->tidc_system_tb__DOT__l2_cmd_addr)
                                 ? 0xffffffffU : 0U));
                vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[4U] 
                    = ((0x2000U == vlTOPp->tidc_system_tb__DOT__l2_cmd_addr)
                        ? 0xffffffffU : 0U);
                vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[5U] 
                    = ((0x2000U == vlTOPp->tidc_system_tb__DOT__l2_cmd_addr)
                        ? 0xffffffffU : 0U);
                vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[6U] 
                    = ((0x2000U == vlTOPp->tidc_system_tb__DOT__l2_cmd_addr)
                        ? 0xffffffffU : ((0x3000U == vlTOPp->tidc_system_tb__DOT__l2_cmd_addr)
                                          ? 0xffffffffU
                                          : 0U));
                vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[7U] 
                    = ((0x2000U == vlTOPp->tidc_system_tb__DOT__l2_cmd_addr)
                        ? 0xffffffffU : ((0x3000U == vlTOPp->tidc_system_tb__DOT__l2_cmd_addr)
                                          ? 0xffffffffU
                                          : 0U));
            }
        }
    } else {
        vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[0U] = 0U;
        vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[1U] = 0U;
        vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[2U] = 0U;
        vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[3U] = 0U;
        vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[4U] = 0U;
        vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[5U] = 0U;
        vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[6U] = 0U;
        vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[7U] = 0U;
    }
    vlTOPp->tidc_system_tb__DOT__timeout_counter = __Vdly__tidc_system_tb__DOT__timeout_counter;
    vlTOPp->tidc_system_tb__DOT__wait_counter = __Vdly__tidc_system_tb__DOT__wait_counter;
    vlTOPp->tidc_system_tb__DOT__test_state = __Vdly__tidc_system_tb__DOT__test_state;
    vlTOPp->tidc_system_tb__DOT__l1_0_request_valid 
        = __Vdly__tidc_system_tb__DOT__l1_0_request_valid;
}

VL_INLINE_OPT void Vtidc_system_tb::_sequent__TOP__3(Vtidc_system_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtidc_system_tb::_sequent__TOP__3\n"); );
    Vtidc_system_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*5:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__3__Vfuncout;
    CData/*5:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__4__Vfuncout;
    CData/*5:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__6__Vfuncout;
    CData/*5:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__7__Vfuncout;
    CData/*5:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__8__Vfuncout;
    CData/*5:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__9__Vfuncout;
    CData/*5:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__11__Vfuncout;
    CData/*5:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__12__Vfuncout;
    CData/*5:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__13__Vfuncout;
    CData/*5:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__14__Vfuncout;
    CData/*0:0*/ __Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found;
    CData/*0:0*/ __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found;
    CData/*0:0*/ __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found;
    CData/*0:0*/ __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found;
    CData/*0:0*/ __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found;
    CData/*1:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id;
    CData/*2:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode;
    CData/*2:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_source;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_sink;
    CData/*1:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel;
    CData/*0:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_valid;
    CData/*2:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_state;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_presence;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_tip_state;
    CData/*5:0*/ __Vdlyvdim0__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v0;
    CData/*0:0*/ __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v0;
    CData/*5:0*/ __Vdlyvdim0__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tags__v0;
    CData/*0:0*/ __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tags__v0;
    CData/*5:0*/ __Vdlyvdim0__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_states__v0;
    CData/*2:0*/ __Vdlyvval__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_states__v0;
    CData/*0:0*/ __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_states__v0;
    CData/*5:0*/ __Vdlyvdim0__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_presence__v0;
    CData/*3:0*/ __Vdlyvval__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_presence__v0;
    CData/*0:0*/ __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_presence__v0;
    CData/*5:0*/ __Vdlyvdim0__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tip_state__v0;
    CData/*3:0*/ __Vdlyvval__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tip_state__v0;
    CData/*0:0*/ __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tip_state__v0;
    CData/*0:0*/ __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v1;
    CData/*0:0*/ __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v2;
    CData/*2:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_req_type;
    CData/*2:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_permissions;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id;
    CData/*0:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_has_data;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__grant_sink;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_source;
    CData/*2:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_req_type;
    CData/*2:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_permissions;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id;
    CData/*0:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_has_data;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__grant_sink;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_source;
    CData/*2:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_req_type;
    CData/*2:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_permissions;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id;
    CData/*0:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_has_data;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__grant_sink;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_source;
    CData/*2:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_req_type;
    CData/*2:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_permissions;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id;
    CData/*0:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_has_data;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__grant_sink;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_source;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
    CData/*3:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
    SData/*15:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use;
    SData/*15:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use;
    SData/*15:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use;
    SData/*15:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use;
    SData/*15:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use;
    IData/*31:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__3__addr;
    IData/*31:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__4__addr;
    IData/*25:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_tag__5__Vfuncout;
    IData/*31:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_tag__5__addr;
    IData/*31:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__6__addr;
    IData/*31:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__7__addr;
    IData/*31:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__8__addr;
    IData/*31:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__9__addr;
    IData/*25:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_tag__10__Vfuncout;
    IData/*31:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_tag__10__addr;
    IData/*31:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__11__addr;
    IData/*31:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__12__addr;
    IData/*31:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__13__addr;
    IData/*31:0*/ __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__14__addr;
    IData/*31:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr;
    WData/*255:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[8];
    IData/*25:0*/ __Vdlyvval__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tags__v0;
    IData/*31:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_addr;
    WData/*255:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[8];
    IData/*31:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_addr;
    WData/*255:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[8];
    IData/*31:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_addr;
    WData/*255:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[8];
    IData/*31:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_addr;
    WData/*255:0*/ __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[8];
    WData/*255:0*/ __Vtemp17[8];
    WData/*255:0*/ __Vtemp18[8];
    WData/*255:0*/ __Vtemp20[8];
    WData/*255:0*/ __Vtemp21[8];
    WData/*255:0*/ __Vtemp23[8];
    WData/*255:0*/ __Vtemp24[8];
    WData/*255:0*/ __Vtemp26[8];
    WData/*255:0*/ __Vtemp27[8];
    WData/*255:0*/ __Vtemp28[8];
    WData/*255:0*/ __Vtemp29[8];
    WData/*255:0*/ __Vtemp30[8];
    WData/*255:0*/ __Vtemp31[8];
    WData/*255:0*/ __Vtemp32[8];
    WData/*255:0*/ __Vtemp33[8];
    IData/*31:0*/ __Vilp;
    // Body
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel;
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[0U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[0U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[1U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[1U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[2U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[2U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[3U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[3U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[4U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[4U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[5U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[5U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[6U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[6U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[7U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[7U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_source 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_source;
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param;
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr;
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_sink 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_sink;
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked;
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent;
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode;
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id;
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id;
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use;
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_tip_state 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_tip_state;
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_presence 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_presence;
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_state 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_state;
    __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tip_state__v0 = 0U;
    __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_presence__v0 = 0U;
    __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_states__v0 = 0U;
    __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tags__v0 = 0U;
    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_valid 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_valid;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_source 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_source;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__grant_sink 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__grant_sink;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_has_data 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_has_data;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[0U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[0U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[1U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[1U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[2U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[2U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[3U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[3U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[4U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[4U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[5U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[5U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[6U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[6U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[7U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[7U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_permissions 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_permissions;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_req_type 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_req_type;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_addr 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_addr;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_source 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_source;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__grant_sink 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__grant_sink;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_has_data 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_has_data;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[0U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[0U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[1U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[1U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[2U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[2U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[3U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[3U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[4U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[4U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[5U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[5U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[6U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[6U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[7U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[7U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_permissions 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_permissions;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_req_type 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_req_type;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_addr 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_addr;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_source 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_source;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__grant_sink 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__grant_sink;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_has_data 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_has_data;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[0U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[0U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[1U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[1U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[2U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[2U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[3U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[3U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[4U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[4U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[5U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[5U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[6U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[6U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[7U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[7U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_permissions 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_permissions;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_req_type 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_req_type;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_addr 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_addr;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_source 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_source;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__grant_sink 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__grant_sink;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_has_data 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_has_data;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[0U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[0U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[1U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[1U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[2U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[2U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[3U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[3U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[4U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[4U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[5U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[5U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[6U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[6U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[7U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[7U];
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_permissions 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_permissions;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_req_type 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_req_type;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_addr 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_addr;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use;
    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use;
    __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v0 = 0U;
    __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v1 = 0U;
    __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v2 = 0U;
    if ((1U & (~ (IData)(vlTOPp->tidc_system_tb__DOT__rst_n)))) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__i = 0x40U;
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__d_ready = 1U;
    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__d_ready = 1U;
    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__d_ready = 1U;
    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__d_ready = 1U;
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        if ((((9U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state)) 
              & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid) 
                 >> (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))) 
             & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink) 
                         >> (0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                     << 2U)))) == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_sink)))) {
            __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use 
                = ((~ ((IData)(1U) << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_dealloc_sink_id))) 
                   & (IData)(__Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use));
        }
        if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_alloc_req) 
             & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__any_id_available))) {
            __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use 
                = ((IData)(__Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use) 
                   | ((IData)(1U) << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)));
            __Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found = 0U;
            if ((1U & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use) 
                          >> (0xfU & ((IData)(1U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(1U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use) 
                             >> (0xfU & ((IData)(2U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(2U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use) 
                             >> (0xfU & ((IData)(3U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(3U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use) 
                             >> (0xfU & ((IData)(4U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(4U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use) 
                             >> (0xfU & ((IData)(5U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(5U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use) 
                             >> (0xfU & ((IData)(6U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(6U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use) 
                             >> (0xfU & ((IData)(7U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(7U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use) 
                             >> (0xfU & ((IData)(8U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(8U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use) 
                             >> (0xfU & ((IData)(9U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(9U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use) 
                             >> (0xfU & ((IData)(0xaU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xaU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use) 
                             >> (0xfU & ((IData)(0xbU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xbU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use) 
                             >> (0xfU & ((IData)(0xcU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xcU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use) 
                             >> (0xfU & ((IData)(0xdU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xdU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use) 
                             >> (0xfU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xeU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use) 
                             >> (0xfU & ((IData)(0xfU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xfU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use) 
                             >> (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id)))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id 
                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id;
                __Vtask_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__find_next_free_id__15__found = 1U;
            }
        }
    } else {
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id = 0U;
    }
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        if (vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__dealloc_source_id_req) {
            __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use 
                = ((~ ((IData)(1U) << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__dealloc_source_id))) 
                   & (IData)(__Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use));
        }
        if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__alloc_source_id_req) 
             & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__any_id_available))) {
            __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use 
                = ((IData)(__Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                   | ((IData)(1U) << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
            __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found = 0U;
            if ((1U & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                          >> (0xfU & ((IData)(1U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(1U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(2U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(2U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(3U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(3U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(4U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(4U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(5U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(5U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(6U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(6U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(7U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(7U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(8U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(8U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(9U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(9U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xaU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xaU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xbU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xbU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xcU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xcU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xdU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xdU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xeU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xfU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xfU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__16__found = 1U;
            }
        }
    } else {
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id = 0U;
    }
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        if (vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__dealloc_source_id_req) {
            __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use 
                = ((~ ((IData)(1U) << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__dealloc_source_id))) 
                   & (IData)(__Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use));
        }
        if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__alloc_source_id_req) 
             & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__any_id_available))) {
            __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use 
                = ((IData)(__Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                   | ((IData)(1U) << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
            __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found = 0U;
            if ((1U & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                          >> (0xfU & ((IData)(1U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(1U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(2U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(2U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(3U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(3U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(4U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(4U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(5U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(5U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(6U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(6U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(7U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(7U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(8U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(8U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(9U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(9U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xaU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xaU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xbU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xbU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xcU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xcU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xdU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xdU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xeU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xfU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xfU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__17__found = 1U;
            }
        }
    } else {
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id = 0U;
    }
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        if (vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__dealloc_source_id_req) {
            __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use 
                = ((~ ((IData)(1U) << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__dealloc_source_id))) 
                   & (IData)(__Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use));
        }
        if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__alloc_source_id_req) 
             & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__any_id_available))) {
            __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use 
                = ((IData)(__Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                   | ((IData)(1U) << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
            __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found = 0U;
            if ((1U & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                          >> (0xfU & ((IData)(1U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(1U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(2U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(2U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(3U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(3U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(4U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(4U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(5U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(5U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(6U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(6U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(7U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(7U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(8U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(8U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(9U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(9U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xaU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xaU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xbU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xbU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xcU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xcU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xdU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xdU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xeU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xfU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xfU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__18__found = 1U;
            }
        }
    } else {
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id = 0U;
    }
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        if (vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__dealloc_source_id_req) {
            __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use 
                = ((~ ((IData)(1U) << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__dealloc_source_id))) 
                   & (IData)(__Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use));
        }
        if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__alloc_source_id_req) 
             & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__any_id_available))) {
            __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use 
                = ((IData)(__Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                   | ((IData)(1U) << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
            __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found = 0U;
            if ((1U & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                          >> (0xfU & ((IData)(1U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(1U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(2U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(2U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(3U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(3U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(4U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(4U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(5U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(5U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(6U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(6U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(7U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(7U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(8U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(8U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(9U) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(9U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xaU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xaU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xbU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xbU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xcU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xcU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xdU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xdU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xeU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (0xfU & ((IData)(0xfU) 
                                         + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = (0xfU & ((IData)(0xfU) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)));
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found = 1U;
            }
            if ((1U & ((~ (IData)(__Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found)) 
                       & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use) 
                             >> (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id)))))) {
                __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
                __Vtask_tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__find_next_free_id__19__found = 1U;
            }
        }
    } else {
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id = 0U;
    }
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_done = 0U;
        if ((0U != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__state))) {
            if ((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__state))) {
                __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_tag__5__addr 
                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__req_addr;
                __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_tag__5__Vfuncout 
                    = (0x3ffffffU & (__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_tag__5__addr 
                                     >> 6U));
                __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__4__addr 
                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__req_addr;
                __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__4__Vfuncout 
                    = (0x3fU & __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__4__addr);
                __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__3__addr 
                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__req_addr;
                __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__3__Vfuncout 
                    = (0x3fU & __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__3__addr);
                if ((vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid
                     [__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__3__Vfuncout] 
                     & (vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tags
                        [__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__4__Vfuncout] 
                        == __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_tag__5__Vfuncout))) {
                    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__6__addr 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__req_addr;
                    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__6__Vfuncout 
                        = (0x3fU & __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__6__addr);
                    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_valid = 1U;
                    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_state 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_states
                        [__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__6__Vfuncout];
                    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__7__addr 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__req_addr;
                    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__7__Vfuncout 
                        = (0x3fU & __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__7__addr);
                    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_presence 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_presence
                        [__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__7__Vfuncout];
                    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__8__addr 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__req_addr;
                    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__8__Vfuncout 
                        = (0x3fU & __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__8__addr);
                    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_tip_state 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tip_state
                        [__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__8__Vfuncout];
                } else {
                    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_valid = 1U;
                    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_state = 0U;
                    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_presence = 0U;
                    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_tip_state = 0U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__state))) {
                    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__9__addr 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__req_addr;
                    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__9__Vfuncout 
                        = (0x3fU & __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__9__addr);
                    __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v0 = 1U;
                    __Vdlyvdim0__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v0 
                        = __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__9__Vfuncout;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_done = 1U;
                    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__11__addr 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__req_addr;
                    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__11__Vfuncout 
                        = (0x3fU & __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__11__addr);
                    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_tag__10__addr 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__req_addr;
                    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_tag__10__Vfuncout 
                        = (0x3ffffffU & (__Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_tag__10__addr 
                                         >> 6U));
                    __Vdlyvval__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tags__v0 
                        = __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_tag__10__Vfuncout;
                    __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tags__v0 = 1U;
                    __Vdlyvdim0__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tags__v0 
                        = __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__11__Vfuncout;
                    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__12__addr 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__req_addr;
                    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__12__Vfuncout 
                        = (0x3fU & __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__12__addr);
                    __Vdlyvval__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_states__v0 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_state;
                    __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_states__v0 = 1U;
                    __Vdlyvdim0__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_states__v0 
                        = __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__12__Vfuncout;
                    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__13__addr 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__req_addr;
                    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__13__Vfuncout 
                        = (0x3fU & __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__13__addr);
                    __Vdlyvval__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_presence__v0 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_presence;
                    __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_presence__v0 = 1U;
                    __Vdlyvdim0__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_presence__v0 
                        = __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__13__Vfuncout;
                    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__14__addr 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__req_addr;
                    __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__14__Vfuncout 
                        = (0x3fU & __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__14__addr);
                    __Vdlyvval__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tip_state__v0 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_tip_state;
                    __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tip_state__v0 = 1U;
                    __Vdlyvdim0__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tip_state__v0 
                        = __Vfunc_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__get_index__14__Vfuncout;
                }
            }
        }
        if ((((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__state)) 
              & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_req)) 
             | ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__state)) 
                & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_req)))) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__req_addr 
                = ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_req)
                    ? vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_addr
                    : vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_addr);
        }
    } else {
        __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v1 = 1U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_valid = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_state = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_presence = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_tip_state = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_done = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__req_addr = 0U;
        __Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v2 = 1U;
    }
    if (__Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v0) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid[__Vdlyvdim0__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v0] = 1U;
    }
    if (__Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v1) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid[0U] = 0U;
    }
    if (__Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v2) {
        __Vilp = 1U;
        while ((__Vilp <= 0x3fU)) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid[__Vilp] = 0U;
            __Vilp = ((IData)(1U) + __Vilp);
        }
    }
    if (__Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tip_state__v0) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tip_state[__Vdlyvdim0__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tip_state__v0] 
            = __Vdlyvval__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tip_state__v0;
    }
    if (__Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v1) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tip_state[0U] = 0U;
    }
    if (__Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v2) {
        __Vilp = 1U;
        while ((__Vilp <= 0x3fU)) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tip_state[__Vilp] = 0U;
            __Vilp = ((IData)(1U) + __Vilp);
        }
    }
    if (__Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_presence__v0) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_presence[__Vdlyvdim0__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_presence__v0] 
            = __Vdlyvval__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_presence__v0;
    }
    if (__Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v1) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_presence[0U] = 0U;
    }
    if (__Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v2) {
        __Vilp = 1U;
        while ((__Vilp <= 0x3fU)) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_presence[__Vilp] = 0U;
            __Vilp = ((IData)(1U) + __Vilp);
        }
    }
    if (__Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_states__v0) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_states[__Vdlyvdim0__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_states__v0] 
            = __Vdlyvval__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_states__v0;
    }
    if (__Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v1) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_states[0U] = 0U;
    }
    if (__Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v2) {
        __Vilp = 1U;
        while ((__Vilp <= 0x3fU)) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_states[__Vilp] = 0U;
            __Vilp = ((IData)(1U) + __Vilp);
        }
    }
    if (__Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tags__v0) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tags[__Vdlyvdim0__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tags__v0] 
            = __Vdlyvval__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tags__v0;
    }
    if (__Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v1) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tags[0U] = 0U;
    }
    if (__Vdlyvset__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_valid__v2) {
        __Vilp = 1U;
        while ((__Vilp <= 0x3fU)) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__dir_tags[__Vilp] = 0U;
            __Vilp = ((IData)(1U) + __Vilp);
        }
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__d_ready 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_ready)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__d_ready) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__d_ready 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_ready)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__d_ready) 
              << 2U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__d_ready 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_ready)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__d_ready) 
              << 1U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__d_ready 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_ready)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__d_ready));
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__b_ready 
            = ((7U != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state)) 
               & (8U != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state)));
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__e_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_valid = 0U;
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
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_addr 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_addr_array[0U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_req_type 
                        = (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array));
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_permissions 
                        = (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_permissions_array));
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[0U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[1U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[1U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[2U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[2U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[3U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[3U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[4U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[4U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[5U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[5U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[6U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[6U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[7U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[7U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id 
                        = ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__allocated_source_id_valid)
                            ? (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__allocated_source_id)
                            : (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id));
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_has_data 
                        = (2U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array)));
                }
            } else {
                if ((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_valid = 1U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_opcode = 6U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_param 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_permissions;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_size = 5U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_source 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_address 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_addr;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_data = 0ULL;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_mask = 0xffU;
                } else {
                    if ((2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) {
                        if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                              & ((4U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode))) 
                                 | (5U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode))))) 
                             & ((0xfU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source)) 
                                == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                            __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__grant_sink 
                                = (0xfU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_sink));
                            if ((5U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode)))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_valid = 1U;
                                VL_EXTEND_WQ(256,64, __Vtemp17, 
                                             (((QData)((IData)(
                                                               vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[1U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[0U]))));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[0U] 
                                    = __Vtemp17[0U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[1U] 
                                    = __Vtemp17[1U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[2U] 
                                    = __Vtemp17[2U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[3U] 
                                    = __Vtemp17[3U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[4U] 
                                    = __Vtemp17[4U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[5U] 
                                    = __Vtemp17[5U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[6U] 
                                    = __Vtemp17[6U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[7U] 
                                    = __Vtemp17[7U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_error 
                                    = (1U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_error));
                            }
                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__dealloc_source_id 
                                = (0xfU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source));
                        }
                    } else {
                        if ((3U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) {
                            vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__e_valid = 1U;
                            vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__e_sink 
                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__grant_sink;
                        } else {
                            if ((4U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_valid = 1U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_opcode 
                                    = ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_has_data)
                                        ? 7U : 6U);
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_param 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_permissions;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_size = 5U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_source 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_address 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_addr;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_error = 0U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_data 
                                    = ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_has_data)
                                        ? (((QData)((IData)(
                                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[1U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[0U])))
                                        : 0ULL);
                            } else {
                                if ((5U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) {
                                    if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                                          & (6U == 
                                             (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode)))) 
                                         & ((0xfU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source)) 
                                            == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__dealloc_source_id 
                                            = (0xfU 
                                               & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source));
                                    }
                                } else {
                                    if ((6U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) {
                                        if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid) 
                                             & (6U 
                                                == 
                                                (7U 
                                                 & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode))))) {
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_addr 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address[0U];
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_param 
                                                = (7U 
                                                   & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param));
                                            __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_source 
                                                = (0xfU 
                                                   & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_source));
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_valid = 1U;
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_addr 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address[0U];
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_permissions 
                                                = (7U 
                                                   & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param));
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
                if ((1U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_valid_array))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_valid = 1U;
                    if (((0U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_permissions_array))) 
                         | (1U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_permissions_array))))) {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_opcode = 5U;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_data 
                            = (((QData)((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[1U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0U])));
                    } else {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_opcode = 4U;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_data = 0ULL;
                    }
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_param 
                        = (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_permissions_array));
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_size = 5U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_source 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_source;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_address 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_addr_array[0U];
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_error = 0U;
                }
            } else {
                if ((9U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_valid = 1U;
                    if ((3U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_req_type))) {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_opcode = 4U;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_data = 0ULL;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_mask = 0xffU;
                    } else {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_opcode = 0U;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_data 
                            = (((QData)((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[1U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[0U])));
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_mask = 0xffU;
                    }
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_param = 0U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_size = 5U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_source 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_address 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_addr;
                } else {
                    if ((0xaU == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state))) {
                        if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                              & ((0U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode))) 
                                 | (1U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode))))) 
                             & ((0xfU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source)) 
                                == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                            if ((1U == (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode)))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_valid = 1U;
                                VL_EXTEND_WQ(256,64, __Vtemp18, 
                                             (((QData)((IData)(
                                                               vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[1U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[0U]))));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[0U] 
                                    = __Vtemp18[0U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[1U] 
                                    = __Vtemp18[1U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[2U] 
                                    = __Vtemp18[2U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[3U] 
                                    = __Vtemp18[3U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[4U] 
                                    = __Vtemp18[4U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[5U] 
                                    = __Vtemp18[5U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[6U] 
                                    = __Vtemp18[6U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[7U] 
                                    = __Vtemp18[7U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_error 
                                    = (1U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_error));
                            }
                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__dealloc_source_id 
                                = (0xfU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source));
                        }
                    }
                }
            }
        }
    } else {
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_addr = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_req_type = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_permissions = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[0U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[1U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[2U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[3U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[4U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[5U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[6U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[7U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_has_data = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_addr = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_param = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_source = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__grant_sink = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__dealloc_source_id = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[0U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[1U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[2U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[3U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[4U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[5U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[6U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_data[7U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_error = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_addr = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_permissions = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_opcode = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_param = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_size = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_source = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_address = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_data = 0ULL;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_mask = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__b_ready = 1U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_opcode = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_param = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_size = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_source = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_address = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_data = 0ULL;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_error = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__e_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__e_sink = 0U;
    }
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__b_ready 
            = ((7U != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state)) 
               & (8U != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state)));
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__e_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_valid = 0U;
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
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_addr 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_addr_array[1U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_req_type 
                        = (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                 >> 3U));
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_permissions 
                        = (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_permissions_array) 
                                 >> 3U));
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[0U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[8U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[1U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[9U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[2U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0xaU];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[3U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0xbU];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[4U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0xcU];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[5U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0xdU];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[6U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0xeU];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[7U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0xfU];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id 
                        = ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__allocated_source_id_valid)
                            ? (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__allocated_source_id)
                            : (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id));
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_has_data 
                        = (2U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                        >> 3U)));
                }
            } else {
                if ((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_valid = 1U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_opcode = 6U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_param 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_permissions;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_size = 5U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_source 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_address 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_addr;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_data = 0ULL;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_mask = 0xffU;
                } else {
                    if ((2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) {
                        if (((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                               >> 1U) & ((4U == (7U 
                                                 & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                    >> 3U))) 
                                         | (5U == (7U 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                      >> 3U))))) 
                             & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                         >> 4U)) == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                            __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__grant_sink 
                                = (0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_sink) 
                                           >> 4U));
                            if ((5U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                              >> 3U)))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_valid = 1U;
                                VL_EXTEND_WQ(256,64, __Vtemp20, 
                                             (((QData)((IData)(
                                                               vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[3U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[2U]))));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[0U] 
                                    = __Vtemp20[0U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[1U] 
                                    = __Vtemp20[1U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[2U] 
                                    = __Vtemp20[2U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[3U] 
                                    = __Vtemp20[3U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[4U] 
                                    = __Vtemp20[4U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[5U] 
                                    = __Vtemp20[5U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[6U] 
                                    = __Vtemp20[6U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[7U] 
                                    = __Vtemp20[7U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_error 
                                    = (1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_error) 
                                             >> 1U));
                            }
                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__dealloc_source_id 
                                = (0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                           >> 4U));
                        }
                    } else {
                        if ((3U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) {
                            vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__e_valid = 1U;
                            vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__e_sink 
                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__grant_sink;
                        } else {
                            if ((4U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_valid = 1U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_opcode 
                                    = ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_has_data)
                                        ? 7U : 6U);
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_param 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_permissions;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_size = 5U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_source 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_address 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_addr;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_error = 0U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_data 
                                    = ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_has_data)
                                        ? (((QData)((IData)(
                                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[1U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[0U])))
                                        : 0ULL);
                            } else {
                                if ((5U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) {
                                    if (((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                                           >> 1U) & 
                                          (6U == (7U 
                                                  & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                     >> 3U)))) 
                                         & ((0xfU & 
                                             ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                              >> 4U)) 
                                            == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__dealloc_source_id 
                                            = (0xfU 
                                               & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                                  >> 4U));
                                    }
                                } else {
                                    if ((6U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) {
                                        if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid) 
                                              >> 1U) 
                                             & (6U 
                                                == 
                                                (7U 
                                                 & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode) 
                                                    >> 3U))))) {
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_addr 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address[1U];
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_param 
                                                = (7U 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param) 
                                                      >> 3U));
                                            __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_source 
                                                = (0xfU 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_source) 
                                                      >> 4U));
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_valid = 1U;
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_addr 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address[1U];
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_permissions 
                                                = (7U 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param) 
                                                      >> 3U));
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
                if ((2U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_valid_array))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_valid = 1U;
                    if (((0U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_permissions_array) 
                                       >> 3U))) | (1U 
                                                   == 
                                                   (7U 
                                                    & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_permissions_array) 
                                                       >> 3U))))) {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_opcode = 5U;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_data 
                            = (((QData)((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[9U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[8U])));
                    } else {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_opcode = 4U;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_data = 0ULL;
                    }
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_param 
                        = (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_permissions_array) 
                                 >> 3U));
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_size = 5U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_source 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_source;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_address 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_addr_array[1U];
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_error = 0U;
                }
            } else {
                if ((9U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_valid = 1U;
                    if ((3U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_req_type))) {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_opcode = 4U;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_data = 0ULL;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_mask = 0xffU;
                    } else {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_opcode = 0U;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_data 
                            = (((QData)((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[1U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[0U])));
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_mask = 0xffU;
                    }
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_param = 0U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_size = 5U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_source 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_address 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_addr;
                } else {
                    if ((0xaU == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state))) {
                        if (((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                               >> 1U) & ((0U == (7U 
                                                 & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                    >> 3U))) 
                                         | (1U == (7U 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                      >> 3U))))) 
                             & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                         >> 4U)) == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                            if ((1U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                              >> 3U)))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_valid = 1U;
                                VL_EXTEND_WQ(256,64, __Vtemp21, 
                                             (((QData)((IData)(
                                                               vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[3U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[2U]))));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[0U] 
                                    = __Vtemp21[0U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[1U] 
                                    = __Vtemp21[1U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[2U] 
                                    = __Vtemp21[2U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[3U] 
                                    = __Vtemp21[3U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[4U] 
                                    = __Vtemp21[4U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[5U] 
                                    = __Vtemp21[5U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[6U] 
                                    = __Vtemp21[6U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[7U] 
                                    = __Vtemp21[7U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_error 
                                    = (1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_error) 
                                             >> 1U));
                            }
                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__dealloc_source_id 
                                = (0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                           >> 4U));
                        }
                    }
                }
            }
        }
    } else {
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_addr = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_req_type = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_permissions = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[0U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[1U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[2U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[3U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[4U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[5U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[6U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[7U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_has_data = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_addr = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_param = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_source = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__grant_sink = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__dealloc_source_id = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[0U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[1U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[2U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[3U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[4U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[5U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[6U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_data[7U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_error = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_addr = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_permissions = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_opcode = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_param = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_size = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_source = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_address = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_data = 0ULL;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_mask = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__b_ready = 1U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_opcode = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_param = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_size = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_source = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_address = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_data = 0ULL;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_error = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__e_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__e_sink = 0U;
    }
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__b_ready 
            = ((7U != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state)) 
               & (8U != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state)));
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__e_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_valid = 0U;
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
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_addr 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_addr_array[2U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_req_type 
                        = (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                 >> 6U));
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_permissions 
                        = (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_permissions_array) 
                                 >> 6U));
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[0U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x10U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[1U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x11U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[2U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x12U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[3U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x13U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[4U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x14U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[5U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x15U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[6U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x16U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[7U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x17U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id 
                        = ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__allocated_source_id_valid)
                            ? (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__allocated_source_id)
                            : (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id));
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_has_data 
                        = (2U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                        >> 6U)));
                }
            } else {
                if ((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_valid = 1U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_opcode = 6U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_param 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_permissions;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_size = 5U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_source 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_address 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_addr;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_data = 0ULL;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_mask = 0xffU;
                } else {
                    if ((2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) {
                        if (((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                               >> 2U) & ((4U == (7U 
                                                 & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                    >> 6U))) 
                                         | (5U == (7U 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                      >> 6U))))) 
                             & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                         >> 8U)) == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                            __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__grant_sink 
                                = (0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_sink) 
                                           >> 8U));
                            if ((5U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                              >> 6U)))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_valid = 1U;
                                VL_EXTEND_WQ(256,64, __Vtemp23, 
                                             (((QData)((IData)(
                                                               vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[5U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[4U]))));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[0U] 
                                    = __Vtemp23[0U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[1U] 
                                    = __Vtemp23[1U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[2U] 
                                    = __Vtemp23[2U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[3U] 
                                    = __Vtemp23[3U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[4U] 
                                    = __Vtemp23[4U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[5U] 
                                    = __Vtemp23[5U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[6U] 
                                    = __Vtemp23[6U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[7U] 
                                    = __Vtemp23[7U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_error 
                                    = (1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_error) 
                                             >> 2U));
                            }
                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__dealloc_source_id 
                                = (0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                           >> 8U));
                        }
                    } else {
                        if ((3U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) {
                            vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__e_valid = 1U;
                            vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__e_sink 
                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__grant_sink;
                        } else {
                            if ((4U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_valid = 1U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_opcode 
                                    = ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_has_data)
                                        ? 7U : 6U);
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_param 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_permissions;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_size = 5U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_source 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_address 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_addr;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_error = 0U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_data 
                                    = ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_has_data)
                                        ? (((QData)((IData)(
                                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[1U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[0U])))
                                        : 0ULL);
                            } else {
                                if ((5U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) {
                                    if (((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                                           >> 2U) & 
                                          (6U == (7U 
                                                  & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                     >> 6U)))) 
                                         & ((0xfU & 
                                             ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                              >> 8U)) 
                                            == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__dealloc_source_id 
                                            = (0xfU 
                                               & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                                  >> 8U));
                                    }
                                } else {
                                    if ((6U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) {
                                        if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid) 
                                              >> 2U) 
                                             & (6U 
                                                == 
                                                (7U 
                                                 & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode) 
                                                    >> 6U))))) {
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_addr 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address[2U];
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_param 
                                                = (7U 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param) 
                                                      >> 6U));
                                            __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_source 
                                                = (0xfU 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_source) 
                                                      >> 8U));
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_valid = 1U;
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_addr 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address[2U];
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_permissions 
                                                = (7U 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param) 
                                                      >> 6U));
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
                if ((4U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_valid_array))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_valid = 1U;
                    if (((0U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_permissions_array) 
                                       >> 6U))) | (1U 
                                                   == 
                                                   (7U 
                                                    & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_permissions_array) 
                                                       >> 6U))))) {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_opcode = 5U;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_data 
                            = (((QData)((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x11U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x10U])));
                    } else {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_opcode = 4U;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_data = 0ULL;
                    }
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_param 
                        = (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_permissions_array) 
                                 >> 6U));
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_size = 5U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_source 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_source;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_address 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_addr_array[2U];
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_error = 0U;
                }
            } else {
                if ((9U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_valid = 1U;
                    if ((3U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_req_type))) {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_opcode = 4U;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_data = 0ULL;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_mask = 0xffU;
                    } else {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_opcode = 0U;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_data 
                            = (((QData)((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[1U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[0U])));
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_mask = 0xffU;
                    }
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_param = 0U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_size = 5U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_source 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_address 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_addr;
                } else {
                    if ((0xaU == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state))) {
                        if (((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                               >> 2U) & ((0U == (7U 
                                                 & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                    >> 6U))) 
                                         | (1U == (7U 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                      >> 6U))))) 
                             & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                         >> 8U)) == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                            if ((1U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                              >> 6U)))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_valid = 1U;
                                VL_EXTEND_WQ(256,64, __Vtemp24, 
                                             (((QData)((IData)(
                                                               vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[5U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[4U]))));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[0U] 
                                    = __Vtemp24[0U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[1U] 
                                    = __Vtemp24[1U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[2U] 
                                    = __Vtemp24[2U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[3U] 
                                    = __Vtemp24[3U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[4U] 
                                    = __Vtemp24[4U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[5U] 
                                    = __Vtemp24[5U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[6U] 
                                    = __Vtemp24[6U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[7U] 
                                    = __Vtemp24[7U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_error 
                                    = (1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_error) 
                                             >> 2U));
                            }
                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__dealloc_source_id 
                                = (0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                           >> 8U));
                        }
                    }
                }
            }
        }
    } else {
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_addr = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_req_type = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_permissions = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[0U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[1U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[2U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[3U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[4U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[5U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[6U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[7U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_has_data = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_addr = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_param = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_source = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__grant_sink = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__dealloc_source_id = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[0U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[1U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[2U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[3U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[4U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[5U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[6U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_data[7U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_error = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_addr = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_permissions = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_opcode = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_param = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_size = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_source = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_address = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_data = 0ULL;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_mask = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__b_ready = 1U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_opcode = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_param = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_size = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_source = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_address = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_data = 0ULL;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_error = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__e_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__e_sink = 0U;
    }
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__b_ready 
            = ((7U != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state)) 
               & (8U != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state)));
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__e_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_valid = 0U;
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
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_addr 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_addr_array[3U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_req_type 
                        = (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                 >> 9U));
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_permissions 
                        = (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_permissions_array) 
                                 >> 9U));
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[0U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x18U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[1U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x19U];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[2U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x1aU];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[3U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x1bU];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[4U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x1cU];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[5U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x1dU];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[6U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x1eU];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[7U] 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_data_array[0x1fU];
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id 
                        = ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__allocated_source_id_valid)
                            ? (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__allocated_source_id)
                            : (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id));
                    __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_has_data 
                        = (2U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_type_array) 
                                        >> 9U)));
                }
            } else {
                if ((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_valid = 1U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_opcode = 6U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_param 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_permissions;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_size = 5U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_source 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_address 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_addr;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_data = 0ULL;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_mask = 0xffU;
                } else {
                    if ((2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) {
                        if (((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                               >> 3U) & ((4U == (7U 
                                                 & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                    >> 9U))) 
                                         | (5U == (7U 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                      >> 9U))))) 
                             & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                         >> 0xcU)) 
                                == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                            __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__grant_sink 
                                = (0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_sink) 
                                           >> 0xcU));
                            if ((5U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                              >> 9U)))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_valid = 1U;
                                VL_EXTEND_WQ(256,64, __Vtemp26, 
                                             (((QData)((IData)(
                                                               vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[7U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[6U]))));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[0U] 
                                    = __Vtemp26[0U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[1U] 
                                    = __Vtemp26[1U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[2U] 
                                    = __Vtemp26[2U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[3U] 
                                    = __Vtemp26[3U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[4U] 
                                    = __Vtemp26[4U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[5U] 
                                    = __Vtemp26[5U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[6U] 
                                    = __Vtemp26[6U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[7U] 
                                    = __Vtemp26[7U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_error 
                                    = (1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_error) 
                                             >> 3U));
                            }
                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__dealloc_source_id 
                                = (0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                           >> 0xcU));
                        }
                    } else {
                        if ((3U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) {
                            vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__e_valid = 1U;
                            vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__e_sink 
                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__grant_sink;
                        } else {
                            if ((4U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_valid = 1U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_opcode 
                                    = ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_has_data)
                                        ? 7U : 6U);
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_param 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_permissions;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_size = 5U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_source 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_address 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_addr;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_error = 0U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_data 
                                    = ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_has_data)
                                        ? (((QData)((IData)(
                                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[1U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[0U])))
                                        : 0ULL);
                            } else {
                                if ((5U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) {
                                    if (((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                                           >> 3U) & 
                                          (6U == (7U 
                                                  & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                     >> 9U)))) 
                                         & ((0xfU & 
                                             ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                              >> 0xcU)) 
                                            == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__dealloc_source_id 
                                            = (0xfU 
                                               & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                                  >> 0xcU));
                                    }
                                } else {
                                    if ((6U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) {
                                        if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid) 
                                              >> 3U) 
                                             & (6U 
                                                == 
                                                (7U 
                                                 & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode) 
                                                    >> 9U))))) {
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_addr 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address[3U];
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_param 
                                                = (7U 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param) 
                                                      >> 9U));
                                            __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_source 
                                                = (0xfU 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_source) 
                                                      >> 0xcU));
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_valid = 1U;
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_addr 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address[3U];
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_permissions 
                                                = (7U 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param) 
                                                      >> 9U));
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
                if ((8U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_valid_array))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_valid = 1U;
                    if (((0U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_permissions_array) 
                                       >> 9U))) | (1U 
                                                   == 
                                                   (7U 
                                                    & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_permissions_array) 
                                                       >> 9U))))) {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_opcode = 5U;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_data 
                            = (((QData)((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x19U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_dirty_data_array[0x18U])));
                    } else {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_opcode = 4U;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_data = 0ULL;
                    }
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_param 
                        = (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_permissions_array) 
                                 >> 9U));
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_size = 5U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_source 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_source;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_address 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_ack_addr_array[3U];
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_error = 0U;
                }
            } else {
                if ((9U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_valid = 1U;
                    if ((3U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_req_type))) {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_opcode = 4U;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_data = 0ULL;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_mask = 0xffU;
                    } else {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_opcode = 0U;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_data 
                            = (((QData)((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[1U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[0U])));
                        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_mask = 0xffU;
                    }
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_param = 0U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_size = 5U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_source 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_address 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_addr;
                } else {
                    if ((0xaU == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state))) {
                        if (((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                               >> 3U) & ((0U == (7U 
                                                 & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                    >> 9U))) 
                                         | (1U == (7U 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                                      >> 9U))))) 
                             & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                         >> 0xcU)) 
                                == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id)))) {
                            if ((1U == (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode) 
                                              >> 9U)))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_valid = 1U;
                                VL_EXTEND_WQ(256,64, __Vtemp27, 
                                             (((QData)((IData)(
                                                               vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[7U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[6U]))));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[0U] 
                                    = __Vtemp27[0U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[1U] 
                                    = __Vtemp27[1U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[2U] 
                                    = __Vtemp27[2U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[3U] 
                                    = __Vtemp27[3U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[4U] 
                                    = __Vtemp27[4U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[5U] 
                                    = __Vtemp27[5U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[6U] 
                                    = __Vtemp27[6U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[7U] 
                                    = __Vtemp27[7U];
                                vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_error 
                                    = (1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_error) 
                                             >> 3U));
                            }
                            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__dealloc_source_id 
                                = (0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source) 
                                           >> 0xcU));
                        }
                    }
                }
            }
        }
    } else {
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_addr = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_req_type = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_permissions = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[0U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[1U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[2U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[3U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[4U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[5U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[6U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[7U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_has_data = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_addr = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_param = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_source = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__grant_sink = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__dealloc_source_id = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[0U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[1U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[2U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[3U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[4U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[5U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[6U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_data[7U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_error = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_addr = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_permissions = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_opcode = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_param = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_size = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_source = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_address = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_data = 0ULL;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_mask = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__b_ready = 1U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_opcode = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_param = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_size = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_source = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_address = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_data = 0ULL;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_error = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__e_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__e_sink = 0U;
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__state 
        = ((IData)(vlTOPp->tidc_system_tb__DOT__rst_n)
            ? (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__directory_inst__DOT__next_state)
            : 0U);
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_addr 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_addr;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_req_type 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_req_type;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_permissions 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_permissions;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[0U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[0U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[1U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[1U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[2U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[2U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[3U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[3U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[4U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[4U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[5U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[5U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[6U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[6U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[7U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_data[7U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_has_data 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_has_data;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__grant_sink 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__grant_sink;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_source 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__probe_source;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__pending_source_id;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_addr 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_addr;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_req_type 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_req_type;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_permissions 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_permissions;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[0U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[0U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[1U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[1U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[2U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[2U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[3U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[3U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[4U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[4U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[5U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[5U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[6U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[6U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[7U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_data[7U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_has_data 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_has_data;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__grant_sink 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__grant_sink;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_source 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__probe_source;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__pending_source_id;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_addr 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_addr;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_req_type 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_req_type;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_permissions 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_permissions;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[0U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[0U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[1U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[1U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[2U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[2U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[3U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[3U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[4U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[4U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[5U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[5U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[6U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[6U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[7U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_data[7U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_has_data 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_has_data;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__grant_sink 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__grant_sink;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_source 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__probe_source;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__pending_source_id;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_addr 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_addr;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_req_type 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_req_type;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_permissions 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_permissions;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[0U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[0U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[1U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[1U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[2U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[2U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[3U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[3U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[4U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[4U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[5U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[5U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[6U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[6U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[7U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_data[7U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_has_data 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_has_data;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__grant_sink 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__grant_sink;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_source 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__probe_source;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__pending_source_id;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__b_ready 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_ready)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__b_ready));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_valid));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_size = 
        ((0xfff0U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_size)) 
         | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_size));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_mask = 
        ((0xffffff00U & vlTOPp->tidc_system_tb__DOT__dut__DOT__a_mask) 
         | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_mask));
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
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__data_to_l1_error));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_size = 
        ((0xfff0U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_size)) 
         | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_size));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_error 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_error)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_error));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_addr_array[0U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_addr;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array 
        = ((0xff8U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_permissions));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__probe_req_to_l1_valid));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_valid));
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r) 
              & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array)) 
             & (0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state)))) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__allocated_source_id 
                = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
        }
    } else {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__allocated_source_id = 0U;
    }
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r) 
              & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array)) 
             & (0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state)))) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__allocated_source_id_valid = 1U;
        } else {
            if (vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__dealloc_source_id_req) {
                vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__allocated_source_id_valid = 0U;
            }
        }
    } else {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__allocated_source_id_valid = 0U;
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__b_ready 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_ready)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__b_ready) 
              << 1U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_valid) 
              << 1U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_size = 
        ((0xff0fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_size)) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_size) 
            << 4U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_mask = 
        ((0xffff00ffU & vlTOPp->tidc_system_tb__DOT__dut__DOT__a_mask) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_mask) 
            << 8U));
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
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__data_to_l1_error) 
              << 1U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_size = 
        ((0xff0fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_size)) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_size) 
            << 4U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_error 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_error)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_error) 
              << 1U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_addr_array[1U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_addr;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array 
        = ((0xfc7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_permissions) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__probe_req_to_l1_valid) 
              << 1U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_valid) 
              << 1U));
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r) 
              & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array) 
                 >> 1U)) & (0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state)))) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__allocated_source_id 
                = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
        }
    } else {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__allocated_source_id = 0U;
    }
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r) 
              & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array) 
                 >> 1U)) & (0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state)))) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__allocated_source_id_valid = 1U;
        } else {
            if (vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__dealloc_source_id_req) {
                vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__allocated_source_id_valid = 0U;
            }
        }
    } else {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__allocated_source_id_valid = 0U;
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__b_ready 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_ready)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__b_ready) 
              << 2U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_valid) 
              << 2U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_size = 
        ((0xf0ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_size)) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_size) 
            << 8U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_mask = 
        ((0xff00ffffU & vlTOPp->tidc_system_tb__DOT__dut__DOT__a_mask) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_mask) 
            << 0x10U));
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
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__data_to_l1_error) 
              << 2U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_size = 
        ((0xf0ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_size)) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_size) 
            << 8U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_error 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_error)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_error) 
              << 2U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_addr_array[2U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_addr;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array 
        = ((0xe3fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_permissions) 
              << 6U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__probe_req_to_l1_valid) 
              << 2U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_valid) 
              << 2U));
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r) 
              & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array) 
                 >> 2U)) & (0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state)))) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__allocated_source_id 
                = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
        }
    } else {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__allocated_source_id = 0U;
    }
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r) 
              & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array) 
                 >> 2U)) & (0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state)))) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__allocated_source_id_valid = 1U;
        } else {
            if (vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__dealloc_source_id_req) {
                vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__allocated_source_id_valid = 0U;
            }
        }
    } else {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__allocated_source_id_valid = 0U;
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__b_ready 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_ready)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__b_ready) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_valid_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_valid) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_size = 
        ((0xfffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_size)) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_size) 
            << 0xcU));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_mask = 
        ((0xffffffU & vlTOPp->tidc_system_tb__DOT__dut__DOT__a_mask) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_mask) 
            << 0x18U));
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
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_data_error_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__data_to_l1_error) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_size = 
        ((0xfffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_size)) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_size) 
            << 0xcU));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_error 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_error)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_error) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_addr_array[3U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_addr;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array 
        = ((0x1ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_permissions_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_permissions) 
              << 9U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_probe_req_valid_array)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__probe_req_to_l1_valid) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_valid) 
              << 3U));
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r) 
              & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array) 
                 >> 3U)) & (0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state)))) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__allocated_source_id 
                = vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
        }
    } else {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__allocated_source_id = 0U;
    }
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r) 
              & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array) 
                 >> 3U)) & (0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state)))) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__allocated_source_id_valid = 1U;
        } else {
            if (vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__dealloc_source_id_req) {
                vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__allocated_source_id_valid = 0U;
            }
        }
    } else {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__allocated_source_id_valid = 0U;
    }
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_req = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_req = 0U;
        vlTOPp->tidc_system_tb__DOT__l2_cmd_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid = 0U;
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
                    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id;
                    if ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel))) {
                        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr 
                            = (((0U == (0x1fU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                 << 5U)))
                                 ? 0U : (vlTOPp->tidc_system_tb__DOT__dut__DOT__a_address[
                                         ((IData)(1U) 
                                          + (3U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id)))] 
                                         << ((IData)(0x20U) 
                                             - (0x1fU 
                                                & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                   << 5U))))) 
                               | (vlTOPp->tidc_system_tb__DOT__dut__DOT__a_address[
                                  (3U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id))] 
                                  >> (0x1fU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                               << 5U))));
                        if ((0xbU >= (0xfU & ((IData)(3U) 
                                              * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id))))) {
                            __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode 
                                = (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_opcode) 
                                         >> (0xfU & 
                                             ((IData)(3U) 
                                              * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id)))));
                            __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param 
                                = (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_param) 
                                         >> (0xfU & 
                                             ((IData)(3U) 
                                              * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id)))));
                        } else {
                            __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode = 0U;
                            __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param = 0U;
                        }
                        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_source 
                            = (0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_source) 
                                       >> (0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                   << 2U))));
                        VL_EXTEND_WQ(256,64, __Vtemp28, 
                                     (((0U == (0x1fU 
                                               & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                  << 6U)))
                                        ? 0ULL : ((QData)((IData)(
                                                                  vlTOPp->tidc_system_tb__DOT__dut__DOT__a_data[
                                                                  ((IData)(2U) 
                                                                   + 
                                                                   (6U 
                                                                    & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                                       << 1U)))])) 
                                                  << 
                                                  ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                       << 6U))))) 
                                      | (((QData)((IData)(
                                                          vlTOPp->tidc_system_tb__DOT__dut__DOT__a_data[
                                                          ((IData)(1U) 
                                                           + 
                                                           (6U 
                                                            & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                               << 1U)))])) 
                                          << ((0U == 
                                               (0x1fU 
                                                & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                   << 6U)))
                                               ? 0x20U
                                               : ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                      << 6U))))) 
                                         | ((QData)((IData)(
                                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__a_data[
                                                            (6U 
                                                             & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                                << 1U))])) 
                                            >> (0x1fU 
                                                & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                   << 6U))))));
                        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[0U] 
                            = __Vtemp28[0U];
                        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[1U] 
                            = __Vtemp28[1U];
                        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[2U] 
                            = __Vtemp28[2U];
                        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[3U] 
                            = __Vtemp28[3U];
                        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[4U] 
                            = __Vtemp28[4U];
                        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[5U] 
                            = __Vtemp28[5U];
                        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[6U] 
                            = __Vtemp28[6U];
                        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[7U] 
                            = __Vtemp28[7U];
                    } else {
                        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr 
                            = (((0U == (0x1fU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                 << 5U)))
                                 ? 0U : (vlTOPp->tidc_system_tb__DOT__dut__DOT__c_address[
                                         ((IData)(1U) 
                                          + (3U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id)))] 
                                         << ((IData)(0x20U) 
                                             - (0x1fU 
                                                & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                   << 5U))))) 
                               | (vlTOPp->tidc_system_tb__DOT__dut__DOT__c_address[
                                  (3U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id))] 
                                  >> (0x1fU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                               << 5U))));
                        if ((0xbU >= (0xfU & ((IData)(3U) 
                                              * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id))))) {
                            __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode 
                                = (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode) 
                                         >> (0xfU & 
                                             ((IData)(3U) 
                                              * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id)))));
                            __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param 
                                = (7U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_param) 
                                         >> (0xfU & 
                                             ((IData)(3U) 
                                              * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id)))));
                        } else {
                            __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode = 0U;
                            __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param = 0U;
                        }
                        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_source 
                            = (0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_source) 
                                       >> (0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                   << 2U))));
                        VL_EXTEND_WQ(256,64, __Vtemp29, 
                                     (((0U == (0x1fU 
                                               & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                  << 6U)))
                                        ? 0ULL : ((QData)((IData)(
                                                                  vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[
                                                                  ((IData)(2U) 
                                                                   + 
                                                                   (6U 
                                                                    & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                                       << 1U)))])) 
                                                  << 
                                                  ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                       << 6U))))) 
                                      | (((QData)((IData)(
                                                          vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[
                                                          ((IData)(1U) 
                                                           + 
                                                           (6U 
                                                            & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                               << 1U)))])) 
                                          << ((0U == 
                                               (0x1fU 
                                                & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                   << 6U)))
                                               ? 0x20U
                                               : ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                      << 6U))))) 
                                         | ((QData)((IData)(
                                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[
                                                            (6U 
                                                             & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                                << 1U))])) 
                                            >> (0x1fU 
                                                & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_id) 
                                                   << 6U))))));
                        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[0U] 
                            = __Vtemp29[0U];
                        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[1U] 
                            = __Vtemp29[1U];
                        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[2U] 
                            = __Vtemp29[2U];
                        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[3U] 
                            = __Vtemp29[3U];
                        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[4U] 
                            = __Vtemp29[4U];
                        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[5U] 
                            = __Vtemp29[5U];
                        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[6U] 
                            = __Vtemp29[6U];
                        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[7U] 
                            = __Vtemp29[7U];
                    }
                }
            } else {
                if ((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_req = 1U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_addr 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr;
                } else {
                    if ((2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) {
                        if (vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_valid) {
                            if (((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param)) 
                                 | (2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param)))) {
                                if (((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_state)) 
                                     | (2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_state)))) {
                                    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent 
                                        = ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_presence) 
                                           & (~ ((IData)(1U) 
                                                 << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))));
                                    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked = 0U;
                                } else {
                                    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent = 0U;
                                    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked = 0U;
                                }
                            } else {
                                __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent = 0U;
                                __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked = 0U;
                            }
                        }
                    } else {
                        if ((3U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) {
                            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__i = 4U;
                            if ((1U & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent) 
                                       & (~ (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked))))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound2 
                                    = (((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param)) 
                                        | (2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param)))
                                        ? 0U : 1U);
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid 
                                    = (1U | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode 
                                    = (6U | (0xff8U 
                                             & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode)));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param 
                                    = ((0xff8U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param)) 
                                       | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound2));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_size 
                                    = (5U | (0xfff0U 
                                             & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_size)));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_source 
                                    = ((0xfff0U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_source)) 
                                       | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_source));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address[0U] 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[0U] = 0U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[1U] = 0U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_mask 
                                    = (0xffU | vlTOPp->tidc_system_tb__DOT__dut__DOT__b_mask);
                            }
                            if ((1U & (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent) 
                                        >> 1U) & (~ 
                                                  ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked) 
                                                   >> 1U))))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound2 
                                    = (((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param)) 
                                        | (2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param)))
                                        ? 0U : 1U);
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid 
                                    = (2U | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode 
                                    = (0x30U | (0xfc7U 
                                                & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode)));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param 
                                    = ((0xfc7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param)) 
                                       | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound2) 
                                          << 3U));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_size 
                                    = (0x50U | (0xff0fU 
                                                & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_size)));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_source 
                                    = ((0xff0fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_source)) 
                                       | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_source) 
                                          << 4U));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address[1U] 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[2U] = 0U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[3U] = 0U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_mask 
                                    = (0xff00U | vlTOPp->tidc_system_tb__DOT__dut__DOT__b_mask);
                            }
                            if ((1U & (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent) 
                                        >> 2U) & (~ 
                                                  ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked) 
                                                   >> 2U))))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound2 
                                    = (((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param)) 
                                        | (2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param)))
                                        ? 0U : 1U);
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid 
                                    = (4U | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode 
                                    = (0x180U | (0xe3fU 
                                                 & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode)));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param 
                                    = ((0xe3fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param)) 
                                       | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound2) 
                                          << 6U));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_size 
                                    = (0x500U | (0xf0ffU 
                                                 & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_size)));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_source 
                                    = ((0xf0ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_source)) 
                                       | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_source) 
                                          << 8U));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address[2U] 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[4U] = 0U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[5U] = 0U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_mask 
                                    = (0xff0000U | vlTOPp->tidc_system_tb__DOT__dut__DOT__b_mask);
                            }
                            if ((1U & (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent) 
                                        >> 3U) & (~ 
                                                  ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked) 
                                                   >> 3U))))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound2 
                                    = (((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param)) 
                                        | (2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param)))
                                        ? 0U : 1U);
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid 
                                    = (8U | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode 
                                    = (0xc00U | (0x1ffU 
                                                 & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode)));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param 
                                    = ((0x1ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param)) 
                                       | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound2) 
                                          << 9U));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_size 
                                    = (0x5000U | (0xfffU 
                                                  & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_size)));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_source 
                                    = ((0xfffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__b_source)) 
                                       | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_source) 
                                          << 0xcU));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address[3U] 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[6U] = 0U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[7U] = 0U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__b_mask 
                                    = (0xff000000U 
                                       | vlTOPp->tidc_system_tb__DOT__dut__DOT__b_mask);
                            }
                        } else {
                            if ((4U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) {
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__j = 4U;
                                if (((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid) 
                                       & ((4U == (7U 
                                                  & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode))) 
                                          | (5U == 
                                             (7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode))))) 
                                      & (vlTOPp->tidc_system_tb__DOT__dut__DOT__c_address[0U] 
                                         == vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr)) 
                                     & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent))) {
                                    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked 
                                        = (1U | (IData)(__Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked));
                                    if ((5U == (7U 
                                                & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode)))) {
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_valid = 1U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_type = 3U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_addr 
                                            = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr;
                                        VL_EXTEND_WQ(256,64, __Vtemp30, 
                                                     (((QData)((IData)(
                                                                       vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[1U])) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(
                                                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[0U]))));
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[0U] 
                                            = __Vtemp30[0U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[1U] 
                                            = __Vtemp30[1U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[2U] 
                                            = __Vtemp30[2U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[3U] 
                                            = __Vtemp30[3U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[4U] 
                                            = __Vtemp30[4U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[5U] 
                                            = __Vtemp30[5U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[6U] 
                                            = __Vtemp30[6U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[7U] 
                                            = __Vtemp30[7U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_size = 5U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_dirty = 1U;
                                    }
                                }
                                if ((((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid) 
                                        >> 1U) & ((4U 
                                                   == 
                                                   (7U 
                                                    & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode) 
                                                       >> 3U))) 
                                                  | (5U 
                                                     == 
                                                     (7U 
                                                      & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode) 
                                                         >> 3U))))) 
                                      & (vlTOPp->tidc_system_tb__DOT__dut__DOT__c_address[1U] 
                                         == vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr)) 
                                     & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent) 
                                        >> 1U))) {
                                    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked 
                                        = (2U | (IData)(__Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked));
                                    if ((5U == (7U 
                                                & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode) 
                                                   >> 3U)))) {
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_valid = 1U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_type = 3U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_addr 
                                            = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr;
                                        VL_EXTEND_WQ(256,64, __Vtemp31, 
                                                     (((QData)((IData)(
                                                                       vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[3U])) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(
                                                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[2U]))));
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[0U] 
                                            = __Vtemp31[0U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[1U] 
                                            = __Vtemp31[1U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[2U] 
                                            = __Vtemp31[2U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[3U] 
                                            = __Vtemp31[3U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[4U] 
                                            = __Vtemp31[4U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[5U] 
                                            = __Vtemp31[5U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[6U] 
                                            = __Vtemp31[6U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[7U] 
                                            = __Vtemp31[7U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_size = 5U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_dirty = 1U;
                                    }
                                }
                                if ((((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid) 
                                        >> 2U) & ((4U 
                                                   == 
                                                   (7U 
                                                    & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode) 
                                                       >> 6U))) 
                                                  | (5U 
                                                     == 
                                                     (7U 
                                                      & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode) 
                                                         >> 6U))))) 
                                      & (vlTOPp->tidc_system_tb__DOT__dut__DOT__c_address[2U] 
                                         == vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr)) 
                                     & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent) 
                                        >> 2U))) {
                                    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked 
                                        = (4U | (IData)(__Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked));
                                    if ((5U == (7U 
                                                & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode) 
                                                   >> 6U)))) {
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_valid = 1U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_type = 3U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_addr 
                                            = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr;
                                        VL_EXTEND_WQ(256,64, __Vtemp32, 
                                                     (((QData)((IData)(
                                                                       vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[5U])) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(
                                                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[4U]))));
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[0U] 
                                            = __Vtemp32[0U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[1U] 
                                            = __Vtemp32[1U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[2U] 
                                            = __Vtemp32[2U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[3U] 
                                            = __Vtemp32[3U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[4U] 
                                            = __Vtemp32[4U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[5U] 
                                            = __Vtemp32[5U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[6U] 
                                            = __Vtemp32[6U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[7U] 
                                            = __Vtemp32[7U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_size = 5U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_dirty = 1U;
                                    }
                                }
                                if ((((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid) 
                                        >> 3U) & ((4U 
                                                   == 
                                                   (7U 
                                                    & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode) 
                                                       >> 9U))) 
                                                  | (5U 
                                                     == 
                                                     (7U 
                                                      & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode) 
                                                         >> 9U))))) 
                                      & (vlTOPp->tidc_system_tb__DOT__dut__DOT__c_address[3U] 
                                         == vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr)) 
                                     & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent) 
                                        >> 3U))) {
                                    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked 
                                        = (8U | (IData)(__Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked));
                                    if ((5U == (7U 
                                                & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode) 
                                                   >> 9U)))) {
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_valid = 1U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_type = 3U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_addr 
                                            = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr;
                                        VL_EXTEND_WQ(256,64, __Vtemp33, 
                                                     (((QData)((IData)(
                                                                       vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[7U])) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(
                                                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[6U]))));
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[0U] 
                                            = __Vtemp33[0U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[1U] 
                                            = __Vtemp33[1U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[2U] 
                                            = __Vtemp33[2U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[3U] 
                                            = __Vtemp33[3U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[4U] 
                                            = __Vtemp33[4U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[5U] 
                                            = __Vtemp33[5U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[6U] 
                                            = __Vtemp33[6U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[7U] 
                                            = __Vtemp33[7U];
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_size = 5U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_dirty = 1U;
                                    }
                                }
                            } else {
                                if ((5U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) {
                                    if ((6U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode))) {
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_valid = 1U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_type = 0U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_addr 
                                            = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[0U] = 0U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[1U] = 0U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[2U] = 0U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[3U] = 0U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[4U] = 0U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[5U] = 0U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[6U] = 0U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[7U] = 0U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_size = 5U;
                                        vlTOPp->tidc_system_tb__DOT__l2_cmd_dirty = 0U;
                                    }
                                } else {
                                    if ((6U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) {
                                        if (((IData)(vlTOPp->tidc_system_tb__DOT__l2_response_valid) 
                                             & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__alloc_gnt_r))) {
                                            __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_sink 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id;
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid 
                                                = ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                                                   | ((IData)(1U) 
                                                      << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id)));
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound3 = 5U;
                                            if ((0xbU 
                                                 >= 
                                                 (0xfU 
                                                  & ((IData)(3U) 
                                                     * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))))) {
                                                vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode 
                                                    = 
                                                    (((~ 
                                                       ((IData)(7U) 
                                                        << 
                                                        (0xfU 
                                                         & ((IData)(3U) 
                                                            * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))))) 
                                                      & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode)) 
                                                     | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound3) 
                                                        << 
                                                        (0xfU 
                                                         & ((IData)(3U) 
                                                            * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id)))));
                                            }
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound4 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param;
                                            if ((0xbU 
                                                 >= 
                                                 (0xfU 
                                                  & ((IData)(3U) 
                                                     * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))))) {
                                                vlTOPp->tidc_system_tb__DOT__dut__DOT__d_param 
                                                    = 
                                                    (((~ 
                                                       ((IData)(7U) 
                                                        << 
                                                        (0xfU 
                                                         & ((IData)(3U) 
                                                            * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))))) 
                                                      & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_param)) 
                                                     | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound4) 
                                                        << 
                                                        (0xfU 
                                                         & ((IData)(3U) 
                                                            * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id)))));
                                            }
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__d_size 
                                                = (
                                                   ((~ 
                                                     ((IData)(0xfU) 
                                                      << 
                                                      (0xfU 
                                                       & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                                          << 2U)))) 
                                                    & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_size)) 
                                                   | ((IData)(5U) 
                                                      << 
                                                      (0xfU 
                                                       & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                                          << 2U))));
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source 
                                                = (
                                                   ((~ 
                                                     ((IData)(0xfU) 
                                                      << 
                                                      (0xfU 
                                                       & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                                          << 2U)))) 
                                                    & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source)) 
                                                   | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_source) 
                                                      << 
                                                      (0xfU 
                                                       & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                                          << 2U))));
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__d_sink 
                                                = (
                                                   ((~ 
                                                     ((IData)(0xfU) 
                                                      << 
                                                      (0xfU 
                                                       & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                                          << 2U)))) 
                                                    & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_sink)) 
                                                   | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id) 
                                                      << 
                                                      (0xfU 
                                                       & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                                          << 2U))));
                                            VL_ASSIGNSEL_WIIQ(64,
                                                              (0xffU 
                                                               & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                                                  << 6U)), vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data, 
                                                              (((QData)((IData)(
                                                                                vlTOPp->tidc_system_tb__DOT__l2_response_data[1U])) 
                                                                << 0x20U) 
                                                               | (QData)((IData)(
                                                                                vlTOPp->tidc_system_tb__DOT__l2_response_data[0U]))));
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__d_error 
                                                = (
                                                   ((~ 
                                                     ((IData)(1U) 
                                                      << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))) 
                                                    & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_error)) 
                                                   | ((IData)(vlTOPp->tidc_system_tb__DOT__l2_response_error) 
                                                      << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id)));
                                        }
                                    } else {
                                        if ((7U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode))) {
                                            vlTOPp->tidc_system_tb__DOT__l2_cmd_valid = 1U;
                                            vlTOPp->tidc_system_tb__DOT__l2_cmd_type = 3U;
                                            vlTOPp->tidc_system_tb__DOT__l2_cmd_addr 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr;
                                            vlTOPp->tidc_system_tb__DOT__l2_cmd_data[0U] 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[0U];
                                            vlTOPp->tidc_system_tb__DOT__l2_cmd_data[1U] 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[1U];
                                            vlTOPp->tidc_system_tb__DOT__l2_cmd_data[2U] 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[2U];
                                            vlTOPp->tidc_system_tb__DOT__l2_cmd_data[3U] 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[3U];
                                            vlTOPp->tidc_system_tb__DOT__l2_cmd_data[4U] 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[4U];
                                            vlTOPp->tidc_system_tb__DOT__l2_cmd_data[5U] 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[5U];
                                            vlTOPp->tidc_system_tb__DOT__l2_cmd_data[6U] 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[6U];
                                            vlTOPp->tidc_system_tb__DOT__l2_cmd_data[7U] 
                                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[7U];
                                            vlTOPp->tidc_system_tb__DOT__l2_cmd_size = 5U;
                                            vlTOPp->tidc_system_tb__DOT__l2_cmd_dirty = 1U;
                                        }
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_req = 1U;
                                        if (((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param)) 
                                             | (2U 
                                                == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param)))) {
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_presence 
                                                = ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_presence) 
                                                   & (~ 
                                                      ((IData)(1U) 
                                                       << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))));
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_tip_state 
                                                = ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_tip_state) 
                                                   & (~ 
                                                      ((IData)(1U) 
                                                       << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))));
                                            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_state 
                                                = (
                                                   (0U 
                                                    == 
                                                    ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_presence) 
                                                     & (~ 
                                                        ((IData)(1U) 
                                                         << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id)))))
                                                    ? 0U
                                                    : 
                                                   ((0U 
                                                     != 
                                                     ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_tip_state) 
                                                      & (~ 
                                                         ((IData)(1U) 
                                                          << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id)))))
                                                     ? 2U
                                                     : 1U));
                                        }
                                        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_addr 
                                            = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((8U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) {
                vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid 
                    = ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                       | ((IData)(1U) << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id)));
                vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound5 = 6U;
                if ((0xbU >= (0xfU & ((IData)(3U) * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode 
                        = (((~ ((IData)(7U) << (0xfU 
                                                & ((IData)(3U) 
                                                   * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))))) 
                            & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode)) 
                           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound5) 
                              << (0xfU & ((IData)(3U) 
                                          * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id)))));
                }
                vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound6 = 0U;
                if ((0xbU >= (0xfU & ((IData)(3U) * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__d_param 
                        = (((~ ((IData)(7U) << (0xfU 
                                                & ((IData)(3U) 
                                                   * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))))) 
                            & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_param)) 
                           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound6) 
                              << (0xfU & ((IData)(3U) 
                                          * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id)))));
                }
                vlTOPp->tidc_system_tb__DOT__dut__DOT__d_size 
                    = (((~ ((IData)(0xfU) << (0xfU 
                                              & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                                 << 2U)))) 
                        & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_size)) 
                       | ((IData)(5U) << (0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                                  << 2U))));
                vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source 
                    = (((~ ((IData)(0xfU) << (0xfU 
                                              & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                                 << 2U)))) 
                        & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source)) 
                       | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_source) 
                          << (0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                      << 2U))));
                vlTOPp->tidc_system_tb__DOT__dut__DOT__d_sink 
                    = ((~ ((IData)(0xfU) << (0xfU & 
                                             ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                              << 2U)))) 
                       & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_sink));
                VL_ASSIGNSEL_WIIQ(64,(0xffU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                               << 6U)), vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data, 0ULL);
                vlTOPp->tidc_system_tb__DOT__dut__DOT__d_error 
                    = ((~ ((IData)(1U) << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))) 
                       & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_error));
            } else {
                if ((9U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) {
                    if ((((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid) 
                          >> (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id)) 
                         & ((0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink) 
                                     >> (0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                                 << 2U)))) 
                            == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_sink)))) {
                        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_req = 1U;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_addr 
                            = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr;
                        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_presence 
                            = (0xfU & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_presence) 
                                       | ((IData)(1U) 
                                          << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))));
                        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_dealloc_sink_id 
                            = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_sink;
                        if (((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param)) 
                             | (2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param)))) {
                            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_tip_state 
                                = (0xfU & ((IData)(1U) 
                                           << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id)));
                            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_state = 2U;
                        } else {
                            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_tip_state 
                                = ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_tip_state) 
                                   & (~ ((IData)(1U) 
                                         << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))));
                            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_state = 1U;
                        }
                    }
                } else {
                    if ((0xaU == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state))) {
                        if ((4U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode))) {
                            vlTOPp->tidc_system_tb__DOT__l2_cmd_valid = 1U;
                            vlTOPp->tidc_system_tb__DOT__l2_cmd_type = 0U;
                            vlTOPp->tidc_system_tb__DOT__l2_cmd_addr 
                                = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr;
                            vlTOPp->tidc_system_tb__DOT__l2_cmd_data[0U] = 0U;
                            vlTOPp->tidc_system_tb__DOT__l2_cmd_data[1U] = 0U;
                            vlTOPp->tidc_system_tb__DOT__l2_cmd_data[2U] = 0U;
                            vlTOPp->tidc_system_tb__DOT__l2_cmd_data[3U] = 0U;
                            vlTOPp->tidc_system_tb__DOT__l2_cmd_data[4U] = 0U;
                            vlTOPp->tidc_system_tb__DOT__l2_cmd_data[5U] = 0U;
                            vlTOPp->tidc_system_tb__DOT__l2_cmd_data[6U] = 0U;
                            vlTOPp->tidc_system_tb__DOT__l2_cmd_data[7U] = 0U;
                            vlTOPp->tidc_system_tb__DOT__l2_cmd_size = 5U;
                            vlTOPp->tidc_system_tb__DOT__l2_cmd_dirty = 0U;
                        } else {
                            if ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode))) {
                                vlTOPp->tidc_system_tb__DOT__l2_cmd_valid = 1U;
                                vlTOPp->tidc_system_tb__DOT__l2_cmd_type = 1U;
                                vlTOPp->tidc_system_tb__DOT__l2_cmd_addr 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr;
                                vlTOPp->tidc_system_tb__DOT__l2_cmd_data[0U] 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[0U];
                                vlTOPp->tidc_system_tb__DOT__l2_cmd_data[1U] 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[1U];
                                vlTOPp->tidc_system_tb__DOT__l2_cmd_data[2U] 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[2U];
                                vlTOPp->tidc_system_tb__DOT__l2_cmd_data[3U] 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[3U];
                                vlTOPp->tidc_system_tb__DOT__l2_cmd_data[4U] 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[4U];
                                vlTOPp->tidc_system_tb__DOT__l2_cmd_data[5U] 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[5U];
                                vlTOPp->tidc_system_tb__DOT__l2_cmd_data[6U] 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[6U];
                                vlTOPp->tidc_system_tb__DOT__l2_cmd_data[7U] 
                                    = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[7U];
                                vlTOPp->tidc_system_tb__DOT__l2_cmd_size = 5U;
                                vlTOPp->tidc_system_tb__DOT__l2_cmd_dirty = 1U;
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid 
                                    = ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                                       | ((IData)(1U) 
                                          << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id)));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound7 = 0U;
                                if ((0xbU >= (0xfU 
                                              & ((IData)(3U) 
                                                 * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))))) {
                                    vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode 
                                        = (((~ ((IData)(7U) 
                                                << 
                                                (0xfU 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))))) 
                                            & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode)) 
                                           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound7) 
                                              << (0xfU 
                                                  & ((IData)(3U) 
                                                     * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id)))));
                                }
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound8 = 0U;
                                if ((0xbU >= (0xfU 
                                              & ((IData)(3U) 
                                                 * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))))) {
                                    vlTOPp->tidc_system_tb__DOT__dut__DOT__d_param 
                                        = (((~ ((IData)(7U) 
                                                << 
                                                (0xfU 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))))) 
                                            & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_param)) 
                                           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT____Vlvbound8) 
                                              << (0xfU 
                                                  & ((IData)(3U) 
                                                     * (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id)))));
                                }
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__d_size 
                                    = (((~ ((IData)(0xfU) 
                                            << (0xfU 
                                                & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                                   << 2U)))) 
                                        & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_size)) 
                                       | ((IData)(5U) 
                                          << (0xfU 
                                              & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                                 << 2U))));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source 
                                    = (((~ ((IData)(0xfU) 
                                            << (0xfU 
                                                & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                                   << 2U)))) 
                                        & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source)) 
                                       | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_source) 
                                          << (0xfU 
                                              & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                                 << 2U))));
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__d_sink 
                                    = ((~ ((IData)(0xfU) 
                                           << (0xfU 
                                               & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                                  << 2U)))) 
                                       & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_sink));
                                VL_ASSIGNSEL_WIIQ(64,
                                                  (0xffU 
                                                   & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id) 
                                                      << 6U)), vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data, 0ULL);
                                vlTOPp->tidc_system_tb__DOT__dut__DOT__d_error 
                                    = (((~ ((IData)(1U) 
                                            << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id))) 
                                        & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_error)) 
                                       | ((IData)(vlTOPp->tidc_system_tb__DOT__l2_response_error) 
                                          << (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id)));
                            }
                        }
                    }
                }
            }
        }
    } else {
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_source = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_sink = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[0U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[1U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[2U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[3U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[4U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[5U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[6U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[7U] = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent = 0U;
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_req = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_addr = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_req = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_addr = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_state = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_presence = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_update_tip_state = 0U;
        vlTOPp->tidc_system_tb__DOT__l2_cmd_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__l2_cmd_type = 0U;
        vlTOPp->tidc_system_tb__DOT__l2_cmd_addr = 0U;
        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[0U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[1U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[2U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[3U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[4U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[5U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[6U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l2_cmd_data[7U] = 0U;
        vlTOPp->tidc_system_tb__DOT__l2_cmd_size = 0U;
        vlTOPp->tidc_system_tb__DOT__l2_cmd_dirty = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__b_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__b_opcode = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__b_param = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__b_size = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__b_source = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address[0U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address[1U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address[2U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__b_address[3U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[0U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[1U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[2U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[3U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[4U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[5U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[6U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__b_data[7U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__b_mask = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__d_opcode = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__d_param = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__d_size = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__d_source = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__d_sink = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[0U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[1U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[2U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[3U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[4U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[5U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[6U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__d_data[7U] = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__d_error = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_dealloc_sink_id = 0U;
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_req_masked 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_req_masked)) 
           | (8U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid)));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__next_free_id;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_state 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_state;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_presence 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_presence;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_tip_state 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_tip_state;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_addr;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_param;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_source 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_source;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[0U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[0U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[1U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[1U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[2U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[2U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[3U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[3U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[4U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[4U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[5U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[5U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[6U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[6U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[7U] 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_data[7U];
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__next_free_id;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_valid 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__dir_lookup_valid;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_opcode;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_sent;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__probe_acked;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_sink 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_sink;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_address[0U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_address;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_address[1U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_address;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_address[2U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_address;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_address[3U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_address;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_opcode 
        = ((0xff8U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_opcode)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_opcode));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_opcode 
        = ((0xfc7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_opcode)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_opcode) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_opcode 
        = ((0xe3fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_opcode)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_opcode) 
              << 6U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_opcode 
        = ((0x1ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_opcode)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_opcode) 
              << 9U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_param 
        = ((0xff8U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_param)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_param));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_param 
        = ((0xfc7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_param)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_param) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_param 
        = ((0xe3fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_param)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_param) 
              << 6U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_param 
        = ((0x1ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_param)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_param) 
              << 9U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_source 
        = ((0xfff0U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_source)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_source));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_source 
        = ((0xff0fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_source)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_source) 
              << 4U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_source 
        = ((0xf0ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_source)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_source) 
              << 8U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_source 
        = ((0xfffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_source)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_source) 
              << 0xcU));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_data[0U] 
        = (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_data);
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_data[1U] 
        = (IData)((vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__a_data 
                   >> 0x20U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_data[2U] 
        = (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_data);
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_data[3U] 
        = (IData)((vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__a_data 
                   >> 0x20U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_data[4U] 
        = (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_data);
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_data[5U] 
        = (IData)((vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__a_data 
                   >> 0x20U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_data[6U] 
        = (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_data);
    vlTOPp->tidc_system_tb__DOT__dut__DOT__a_data[7U] 
        = (IData)((vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__a_data 
                   >> 0x20U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_address[0U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_address;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_address[1U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_address;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_address[2U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_address;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_address[3U] 
        = vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_address;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode 
        = ((0xff8U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_opcode));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode 
        = ((0xfc7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_opcode) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode 
        = ((0xe3fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_opcode) 
              << 6U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode 
        = ((0x1ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_opcode)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_opcode) 
              << 9U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_param 
        = ((0xff8U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_param)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_param));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_param 
        = ((0xfc7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_param)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_param) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_param 
        = ((0xe3fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_param)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_param) 
              << 6U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_param 
        = ((0x1ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_param)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_param) 
              << 9U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_source 
        = ((0xfff0U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_source)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_source));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_source 
        = ((0xff0fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_source)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_source) 
              << 4U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_source 
        = ((0xf0ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_source)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_source) 
              << 8U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_source 
        = ((0xfffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_source)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_source) 
              << 0xcU));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[0U] 
        = (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_data);
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[1U] 
        = (IData)((vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__c_data 
                   >> 0x20U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[2U] 
        = (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_data);
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[3U] 
        = (IData)((vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__c_data 
                   >> 0x20U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[4U] 
        = (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_data);
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[5U] 
        = (IData)((vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__c_data 
                   >> 0x20U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[6U] 
        = (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_data);
    vlTOPp->tidc_system_tb__DOT__dut__DOT__c_data[7U] 
        = (IData)((vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__c_data 
                   >> 0x20U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid)) 
           | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__e_valid));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid 
        = ((0xdU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__e_valid) 
              << 1U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid 
        = ((0xbU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__e_valid) 
              << 2U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid 
        = ((7U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_valid)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__e_valid) 
              << 3U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink = 
        ((0xfff0U & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink)) 
         | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__e_sink));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink = 
        ((0xff0fU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink)) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__e_sink) 
            << 4U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink = 
        ((0xf0ffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink)) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__e_sink) 
            << 8U));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink = 
        ((0xfffU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__e_sink)) 
         | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__e_sink) 
            << 0xcU));
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r = 0U;
        if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__alloc_source_id_req) 
             & (0xffffU != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use)))) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r = 1U;
        }
    } else {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r = 0U;
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state 
        = ((IData)(vlTOPp->tidc_system_tb__DOT__rst_n)
            ? (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__next_state)
            : 0U);
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r = 0U;
        if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__alloc_source_id_req) 
             & (0xffffU != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use)))) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r = 1U;
        }
    } else {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r = 0U;
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state 
        = ((IData)(vlTOPp->tidc_system_tb__DOT__rst_n)
            ? (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__next_state)
            : 0U);
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r = 0U;
        if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__alloc_source_id_req) 
             & (0xffffU != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use)))) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r = 1U;
        }
    } else {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r = 0U;
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state 
        = ((IData)(vlTOPp->tidc_system_tb__DOT__rst_n)
            ? (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__next_state)
            : 0U);
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r = 0U;
        if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__alloc_source_id_req) 
             & (0xffffU != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use)))) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r = 1U;
        }
    } else {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r = 0U;
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state 
        = ((IData)(vlTOPp->tidc_system_tb__DOT__rst_n)
            ? (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__next_state)
            : 0U);
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
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__alloc_gnt_r = 0U;
        if (((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_alloc_req) 
             & (0xffffU != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use)))) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__alloc_gnt_r = 1U;
        }
    } else {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__alloc_gnt_r = 0U;
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state 
        = ((IData)(vlTOPp->tidc_system_tb__DOT__rst_n)
            ? (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__next_state)
            : 0U);
    if (vlTOPp->tidc_system_tb__DOT__rst_n) {
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_valid = 0U;
        if ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__state))) {
            vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_busy = 0U;
            if ((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state))) {
                vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_busy = 1U;
                if ((0U != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid))) {
                    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel = 1U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_oh 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_selected_oh;
                } else {
                    __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel = 0U;
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_oh 
                        = vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_selected_oh;
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__state))) {
                vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_valid = 1U;
                if ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_rr_ptr 
                        = (3U & ((IData)(1U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_selected_id)));
                } else {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_rr_ptr 
                        = (3U & ((IData)(1U) + (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_selected_id)));
                }
            } else {
                if ((2U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__state))) {
                    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_busy = 1U;
                }
            }
        }
    } else {
        __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_busy = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_valid = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_master_oh = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_rr_ptr = 0U;
        vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__c_rr_ptr = 0U;
    }
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use;
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel 
        = __Vdly__tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__arb_channel;
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
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__any_id_available 
        = (0xffffU != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use));
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
    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__l1_request_ready 
        = ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__state)) 
           & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__allocated_source_id_valid) 
              | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__0__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r)));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__any_id_available 
        = (0xffffU != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use));
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
    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__l1_request_ready 
        = ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__state)) 
           & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__allocated_source_id_valid) 
              | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__1__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r)));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__any_id_available 
        = (0xffffU != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use));
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
    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__l1_request_ready 
        = ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__state)) 
           & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__allocated_source_id_valid) 
              | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__2__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r)));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__any_id_available 
        = (0xffffU != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__source_id_in_use));
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
    vlTOPp->tidc_system_tb__DOT__dut__DOT____Vcellout__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__l1_request_ready 
        = ((0U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__state)) 
           & ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__allocated_source_id_valid) 
              | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__gen_l1_instances__BRA__3__KET____DOT__l1_adapter__DOT__source_id_mgr__DOT__alloc_gnt_r)));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__any_id_available 
        = (0xffffU != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_mgr__DOT__sink_id_in_use));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_req_masked 
        = ((0xeU & (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_req_masked)) 
           | ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid) 
              & (0U >= (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__a_rr_ptr))));
}

VL_INLINE_OPT void Vtidc_system_tb::_sequent__TOP__4(Vtidc_system_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtidc_system_tb::_sequent__TOP__4\n"); );
    Vtidc_system_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__state 
        = ((IData)(vlTOPp->tidc_system_tb__DOT__rst_n)
            ? (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state)
            : 0U);
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
    vlTOPp->__Vtableidx1 = (((IData)((0U != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__c_valid))) 
                             << 3U) | (((IData)((0U 
                                                 != (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__a_valid))) 
                                        << 2U) | (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__state)));
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state 
        = vlTOPp->__Vtable1_tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__request_arbiter__DOT__next_state
        [vlTOPp->__Vtableidx1];
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
}

VL_INLINE_OPT void Vtidc_system_tb::_sequent__TOP__6(Vtidc_system_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtidc_system_tb::_sequent__TOP__6\n"); );
    Vtidc_system_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_permissions_array 
        = (((IData)(vlTOPp->tidc_system_tb__DOT__l1_3_request_permissions) 
            << 9U) | (((IData)(vlTOPp->tidc_system_tb__DOT__l1_2_request_permissions) 
                       << 6U) | (((IData)(vlTOPp->tidc_system_tb__DOT__l1_1_request_permissions) 
                                  << 3U) | (IData)(vlTOPp->tidc_system_tb__DOT__l1_0_request_permissions))));
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
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l1_request_valid_array 
        = (((IData)(vlTOPp->tidc_system_tb__DOT__l1_3_request_valid) 
            << 3U) | (((IData)(vlTOPp->tidc_system_tb__DOT__l1_2_request_valid) 
                       << 2U) | (((IData)(vlTOPp->tidc_system_tb__DOT__l1_1_request_valid) 
                                  << 1U) | (IData)(vlTOPp->tidc_system_tb__DOT__l1_0_request_valid))));
    vlTOPp->tidc_system_tb__DOT__l2_response_data[0U] 
        = vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[0U];
    vlTOPp->tidc_system_tb__DOT__l2_response_data[1U] 
        = vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[1U];
    vlTOPp->tidc_system_tb__DOT__l2_response_data[2U] 
        = vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[2U];
    vlTOPp->tidc_system_tb__DOT__l2_response_data[3U] 
        = vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[3U];
    vlTOPp->tidc_system_tb__DOT__l2_response_data[4U] 
        = vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[4U];
    vlTOPp->tidc_system_tb__DOT__l2_response_data[5U] 
        = vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[5U];
    vlTOPp->tidc_system_tb__DOT__l2_response_data[6U] 
        = vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[6U];
    vlTOPp->tidc_system_tb__DOT__l2_response_data[7U] 
        = vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_data[7U];
    vlTOPp->tidc_system_tb__DOT__l2_response_error 
        = vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_error;
    vlTOPp->tidc_system_tb__DOT__l2_response_valid 
        = vlTOPp->__Vdly__tidc_system_tb__DOT__l2_response_valid;
    if ((0x32U > (IData)(vlTOPp->tidc_system_tb__DOT__reset_counter))) {
        vlTOPp->tidc_system_tb__DOT__reset_counter 
            = (0xffU & ((IData)(1U) + (IData)(vlTOPp->tidc_system_tb__DOT__reset_counter)));
        vlTOPp->tidc_system_tb__DOT__rst_n = 0U;
    } else {
        vlTOPp->tidc_system_tb__DOT__rst_n = 1U;
    }
}

VL_INLINE_OPT void Vtidc_system_tb::_sequent__TOP__7(Vtidc_system_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtidc_system_tb::_sequent__TOP__7\n"); );
    Vtidc_system_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__sink_id_alloc_req 
        = (((6U == (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__state)) 
            & (~ ((IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__d_valid) 
                  >> (IData)(vlTOPp->tidc_system_tb__DOT__dut__DOT__l2_adapter__DOT__pending_master_id)))) 
           & (IData)(vlTOPp->tidc_system_tb__DOT__l2_response_valid));
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
}

void Vtidc_system_tb::_eval(Vtidc_system_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtidc_system_tb::_eval\n"); );
    Vtidc_system_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->__VinpClk__TOP__tidc_system_tb__DOT__rst_n)) 
            & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__tidc_system_tb__DOT__rst_n)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->__VinpClk__TOP__tidc_system_tb__DOT__rst_n)) 
            & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__tidc_system_tb__DOT__rst_n)))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
        vlTOPp->__Vm_traceActivity[4U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__tidc_system_tb__DOT__rst_n 
        = vlTOPp->__VinpClk__TOP__tidc_system_tb__DOT__rst_n;
    vlTOPp->__VinpClk__TOP__tidc_system_tb__DOT__rst_n 
        = vlTOPp->tidc_system_tb__DOT__rst_n;
}

VL_INLINE_OPT QData Vtidc_system_tb::_change_request(Vtidc_system_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtidc_system_tb::_change_request\n"); );
    Vtidc_system_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtidc_system_tb::_change_request_1(Vtidc_system_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtidc_system_tb::_change_request_1\n"); );
    Vtidc_system_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->tidc_system_tb__DOT__rst_n ^ vlTOPp->__Vchglast__TOP__tidc_system_tb__DOT__rst_n));
    VL_DEBUG_IF( if(__req && ((vlTOPp->tidc_system_tb__DOT__rst_n ^ vlTOPp->__Vchglast__TOP__tidc_system_tb__DOT__rst_n))) VL_DBG_MSGF("        CHANGE: tb/tidc_system_tb_verilator.v:15: tidc_system_tb.rst_n\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__tidc_system_tb__DOT__rst_n 
        = vlTOPp->tidc_system_tb__DOT__rst_n;
    return __req;
}

#ifdef VL_DEBUG
void Vtidc_system_tb::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtidc_system_tb::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG

// =============================================================================
// Project: TileLink Inclusive Directory Coherence (TIDC) System
// Module: Test Environment
// Description: Top-level test environment that connects Stimulus, DUT, and Monitor
//              This is the main testbench that should be used for simulation
// =============================================================================

`include "tidc_params.v"

module test_environment ();
    // Clock generation
    reg clk;
    always #5 clk = ~clk;
    
    initial begin
        clk = 1'b0;
    end
    
    // Test control signals
    wire rst_n;
    wire [4:0] test_phase;
    wire [15:0] cycle_counter;
    wire test_complete;
    wire timeout_detected;
    
    // Monitor output signals
    wire [31:0] total_cycles;
    wire [31:0] error_count;
    wire [31:0] success_count;
    
    // DUT interface signals - L1_0
    wire l1_0_request_valid;
    wire [63:0] l1_0_request_addr;
    wire [2:0] l1_0_request_type;
    wire [511:0] l1_0_request_data;
    wire [2:0] l1_0_request_permissions;
    wire l1_0_request_ready;
    wire l1_0_data_valid;
    wire [511:0] l1_0_data;
    wire l1_0_data_error;
    wire l1_0_probe_req_valid;
    wire [63:0] l1_0_probe_req_addr;
    wire [2:0] l1_0_probe_req_permissions;
    wire l1_0_probe_ack_valid;
    wire [63:0] l1_0_probe_ack_addr;
    wire [2:0] l1_0_probe_ack_permissions;
    wire [511:0] l1_0_probe_ack_dirty_data;
    
    // DUT interface signals - L1_1
    wire l1_1_request_valid;
    wire [63:0] l1_1_request_addr;
    wire [2:0] l1_1_request_type;
    wire [511:0] l1_1_request_data;
    wire [2:0] l1_1_request_permissions;
    wire l1_1_request_ready;
    wire l1_1_data_valid;
    wire [511:0] l1_1_data;
    wire l1_1_data_error;
    wire l1_1_probe_req_valid;
    wire [63:0] l1_1_probe_req_addr;
    wire [2:0] l1_1_probe_req_permissions;
    wire l1_1_probe_ack_valid;
    wire [63:0] l1_1_probe_ack_addr;
    wire [2:0] l1_1_probe_ack_permissions;
    wire [511:0] l1_1_probe_ack_dirty_data;
    
    // DUT interface signals - L2
    wire l2_cmd_valid;
    wire [2:0] l2_cmd_type;
    wire [63:0] l2_cmd_addr;
    wire [511:0] l2_cmd_data;
    wire [3:0] l2_cmd_size;
    wire l2_cmd_dirty;
    wire l2_response_valid;
    wire [511:0] l2_response_data;
    wire l2_response_error;
    
    // Stimulus module - generates all test scenarios
    stimulus stimulus_inst (
        .clk(clk),
        .timeout_detected(timeout_detected),
        
        // Test control outputs
        .rst_n(rst_n),
        .test_phase(test_phase),
        .cycle_counter(cycle_counter),
        .test_complete(test_complete),
        
        // L1_0 interface (stimulus outputs to DUT)
        .l1_0_request_valid(l1_0_request_valid),
        .l1_0_request_addr(l1_0_request_addr),
        .l1_0_request_type(l1_0_request_type),
        .l1_0_request_data(l1_0_request_data),
        .l1_0_request_permissions(l1_0_request_permissions),
        .l1_0_request_ready(l1_0_request_ready),
        .l1_0_data_valid(l1_0_data_valid),
        .l1_0_data(l1_0_data),
        .l1_0_data_error(l1_0_data_error),
        .l1_0_probe_req_valid(l1_0_probe_req_valid),
        .l1_0_probe_req_addr(l1_0_probe_req_addr),
        .l1_0_probe_req_permissions(l1_0_probe_req_permissions),
        .l1_0_probe_ack_valid(l1_0_probe_ack_valid),
        .l1_0_probe_ack_addr(l1_0_probe_ack_addr),
        .l1_0_probe_ack_permissions(l1_0_probe_ack_permissions),
        .l1_0_probe_ack_dirty_data(l1_0_probe_ack_dirty_data),
        
        // L1_1 interface (stimulus outputs to DUT)
        .l1_1_request_valid(l1_1_request_valid),
        .l1_1_request_addr(l1_1_request_addr),
        .l1_1_request_type(l1_1_request_type),
        .l1_1_request_data(l1_1_request_data),
        .l1_1_request_permissions(l1_1_request_permissions),
        .l1_1_request_ready(l1_1_request_ready),
        .l1_1_data_valid(l1_1_data_valid),
        .l1_1_data(l1_1_data),
        .l1_1_data_error(l1_1_data_error),
        .l1_1_probe_req_valid(l1_1_probe_req_valid),
        .l1_1_probe_req_addr(l1_1_probe_req_addr),
        .l1_1_probe_req_permissions(l1_1_probe_req_permissions),
        .l1_1_probe_ack_valid(l1_1_probe_ack_valid),
        .l1_1_probe_ack_addr(l1_1_probe_ack_addr),
        .l1_1_probe_ack_permissions(l1_1_probe_ack_permissions),
        .l1_1_probe_ack_dirty_data(l1_1_probe_ack_dirty_data),
        
        // L2 interface (stimulus acts as memory)
        .l2_cmd_valid(l2_cmd_valid),
        .l2_cmd_type(l2_cmd_type),
        .l2_cmd_addr(l2_cmd_addr),
        .l2_cmd_data(l2_cmd_data),
        .l2_cmd_size(l2_cmd_size),
        .l2_cmd_dirty(l2_cmd_dirty),
        .l2_response_valid(l2_response_valid),
        .l2_response_data(l2_response_data),
        .l2_response_error(l2_response_error)
    );
    
    // DUT instantiation - the system under test
    tidc_top dut (
        .clk(clk),
        .rst_n(rst_n),
        
        // L1_0 interface
        .l1_0_request_valid(l1_0_request_valid),
        .l1_0_request_addr(l1_0_request_addr),
        .l1_0_request_type(l1_0_request_type),
        .l1_0_request_data(l1_0_request_data),
        .l1_0_request_permissions(l1_0_request_permissions),
        .l1_0_request_ready(l1_0_request_ready),
        .l1_0_data_valid(l1_0_data_valid),
        .l1_0_data(l1_0_data),
        .l1_0_data_error(l1_0_data_error),
        .l1_0_probe_req_valid(l1_0_probe_req_valid),
        .l1_0_probe_req_addr(l1_0_probe_req_addr),
        .l1_0_probe_req_permissions(l1_0_probe_req_permissions),
        .l1_0_probe_ack_valid(l1_0_probe_ack_valid),
        .l1_0_probe_ack_addr(l1_0_probe_ack_addr),
        .l1_0_probe_ack_permissions(l1_0_probe_ack_permissions),
        .l1_0_probe_ack_dirty_data(l1_0_probe_ack_dirty_data),
        
        // L1_1 interface
        .l1_1_request_valid(l1_1_request_valid),
        .l1_1_request_addr(l1_1_request_addr),
        .l1_1_request_type(l1_1_request_type),
        .l1_1_request_data(l1_1_request_data),
        .l1_1_request_permissions(l1_1_request_permissions),
        .l1_1_request_ready(l1_1_request_ready),
        .l1_1_data_valid(l1_1_data_valid),
        .l1_1_data(l1_1_data),
        .l1_1_data_error(l1_1_data_error),
        .l1_1_probe_req_valid(l1_1_probe_req_valid),
        .l1_1_probe_req_addr(l1_1_probe_req_addr),
        .l1_1_probe_req_permissions(l1_1_probe_req_permissions),
        .l1_1_probe_ack_valid(l1_1_probe_ack_valid),
        .l1_1_probe_ack_addr(l1_1_probe_ack_addr),
        .l1_1_probe_ack_permissions(l1_1_probe_ack_permissions),
        .l1_1_probe_ack_dirty_data(l1_1_probe_ack_dirty_data),
        
        // L2 interface
        .l2_cmd_valid(l2_cmd_valid),
        .l2_cmd_type(l2_cmd_type),
        .l2_cmd_addr(l2_cmd_addr),
        .l2_cmd_data(l2_cmd_data),
        .l2_cmd_size(l2_cmd_size),
        .l2_cmd_dirty(l2_cmd_dirty),
        .l2_response_valid(l2_response_valid),
        .l2_response_data(l2_response_data),
        .l2_response_error(l2_response_error)
    );
    
    // Monitor module - tracks all transactions and validates behavior
    monitor monitor_inst (
        .clk(clk),
        .rst_n(rst_n),
        
        // Test control inputs
        .test_phase(test_phase),
        .cycle_counter(cycle_counter),
        .test_complete(test_complete),
        
        // DUT monitoring signals - L1_0 interface
        .l1_0_request_valid(l1_0_request_valid),
        .l1_0_request_ready(l1_0_request_ready),
        .l1_0_data_valid(l1_0_data_valid),
        .l1_0_data_error(l1_0_data_error),
        .l1_0_data(l1_0_data),
        .l1_0_probe_req_valid(l1_0_probe_req_valid),
        .l1_0_probe_req_addr(l1_0_probe_req_addr),
        .l1_0_probe_req_permissions(l1_0_probe_req_permissions),
        .l1_0_probe_ack_valid(l1_0_probe_ack_valid),
        .l1_0_probe_ack_addr(l1_0_probe_ack_addr),
        .l1_0_probe_ack_permissions(l1_0_probe_ack_permissions),
        
        // DUT monitoring signals - L1_1 interface  
        .l1_1_request_valid(l1_1_request_valid),
        .l1_1_request_ready(l1_1_request_ready),
        .l1_1_data_valid(l1_1_data_valid),
        .l1_1_data_error(l1_1_data_error),
        .l1_1_data(l1_1_data),
        .l1_1_probe_req_valid(l1_1_probe_req_valid),
        .l1_1_probe_req_addr(l1_1_probe_req_addr),
        .l1_1_probe_req_permissions(l1_1_probe_req_permissions),
        .l1_1_probe_ack_valid(l1_1_probe_ack_valid),
        .l1_1_probe_ack_addr(l1_1_probe_ack_addr),
        .l1_1_probe_ack_permissions(l1_1_probe_ack_permissions),
        
        // DUT monitoring signals - L2 interface
        .l2_cmd_valid(l2_cmd_valid),
        .l2_cmd_type(l2_cmd_type),
        .l2_cmd_addr(l2_cmd_addr),
        .l2_response_valid(l2_response_valid),
        .l2_response_error(l2_response_error),
        
        // Monitor outputs
        .total_cycles(total_cycles),
        .error_count(error_count),
        .success_count(success_count),
        .timeout_detected(timeout_detected)
    );
    
    // Test summary at simulation end
    final begin
        $display("\n" + "="*60);
        $display("=== TEST ENVIRONMENT SUMMARY ===");
        $display("="*60);
        $display("Final Statistics:");
        $display("  Total cycles: %d", total_cycles);
        $display("  Successful operations: %d", success_count);
        $display("  Error conditions: %d", error_count);
        
        if (error_count == 0) begin
            $display("\n✅ COMPREHENSIVE TEST SUITE PASSED!");
        end else begin
            $display("\n❌ COMPREHENSIVE TEST SUITE FAILED!");
            $display("   %d errors detected during simulation", error_count);
        end
        $display("="*60);
    end

endmodule 
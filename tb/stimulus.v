// =============================================================================
// Project: TileLink Inclusive Directory Coherence (TIDC) System
// Module: Stimulus
// Description: Stimulus generation module for TIDC testbench
//              Generates test scenarios, manages L2 memory model, and probe responses
// =============================================================================

`include "tidc_params.v"

module stimulus (
    input wire clk,
    input wire timeout_detected,
    
    output reg rst_n,
    output reg [4:0] test_phase,
    output reg [15:0] cycle_counter,
    output reg test_complete,
    
    // L1_0 interface outputs (to DUT)
    output reg l1_0_request_valid,
    output reg [63:0] l1_0_request_addr,
    output reg [2:0] l1_0_request_type,
    output reg [511:0] l1_0_request_data,
    output reg [2:0] l1_0_request_permissions,
    input wire l1_0_request_ready,
    input wire l1_0_data_valid,
    input wire [511:0] l1_0_data,
    input wire l1_0_data_error,
    input wire l1_0_probe_req_valid,
    input wire [63:0] l1_0_probe_req_addr,
    input wire [2:0] l1_0_probe_req_permissions,
    output reg l1_0_probe_ack_valid,
    output reg [63:0] l1_0_probe_ack_addr,
    output reg [2:0] l1_0_probe_ack_permissions,
    output reg [511:0] l1_0_probe_ack_dirty_data,
    
    // L1_1 interface outputs (to DUT)
    output reg l1_1_request_valid,
    output reg [63:0] l1_1_request_addr,
    output reg [2:0] l1_1_request_type,
    output reg [511:0] l1_1_request_data,
    output reg [2:0] l1_1_request_permissions,
    input wire l1_1_request_ready,
    input wire l1_1_data_valid,
    input wire [511:0] l1_1_data,
    input wire l1_1_data_error,
    input wire l1_1_probe_req_valid,
    input wire [63:0] l1_1_probe_req_addr,
    input wire [2:0] l1_1_probe_req_permissions,
    output reg l1_1_probe_ack_valid,
    output reg [63:0] l1_1_probe_ack_addr,
    output reg [2:0] l1_1_probe_ack_permissions,
    output reg [511:0] l1_1_probe_ack_dirty_data,
    
    // L2 interface outputs (to DUT)
    input wire l2_cmd_valid,
    input wire [2:0] l2_cmd_type,
    input wire [63:0] l2_cmd_addr,
    input wire [511:0] l2_cmd_data,
    input wire [3:0] l2_cmd_size,
    input wire l2_cmd_dirty,
    output reg l2_response_valid,
    output reg [511:0] l2_response_data,
    output reg l2_response_error
);

    // Test addresses - multiple for conflict testing
    parameter ADDR_A = 64'h0000000000001000;
    parameter ADDR_B = 64'h0000000000002000;
    parameter ADDR_C = 64'h0000000000003000;
    parameter ADDR_D = 64'h0000000000004000;
    
    // Test data patterns
    parameter DATA_PATTERN_A = 512'hABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789;
    parameter DATA_PATTERN_B = 512'h0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF;
    parameter DATA_PATTERN_C = 512'hFEDCBA9876543210FEDCBA9876543210FEDCBA9876543210FEDCBA9876543210FEDCBA9876543210FEDCBA9876543210FEDCBA9876543210;
    parameter DATA_PATTERN_D = 512'h5555AAAA5555AAAA5555AAAA5555AAAA5555AAAA5555AAAA5555AAAA5555AAAA5555AAAA5555AAAA5555AAAA5555AAAA5555AAAA5555AAAA5555AAAA;
    
    // Test phase definitions
    localparam PHASE_RESET           = 5'd0;
    localparam PHASE_BASIC_COHERENCE = 5'd1;
    localparam PHASE_MULTI_ADDR     = 5'd2;
    localparam PHASE_STRESS_TEST    = 5'd3;
    localparam PHASE_WRITE_BACK     = 5'd4;
    localparam PHASE_ERROR_INJECT   = 5'd5;
    localparam PHASE_RAPID_REQUESTS = 5'd6;
    localparam PHASE_UNCACHED_OPS   = 5'd7;
    localparam PHASE_CORNER_CASES   = 5'd8;
    localparam PHASE_FINAL_REPORT   = 5'd9;
    
    // Enhanced L2 memory model with configurable response delays
    reg [511:0] memory [0:1023];
    integer mem_idx;
    reg [2:0] l2_delay_counter;
    reg [2:0] l2_response_delay; // Configurable delay
    reg l2_cmd_pending;
    reg [2:0] pending_cmd_type;
    reg [63:0] pending_cmd_addr;
    reg [511:0] pending_cmd_data;
    
    // Probe response state for L1_0
    reg l1_0_has_dirty_data;
    reg [511:0] l1_0_cached_data;
    reg [63:0] l1_0_cached_addr;
    
    // Probe response state for L1_1
    reg l1_1_has_dirty_data;
    reg [511:0] l1_1_cached_data;
    reg [63:0] l1_1_cached_addr;
    
    // Initialize memory with known patterns
    initial begin
        for (mem_idx = 0; mem_idx < 1024; mem_idx = mem_idx + 1) begin
            memory[mem_idx] = {32{mem_idx[15:0]}};
        end
    end
    
    // Test initialization and control
    initial begin
        $display("=== TIDC Comprehensive Test Suite - Stimulus Module ===");
        rst_n = 1'b0;
        test_phase = PHASE_RESET;
        cycle_counter = 16'b0;
        test_complete = 1'b0;
        
        // Initialize outputs
        l1_0_request_valid = 1'b0;
        l1_0_request_addr = 64'b0;
        l1_0_request_type = 3'b0;
        l1_0_request_data = 512'b0;
        l1_0_request_permissions = 3'b0;
        l1_0_probe_ack_valid = 1'b0;
        l1_0_probe_ack_addr = 64'b0;
        l1_0_probe_ack_permissions = 3'b0;
        l1_0_probe_ack_dirty_data = 512'b0;
        
        l1_1_request_valid = 1'b0;
        l1_1_request_addr = 64'b0;
        l1_1_request_type = 3'b0;
        l1_1_request_data = 512'b0;
        l1_1_request_permissions = 3'b0;
        l1_1_probe_ack_valid = 1'b0;
        l1_1_probe_ack_addr = 64'b0;
        l1_1_probe_ack_permissions = 3'b0;
        l1_1_probe_ack_dirty_data = 512'b0;
        
        l2_response_valid = 1'b0;
        l2_response_data = 512'b0;
        l2_response_error = 1'b0;
        
        #100; // Reset period
        rst_n = 1'b1;
        $display("Reset complete, starting comprehensive tests...");
    end
    
    // Main test execution engine
    always @(posedge clk) begin
        if (rst_n) begin
            cycle_counter <= cycle_counter + 1;
            
            // Handle timeout from monitor
            if (timeout_detected) begin
                test_phase <= test_phase + 1;
                cycle_counter <= 0;
            end
            
            // Default: clear request valids
            l1_0_request_valid <= 1'b0;
            l1_1_request_valid <= 1'b0;
            
            case (test_phase)
                PHASE_RESET: begin
                    if (cycle_counter >= 20) begin
                        test_phase <= PHASE_BASIC_COHERENCE;
                        cycle_counter <= 0;
                        $display("\n=== PHASE 1: Basic Coherence Tests ===");
                    end
                end
                
                PHASE_BASIC_COHERENCE: begin
                    run_basic_coherence_test();
                    if (cycle_counter >= 200) begin
                        test_phase <= PHASE_MULTI_ADDR;
                        cycle_counter <= 0;
                        $display("\n=== PHASE 2: Multiple Address Tests ===");
                    end
                end
                
                PHASE_MULTI_ADDR: begin
                    run_multi_addr_test();
                    if (cycle_counter >= 300) begin
                        test_phase <= PHASE_STRESS_TEST;
                        cycle_counter <= 0;
                        l2_response_delay <= 3'd3; // Add delay for stress
                        $display("\n=== PHASE 3: Stress Tests ===");
                    end
                end
                
                PHASE_STRESS_TEST: begin
                    run_stress_test();
                    if (cycle_counter >= 400) begin
                        test_phase <= PHASE_WRITE_BACK;
                        cycle_counter <= 0;
                        l2_response_delay <= 3'd1; // Back to normal
                        $display("\n=== PHASE 4: Write-back Tests ===");
                    end
                end
                
                PHASE_WRITE_BACK: begin
                    run_write_back_test();
                    if (cycle_counter >= 200) begin
                        test_phase <= PHASE_ERROR_INJECT;
                        cycle_counter <= 0;
                        $display("\n=== PHASE 5: Error Injection Tests ===");
                    end
                end
                
                PHASE_ERROR_INJECT: begin
                    run_error_injection_test();
                    if (cycle_counter >= 150) begin
                        test_phase <= PHASE_RAPID_REQUESTS;
                        cycle_counter <= 0;
                        $display("\n=== PHASE 6: Rapid Request Tests ===");
                    end
                end
                
                PHASE_RAPID_REQUESTS: begin
                    run_rapid_request_test();
                    if (cycle_counter >= 200) begin
                        test_phase <= PHASE_UNCACHED_OPS;
                        cycle_counter <= 0;
                        $display("\n=== PHASE 7: Uncached Operations ===");
                    end
                end
                
                PHASE_UNCACHED_OPS: begin
                    run_uncached_ops_test();
                    if (cycle_counter >= 150) begin
                        test_phase <= PHASE_CORNER_CASES;
                        cycle_counter <= 0;
                        $display("\n=== PHASE 8: Corner Cases ===");
                    end
                end
                
                PHASE_CORNER_CASES: begin
                    run_corner_cases_test();
                    if (cycle_counter >= 250) begin
                        test_phase <= PHASE_FINAL_REPORT;
                        cycle_counter <= 0;
                    end
                end
                
                PHASE_FINAL_REPORT: begin
                    if (cycle_counter == 10) begin
                        test_complete <= 1'b1;
                        #100; // Allow monitor to finish
                        $finish;
                    end
                end
            endcase
        end
    end
    
    // Test implementation tasks
    task run_basic_coherence_test;
        begin
            case (cycle_counter)
                10: begin
                    $display("Test 1: L1_0 read (shared)");
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= ADDR_A;
                    l1_0_request_type <= L1_REQ_READ_MISS;
                    l1_0_request_permissions <= PARAM_NtoB;
                end
                
                30: begin
                    $display("Test 2: L1_1 read same address (shared)");
                    l1_1_request_valid <= 1'b1;
                    l1_1_request_addr <= ADDR_A;
                    l1_1_request_type <= L1_REQ_READ_MISS;
                    l1_1_request_permissions <= PARAM_NtoB;
                end
                
                60: begin
                    $display("Test 3: L1_0 write upgrade (exclusive)");
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= ADDR_A;
                    l1_0_request_type <= L1_REQ_WRITE_MISS;
                    l1_0_request_permissions <= PARAM_BtoT;
                    l1_0_request_data <= DATA_PATTERN_A;
                end
                
                100: begin
                    $display("Test 4: L1_1 write different address");
                    l1_1_request_valid <= 1'b1;
                    l1_1_request_addr <= ADDR_B;
                    l1_1_request_type <= L1_REQ_WRITE_MISS;
                    l1_1_request_permissions <= PARAM_NtoT;
                    l1_1_request_data <= DATA_PATTERN_B;
                end
            endcase
        end
    endtask
    
    task run_multi_addr_test;
        begin
            case (cycle_counter)
                10: begin
                    $display("Multi-addr Test 1: L1_0 read ADDR_A");
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= ADDR_A;
                    l1_0_request_type <= L1_REQ_READ_MISS;
                    l1_0_request_permissions <= PARAM_NtoB;
                end
                
                15: begin
                    $display("Multi-addr Test 2: L1_1 read ADDR_B (parallel)");
                    l1_1_request_valid <= 1'b1;
                    l1_1_request_addr <= ADDR_B;
                    l1_1_request_type <= L1_REQ_READ_MISS;
                    l1_1_request_permissions <= PARAM_NtoB;
                end
                
                40: begin
                    $display("Multi-addr Test 3: L1_0 write ADDR_C");
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= ADDR_C;
                    l1_0_request_type <= L1_REQ_WRITE_MISS;
                    l1_0_request_permissions <= PARAM_NtoT;
                    l1_0_request_data <= DATA_PATTERN_C;
                end
                
                60: begin
                    $display("Multi-addr Test 4: L1_1 read ADDR_A (conflict)");
                    l1_1_request_valid <= 1'b1;
                    l1_1_request_addr <= ADDR_A;
                    l1_1_request_type <= L1_REQ_READ_MISS;
                    l1_1_request_permissions <= PARAM_NtoB;
                end
                
                100: begin
                    $display("Multi-addr Test 5: L1_0 write ADDR_B (conflict)");
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= ADDR_B;
                    l1_0_request_type <= L1_REQ_WRITE_MISS;
                    l1_0_request_permissions <= PARAM_BtoT;
                    l1_0_request_data <= DATA_PATTERN_D;
                end
            endcase
        end
    endtask
    
    task run_stress_test;
        begin
            // Generate stress patterns with higher frequency
            if (cycle_counter % 5 == 0) begin
                l1_0_request_valid <= 1'b1;
                l1_0_request_addr <= {ADDR_A[63:8], cycle_counter[7:0]};
                l1_0_request_type <= (cycle_counter % 3 == 0) ? L1_REQ_WRITE_MISS : L1_REQ_READ_MISS;
                l1_0_request_permissions <= (cycle_counter % 3 == 0) ? PARAM_NtoT : PARAM_NtoB;
                l1_0_request_data <= {32{cycle_counter}};
            end
            
            if (cycle_counter % 7 == 0) begin
                l1_1_request_valid <= 1'b1;
                l1_1_request_addr <= {ADDR_B[63:8], cycle_counter[7:0]};
                l1_1_request_type <= (cycle_counter % 4 == 0) ? L1_REQ_WRITE_MISS : L1_REQ_READ_MISS;
                l1_1_request_permissions <= (cycle_counter % 4 == 0) ? PARAM_NtoT : PARAM_NtoB;
                l1_1_request_data <= {32{~cycle_counter}};
            end
        end
    endtask
    
    task run_write_back_test;
        begin
            case (cycle_counter)
                10: begin
                    $display("Write-back Test 1: L1_0 explicit write-back");
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= ADDR_A;
                    l1_0_request_type <= L1_REQ_WRITE_BACK;
                    l1_0_request_data <= DATA_PATTERN_A;
                end
                
                40: begin
                    $display("Write-back Test 2: L1_1 explicit write-back");
                    l1_1_request_valid <= 1'b1;
                    l1_1_request_addr <= ADDR_B;
                    l1_1_request_type <= L1_REQ_WRITE_BACK;
                    l1_1_request_data <= DATA_PATTERN_B;
                end
                
                80: begin
                    $display("Write-back Test 3: Dirty data eviction scenario");
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= ADDR_C;
                    l1_0_request_type <= L1_REQ_WRITE_MISS;
                    l1_0_request_permissions <= PARAM_NtoT;
                    l1_0_request_data <= DATA_PATTERN_C;
                end
                
                120: begin
                    $display("Write-back Test 4: Force probe with dirty data");
                    l1_1_request_valid <= 1'b1;
                    l1_1_request_addr <= ADDR_C;
                    l1_1_request_type <= L1_REQ_WRITE_MISS;
                    l1_1_request_permissions <= PARAM_NtoT;
                    l1_1_request_data <= DATA_PATTERN_D;
                end
            endcase
        end
    endtask
    
    task run_error_injection_test;
        begin
            case (cycle_counter)
                10: begin
                    $display("Error Test 1: Injecting L2 error");
                    l2_response_error <= 1'b1; // Force error on next response
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= ADDR_A;
                    l1_0_request_type <= L1_REQ_READ_MISS;
                    l1_0_request_permissions <= PARAM_NtoB;
                end
                
                20: begin
                    l2_response_error <= 1'b0; // Clear error injection
                end
                
                50: begin
                    $display("Error Test 2: Invalid permission request");
                    l1_1_request_valid <= 1'b1;
                    l1_1_request_addr <= ADDR_B;
                    l1_1_request_type <= L1_REQ_READ_MISS;
                    l1_1_request_permissions <= 3'b111; // Invalid permission
                end
                
                100: begin
                    $display("Error Test 3: Misaligned address");
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= 64'h0000000000001001; // Misaligned
                    l1_0_request_type <= L1_REQ_READ_MISS;
                    l1_0_request_permissions <= PARAM_NtoB;
                end
            endcase
        end
    endtask
    
    task run_rapid_request_test;
        begin
            // Back-to-back requests every cycle
            l1_0_request_valid <= 1'b1;
            l1_0_request_addr <= ADDR_A + {56'b0, cycle_counter[7:0]};
            l1_0_request_type <= cycle_counter[0] ? L1_REQ_WRITE_MISS : L1_REQ_READ_MISS;
            l1_0_request_permissions <= cycle_counter[0] ? PARAM_NtoT : PARAM_NtoB;
            l1_0_request_data <= {32{cycle_counter}};
            
            l1_1_request_valid <= 1'b1;
            l1_1_request_addr <= ADDR_B + {56'b0, cycle_counter[7:0]};
            l1_1_request_type <= cycle_counter[1] ? L1_REQ_WRITE_MISS : L1_REQ_READ_MISS;
            l1_1_request_permissions <= cycle_counter[1] ? PARAM_NtoT : PARAM_NtoB;
            l1_1_request_data <= {32{~cycle_counter}};
        end
    endtask
    
    task run_uncached_ops_test;
        begin
            case (cycle_counter)
                10: begin
                    $display("Uncached Test 1: L1_0 uncached read");
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= ADDR_D;
                    l1_0_request_type <= L1_REQ_UNCACHED_READ;
                    l1_0_request_permissions <= PARAM_NtoN;
                end
                
                40: begin
                    $display("Uncached Test 2: L1_1 uncached write");
                    l1_1_request_valid <= 1'b1;
                    l1_1_request_addr <= ADDR_D;
                    l1_1_request_type <= L1_REQ_UNCACHED_WRITE;
                    l1_1_request_permissions <= PARAM_NtoN;
                    l1_1_request_data <= DATA_PATTERN_D;
                end
                
                80: begin
                    $display("Uncached Test 3: Mixed cached/uncached");
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= ADDR_A;
                    l1_0_request_type <= L1_REQ_READ_MISS;
                    l1_0_request_permissions <= PARAM_NtoB;
                end
                
                85: begin
                    l1_1_request_valid <= 1'b1;
                    l1_1_request_addr <= ADDR_D + 64;
                    l1_1_request_type <= L1_REQ_UNCACHED_READ;
                    l1_1_request_permissions <= PARAM_NtoN;
                end
            endcase
        end
    endtask
    
    task run_corner_cases_test;
        begin
            case (cycle_counter)
                10: begin
                    $display("Corner Case 1: Same address, different L1s, same cycle");
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= ADDR_A;
                    l1_0_request_type <= L1_REQ_READ_MISS;
                    l1_0_request_permissions <= PARAM_NtoB;
                    
                    l1_1_request_valid <= 1'b1;
                    l1_1_request_addr <= ADDR_A;
                    l1_1_request_type <= L1_REQ_READ_MISS;
                    l1_1_request_permissions <= PARAM_NtoB;
                end
                
                50: begin
                    $display("Corner Case 2: Write upgrade conflicts");
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= ADDR_B;
                    l1_0_request_type <= L1_REQ_WRITE_MISS;
                    l1_0_request_permissions <= PARAM_NtoT;
                    l1_0_request_data <= DATA_PATTERN_A;
                    
                    l1_1_request_valid <= 1'b1;
                    l1_1_request_addr <= ADDR_B;
                    l1_1_request_type <= L1_REQ_WRITE_MISS;
                    l1_1_request_permissions <= PARAM_NtoT;
                    l1_1_request_data <= DATA_PATTERN_B;
                end
                
                100: begin
                    $display("Corner Case 3: Rapid permission changes");
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= ADDR_C;
                    l1_0_request_type <= L1_REQ_READ_MISS;
                    l1_0_request_permissions <= PARAM_NtoB;
                end
                
                110: begin
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= ADDR_C;
                    l1_0_request_type <= L1_REQ_WRITE_MISS;
                    l1_0_request_permissions <= PARAM_BtoT;
                    l1_0_request_data <= DATA_PATTERN_C;
                end
                
                150: begin
                    $display("Corner Case 4: Maximum address range");
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= 64'hFFFFFFFFFFFFFC00; // Max aligned addr
                    l1_0_request_type <= L1_REQ_READ_MISS;
                    l1_0_request_permissions <= PARAM_NtoB;
                end
                
                200: begin
                    $display("Corner Case 5: Zero address edge case");
                    l1_1_request_valid <= 1'b1;
                    l1_1_request_addr <= 64'h0000000000000000;
                    l1_1_request_type <= L1_REQ_WRITE_MISS;
                    l1_1_request_permissions <= PARAM_NtoT;
                    l1_1_request_data <= {512{1'b1}}; // All ones pattern
                end
            endcase
        end
    endtask

    // Enhanced L2 memory model with configurable response delays
    always @(posedge clk) begin
        if (!rst_n) begin
            l2_response_valid <= 1'b0;
            l2_response_error <= 1'b0;
            l2_delay_counter <= 3'b0;
            l2_cmd_pending <= 1'b0;
            l2_response_delay <= 3'd1; // Default 1 cycle delay
        end else begin
            l2_response_valid <= 1'b0;
            
            if (l2_cmd_valid && !l2_cmd_pending) begin
                l2_cmd_pending <= 1'b1;
                pending_cmd_type <= l2_cmd_type;
                pending_cmd_addr <= l2_cmd_addr;
                pending_cmd_data <= l2_cmd_data;
                l2_delay_counter <= l2_response_delay;
                $display("[L2] Command received: type=%d, addr=%h", l2_cmd_type, l2_cmd_addr);
            end
            
            if (l2_cmd_pending) begin
                if (l2_delay_counter == 0) begin
                    mem_idx = pending_cmd_addr[31:6]; // 64-byte aligned
                    case (pending_cmd_type)
                        L2_CMD_READ: begin
                            l2_response_valid <= 1'b1;
                            l2_response_data <= memory[mem_idx];
                            l2_response_error <= 1'b0;
                            $display("[L2] Read complete: addr=%h, data=%h", pending_cmd_addr, memory[mem_idx]);
                        end
                        L2_CMD_WRITE, L2_CMD_WRITE_BACK: begin
                            memory[mem_idx] <= pending_cmd_data;
                            l2_response_valid <= 1'b1;
                            l2_response_data <= pending_cmd_data;
                            l2_response_error <= 1'b0;
                            $display("[L2] Write complete: addr=%h, data=%h", pending_cmd_addr, pending_cmd_data);
                        end
                        default: begin
                            l2_response_valid <= 1'b1;
                            l2_response_error <= 1'b1;
                            $display("[L2] ERROR: Unknown command type %d", pending_cmd_type);
                        end
                    endcase
                    l2_cmd_pending <= 1'b0;
                end else begin
                    l2_delay_counter <= l2_delay_counter - 1;
                end
            end
        end
    end
    
    // Enhanced probe response logic for L1_0 with dirty data handling
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            l1_0_probe_ack_valid <= 1'b0;
            l1_0_has_dirty_data <= 1'b0;
            l1_0_cached_data <= 512'b0;
            l1_0_cached_addr <= 64'b0;
        end else begin
            // Track write data for dirty responses
            if (l1_0_request_valid && l1_0_request_ready && 
                (l1_0_request_type == L1_REQ_WRITE_MISS)) begin
                l1_0_has_dirty_data <= 1'b1;
                l1_0_cached_data <= l1_0_request_data;
                l1_0_cached_addr <= l1_0_request_addr;
            end
            
            if (l1_0_probe_req_valid && !l1_0_probe_ack_valid) begin
                l1_0_probe_ack_valid <= 1'b1;
                l1_0_probe_ack_addr <= l1_0_probe_req_addr;
                
                case (l1_0_probe_req_permissions)
                    PARAM_toN: begin // Invalidate
                        l1_0_probe_ack_permissions <= l1_0_has_dirty_data ? PARAM_TtoN : PARAM_BtoN;
                        l1_0_probe_ack_dirty_data <= l1_0_has_dirty_data ? l1_0_cached_data : 512'b0;
                        if (l1_0_probe_req_addr == l1_0_cached_addr) begin
                            l1_0_has_dirty_data <= 1'b0;
                        end
                    end
                    PARAM_toB: begin // Downgrade to shared
                        l1_0_probe_ack_permissions <= PARAM_TtoB;
                        l1_0_probe_ack_dirty_data <= 512'b0;
                    end
                    default: begin
                        l1_0_probe_ack_permissions <= PARAM_NtoN;
                        l1_0_probe_ack_dirty_data <= 512'b0;
                    end
                endcase
                $display("[PROBE] L1_0 responding to probe: addr=%h, req_perm=%d, resp_perm=%d, dirty=%b", 
                         l1_0_probe_req_addr, l1_0_probe_req_permissions, l1_0_probe_ack_permissions, 
                         l1_0_has_dirty_data);
            end else if (l1_0_probe_ack_valid) begin
                l1_0_probe_ack_valid <= 1'b0;
            end
        end
    end
    
    // Enhanced probe response logic for L1_1 with dirty data handling  
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            l1_1_probe_ack_valid <= 1'b0;
            l1_1_has_dirty_data <= 1'b0;
            l1_1_cached_data <= 512'b0;
            l1_1_cached_addr <= 64'b0;
        end else begin
            // Track write data for dirty responses
            if (l1_1_request_valid && l1_1_request_ready && 
                (l1_1_request_type == L1_REQ_WRITE_MISS)) begin
                l1_1_has_dirty_data <= 1'b1;
                l1_1_cached_data <= l1_1_request_data;
                l1_1_cached_addr <= l1_1_request_addr;
            end
            
            if (l1_1_probe_req_valid && !l1_1_probe_ack_valid) begin
                l1_1_probe_ack_valid <= 1'b1;
                l1_1_probe_ack_addr <= l1_1_probe_req_addr;
                
                case (l1_1_probe_req_permissions)
                    PARAM_toN: begin // Invalidate
                        l1_1_probe_ack_permissions <= l1_1_has_dirty_data ? PARAM_TtoN : PARAM_BtoN;
                        l1_1_probe_ack_dirty_data <= l1_1_has_dirty_data ? l1_1_cached_data : 512'b0;
                        if (l1_1_probe_req_addr == l1_1_cached_addr) begin
                            l1_1_has_dirty_data <= 1'b0;
                        end
                    end
                    PARAM_toB: begin // Downgrade to shared
                        l1_1_probe_ack_permissions <= PARAM_TtoB;
                        l1_1_probe_ack_dirty_data <= 512'b0;
                    end
                    default: begin
                        l1_1_probe_ack_permissions <= PARAM_NtoN;
                        l1_1_probe_ack_dirty_data <= 512'b0;
                    end
                endcase
                $display("[PROBE] L1_1 responding to probe: addr=%h, req_perm=%d, resp_perm=%d, dirty=%b", 
                         l1_1_probe_req_addr, l1_1_probe_req_permissions, l1_1_probe_ack_permissions,
                         l1_1_has_dirty_data);
            end else if (l1_1_probe_ack_valid) begin
                l1_1_probe_ack_valid <= 1'b0;
            end
        end
    end

endmodule 
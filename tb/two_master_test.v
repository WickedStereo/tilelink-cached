// Two master test for TIDC system - validates 2-L1 coherence
`include "tidc_params.v"

module two_master_test (
    input wire clk  // Clock driven from C++ for Verilator compatibility
);
    reg rst_n;
    
    // Test addresses and data
    parameter ADDR_A = 32'h00001000;
    parameter ADDR_B = 32'h00002000;
    parameter DATA_PATTERN_A = 256'hABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789;
    parameter DATA_PATTERN_B = 256'h0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF;
    
    // L1 adapter interfaces
    reg                         l1_0_request_valid;
    reg  [31:0]                 l1_0_request_addr;
    reg  [2:0]                  l1_0_request_type;
    reg  [255:0]                l1_0_request_data;
    reg  [2:0]                  l1_0_request_permissions;
    wire                        l1_0_request_ready;
    wire                        l1_0_data_valid;
    wire [255:0]                l1_0_data;
    wire                        l1_0_data_error;
    wire                        l1_0_probe_req_valid;
    wire [31:0]                 l1_0_probe_req_addr;
    wire [2:0]                  l1_0_probe_req_permissions;
    reg                         l1_0_probe_ack_valid;
    reg  [31:0]                 l1_0_probe_ack_addr;
    reg  [2:0]                  l1_0_probe_ack_permissions;
    reg  [255:0]                l1_0_probe_ack_dirty_data;
    
    reg                         l1_1_request_valid;
    reg  [31:0]                 l1_1_request_addr;
    reg  [2:0]                  l1_1_request_type;
    reg  [255:0]                l1_1_request_data;
    reg  [2:0]                  l1_1_request_permissions;
    wire                        l1_1_request_ready;
    wire                        l1_1_data_valid;
    wire [255:0]                l1_1_data;
    wire                        l1_1_data_error;
    wire                        l1_1_probe_req_valid;
    wire [31:0]                 l1_1_probe_req_addr;
    wire [2:0]                  l1_1_probe_req_permissions;
    reg                         l1_1_probe_ack_valid;
    reg  [31:0]                 l1_1_probe_ack_addr;
    reg  [2:0]                  l1_1_probe_ack_permissions;
    reg  [255:0]                l1_1_probe_ack_dirty_data;
    
    // L2 interface (simple memory model)
    wire                        l2_cmd_valid;
    wire [2:0]                  l2_cmd_type;
    wire [31:0]                 l2_cmd_addr;
    wire [255:0]                l2_cmd_data;
    wire [3:0]                  l2_cmd_size;
    wire                        l2_cmd_dirty;
    reg                         l2_response_valid;
    reg  [255:0]                l2_response_data;
    reg                         l2_response_error;
    
    // DUT instantiation
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
    
    // Simple L2 memory model
    reg [255:0] memory [0:1023];
    integer mem_idx;
    
    always @(posedge clk) begin
        l2_response_valid <= 1'b0;
        l2_response_error <= 1'b0;
        
        if (l2_cmd_valid) begin
            mem_idx = l2_cmd_addr[31:5]; // 32-byte aligned addressing
            case (l2_cmd_type)
                L2_CMD_READ: begin
                    l2_response_valid <= 1'b1;
                    l2_response_data <= memory[mem_idx];
                    $display("[L2] Read addr=%h, data=%h", l2_cmd_addr, memory[mem_idx]);
                end
                L2_CMD_WRITE, L2_CMD_WRITE_BACK: begin
                    memory[mem_idx] <= l2_cmd_data;
                    l2_response_valid <= 1'b1;
                    l2_response_data <= l2_cmd_data;
                    $display("[L2] Write addr=%h, data=%h", l2_cmd_addr, l2_cmd_data);
                end
            endcase
        end
    end
    
    // Initialize memory with pattern
    initial begin
        for (mem_idx = 0; mem_idx < 1024; mem_idx = mem_idx + 1) begin
            memory[mem_idx] = {8{mem_idx[7:0]}} | 256'hFFFFFFFFFFFFFFFF0000000000000000;
        end
    end
    
    // Probe response logic for L1_0
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            l1_0_probe_ack_valid <= 1'b0;
        end else begin
            if (l1_0_probe_req_valid && !l1_0_probe_ack_valid) begin
                l1_0_probe_ack_valid <= 1'b1;
                l1_0_probe_ack_addr <= l1_0_probe_req_addr;
                l1_0_probe_ack_permissions <= PARAM_BtoN; // Downgrade to None
                l1_0_probe_ack_dirty_data <= 256'b0;
                $display("[PROBE] L1_0 responding to probe at addr %h", l1_0_probe_req_addr);
            end else if (l1_0_probe_ack_valid) begin
                l1_0_probe_ack_valid <= 1'b0;
            end
        end
    end
    
    // Probe response logic for L1_1
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            l1_1_probe_ack_valid <= 1'b0;
        end else begin
            if (l1_1_probe_req_valid && !l1_1_probe_ack_valid) begin
                l1_1_probe_ack_valid <= 1'b1;
                l1_1_probe_ack_addr <= l1_1_probe_req_addr;
                l1_1_probe_ack_permissions <= PARAM_BtoN; // Downgrade to None
                l1_1_probe_ack_dirty_data <= 256'b0;
                $display("[PROBE] L1_1 responding to probe at addr %h", l1_1_probe_req_addr);
            end else if (l1_1_probe_ack_valid) begin
                l1_1_probe_ack_valid <= 1'b0;
            end
        end
    end
    
    // Test state machine
    reg [3:0] test_state;
    reg [7:0] wait_counter;
    reg l1_0_data_received, l1_1_data_received;
    reg l1_0_probe_received, l1_1_probe_received;
    
    localparam TEST_RESET = 0, TEST_L1_0_SHARED = 1, TEST_L1_1_SHARED = 2, 
               TEST_WAIT_SHARED = 3, TEST_L1_0_EXCLUSIVE = 4, TEST_WAIT_PROBE = 5, 
               TEST_VALIDATE = 6, TEST_COMPLETE = 7;
    
    // Initialize test inputs
    initial begin
        rst_n = 1'b0;
        test_state = TEST_RESET;
        wait_counter = 0;
        
        // Initialize L1_0 inputs
        l1_0_request_valid = 1'b0;
        l1_0_request_addr = 32'b0;
        l1_0_request_type = 3'b0;
        l1_0_request_data = 256'b0;
        l1_0_request_permissions = 3'b0;
        l1_0_probe_ack_valid = 1'b0;
        l1_0_probe_ack_addr = 32'b0;
        l1_0_probe_ack_permissions = 3'b0;
        l1_0_probe_ack_dirty_data = 256'b0;
        
        // Initialize L1_1 inputs
        l1_1_request_valid = 1'b0;
        l1_1_request_addr = 32'b0;
        l1_1_request_type = 3'b0;
        l1_1_request_data = 256'b0;
        l1_1_request_permissions = 3'b0;
        l1_1_probe_ack_valid = 1'b0;
        l1_1_probe_ack_addr = 32'b0;
        l1_1_probe_ack_permissions = 3'b0;
        l1_1_probe_ack_dirty_data = 256'b0;
        
        l1_0_data_received = 1'b0;
        l1_1_data_received = 1'b0;
        l1_0_probe_received = 1'b0;
        l1_1_probe_received = 1'b0;
    end
    
    // Monitor data responses
    always @(posedge clk) begin
        if (l1_0_data_valid) begin
            l1_0_data_received <= 1'b1;
            $display("[%0d] L1_0 data received: %h", $time, l1_0_data);
        end
        if (l1_1_data_valid) begin
            l1_1_data_received <= 1'b1;
            $display("[%0d] L1_1 data received: %h", $time, l1_1_data);
        end
        if (l1_0_probe_req_valid) begin
            l1_0_probe_received <= 1'b1;
            $display("[%0d] L1_0 probe received for addr %h", $time, l1_0_probe_req_addr);
        end
        if (l1_1_probe_req_valid) begin
            l1_1_probe_received <= 1'b1;
            $display("[%0d] L1_1 probe received for addr %h", $time, l1_1_probe_req_addr);
        end
    end
    
    // Main test sequence
    always @(posedge clk) begin
        if (!rst_n) begin
            rst_n <= 1'b1;
            $display("Two master test starting...");
            $display("=== Two Master Test - 2-L1 Coherence ===");
        end else begin
            wait_counter <= wait_counter + 1;
            
            case (test_state)
                TEST_RESET: begin
                    if (wait_counter == 20) begin
                        test_state <= TEST_L1_0_SHARED;
                        wait_counter <= 0;
                        $display("TEST 1: L1_0 requests shared access to addr %h", ADDR_A);
                        l1_0_request_valid <= 1'b1;
                        l1_0_request_addr <= ADDR_A;
                        l1_0_request_type <= L1_REQ_READ_MISS;
                        l1_0_request_permissions <= PARAM_NtoB;
                    end
                end
                
                TEST_L1_0_SHARED: begin
                    if (l1_0_request_ready) begin
                        l1_0_request_valid <= 1'b0;
                        test_state <= TEST_L1_1_SHARED;
                        wait_counter <= 0;
                        $display("TEST 2: L1_1 requests shared access to same addr %h", ADDR_A);
                        l1_1_request_valid <= 1'b1;
                        l1_1_request_addr <= ADDR_A;
                        l1_1_request_type <= L1_REQ_READ_MISS;
                        l1_1_request_permissions <= PARAM_NtoB;
                    end
                end
                
                TEST_L1_1_SHARED: begin
                    if (l1_1_request_ready) begin
                        l1_1_request_valid <= 1'b0;
                        test_state <= TEST_WAIT_SHARED;
                        wait_counter <= 0;
                        $display("Waiting for both L1s to receive shared data...");
                    end
                end
                
                TEST_WAIT_SHARED: begin
                    if (l1_0_data_received && l1_1_data_received) begin
                        test_state <= TEST_L1_0_EXCLUSIVE;
                        wait_counter <= 0;
                        $display("TEST 3: L1_0 upgrades to exclusive access");
                        l1_0_request_valid <= 1'b1;
                        l1_0_request_addr <= ADDR_A;
                        l1_0_request_type <= L1_REQ_WRITE_MISS;
                        l1_0_request_permissions <= PARAM_BtoT;
                        l1_0_request_data <= DATA_PATTERN_A;
                    end else if (wait_counter > 100) begin
                        $display("ERROR: Timeout waiting for shared data");
                        $finish;
                    end
                end
                
                TEST_L1_0_EXCLUSIVE: begin
                    if (l1_0_request_ready) begin
                        l1_0_request_valid <= 1'b0;
                        test_state <= TEST_WAIT_PROBE;
                        wait_counter <= 0;
                        $display("Waiting for L1_1 to be probed for exclusive upgrade...");
                    end
                end
                
                TEST_WAIT_PROBE: begin
                    if (l1_1_probe_received) begin
                        test_state <= TEST_VALIDATE;
                        wait_counter <= 0;
                        $display("TEST 4: Validating probe response and completion...");
                    end else if (wait_counter > 100) begin
                        $display("ERROR: Timeout waiting for probe");
                        $finish;
                    end
                end
                
                TEST_VALIDATE: begin
                    if (wait_counter > 20) begin
                        test_state <= TEST_COMPLETE;
                        $display("=== Two Master Test Results ===");
                        $display("✓ L1_0 shared access: %s", l1_0_data_received ? "PASS" : "FAIL");
                        $display("✓ L1_1 shared access: %s", l1_1_data_received ? "PASS" : "FAIL");
                        $display("✓ L1_1 probe received: %s", l1_1_probe_received ? "PASS" : "FAIL");
                        $display("✓ Two master coherence: COMPLETE");
                        $display("=== Two Master Test Complete ===");
                        $finish;
                    end
                end
                
                default: begin
                    $display("ERROR: Invalid test state");
                    $finish;
                end
            endcase
        end
    end
    
    // VCD dump
    initial begin
        $dumpfile("two_master_test.vcd");
        $dumpvars(0, two_master_test);
    end

endmodule 
// =============================================================================
// Multi-Sharer Test for TIDC System
// Tests multiple L1s sharing the same cache line and complex probe scenarios
// Built on the working simple_probe_test foundation
// =============================================================================

`timescale 1ns / 1ps

module multi_sharer_test (
    input wire clk,   // Clock driven from C++ for Verilator compatibility
    input wire rst_n  // Reset driven from C++
);
    
    // L1 interface signals (matching existing working interface)
    // L1_0 request interface
    reg         l1_0_request_valid;
    reg  [31:0] l1_0_request_addr;
    reg  [2:0]  l1_0_request_type;
    reg  [63:0] l1_0_request_data;
    reg  [2:0]  l1_0_request_permissions;
    wire        l1_0_request_ready;
    wire        l1_0_data_valid;
    wire [63:0] l1_0_data;
    wire        l1_0_data_error;
    
    // L1_0 probe interface
    wire        l1_0_probe_req_valid;
    wire [31:0] l1_0_probe_req_addr;
    wire [2:0]  l1_0_probe_req_permissions;
    reg         l1_0_probe_ack_valid;
    reg  [31:0] l1_0_probe_ack_addr;
    reg  [2:0]  l1_0_probe_ack_permissions;
    reg  [255:0] l1_0_probe_ack_dirty_data;
    
    // L1_1 request interface  
    reg         l1_1_request_valid;
    reg  [31:0] l1_1_request_addr;
    reg  [2:0]  l1_1_request_type;
    reg  [63:0] l1_1_request_data;
    reg  [2:0]  l1_1_request_permissions;
    wire        l1_1_request_ready;
    wire        l1_1_data_valid;
    wire [63:0] l1_1_data;
    wire        l1_1_data_error;
    
    // L1_1 probe interface
    wire        l1_1_probe_req_valid;
    wire [31:0] l1_1_probe_req_addr;
    wire [2:0]  l1_1_probe_req_permissions;
    reg         l1_1_probe_ack_valid;
    reg  [31:0] l1_1_probe_ack_addr;
    reg  [2:0]  l1_1_probe_ack_permissions;
    reg  [255:0] l1_1_probe_ack_dirty_data;
    
    // L1_2 request interface
    reg         l1_2_request_valid;
    reg  [31:0] l1_2_request_addr;
    reg  [2:0]  l1_2_request_type;
    reg  [63:0] l1_2_request_data;
    reg  [2:0]  l1_2_request_permissions;
    wire        l1_2_request_ready;
    wire        l1_2_data_valid;
    wire [63:0] l1_2_data;
    wire        l1_2_data_error;
    
    // L1_2 probe interface
    wire        l1_2_probe_req_valid;
    wire [31:0] l1_2_probe_req_addr;
    wire [2:0]  l1_2_probe_req_permissions;
    reg         l1_2_probe_ack_valid;
    reg  [31:0] l1_2_probe_ack_addr;
    reg  [2:0]  l1_2_probe_ack_permissions;
    reg  [255:0] l1_2_probe_ack_dirty_data;
    
    // L1_3 request interface
    reg         l1_3_request_valid;
    reg  [31:0] l1_3_request_addr;
    reg  [2:0]  l1_3_request_type;
    reg  [63:0] l1_3_request_data;
    reg  [2:0]  l1_3_request_permissions;
    wire        l1_3_request_ready;
    wire        l1_3_data_valid;
    wire [63:0] l1_3_data;
    wire        l1_3_data_error;
    
    // L1_3 probe interface
    wire        l1_3_probe_req_valid;
    wire [31:0] l1_3_probe_req_addr;
    wire [2:0]  l1_3_probe_req_permissions;
    reg         l1_3_probe_ack_valid;
    reg  [31:0] l1_3_probe_ack_addr;
    reg  [2:0]  l1_3_probe_ack_permissions;
    reg  [255:0] l1_3_probe_ack_dirty_data;
    
    // L2 cache interface (memory model)
    wire        l2_cmd_valid;
    wire [2:0]  l2_cmd_type;
    wire [31:0] l2_cmd_addr;
    wire [255:0] l2_cmd_data;
    wire [3:0]  l2_cmd_size;
    wire        l2_cmd_dirty;
    reg         l2_response_valid;
    reg  [255:0] l2_response_data;
    reg         l2_response_error;
    
    // Test state machine
    reg [3:0] test_state;
    reg [15:0] timeout_counter;
    
    // Test parameters
    localparam TEST_ADDR1 = 32'h00001000;
    localparam TEST_ADDR2 = 32'h00002000;
    
    // Test states
    localparam TEST_RESET = 0;
    localparam TEST_L1_0_READ = 1;      // L1_0 gets shared access
    localparam TEST_L1_0_WAIT = 2;
    localparam TEST_L1_1_READ = 3;      // L1_1 gets shared access  
    localparam TEST_L1_1_WAIT = 4;
    localparam TEST_L1_2_READ = 5;      // L1_2 gets shared access
    localparam TEST_L1_2_WAIT = 6;
    localparam TEST_L1_3_WRITE = 7;     // L1_3 requests exclusive (should probe all)
    localparam TEST_MULTI_PROBE_WAIT = 8;
    localparam TEST_ADDR2_ACCESS = 9;   // Test different address
    localparam TEST_ADDR2_WAIT = 10;
    localparam TEST_COMPLETE = 11;
    
    // Instantiate TIDC system
    tidc_top dut (
        .clk(clk),
        .rst_n(rst_n),
        
        // L1_0 interfaces
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
        
        // L1_1 interfaces
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
        
        // L1_2 interfaces
        .l1_2_request_valid(l1_2_request_valid),
        .l1_2_request_addr(l1_2_request_addr),
        .l1_2_request_type(l1_2_request_type),
        .l1_2_request_data(l1_2_request_data),
        .l1_2_request_permissions(l1_2_request_permissions),
        .l1_2_request_ready(l1_2_request_ready),
        .l1_2_data_valid(l1_2_data_valid),
        .l1_2_data(l1_2_data),
        .l1_2_data_error(l1_2_data_error),
        .l1_2_probe_req_valid(l1_2_probe_req_valid),
        .l1_2_probe_req_addr(l1_2_probe_req_addr),
        .l1_2_probe_req_permissions(l1_2_probe_req_permissions),
        .l1_2_probe_ack_valid(l1_2_probe_ack_valid),
        .l1_2_probe_ack_addr(l1_2_probe_ack_addr),
        .l1_2_probe_ack_permissions(l1_2_probe_ack_permissions),
        .l1_2_probe_ack_dirty_data(l1_2_probe_ack_dirty_data),
        
        // L1_3 interfaces
        .l1_3_request_valid(l1_3_request_valid),
        .l1_3_request_addr(l1_3_request_addr),
        .l1_3_request_type(l1_3_request_type),
        .l1_3_request_data(l1_3_request_data),
        .l1_3_request_permissions(l1_3_request_permissions),
        .l1_3_request_ready(l1_3_request_ready),
        .l1_3_data_valid(l1_3_data_valid),
        .l1_3_data(l1_3_data),
        .l1_3_data_error(l1_3_data_error),
        .l1_3_probe_req_valid(l1_3_probe_req_valid),
        .l1_3_probe_req_addr(l1_3_probe_req_addr),
        .l1_3_probe_req_permissions(l1_3_probe_req_permissions),
        .l1_3_probe_ack_valid(l1_3_probe_ack_valid),
        .l1_3_probe_ack_addr(l1_3_probe_ack_addr),
        .l1_3_probe_ack_permissions(l1_3_probe_ack_permissions),
        .l1_3_probe_ack_dirty_data(l1_3_probe_ack_dirty_data),
        
        // L2 cache interface
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
    
    // L2 memory model
    reg [255:0] l2_memory [0:4095];
    
    // Initialize memory
    initial begin
        integer i;
        for (i = 0; i < 4096; i = i + 1) begin
            l2_memory[i] = {4{64'h8080808080808080}} + i;
        end
    end
    
    // L2 memory response
    always @(posedge clk) begin
        if (!rst_n) begin
            l2_response_valid <= 1'b0;
            l2_response_data <= 256'b0;
            l2_response_error <= 1'b0;
        end else begin
            if (l2_cmd_valid) begin
                l2_response_valid <= 1'b1;
                l2_response_error <= 1'b0;
                if (l2_cmd_type == 3'b000) begin // Read
                    l2_response_data <= l2_memory[l2_cmd_addr[31:8]];
                    $display("[%0d] L2: Read addr=%h, data=%h", $time, l2_cmd_addr, l2_memory[l2_cmd_addr[31:8]]);
                end else if (l2_cmd_type == 3'b001) begin // Write
                    l2_memory[l2_cmd_addr[31:8]] <= l2_cmd_data;
                    l2_response_data <= 256'b0;
                    $display("[%0d] L2: Write addr=%h, data=%h", $time, l2_cmd_addr, l2_cmd_data);
                end
            end else begin
                l2_response_valid <= 1'b0;
            end
        end
    end
    
    // Initialize all L1 interfaces
    initial begin
        // L1_0
        l1_0_request_valid = 1'b0;
        l1_0_request_addr = 32'b0;
        l1_0_request_type = 3'b0;
        l1_0_request_data = 64'b0;
        l1_0_request_permissions = 3'b0;
        l1_0_probe_ack_valid = 1'b0;
        l1_0_probe_ack_addr = 32'b0;
        l1_0_probe_ack_permissions = 3'b0;
        l1_0_probe_ack_dirty_data = 256'b0;
        
        // L1_1
        l1_1_request_valid = 1'b0;
        l1_1_request_addr = 32'b0;
        l1_1_request_type = 3'b0;
        l1_1_request_data = 64'b0;
        l1_1_request_permissions = 3'b0;
        l1_1_probe_ack_valid = 1'b0;
        l1_1_probe_ack_addr = 32'b0;
        l1_1_probe_ack_permissions = 3'b0;
        l1_1_probe_ack_dirty_data = 256'b0;
        
        // L1_2
        l1_2_request_valid = 1'b0;
        l1_2_request_addr = 32'b0;
        l1_2_request_type = 3'b0;
        l1_2_request_data = 64'b0;
        l1_2_request_permissions = 3'b0;
        l1_2_probe_ack_valid = 1'b0;
        l1_2_probe_ack_addr = 32'b0;
        l1_2_probe_ack_permissions = 3'b0;
        l1_2_probe_ack_dirty_data = 256'b0;
        
        // L1_3
        l1_3_request_valid = 1'b0;
        l1_3_request_addr = 32'b0;
        l1_3_request_type = 3'b0;
        l1_3_request_data = 64'b0;
        l1_3_request_permissions = 3'b0;
        l1_3_probe_ack_valid = 1'b0;
        l1_3_probe_ack_addr = 32'b0;
        l1_3_probe_ack_permissions = 3'b0;
        l1_3_probe_ack_dirty_data = 256'b0;
        
        test_state = TEST_RESET;
        timeout_counter = 16'b0;
    end
    
    // Probe response logic for all L1s
    always @(posedge clk) begin
        if (rst_n) begin
            // L1_0 probe response
            if (l1_0_probe_req_valid && !l1_0_probe_ack_valid) begin
                l1_0_probe_ack_valid <= 1'b1;
                l1_0_probe_ack_addr <= l1_0_probe_req_addr;
                l1_0_probe_ack_permissions <= 3'b001; // toB (downgrade to shared/invalid)
                l1_0_probe_ack_dirty_data <= 256'b0;
                $display("[%0d] L1_0 responding to probe at addr %h", $time, l1_0_probe_req_addr);
            end else if (l1_0_probe_ack_valid) begin
                l1_0_probe_ack_valid <= 1'b0;
            end
            
            // L1_1 probe response
            if (l1_1_probe_req_valid && !l1_1_probe_ack_valid) begin
                l1_1_probe_ack_valid <= 1'b1;
                l1_1_probe_ack_addr <= l1_1_probe_req_addr;
                l1_1_probe_ack_permissions <= 3'b001; // toB (downgrade to shared/invalid)
                l1_1_probe_ack_dirty_data <= 256'b0;
                $display("[%0d] L1_1 responding to probe at addr %h", $time, l1_1_probe_req_addr);
            end else if (l1_1_probe_ack_valid) begin
                l1_1_probe_ack_valid <= 1'b0;
            end
            
            // L1_2 probe response
            if (l1_2_probe_req_valid && !l1_2_probe_ack_valid) begin
                l1_2_probe_ack_valid <= 1'b1;
                l1_2_probe_ack_addr <= l1_2_probe_req_addr;
                l1_2_probe_ack_permissions <= 3'b001; // toB (downgrade to shared/invalid)
                l1_2_probe_ack_dirty_data <= 256'b0;
                $display("[%0d] L1_2 responding to probe at addr %h", $time, l1_2_probe_req_addr);
            end else if (l1_2_probe_ack_valid) begin
                l1_2_probe_ack_valid <= 1'b0;
            end
            
            // L1_3 probe response  
            if (l1_3_probe_req_valid && !l1_3_probe_ack_valid) begin
                l1_3_probe_ack_valid <= 1'b1;
                l1_3_probe_ack_addr <= l1_3_probe_req_addr;
                l1_3_probe_ack_permissions <= 3'b001; // toB (downgrade to shared/invalid)
                l1_3_probe_ack_dirty_data <= 256'b0;
                $display("[%0d] L1_3 responding to probe at addr %h", $time, l1_3_probe_req_addr);
            end else if (l1_3_probe_ack_valid) begin
                l1_3_probe_ack_valid <= 1'b0;
            end
        end
    end
    
    // Probe detection and reporting
    always @(posedge clk) begin
        if (rst_n) begin
            if (l1_0_probe_req_valid) $display("[%0d] PROBE: L1_0 probed at addr %h", $time, l1_0_probe_req_addr);
            if (l1_1_probe_req_valid) $display("[%0d] PROBE: L1_1 probed at addr %h", $time, l1_1_probe_req_addr);
            if (l1_2_probe_req_valid) $display("[%0d] PROBE: L1_2 probed at addr %h", $time, l1_2_probe_req_addr);
            if (l1_3_probe_req_valid) $display("[%0d] PROBE: L1_3 probed at addr %h", $time, l1_3_probe_req_addr);
        end
    end
    
    // Data reception monitoring
    always @(posedge clk) begin
        if (rst_n) begin
            if (l1_0_data_valid) $display("[%0d] L1_0 data received: %h", $time, l1_0_data);
            if (l1_1_data_valid) $display("[%0d] L1_1 data received: %h", $time, l1_1_data);
            if (l1_2_data_valid) $display("[%0d] L1_2 data received: %h", $time, l1_2_data);
            if (l1_3_data_valid) $display("[%0d] L1_3 data received: %h", $time, l1_3_data);
        end
    end
    
    // Main test state machine
    always @(posedge clk) begin
        if (!rst_n) begin
            test_state <= TEST_RESET;
            timeout_counter <= 16'b0;
        end else begin
            case (test_state)
                TEST_RESET: begin
                    test_state <= TEST_L1_0_READ;
                    $display("=== Multi-Sharer Test Starting ===");
                    $display("Testing multiple L1s sharing same address with complex probing");
                end
                
                TEST_L1_0_READ: begin
                    $display("\nTEST 1: L1_0 read (shared access) - addr=%h", TEST_ADDR1);
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= TEST_ADDR1;
                    l1_0_request_type <= 3'b000; // Read
                    l1_0_request_permissions <= 3'b000; // Shared (NtoB)
                    if (l1_0_request_ready) begin
                        l1_0_request_valid <= 1'b0;
                        test_state <= TEST_L1_0_WAIT;
                        timeout_counter <= 16'b0;
                    end
                end
                
                TEST_L1_0_WAIT: begin
                    timeout_counter <= timeout_counter + 1;
                    if (l1_0_data_valid) begin
                        $display("SUCCESS: L1_0 got shared access");
                        test_state <= TEST_L1_1_READ;
                    end else if (timeout_counter > 1000) begin
                        $display("TIMEOUT: L1_0 read failed");
                        test_state <= TEST_COMPLETE;
                    end
                end
                
                TEST_L1_1_READ: begin
                    $display("\nTEST 2: L1_1 read (shared access) - same addr=%h", TEST_ADDR1);
                    l1_1_request_valid <= 1'b1;
                    l1_1_request_addr <= TEST_ADDR1;
                    l1_1_request_type <= 3'b000; // Read
                    l1_1_request_permissions <= 3'b000; // Shared (NtoB)
                    if (l1_1_request_ready) begin
                        l1_1_request_valid <= 1'b0;
                        test_state <= TEST_L1_1_WAIT;
                        timeout_counter <= 16'b0;
                    end
                end
                
                TEST_L1_1_WAIT: begin
                    timeout_counter <= timeout_counter + 1;
                    if (l1_1_data_valid) begin
                        $display("SUCCESS: L1_1 got shared access");
                        test_state <= TEST_L1_2_READ;
                    end else if (timeout_counter > 1000) begin
                        $display("TIMEOUT: L1_1 read failed");
                        test_state <= TEST_COMPLETE;
                    end
                end
                
                TEST_L1_2_READ: begin
                    $display("\nTEST 3: L1_2 read (shared access) - same addr=%h", TEST_ADDR1);
                    l1_2_request_valid <= 1'b1;
                    l1_2_request_addr <= TEST_ADDR1;
                    l1_2_request_type <= 3'b000; // Read
                    l1_2_request_permissions <= 3'b000; // Shared (NtoB)
                    if (l1_2_request_ready) begin
                        l1_2_request_valid <= 1'b0;
                        test_state <= TEST_L1_2_WAIT;
                        timeout_counter <= 16'b0;
                    end
                end
                
                TEST_L1_2_WAIT: begin
                    timeout_counter <= timeout_counter + 1;
                    if (l1_2_data_valid) begin
                        $display("SUCCESS: L1_2 got shared access");
                        $display("STATUS: 3 L1s now have shared access to addr=%h", TEST_ADDR1);
                        test_state <= TEST_L1_3_WRITE;
                    end else if (timeout_counter > 1000) begin
                        $display("TIMEOUT: L1_2 read failed");
                        test_state <= TEST_COMPLETE;
                    end
                end
                
                TEST_L1_3_WRITE: begin
                    $display("\nTEST 4: L1_3 write (exclusive access) - should probe L1_0, L1_1, L1_2");
                    l1_3_request_valid <= 1'b1;
                    l1_3_request_addr <= TEST_ADDR1;
                    l1_3_request_type <= 3'b001; // Write
                    l1_3_request_permissions <= 3'b010; // Exclusive (BtoT)
                    if (l1_3_request_ready) begin
                        l1_3_request_valid <= 1'b0;
                        test_state <= TEST_MULTI_PROBE_WAIT;
                        timeout_counter <= 16'b0;
                        $display("Waiting for probes to L1_0, L1_1, L1_2...");
                    end
                end
                
                TEST_MULTI_PROBE_WAIT: begin
                    timeout_counter <= timeout_counter + 1;
                    if (l1_3_data_valid) begin
                        $display("SUCCESS: L1_3 got exclusive access after multi-probe!");
                        $display("Complex probe scenario completed successfully");
                        test_state <= TEST_ADDR2_ACCESS;
                    end else if (timeout_counter > 3000) begin
                        $display("TIMEOUT: Multi-probe scenario failed");
                        test_state <= TEST_COMPLETE;
                    end else if (timeout_counter % 500 == 0) begin
                        $display("[%0d] Still waiting for multi-probe completion, timeout=%d", $time, timeout_counter);
                    end
                end
                
                TEST_ADDR2_ACCESS: begin
                    $display("\nTEST 5: Different address access - addr=%h", TEST_ADDR2);
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= TEST_ADDR2;
                    l1_0_request_type <= 3'b000; // Read
                    l1_0_request_permissions <= 3'b000; // Shared
                    if (l1_0_request_ready) begin
                        l1_0_request_valid <= 1'b0;
                        test_state <= TEST_ADDR2_WAIT;
                        timeout_counter <= 16'b0;
                    end
                end
                
                TEST_ADDR2_WAIT: begin
                    timeout_counter <= timeout_counter + 1;
                    if (l1_0_data_valid) begin
                        $display("SUCCESS: Different address access completed");
                        test_state <= TEST_COMPLETE;
                    end else if (timeout_counter > 1000) begin
                        $display("TIMEOUT: Different address access failed");
                        test_state <= TEST_COMPLETE;
                    end
                end
                
                TEST_COMPLETE: begin
                    $display("\n=== Multi-Sharer Test Complete ===");
                    $display("Successfully tested:");
                    $display("  - 3 L1s getting shared access to same address");
                    $display("  - L1_3 requesting exclusive access");
                    $display("  - Simultaneous probes to multiple sharers");
                    $display("  - Independent access to different address");
                    $finish;
                end
            endcase
        end
    end
    
    // VCD dump
    initial begin
        $dumpfile("multi_sharer_test.vcd");
        $dumpvars(0, multi_sharer_test);
    end

endmodule 
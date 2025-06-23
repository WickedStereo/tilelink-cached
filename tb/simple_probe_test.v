// Simple probe test for TIDC system
`include "tidc_params.v"

module simple_probe_test (
    input wire clk  // Clock driven from C++ for Verilator compatibility
);
    reg rst_n;
    
    // Test addresses and data
    parameter ADDR_A = 64'h0000000000001000;
    parameter DATA_PATTERN = 512'hDEADBEEFCAFEBABE0123456789ABCDEF0123456789ABCDEF0123456789ABCDEFDEADBEEFCAFEBABE0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF;
    
    // L1 adapter interfaces
    reg                         l1_0_request_valid;
    reg  [63:0]                 l1_0_request_addr;
    reg  [2:0]                  l1_0_request_type;
    reg  [511:0]                l1_0_request_data;
    reg  [2:0]                  l1_0_request_permissions;
    wire                        l1_0_request_ready;
    wire                        l1_0_data_valid;
    wire [511:0]                l1_0_data;
    wire                        l1_0_data_error;
    wire                        l1_0_probe_req_valid;
    wire [63:0]                 l1_0_probe_req_addr;
    wire [2:0]                  l1_0_probe_req_permissions;
    reg                         l1_0_probe_ack_valid;
    reg  [63:0]                 l1_0_probe_ack_addr;
    reg  [2:0]                  l1_0_probe_ack_permissions;
    reg  [511:0]                l1_0_probe_ack_dirty_data;
    
    reg                         l1_1_request_valid;
    reg  [63:0]                 l1_1_request_addr;
    reg  [2:0]                  l1_1_request_type;
    reg  [511:0]                l1_1_request_data;
    reg  [2:0]                  l1_1_request_permissions;
    wire                        l1_1_request_ready;
    wire                        l1_1_data_valid;
    wire [511:0]                l1_1_data;
    wire                        l1_1_data_error;
    wire                        l1_1_probe_req_valid;
    wire [63:0]                 l1_1_probe_req_addr;
    wire [2:0]                  l1_1_probe_req_permissions;
    reg                         l1_1_probe_ack_valid;
    reg  [63:0]                 l1_1_probe_ack_addr;
    reg  [2:0]                  l1_1_probe_ack_permissions;
    reg  [511:0]                l1_1_probe_ack_dirty_data;
    
    // L2 interface (simple memory model)
    wire                        l2_cmd_valid;
    wire [2:0]                  l2_cmd_type;
    wire [63:0]                 l2_cmd_addr;
    wire [511:0]                l2_cmd_data;
    wire [3:0]                  l2_cmd_size;
    wire                        l2_cmd_dirty;
    reg                         l2_response_valid;
    reg  [511:0]                l2_response_data;
    reg                         l2_response_error;
    

    
    // DUT instantiation
    /* verilator lint_off PINMISSING */
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
    reg [511:0] memory [0:1023];
    integer mem_idx;
    
    always @(posedge clk) begin
        l2_response_valid <= 1'b0;
        l2_response_error <= 1'b0;
        
        if (l2_cmd_valid) begin
            mem_idx = l2_cmd_addr[31:6]; // 64-byte aligned addressing
            case (l2_cmd_type)
                L2_CMD_READ: begin
                    l2_response_valid <= 1'b1;
                    l2_response_data <= memory[mem_idx];
                    $display("L2: Read addr=%h, data=%h", l2_cmd_addr, memory[mem_idx]);
                end
                L2_CMD_WRITE, L2_CMD_WRITE_BACK: begin
                    memory[mem_idx] <= l2_cmd_data;
                    l2_response_valid <= 1'b1;
                    l2_response_data <= l2_cmd_data;
                    $display("L2: Write addr=%h, data=%h", l2_cmd_addr, l2_cmd_data);
                end
            endcase
        end
    end
    
    // Initialize memory with pattern
    initial begin
        for (mem_idx = 0; mem_idx < 1024; mem_idx = mem_idx + 1) begin
            memory[mem_idx] = {16{mem_idx[7:0]}} | 512'hFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000000000;
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
                l1_0_probe_ack_dirty_data <= 512'b0;
                $display("PROBE: L1_0 responding to probe at addr %h", l1_0_probe_req_addr);
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
                l1_1_probe_ack_dirty_data <= 512'b0;
                $display("PROBE: L1_1 responding to probe at addr %h", l1_1_probe_req_addr);
            end else if (l1_1_probe_ack_valid) begin
                l1_1_probe_ack_valid <= 1'b0;
            end
        end
    end
    
    // Test state machine
    localparam TEST_RESET       = 4'd0;
    localparam TEST_L1_0_READ   = 4'd1;
    localparam TEST_L1_0_WAIT   = 4'd2;
    localparam TEST_L1_1_READ   = 4'd3;
    localparam TEST_L1_1_WAIT   = 4'd4;
    localparam TEST_L1_0_WRITE  = 4'd5;
    localparam TEST_L1_0_WWAIT  = 4'd6;
    localparam TEST_PROBE_WAIT  = 4'd7;
    localparam TEST_DONE        = 4'd8;
    
    reg [3:0] test_state;
    reg [15:0] wait_counter;
    reg [31:0] timeout_counter;
    
    // Reset and test control
    initial begin
        $display("Simple probe test starting...");
        rst_n = 0;
        test_state = TEST_RESET;
    end
    
    // Release reset after a few cycles
    reg [7:0] reset_counter;
    initial reset_counter = 0;
    
    always @(posedge clk) begin
        if (reset_counter < 8'd10) begin
            reset_counter <= reset_counter + 1;
            rst_n <= 1'b0;
        end else if (reset_counter == 8'd10) begin
            rst_n <= 1'b1;
            $display("Reset released, test_state = %d", test_state);
            reset_counter <= reset_counter + 1;
        end
    end
    
    // Debug state transitions
    reg [3:0] prev_test_state;
    always @(posedge clk) begin
        if (rst_n) begin
            if (prev_test_state != test_state) begin
                $display("[%0t] State transition: %d -> %d", $time, prev_test_state, test_state);
                prev_test_state <= test_state;
            end
        end else begin
            prev_test_state <= TEST_RESET;
        end
    end
    
    // Simple debug output
    always @(posedge clk) begin
        if (test_state == TEST_L1_0_READ && l1_0_request_valid && l1_0_request_ready) begin
            $display("L1_0 read request accepted at time %0t", $time);
        end
        if (test_state == TEST_L1_1_READ && l1_1_request_valid && l1_1_request_ready) begin
            $display("L1_1 read request accepted at time %0t", $time);
        end
        if (test_state == TEST_L1_0_WRITE && l1_0_request_valid && l1_0_request_ready) begin
            $display("L1_0 write request accepted at time %0t", $time);
        end
        if (l1_0_probe_req_valid || l1_1_probe_req_valid) begin
            $display("PROBE detected at time %0t: L1_0=%b, L1_1=%b", $time, l1_0_probe_req_valid, l1_1_probe_req_valid);
        end
        
        // Debug specific states
        if (test_state == TEST_PROBE_WAIT && (timeout_counter % 1000 == 0)) begin
            $display("[%0t] Still waiting for probe, timeout_counter=%d", $time, timeout_counter);
        end
        
        // Debug data reception  
        if (l1_0_data_valid) begin
            $display("[%0t] L1_0 data received: %h", $time, l1_0_data[63:0]);
        end
        if (l1_1_data_valid) begin
            $display("[%0t] L1_1 data received: %h", $time, l1_1_data[63:0]);
        end
    end
    
    always @(posedge clk) begin
        if (!rst_n) begin
            test_state <= TEST_RESET;
            wait_counter <= 16'd0;
            timeout_counter <= 32'd0;
            
            // Initialize all inputs
            l1_0_request_valid <= 1'b0;
            l1_0_request_addr <= 64'h0;
            l1_0_request_type <= 3'b000;
            l1_0_request_data <= 512'b0;
            l1_0_request_permissions <= 3'b000;
            
            l1_1_request_valid <= 1'b0;
            l1_1_request_addr <= 64'h0;
            l1_1_request_type <= 3'b000;
            l1_1_request_data <= 512'b0;
            l1_1_request_permissions <= 3'b000;
        end
        else begin
            // Timeout detection
            timeout_counter <= timeout_counter + 1;
            if (timeout_counter > 32'd50000) begin
                $display("ERROR: Test timeout at state %d", test_state);
                $finish;
            end
            
            // Default - clear valid signals
            l1_0_request_valid <= 1'b0;
            l1_1_request_valid <= 1'b0;
            
            case (test_state)
                TEST_RESET: begin
                    wait_counter <= wait_counter + 1;
                    if (wait_counter >= 16'd20) begin
                        $display("=== Simple Probe Test ===");
                        $display("TEST 1: L1_0 Read (Shared)");
                        test_state <= TEST_L1_0_READ;
                        wait_counter <= 16'd0;
                        timeout_counter <= 32'd0;
                    end
                    if (wait_counter == 16'd1) begin
                        $display("TEST_RESET state entered, wait_counter = %d", wait_counter);
                    end
                end
                
                TEST_L1_0_READ: begin
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= ADDR_A;
                    l1_0_request_type <= L1_REQ_READ_MISS;
                    l1_0_request_permissions <= PARAM_NtoB;
                    
                    if (l1_0_request_ready) begin
                        $display("L1_0 request accepted");
                        test_state <= TEST_L1_0_WAIT;
                        timeout_counter <= 32'd0;
                    end
                end
                
                TEST_L1_0_WAIT: begin
                    if (l1_0_data_valid) begin
                        $display("L1_0 received data: %h", l1_0_data[63:0]);
                        $display("TEST 2: L1_1 Read (Shared) - same address");
                        test_state <= TEST_L1_1_READ;
                        timeout_counter <= 32'd0;
                    end
                end
                
                TEST_L1_1_READ: begin
                    l1_1_request_valid <= 1'b1;
                    l1_1_request_addr <= ADDR_A;
                    l1_1_request_type <= L1_REQ_READ_MISS;
                    l1_1_request_permissions <= PARAM_NtoB;
                    
                    if (l1_1_request_ready) begin
                        $display("L1_1 request accepted");
                        test_state <= TEST_L1_1_WAIT;
                        timeout_counter <= 32'd0;
                    end
                end
                
                TEST_L1_1_WAIT: begin
                    if (l1_1_data_valid) begin
                        $display("L1_1 received data: %h", l1_1_data[63:0]);
                        $display("TEST 3: L1_0 Write (Exclusive) - should probe L1_1");
                        test_state <= TEST_L1_0_WRITE;
                        timeout_counter <= 32'd0;
                    end
                end
                
                TEST_L1_0_WRITE: begin
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= ADDR_A;
                    l1_0_request_type <= L1_REQ_WRITE_MISS;
                    l1_0_request_permissions <= PARAM_BtoT; // Upgrade to exclusive
                    l1_0_request_data <= DATA_PATTERN;
                    
                    if (l1_0_request_ready) begin
                        $display("L1_0 write upgrade request accepted");
                        test_state <= TEST_PROBE_WAIT;
                        timeout_counter <= 32'd0;
                    end
                end
                
                TEST_PROBE_WAIT: begin
                    if (l1_1_probe_req_valid) begin
                        $display("SUCCESS: L1_1 received probe!");
                        test_state <= TEST_L1_0_WWAIT;
                        timeout_counter <= 32'd0;
                    end
                end
                
                TEST_L1_0_WWAIT: begin
                    if (l1_0_data_valid) begin
                        $display("L1_0 received exclusive access");
                        test_state <= TEST_DONE;
                    end
                end
                
                TEST_DONE: begin
                    $display("=== Simple Probe Test Complete ===");
                    $finish;
                end
            endcase
        end
    end
    
    // Remove time-based timeout - we use cycle counter instead
    
    // Dump waves
    initial begin
        $dumpfile("simple_probe_test.vcd");
        $dumpvars(0, simple_probe_test);
    end
    
endmodule 
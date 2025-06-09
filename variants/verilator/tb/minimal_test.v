// Minimal test for TIDC system
`include "tidc_params.v"

module minimal_test (
    input wire clk  // Clock driven from C++ for Verilator compatibility
);
    reg rst_n;
    
    // Simple test address
    parameter ADDR_A = 32'h00001000;
    
    // L1_0 interface only
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
    
    // Reset control
    initial begin
        $display("Minimal test starting...");
        rst_n = 0;
        #50;
        rst_n = 1;
        $display("Reset complete");
    end
    
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
        
        // Tie off all other L1 interfaces
        .l1_1_request_valid(1'b0),
        .l1_1_request_addr(32'b0),
        .l1_1_request_type(3'b0),
        .l1_1_request_data(256'b0),
        .l1_1_request_permissions(3'b0),
        .l1_1_probe_ack_valid(1'b0),
        .l1_1_probe_ack_addr(32'b0),
        .l1_1_probe_ack_permissions(3'b0),
        .l1_1_probe_ack_dirty_data(256'b0),
        
        .l1_2_request_valid(1'b0),
        .l1_2_request_addr(32'b0),
        .l1_2_request_type(3'b0),
        .l1_2_request_data(256'b0),
        .l1_2_request_permissions(3'b0),
        .l1_2_probe_ack_valid(1'b0),
        .l1_2_probe_ack_addr(32'b0),
        .l1_2_probe_ack_permissions(3'b0),
        .l1_2_probe_ack_dirty_data(256'b0),
        
        .l1_3_request_valid(1'b0),
        .l1_3_request_addr(32'b0),
        .l1_3_request_type(3'b0),
        .l1_3_request_data(256'b0),
        .l1_3_request_permissions(3'b0),
        .l1_3_probe_ack_valid(1'b0),
        .l1_3_probe_ack_addr(32'b0),
        .l1_3_probe_ack_permissions(3'b0),
        .l1_3_probe_ack_dirty_data(256'b0),
        
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
    /* verilator lint_on PINMISSING */
    
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
    
    // Initialize memory
    initial begin
        for (mem_idx = 0; mem_idx < 1024; mem_idx = mem_idx + 1) begin
            memory[mem_idx] = {8{mem_idx[7:0]}} | 256'h1234567890ABCDEF;
        end
    end
    
    // Test sequence
    reg [3:0] test_state;
    reg [15:0] counter;
    
    localparam IDLE = 0, SEND_REQ = 1, WAIT_RESP = 2, DONE = 3;
    
    initial begin
        l1_0_request_valid = 0;
        l1_0_request_addr = 0;
        l1_0_request_type = 0;
        l1_0_request_data = 0;
        l1_0_request_permissions = 0;
        l1_0_probe_ack_valid = 0;
        l1_0_probe_ack_addr = 0;
        l1_0_probe_ack_permissions = 0;
        l1_0_probe_ack_dirty_data = 0;
        test_state = IDLE;
        counter = 0;
    end
    
    always @(posedge clk) begin
        if (!rst_n) begin
            test_state <= IDLE;
            counter <= 0;
            l1_0_request_valid <= 0;
        end
        else begin
            counter <= counter + 1;
            
            case (test_state)
                IDLE: begin
                    if (counter > 16'd10) begin
                        $display("Minimal test - no transactions, just reset check");
                        test_state <= DONE;
                    end
                end
                
                DONE: begin
                    $display("Test complete - basic reset/clock works");
                    $finish;
                end
            endcase
            
            if (counter > 16'd100) begin
                $display("Test timeout");
                $finish;
            end
        end
    end
    
    // Dump waves
    initial begin
        $dumpfile("minimal_test.vcd");
        $dumpvars(0, minimal_test);
    end
    
endmodule 
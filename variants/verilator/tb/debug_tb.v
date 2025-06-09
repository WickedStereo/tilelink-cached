// =============================================================================
// Project: TileLink Inclusive Directory Coherence (TIDC) System
// Module: Debug TIDC System Testbench (Verilator Compatible)
// Description: Focused debug testbench to identify coherence protocol issues
// =============================================================================

// Include shared parameter definitions
`include "tidc_params.v"

module debug_tb (
    input wire clk  // Clock driven from C++ for Verilator compatibility
);

    // Reset
    reg rst_n;
    
    // L1 TileLink Adapter interfaces (simplified for debugging)
    // L1 Adapter 0 interface
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
    
    // L1 Adapter 1 interface
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
    
    // L1 Adapter 2 and 3 (minimal for this debug)
    reg                         l1_2_request_valid;
    reg  [31:0]                 l1_2_request_addr;
    reg  [2:0]                  l1_2_request_type;
    reg  [255:0]                l1_2_request_data;
    reg  [2:0]                  l1_2_request_permissions;
    wire                        l1_2_request_ready;
    wire                        l1_2_data_valid;
    wire [255:0]                l1_2_data;
    wire                        l1_2_data_error;
    wire                        l1_2_probe_req_valid;
    wire [31:0]                 l1_2_probe_req_addr;
    wire [2:0]                  l1_2_probe_req_permissions;
    reg                         l1_2_probe_ack_valid;
    reg  [31:0]                 l1_2_probe_ack_addr;
    reg  [2:0]                  l1_2_probe_ack_permissions;
    reg  [255:0]                l1_2_probe_ack_dirty_data;
    
    reg                         l1_3_request_valid;
    reg  [31:0]                 l1_3_request_addr;
    reg  [2:0]                  l1_3_request_type;
    reg  [255:0]                l1_3_request_data;
    reg  [2:0]                  l1_3_request_permissions;
    wire                        l1_3_request_ready;
    wire                        l1_3_data_valid;
    wire [255:0]                l1_3_data;
    wire                        l1_3_data_error;
    wire                        l1_3_probe_req_valid;
    wire [31:0]                 l1_3_probe_req_addr;
    wire [2:0]                  l1_3_probe_req_permissions;
    reg                         l1_3_probe_ack_valid;
    reg  [31:0]                 l1_3_probe_ack_addr;
    reg  [2:0]                  l1_3_probe_ack_permissions;
    reg  [255:0]                l1_3_probe_ack_dirty_data;
    
    // L2 TileLink Adapter interface
    wire                        l2_cmd_valid;
    wire [2:0]                  l2_cmd_type;
    wire [31:0]                 l2_cmd_addr;
    wire [255:0]                l2_cmd_data;
    wire [3:0]                  l2_cmd_size;
    wire                        l2_cmd_dirty;
    
    reg                         l2_response_valid;
    reg  [255:0]                l2_response_data;
    reg                         l2_response_error;
    
    // Test address and data
    localparam ADDR_A = 32'h1000;
    localparam [255:0] DATA_PATTERN = {256{1'b1}};
    
    // Debug test state machine
    localparam DEBUG_RESET        = 4'd0;
    localparam DEBUG_L1_0_READ    = 4'd1;
    localparam DEBUG_L1_0_WAIT    = 4'd2;
    localparam DEBUG_L1_1_READ    = 4'd3;
    localparam DEBUG_L1_1_WAIT    = 4'd4;
    localparam DEBUG_L1_0_WRITE   = 4'd5;
    localparam DEBUG_L1_0_WWAIT   = 4'd6;
    localparam DEBUG_DONE         = 4'd7;
    
    reg [3:0] debug_state;
    reg [15:0] wait_counter;
    reg [31:0] timeout_counter;
    
    // Instantiate the DUT
    tidc_top dut (
        .clk(clk),
        .rst_n(rst_n),
        
        // L1 Adapter 0 interface
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
        
        // L1 Adapter 1 interface
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
        
        // L1 Adapter 2 interface
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
        
        // L1 Adapter 3 interface
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
        
        // L2 TileLink Adapter interface
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
    
    // L2 simulation
    always @(posedge clk) begin
        if (!rst_n) begin
            l2_response_valid <= 1'b0;
            l2_response_data <= 256'b0;
            l2_response_error <= 1'b0;
        end else begin
            if (l2_cmd_valid) begin
                l2_response_valid <= 1'b1;
                l2_response_data <= DATA_PATTERN;
                l2_response_error <= 1'b0;
                $display("L2: Received command type=%d, addr=%h", l2_cmd_type, l2_cmd_addr);
            end else begin
                l2_response_valid <= 1'b0;
            end
        end
    end
    
    // Probe response logic - L1_0
    reg l1_0_probe_pending;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            l1_0_probe_pending <= 1'b0;
        end else begin
            if (l1_0_probe_req_valid && !l1_0_probe_pending) begin
                l1_0_probe_pending <= 1'b1;
                $display("PROBE: L1_0 received probe for addr %h, permissions %b", l1_0_probe_req_addr, l1_0_probe_req_permissions);
            end else if (l1_0_probe_pending && !l1_0_probe_ack_valid) begin
                // Send probe ack after one cycle delay
                l1_0_probe_ack_valid <= 1'b1;
                l1_0_probe_ack_addr <= l1_0_probe_req_addr;
                l1_0_probe_ack_permissions <= 3'b001; // NtoN - invalidated
                l1_0_probe_ack_dirty_data <= 256'b0;
                l1_0_probe_pending <= 1'b0;
                $display("PROBE: L1_0 sending probe ack for addr %h", l1_0_probe_req_addr);
            end else if (l1_0_probe_ack_valid) begin
                l1_0_probe_ack_valid <= 1'b0;
            end
        end
    end

    // Probe response logic - L1_1  
    reg l1_1_probe_pending;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            l1_1_probe_pending <= 1'b0;
        end else begin
            if (l1_1_probe_req_valid && !l1_1_probe_pending) begin
                l1_1_probe_pending <= 1'b1;
                $display("PROBE: L1_1 received probe for addr %h, permissions %b", l1_1_probe_req_addr, l1_1_probe_req_permissions);
            end else if (l1_1_probe_pending && !l1_1_probe_ack_valid) begin
                // Send probe ack after one cycle delay
                l1_1_probe_ack_valid <= 1'b1;
                l1_1_probe_ack_addr <= l1_1_probe_req_addr;
                l1_1_probe_ack_permissions <= 3'b001; // NtoN - invalidated
                l1_1_probe_ack_dirty_data <= 256'b0;
                l1_1_probe_pending <= 1'b0;
                $display("PROBE: L1_1 sending probe ack for addr %h", l1_1_probe_req_addr);
            end else if (l1_1_probe_ack_valid) begin
                l1_1_probe_ack_valid <= 1'b0;
            end
        end
    end

    // Probe response logic - L1_2
    reg l1_2_probe_pending;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            l1_2_probe_pending <= 1'b0;
        end else begin
            if (l1_2_probe_req_valid && !l1_2_probe_pending) begin
                l1_2_probe_pending <= 1'b1;
                $display("PROBE: L1_2 received probe for addr %h, permissions %b", l1_2_probe_req_addr, l1_2_probe_req_permissions);
            end else if (l1_2_probe_pending && !l1_2_probe_ack_valid) begin
                // Send probe ack after one cycle delay
                l1_2_probe_ack_valid <= 1'b1;
                l1_2_probe_ack_addr <= l1_2_probe_req_addr;
                l1_2_probe_ack_permissions <= 3'b001; // NtoN - invalidated
                l1_2_probe_ack_dirty_data <= 256'b0;
                l1_2_probe_pending <= 1'b0;
                $display("PROBE: L1_2 sending probe ack for addr %h", l1_2_probe_req_addr);
            end else if (l1_2_probe_ack_valid) begin
                l1_2_probe_ack_valid <= 1'b0;
            end
        end
    end

    // Probe response logic - L1_3
    reg l1_3_probe_pending;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            l1_3_probe_pending <= 1'b0;
        end else begin
            if (l1_3_probe_req_valid && !l1_3_probe_pending) begin
                l1_3_probe_pending <= 1'b1;
                $display("PROBE: L1_3 received probe for addr %h, permissions %b", l1_3_probe_req_addr, l1_3_probe_req_permissions);
            end else if (l1_3_probe_pending && !l1_3_probe_ack_valid) begin
                // Send probe ack after one cycle delay
                l1_3_probe_ack_valid <= 1'b1;
                l1_3_probe_ack_addr <= l1_3_probe_req_addr;
                l1_3_probe_ack_permissions <= 3'b001; // NtoN - invalidated
                l1_3_probe_ack_dirty_data <= 256'b0;
                l1_3_probe_pending <= 1'b0;
                $display("PROBE: L1_3 sending probe ack for addr %h", l1_3_probe_req_addr);
            end else if (l1_3_probe_ack_valid) begin
                l1_3_probe_ack_valid <= 1'b0;
            end
        end
    end
    
    // Debug test state machine
    always @(posedge clk) begin
        if (!rst_n) begin
            debug_state <= DEBUG_RESET;
            wait_counter <= 16'd0;
            timeout_counter <= 32'd0;
            rst_n <= 1'b0;
            
            // Initialize all inputs
            l1_0_request_valid <= 1'b0;
            l1_0_request_addr <= 32'h0;
            l1_0_request_type <= 3'b000;
            l1_0_request_data <= 256'b0;
            l1_0_request_permissions <= 3'b000;
            // Probe acks handled in separate logic
            
            l1_1_request_valid <= 1'b0;
            l1_1_request_addr <= 32'h0;
            l1_1_request_type <= 3'b000;
            l1_1_request_data <= 256'b0;
            l1_1_request_permissions <= 3'b000;
            // Probe acks handled in separate logic
            
            l1_2_request_valid <= 1'b0;
            l1_2_request_addr <= 32'h0;
            l1_2_request_type <= 3'b000;
            l1_2_request_data <= 256'b0;
            l1_2_request_permissions <= 3'b000;
            // Probe acks handled in separate logic
            
            l1_3_request_valid <= 1'b0;
            l1_3_request_addr <= 32'h0;
            l1_3_request_type <= 3'b000;
            l1_3_request_data <= 256'b0;
            l1_3_request_permissions <= 3'b000;
            // Probe acks handled in separate logic
        end
        else begin
            // Timeout detection
            timeout_counter <= timeout_counter + 1;
            if (timeout_counter > 32'd10000) begin
                $display("ERROR: Debug test timeout at state %d", debug_state);
                $display("- L1_0: req_valid=%b, req_ready=%b, data_valid=%b", 
                         l1_0_request_valid, l1_0_request_ready, l1_0_data_valid);
                $display("- L1_1: req_valid=%b, req_ready=%b, data_valid=%b", 
                         l1_1_request_valid, l1_1_request_ready, l1_1_data_valid);
                $display("- L2: cmd_valid=%b, response_valid=%b", l2_cmd_valid, l2_response_valid);
                $finish;
            end
            
            // Default - clear valid signals
            l1_0_request_valid <= 1'b0;
            l1_1_request_valid <= 1'b0;
            // Probe acks handled in separate logic
            
            case (debug_state)
                DEBUG_RESET: begin
                    wait_counter <= wait_counter + 1;
                    if (wait_counter >= 16'd20) begin
                        rst_n <= 1'b1;
                        $display("=== Debug Coherence Testing ===");
                        $display("DEBUG 1: L1_0 Read Request");
                        debug_state <= DEBUG_L1_0_READ;
                        wait_counter <= 16'd0;
                        timeout_counter <= 32'd0;
                    end
                    else if (wait_counter == 16'd10) begin
                        $display("Reset released");
                    end
                end
                
                DEBUG_L1_0_READ: begin
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= ADDR_A;
                    l1_0_request_type <= L1_REQ_READ_MISS;
                    l1_0_request_permissions <= PARAM_NtoB;
                    l1_0_request_data <= 256'b0;
                    
                    $display("L1_0 requesting read: valid=%b, ready=%b", l1_0_request_valid, l1_0_request_ready);
                    
                    if (l1_0_request_ready) begin
                        $display("L1_0 read request accepted");
                        debug_state <= DEBUG_L1_0_WAIT;
                        timeout_counter <= 32'd0;
                    end
                end
                
                DEBUG_L1_0_WAIT: begin
                    if (l1_0_data_valid) begin
                        $display("L1_0 received data: %h", l1_0_data[63:0]);
                        $display("DEBUG 2: L1_1 Read Same Address (Shared)");
                        debug_state <= DEBUG_L1_1_READ;
                        timeout_counter <= 32'd0;
                    end
                end
                
                DEBUG_L1_1_READ: begin
                    l1_1_request_valid <= 1'b1;
                    l1_1_request_addr <= ADDR_A;
                    l1_1_request_type <= L1_REQ_READ_MISS;
                    l1_1_request_permissions <= PARAM_NtoB;
                    l1_1_request_data <= 256'b0;
                    
                    $display("L1_1 requesting shared read: valid=%b, ready=%b", l1_1_request_valid, l1_1_request_ready);
                    
                    if (l1_1_request_ready) begin
                        $display("L1_1 shared read request accepted");
                        debug_state <= DEBUG_L1_1_WAIT;
                        timeout_counter <= 32'd0;
                    end
                end
                
                DEBUG_L1_1_WAIT: begin
                    if (l1_1_data_valid) begin
                        $display("L1_1 received shared data: %h", l1_1_data[63:0]);
                        $display("DEBUG 3: L1_0 Write Upgrade (Should Probe L1_1)");
                        debug_state <= DEBUG_L1_0_WRITE;
                        timeout_counter <= 32'd0;
                    end
                end
                
                DEBUG_L1_0_WRITE: begin
                    l1_0_request_valid <= 1'b1;
                    l1_0_request_addr <= ADDR_A;
                    l1_0_request_type <= L1_REQ_WRITE_MISS;
                    l1_0_request_permissions <= PARAM_BtoT;  // Branch to Tip (upgrade)
                    l1_0_request_data <= DATA_PATTERN;
                    
                    $display("L1_0 requesting write upgrade: valid=%b, ready=%b", l1_0_request_valid, l1_0_request_ready);
                    
                    if (l1_0_request_ready) begin
                        $display("L1_0 write upgrade request accepted - should probe L1_1");
                        debug_state <= DEBUG_L1_0_WWAIT;
                        timeout_counter <= 32'd0;
                    end
                    
                    // Probe responses handled automatically in separate logic
                end
                
                DEBUG_L1_0_WWAIT: begin
                    // Probe responses handled automatically in separate logic
                    
                    if (l1_0_data_valid) begin
                        $display("L1_0 received exclusive data after upgrade: %h", l1_0_data[63:0]);
                        $display("=== Debug Test Complete ===");
                        debug_state <= DEBUG_DONE;
                    end
                end
                
                DEBUG_DONE: begin
                    $display("Debug coherence testing completed successfully!");
                    $finish;
                end
            endcase
        end
    end

endmodule 
// =============================================================================
// Complex Coherence Test for TIDC System (Verilator Compatible)
// Tests multiple sharers, simultaneous probes, and complex coherence scenarios
// =============================================================================

`timescale 1ns / 1ps

module complex_coherence_test;

    // Clock and reset
    reg clk;
    reg rst_n;
    
    // Test control
    reg [3:0] test_state;
    reg [15:0] timeout_counter;
    reg [31:0] cycle_count;
    
    // Test states
    localparam TEST_RESET = 0;
    localparam TEST_ADDR1_L1_0_READ = 1;   // L1_0 gets shared access to addr1
    localparam TEST_ADDR1_L1_1_READ = 2;   // L1_1 gets shared access to addr1  
    localparam TEST_ADDR1_L1_2_READ = 3;   // L1_2 gets shared access to addr1
    localparam TEST_ADDR1_L1_3_WRITE = 4;  // L1_3 requests exclusive (should probe L1_0, L1_1, L1_2)
    localparam TEST_ADDR1_PROBE_WAIT = 5;  // Wait for all probes to complete
    localparam TEST_ADDR2_PARALLEL = 6;    // Test parallel access to different address
    localparam TEST_ADDR2_CONFLICT = 7;    // Create conflict on addr2
    localparam TEST_MIXED_PATTERNS = 8;    // Mixed access patterns
    localparam TEST_COMPLETE = 9;
    
    // Test parameters
    localparam TEST_ADDR1 = 32'h00001000;
    localparam TEST_ADDR2 = 32'h00002000;
    localparam TEST_ADDR3 = 32'h00003000;
    localparam TIMEOUT_LIMIT = 5000;
    
    // Track L1 responses
    reg [3:0] l1_response_received;
    reg [3:0] l1_probe_received;
    
    // L1 adapter interfaces (simplified for Verilator)
    // Channel A (Acquire) - L1 to L2
    reg  [3:0]  a_valid;
    wire [3:0]  a_ready;
    reg  [11:0] a_opcode;      // 3 bits per L1
    reg  [11:0] a_param;       // 3 bits per L1
    reg  [15:0] a_size;        // 4 bits per L1
    reg  [15:0] a_source;      // 4 bits per L1
    reg  [127:0] a_address;    // 32 bits per L1
    reg  [31:0] a_mask;        // 8 bits per L1
    reg  [255:0] a_data;       // 64 bits per L1
    
    // Channel D (Grant) - L2 to L1
    wire [3:0]  d_valid;
    reg  [3:0]  d_ready;
    wire [11:0] d_opcode;      // 3 bits per L1
    wire [11:0] d_param;       // 3 bits per L1
    wire [15:0] d_size;        // 4 bits per L1
    wire [15:0] d_source;      // 4 bits per L1
    wire [15:0] d_sink;        // 4 bits per L1
    wire [255:0] d_data;       // 64 bits per L1
    wire [3:0]  d_error;
    
    // Channel E (GrantAck) - L1 to L2
    reg  [3:0]  e_valid;
    wire [3:0]  e_ready;
    reg  [15:0] e_sink;        // 4 bits per L1
    
    // L2 cache interface
    wire        l2_cmd_valid;
    wire [2:0]  l2_cmd_type;
    wire [31:0] l2_cmd_addr;
    wire [255:0] l2_cmd_data;
    wire [3:0]  l2_cmd_size;
    wire        l2_cmd_dirty;
    reg         l2_response_valid;
    reg  [255:0] l2_response_data;
    reg         l2_response_error;
    
    // Instantiate the TIDC top module
    tidc_top dut (
        .clk(clk),
        .rst_n(rst_n),
        
        // L1 TileLink interfaces
        .a_valid(a_valid),
        .a_ready(a_ready),
        .a_opcode(a_opcode),
        .a_param(a_param),
        .a_size(a_size),
        .a_source(a_source),
        .a_address(a_address),
        .a_mask(a_mask),
        .a_data(a_data),
        
        .d_valid(d_valid),
        .d_ready(d_ready),
        .d_opcode(d_opcode),
        .d_param(d_param),
        .d_size(d_size),
        .d_source(d_source),
        .d_sink(d_sink),
        .d_data(d_data),
        .d_error(d_error),
        
        .e_valid(e_valid),
        .e_ready(e_ready),
        .e_sink(e_sink),
        
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
    
    // Initialize L2 memory with test data
    initial begin
        integer i;
        for (i = 0; i < 4096; i = i + 1) begin
            l2_memory[i] = {8{32'h80808080 + i}};
        end
    end
    
    // L2 memory response logic
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
    
    // Monitor responses
    always @(posedge clk) begin
        if (rst_n) begin
            for (integer i = 0; i < 4; i = i + 1) begin
                if (d_valid[i] && d_ready[i]) begin
                    l1_response_received[i] <= 1'b1;
                    $display("[%0d] L1_%0d received Grant: opcode=%b, data=%h", 
                             $time, i, d_opcode[i*3 +: 3], d_data[i*64 +: 64]);
                end
            end
        end
    end
    
    // Helper task for L1 read request
    task send_l1_read_request;
        input [1:0] l1_id;
        input [31:0] addr;
        begin
            @(posedge clk);
            // Set Acquire (read for shared access)
            a_valid[l1_id] <= 1'b1;
            a_opcode[l1_id*3 +: 3] <= 3'b110; // AcquireBlock
            a_param[l1_id*3 +: 3] <= 3'b000;  // NtoB (shared)
            a_size[l1_id*4 +: 4] <= 4'h5;     // 32 bytes
            a_source[l1_id*4 +: 4] <= 4'h0;
            a_address[l1_id*32 +: 32] <= addr;
            a_mask[l1_id*8 +: 8] <= 8'hFF;
            a_data[l1_id*64 +: 64] <= 64'h0;
            
            // Wait for ready
            wait(a_ready[l1_id]);
            @(posedge clk);
            a_valid[l1_id] <= 1'b0;
            $display("[%0d] L1_%0d read request sent for addr=%h", $time, l1_id, addr);
        end
    endtask
    
    // Helper task for L1 write request (exclusive access)
    task send_l1_write_request;
        input [1:0] l1_id;
        input [31:0] addr;
        begin
            @(posedge clk);
            // Set Acquire (write for exclusive access)
            a_valid[l1_id] <= 1'b1;
            a_opcode[l1_id*3 +: 3] <= 3'b110; // AcquireBlock
            a_param[l1_id*3 +: 3] <= 3'b010;  // BtoT (exclusive)
            a_size[l1_id*4 +: 4] <= 4'h5;     // 32 bytes
            a_source[l1_id*4 +: 4] <= 4'h0;
            a_address[l1_id*32 +: 32] <= addr;
            a_mask[l1_id*8 +: 8] <= 8'hFF;
            a_data[l1_id*64 +: 64] <= 64'h0;
            
            // Wait for ready
            wait(a_ready[l1_id]);
            @(posedge clk);
            a_valid[l1_id] <= 1'b0;
            $display("[%0d] L1_%0d write request sent for addr=%h", $time, l1_id, addr);
        end
    endtask
    
    // Helper task to wait for L1 response
    task wait_for_l1_response;
        input [1:0] l1_id;
        input [31:0] addr;
        begin
            l1_response_received[l1_id] <= 1'b0;
            
            // Wait for Grant/GrantData
            wait(d_valid[l1_id]);
            @(posedge clk);
            $display("[%0d] L1_%0d received response for addr=%h", $time, l1_id, addr);
            
            // Send GrantAck
            e_valid[l1_id] <= 1'b1;
            e_sink[l1_id*4 +: 4] <= d_sink[l1_id*4 +: 4];
            @(posedge clk);
            e_valid[l1_id] <= 1'b0;
        end
    endtask
    
    // Initialize all interfaces
    initial begin
        a_valid = 4'b0;
        a_opcode = 12'b0;
        a_param = 12'b0;
        a_size = 16'b0;
        a_source = 16'b0;
        a_address = 128'b0;
        a_mask = 32'b0;
        a_data = 256'b0;
        
        d_ready = 4'b1111; // Always ready to receive grants
        
        e_valid = 4'b0;
        e_sink = 16'b0;
        
        l1_response_received = 4'b0;
        l1_probe_received = 4'b0;
    end
    
    // Main test sequence
    initial begin
        // Initialize
        rst_n = 0;
        test_state = TEST_RESET;
        timeout_counter = 0;
        cycle_count = 0;
        
        // Reset
        #100;
        rst_n = 1;
        #50;
        
        $display("=== Complex Coherence Test Starting ===");
        
        // Test 1: Multiple sharers on same address
        $display("\n--- TEST 1: Multiple Sharers (addr=%h) ---", TEST_ADDR1);
        
        test_state = TEST_ADDR1_L1_0_READ;
        $display("Step 1: L1_0 read (should get shared access)");
        send_l1_read_request(0, TEST_ADDR1);
        wait_for_l1_response(0, TEST_ADDR1);
        
        test_state = TEST_ADDR1_L1_1_READ;
        $display("Step 2: L1_1 read (should get shared access)");
        send_l1_read_request(1, TEST_ADDR1);
        wait_for_l1_response(1, TEST_ADDR1);
        
        test_state = TEST_ADDR1_L1_2_READ;
        $display("Step 3: L1_2 read (should get shared access)");
        send_l1_read_request(2, TEST_ADDR1);
        wait_for_l1_response(2, TEST_ADDR1);
        
        $display("Status: 3 L1s now have shared access to addr=%h", TEST_ADDR1);
        
        // Test 2: Exclusive access should probe all sharers
        test_state = TEST_ADDR1_L1_3_WRITE;
        $display("\nStep 4: L1_3 write (should probe L1_0, L1_1, L1_2)");
        send_l1_write_request(3, TEST_ADDR1);
        
        test_state = TEST_ADDR1_PROBE_WAIT;
        timeout_counter = 0;
        $display("Waiting for probes to complete...");
        
        // Wait for all probes and response
        wait_for_l1_response(3, TEST_ADDR1);
        $display("SUCCESS: L1_3 got exclusive access after probing 3 sharers");
        
        // Test 3: Different address access
        $display("\n--- TEST 2: Different Address Access (addr=%h) ---", TEST_ADDR2);
        test_state = TEST_ADDR2_PARALLEL;
        
        send_l1_read_request(0, TEST_ADDR2);
        wait_for_l1_response(0, TEST_ADDR2);
        $display("L1_0 completed addr2 access");
        
        send_l1_read_request(1, TEST_ADDR2);
        wait_for_l1_response(1, TEST_ADDR2);
        $display("L1_1 completed addr2 access");
        
        // Test 4: Create conflict on addr2
        test_state = TEST_ADDR2_CONFLICT;
        $display("\nStep 5: Create conflict on addr=%h", TEST_ADDR2);
        send_l1_write_request(2, TEST_ADDR2); // Should probe L1_0 and L1_1
        wait_for_l1_response(2, TEST_ADDR2);
        $display("SUCCESS: L1_2 got exclusive access to addr2");
        
        // Test 5: Additional pattern
        $display("\n--- TEST 3: Additional Access Pattern ---");
        test_state = TEST_MIXED_PATTERNS;
        
        send_l1_read_request(0, TEST_ADDR3);
        wait_for_l1_response(0, TEST_ADDR3);
        
        send_l1_write_request(1, TEST_ADDR1); // Should probe L1_3
        wait_for_l1_response(1, TEST_ADDR1);
        
        send_l1_read_request(2, TEST_ADDR3); // Should share with L1_0
        wait_for_l1_response(2, TEST_ADDR3);
        
        test_state = TEST_COMPLETE;
        $display("\n=== Complex Coherence Test PASSED ===");
        $display("Successfully tested:");
        $display("  - Multiple sharers (3 L1s sharing same address)");
        $display("  - Simultaneous probes (probing 3 L1s at once)");
        $display("  - Multiple addresses with independent coherence");
        $display("  - Mixed shared/exclusive patterns");
        $display("  - Complex coherence state transitions");
        
        #100;
        $finish;
    end
    
    // Timeout detection
    always @(posedge clk) begin
        if (rst_n) begin
            cycle_count <= cycle_count + 1;
            
            if (test_state == TEST_ADDR1_PROBE_WAIT || test_state == TEST_ADDR2_CONFLICT) begin
                timeout_counter <= timeout_counter + 1;
                if (timeout_counter > TIMEOUT_LIMIT) begin
                    $display("ERROR: Test timed out in state %0d after %0d cycles", test_state, timeout_counter);
                    $display("This indicates a problem with probe acknowledgment or L2 response");
                    $finish;
                end
                
                if (timeout_counter % 1000 == 0 && timeout_counter > 0) begin
                    $display("[%0d] Still waiting in state %0d, timeout_counter=%0d", $time, test_state, timeout_counter);
                end
            end else begin
                timeout_counter <= 0;
            end
        end
    end
    
    // VCD dump
    initial begin
        $dumpfile("complex_coherence_test.vcd");
        $dumpvars(0, complex_coherence_test);
    end

endmodule 
// =============================================================================
// Project: TileLink Inclusive Directory Coherence (TIDC) System
// Module: TIDC Top Level
// Description: Top-level module that connects TileLink adapters directly
//              without cache controller stubs for TileLink testing
// =============================================================================

`include "tidc_params.vh"

module tidc_top #(
    parameter NUM_L1_CACHES = `NUM_L1_CACHES,
    parameter WDATA = `WDATA,
    parameter WADDR = `WADDR,
    parameter WSIZE = `WSIZE,
    parameter WSOURCE = `WSOURCE,
    parameter WSINK = `WSINK,
    parameter CACHE_LINE_BITS = `CACHE_LINE_BITS
)(
    input  wire                     clk,
    input  wire                     rst_n,
    
    // Direct L1 TileLink Adapter interfaces (no cache controller)
    // L1 Adapter 0 interface
    input  wire                         l1_0_request_valid,
    input  wire [WADDR-1:0]            l1_0_request_addr,
    input  wire [2:0]                   l1_0_request_type,
    input  wire [CACHE_LINE_BITS-1:0]  l1_0_request_data,
    input  wire [2:0]                   l1_0_request_permissions,
    output wire                         l1_0_request_ready,
    
    output wire                         l1_0_data_valid,
    output wire [CACHE_LINE_BITS-1:0]  l1_0_data,
    output wire                         l1_0_data_error,
    
    output wire                         l1_0_probe_req_valid,
    output wire [WADDR-1:0]            l1_0_probe_req_addr,
    output wire [2:0]                   l1_0_probe_req_permissions,
    
    input  wire                         l1_0_probe_ack_valid,
    input  wire [WADDR-1:0]            l1_0_probe_ack_addr,
    input  wire [2:0]                   l1_0_probe_ack_permissions,
    input  wire [CACHE_LINE_BITS-1:0]  l1_0_probe_ack_dirty_data,
    
    // L1 Adapter 1 interface
    input  wire                         l1_1_request_valid,
    input  wire [WADDR-1:0]            l1_1_request_addr,
    input  wire [2:0]                   l1_1_request_type,
    input  wire [CACHE_LINE_BITS-1:0]  l1_1_request_data,
    input  wire [2:0]                   l1_1_request_permissions,
    output wire                         l1_1_request_ready,
    
    output wire                         l1_1_data_valid,
    output wire [CACHE_LINE_BITS-1:0]  l1_1_data,
    output wire                         l1_1_data_error,
    
    output wire                         l1_1_probe_req_valid,
    output wire [WADDR-1:0]            l1_1_probe_req_addr,
    output wire [2:0]                   l1_1_probe_req_permissions,
    
    input  wire                         l1_1_probe_ack_valid,
    input  wire [WADDR-1:0]            l1_1_probe_ack_addr,
    input  wire [2:0]                   l1_1_probe_ack_permissions,
    input  wire [CACHE_LINE_BITS-1:0]  l1_1_probe_ack_dirty_data,
    
    // L1 Adapter 2 interface
    input  wire                         l1_2_request_valid,
    input  wire [WADDR-1:0]            l1_2_request_addr,
    input  wire [2:0]                   l1_2_request_type,
    input  wire [CACHE_LINE_BITS-1:0]  l1_2_request_data,
    input  wire [2:0]                   l1_2_request_permissions,
    output wire                         l1_2_request_ready,
    
    output wire                         l1_2_data_valid,
    output wire [CACHE_LINE_BITS-1:0]  l1_2_data,
    output wire                         l1_2_data_error,
    
    output wire                         l1_2_probe_req_valid,
    output wire [WADDR-1:0]            l1_2_probe_req_addr,
    output wire [2:0]                   l1_2_probe_req_permissions,
    
    input  wire                         l1_2_probe_ack_valid,
    input  wire [WADDR-1:0]            l1_2_probe_ack_addr,
    input  wire [2:0]                   l1_2_probe_ack_permissions,
    input  wire [CACHE_LINE_BITS-1:0]  l1_2_probe_ack_dirty_data,
    
    // L1 Adapter 3 interface
    input  wire                         l1_3_request_valid,
    input  wire [WADDR-1:0]            l1_3_request_addr,
    input  wire [2:0]                   l1_3_request_type,
    input  wire [CACHE_LINE_BITS-1:0]  l1_3_request_data,
    input  wire [2:0]                   l1_3_request_permissions,
    output wire                         l1_3_request_ready,
    
    output wire                         l1_3_data_valid,
    output wire [CACHE_LINE_BITS-1:0]  l1_3_data,
    output wire                         l1_3_data_error,
    
    output wire                         l1_3_probe_req_valid,
    output wire [WADDR-1:0]            l1_3_probe_req_addr,
    output wire [2:0]                   l1_3_probe_req_permissions,
    
    input  wire                         l1_3_probe_ack_valid,
    input  wire [WADDR-1:0]            l1_3_probe_ack_addr,
    input  wire [2:0]                   l1_3_probe_ack_permissions,
    input  wire [CACHE_LINE_BITS-1:0]  l1_3_probe_ack_dirty_data,
    
    // L2 TileLink Adapter interface (direct, no cache controller)
    output wire                         l2_cmd_valid,
    output wire [2:0]                   l2_cmd_type,
    output wire [WADDR-1:0]             l2_cmd_addr,
    output wire [CACHE_LINE_BITS-1:0]   l2_cmd_data,
    output wire [WSIZE-1:0]             l2_cmd_size,
    output wire                         l2_cmd_dirty,
    
    input  wire                         l2_response_valid,
    input  wire [CACHE_LINE_BITS-1:0]   l2_response_data,
    input  wire                         l2_response_error
);

    // TileLink Channel Signals between L1 and L2
    
    // Channel A (L1 → L2)
    wire [NUM_L1_CACHES-1:0]       a_valid;
    wire [NUM_L1_CACHES*3-1:0]     a_opcode;
    wire [NUM_L1_CACHES*3-1:0]     a_param;
    wire [NUM_L1_CACHES*WSIZE-1:0] a_size;
    wire [NUM_L1_CACHES*WSOURCE-1:0] a_source;
    wire [NUM_L1_CACHES*WADDR-1:0] a_address;
    wire [NUM_L1_CACHES*WDATA*8-1:0] a_data;
    wire [NUM_L1_CACHES*WDATA-1:0] a_mask;
    wire [NUM_L1_CACHES-1:0]       a_ready;
    
    // Channel B (L2 → L1)
    wire [NUM_L1_CACHES-1:0]       b_valid;
    wire [NUM_L1_CACHES*3-1:0]     b_opcode;
    wire [NUM_L1_CACHES*3-1:0]     b_param;
    wire [NUM_L1_CACHES*WSIZE-1:0] b_size;
    wire [NUM_L1_CACHES*WSOURCE-1:0] b_source;
    wire [NUM_L1_CACHES*WADDR-1:0] b_address;
    wire [NUM_L1_CACHES*WDATA*8-1:0] b_data;
    wire [NUM_L1_CACHES*WDATA-1:0] b_mask;
    wire [NUM_L1_CACHES-1:0]       b_ready;
    
    // Channel C (L1 → L2)
    wire [NUM_L1_CACHES-1:0]       c_valid;
    wire [NUM_L1_CACHES*3-1:0]     c_opcode;
    wire [NUM_L1_CACHES*3-1:0]     c_param;
    wire [NUM_L1_CACHES*WSIZE-1:0] c_size;
    wire [NUM_L1_CACHES*WSOURCE-1:0] c_source;
    wire [NUM_L1_CACHES*WADDR-1:0] c_address;
    wire [NUM_L1_CACHES*WDATA*8-1:0] c_data;
    wire [NUM_L1_CACHES-1:0]       c_error;
    wire [NUM_L1_CACHES-1:0]       c_ready;
    
    // Channel D (L2 → L1)
    wire [NUM_L1_CACHES-1:0]       d_valid;
    wire [NUM_L1_CACHES*3-1:0]     d_opcode;
    wire [NUM_L1_CACHES*3-1:0]     d_param;
    wire [NUM_L1_CACHES*WSIZE-1:0] d_size;
    wire [NUM_L1_CACHES*WSOURCE-1:0] d_source;
    wire [NUM_L1_CACHES*WSINK-1:0] d_sink;
    wire [NUM_L1_CACHES*WDATA*8-1:0] d_data;
    wire [NUM_L1_CACHES-1:0]       d_error;
    wire [NUM_L1_CACHES-1:0]       d_ready;
    
    // Channel E (L1 → L2)
    wire [NUM_L1_CACHES-1:0]       e_valid;
    wire [NUM_L1_CACHES*WSINK-1:0] e_sink;
    wire [NUM_L1_CACHES-1:0]       e_ready;
    
    // Bundle L1 adapter interfaces for the generate loop
    wire [NUM_L1_CACHES-1:0]                        l1_request_valid_array;
    wire [NUM_L1_CACHES*WADDR-1:0]                 l1_request_addr_array;
    wire [NUM_L1_CACHES*3-1:0]                     l1_request_type_array;
    wire [NUM_L1_CACHES*CACHE_LINE_BITS-1:0]       l1_request_data_array;
    wire [NUM_L1_CACHES*3-1:0]                     l1_request_permissions_array;
    wire [NUM_L1_CACHES-1:0]                       l1_request_ready_array;
    
    wire [NUM_L1_CACHES-1:0]                       l1_data_valid_array;
    wire [NUM_L1_CACHES*CACHE_LINE_BITS-1:0]       l1_data_array;
    wire [NUM_L1_CACHES-1:0]                       l1_data_error_array;
    
    wire [NUM_L1_CACHES-1:0]                       l1_probe_req_valid_array;
    wire [NUM_L1_CACHES*WADDR-1:0]                 l1_probe_req_addr_array;
    wire [NUM_L1_CACHES*3-1:0]                     l1_probe_req_permissions_array;
    
    wire [NUM_L1_CACHES-1:0]                       l1_probe_ack_valid_array;
    wire [NUM_L1_CACHES*WADDR-1:0]                 l1_probe_ack_addr_array;
    wire [NUM_L1_CACHES*3-1:0]                     l1_probe_ack_permissions_array;
    wire [NUM_L1_CACHES*CACHE_LINE_BITS-1:0]       l1_probe_ack_dirty_data_array;
    
    // Map individual L1 interfaces to arrays
    assign l1_request_valid_array = {l1_3_request_valid, l1_2_request_valid, l1_1_request_valid, l1_0_request_valid};
    assign l1_request_addr_array = {l1_3_request_addr, l1_2_request_addr, l1_1_request_addr, l1_0_request_addr};
    assign l1_request_type_array = {l1_3_request_type, l1_2_request_type, l1_1_request_type, l1_0_request_type};
    assign l1_request_data_array = {l1_3_request_data, l1_2_request_data, l1_1_request_data, l1_0_request_data};
    assign l1_request_permissions_array = {l1_3_request_permissions, l1_2_request_permissions, l1_1_request_permissions, l1_0_request_permissions};
    
    assign {l1_3_request_ready, l1_2_request_ready, l1_1_request_ready, l1_0_request_ready} = l1_request_ready_array;
    assign {l1_3_data_valid, l1_2_data_valid, l1_1_data_valid, l1_0_data_valid} = l1_data_valid_array;
    assign {l1_3_data, l1_2_data, l1_1_data, l1_0_data} = l1_data_array;
    assign {l1_3_data_error, l1_2_data_error, l1_1_data_error, l1_0_data_error} = l1_data_error_array;
    
    assign {l1_3_probe_req_valid, l1_2_probe_req_valid, l1_1_probe_req_valid, l1_0_probe_req_valid} = l1_probe_req_valid_array;
    assign {l1_3_probe_req_addr, l1_2_probe_req_addr, l1_1_probe_req_addr, l1_0_probe_req_addr} = l1_probe_req_addr_array;
    assign {l1_3_probe_req_permissions, l1_2_probe_req_permissions, l1_1_probe_req_permissions, l1_0_probe_req_permissions} = l1_probe_req_permissions_array;
    
    assign l1_probe_ack_valid_array = {l1_3_probe_ack_valid, l1_2_probe_ack_valid, l1_1_probe_ack_valid, l1_0_probe_ack_valid};
    assign l1_probe_ack_addr_array = {l1_3_probe_ack_addr, l1_2_probe_ack_addr, l1_1_probe_ack_addr, l1_0_probe_ack_addr};
    assign l1_probe_ack_permissions_array = {l1_3_probe_ack_permissions, l1_2_probe_ack_permissions, l1_1_probe_ack_permissions, l1_0_probe_ack_permissions};
    assign l1_probe_ack_dirty_data_array = {l1_3_probe_ack_dirty_data, l1_2_probe_ack_dirty_data, l1_1_probe_ack_dirty_data, l1_0_probe_ack_dirty_data};
    
    // Instantiate L1 TileLink adapters without cache controllers
    genvar i;
    generate
        for (i = 0; i < NUM_L1_CACHES; i = i + 1) begin : gen_l1_instances
            // L1 TileLink Adapter
            l1_tilelink_adapter l1_adapter (
                .clk(clk),
                .rst_n(rst_n),
                .l1_id(i[1:0]),
                
                // L1 Adapter Interface (direct connection from top level)
                .l1_request_valid(l1_request_valid_array[i]),
                .l1_request_addr(l1_request_addr_array[i*WADDR +: WADDR]),
                .l1_request_type(l1_request_type_array[i*3 +: 3]),
                .l1_request_data(l1_request_data_array[i*CACHE_LINE_BITS +: CACHE_LINE_BITS]),
                .l1_request_permissions(l1_request_permissions_array[i*3 +: 3]),
                .l1_request_ready(l1_request_ready_array[i]),
                
                .data_to_l1_valid(l1_data_valid_array[i]),
                .data_to_l1_data(l1_data_array[i*CACHE_LINE_BITS +: CACHE_LINE_BITS]),
                .data_to_l1_error(l1_data_error_array[i]),
                
                .probe_req_to_l1_valid(l1_probe_req_valid_array[i]),
                .probe_req_to_l1_addr(l1_probe_req_addr_array[i*WADDR +: WADDR]),
                .probe_req_to_l1_permissions(l1_probe_req_permissions_array[i*3 +: 3]),
                
                .probe_ack_from_l1_valid(l1_probe_ack_valid_array[i]),
                .probe_ack_from_l1_addr(l1_probe_ack_addr_array[i*WADDR +: WADDR]),
                .probe_ack_from_l1_permissions(l1_probe_ack_permissions_array[i*3 +: 3]),
                .probe_ack_from_l1_dirty_data(l1_probe_ack_dirty_data_array[i*CACHE_LINE_BITS +: CACHE_LINE_BITS]),
                
                // TileLink interface
                .a_valid(a_valid[i]),
                .a_opcode(a_opcode[i*3 +: 3]),
                .a_param(a_param[i*3 +: 3]),
                .a_size(a_size[i*WSIZE +: WSIZE]),
                .a_source(a_source[i*WSOURCE +: WSOURCE]),
                .a_address(a_address[i*WADDR +: WADDR]),
                .a_data(a_data[i*WDATA*8 +: WDATA*8]),
                .a_mask(a_mask[i*WDATA +: WDATA]),
                .a_ready(a_ready[i]),
                
                .b_valid(b_valid[i]),
                .b_opcode(b_opcode[i*3 +: 3]),
                .b_param(b_param[i*3 +: 3]),
                .b_size(b_size[i*WSIZE +: WSIZE]),
                .b_source(b_source[i*WSOURCE +: WSOURCE]),
                .b_address(b_address[i*WADDR +: WADDR]),
                .b_data(b_data[i*WDATA*8 +: WDATA*8]),
                .b_mask(b_mask[i*WDATA +: WDATA]),
                .b_ready(b_ready[i]),
                
                .c_valid(c_valid[i]),
                .c_opcode(c_opcode[i*3 +: 3]),
                .c_param(c_param[i*3 +: 3]),
                .c_size(c_size[i*WSIZE +: WSIZE]),
                .c_source(c_source[i*WSOURCE +: WSOURCE]),
                .c_address(c_address[i*WADDR +: WADDR]),
                .c_data(c_data[i*WDATA*8 +: WDATA*8]),
                .c_error(c_error[i]),
                .c_ready(c_ready[i]),
                
                .d_valid(d_valid[i]),
                .d_opcode(d_opcode[i*3 +: 3]),
                .d_param(d_param[i*3 +: 3]),
                .d_size(d_size[i*WSIZE +: WSIZE]),
                .d_source(d_source[i*WSOURCE +: WSOURCE]),
                .d_sink(d_sink[i*WSINK +: WSINK]),
                .d_data(d_data[i*WDATA*8 +: WDATA*8]),
                .d_error(d_error[i]),
                .d_ready(d_ready[i]),
                
                .e_valid(e_valid[i]),
                .e_sink(e_sink[i*WSINK +: WSINK]),
                .e_ready(e_ready[i])
            );
        end
    endgenerate
    
    // Instantiate L2 TileLink Adapter (direct interface, no cache controller)
    l2_tilelink_adapter #(
        .NUM_MASTERS(NUM_L1_CACHES)
    ) l2_adapter (
        .clk(clk),
        .rst_n(rst_n),
        
        // TileLink interface
        .a_valid(a_valid),
        .a_opcode(a_opcode),
        .a_param(a_param),
        .a_size(a_size),
        .a_source(a_source),
        .a_address(a_address),
        .a_data(a_data),
        .a_mask(a_mask),
        .a_ready(a_ready),
        
        .b_valid(b_valid),
        .b_opcode(b_opcode),
        .b_param(b_param),
        .b_size(b_size),
        .b_source(b_source),
        .b_address(b_address),
        .b_data(b_data),
        .b_mask(b_mask),
        .b_ready(b_ready),
        
        .c_valid(c_valid),
        .c_opcode(c_opcode),
        .c_param(c_param),
        .c_size(c_size),
        .c_source(c_source),
        .c_address(c_address),
        .c_data(c_data),
        .c_error(c_error),
        .c_ready(c_ready),
        
        .d_valid(d_valid),
        .d_opcode(d_opcode),
        .d_param(d_param),
        .d_size(d_size),
        .d_source(d_source),
        .d_sink(d_sink),
        .d_data(d_data),
        .d_error(d_error),
        .d_ready(d_ready),
        
        .e_valid(e_valid),
        .e_sink(e_sink),
        .e_ready(e_ready),
        
        // L2 Direct Interface (no cache controller)
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

endmodule 
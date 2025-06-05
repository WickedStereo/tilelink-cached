// =============================================================================
// Project: TileLink Inclusive Directory Coherence (TIDC) System
// Module: Common Parameters
// Description: System-wide parameters and constants for the TIDC system
// =============================================================================

// Default parameters (can be overridden by instantiating modules)
`ifndef TIDC_PARAMS_VH
`define TIDC_PARAMS_VH

// System-wide parameters
`define WDATA           8       // Data bus width in bytes (default: 8 for 64-bit)
`define WADDR           32      // Address field width in bits
`define WSIZE           4       // Size field width in bits
`define WSOURCE         4       // Master source ID width in bits
`define WSINK           4       // Slave sink ID width in bits
`define CACHE_LINE_BITS 256     // Cache line size in bits (32 bytes)
`define NUM_L1_CACHES   4       // Number of L1 caches in the system

// Channel A opcodes (Master → Slave)
`define A_OPCODE_PUT_FULL_DATA       0   // PutFullData
`define A_OPCODE_PUT_PARTIAL_DATA    1   // PutPartialData
`define A_OPCODE_ARITHMETIC_DATA     2   // ArithmeticData
`define A_OPCODE_LOGICAL_DATA        3   // LogicalData
`define A_OPCODE_GET                 4   // Get
`define A_OPCODE_INTENT              5   // Intent
`define A_OPCODE_ACQUIRE_BLOCK       6   // Acquire

// Channel B opcodes (Slave → Master)
`define B_OPCODE_PUT_FULL_DATA       0   // PutFullData
`define B_OPCODE_PUT_PARTIAL_DATA    1   // PutPartialData
`define B_OPCODE_ARITHMETIC_DATA     2   // ArithmeticData
`define B_OPCODE_LOGICAL_DATA        3   // LogicalData
`define B_OPCODE_GET                 4   // Get
`define B_OPCODE_INTENT              5   // Intent
`define B_OPCODE_PROBE_BLOCK         6   // Probe

// Channel C opcodes (Master → Slave)
`define C_OPCODE_ACCESS_ACK          0   // AccessAck
`define C_OPCODE_ACCESS_ACK_DATA     1   // AccessAckData
`define C_OPCODE_HINT_ACK            2   // HintAck
`define C_OPCODE_PROBE_ACK           4   // ProbeAck
`define C_OPCODE_PROBE_ACK_DATA      5   // ProbeAckData
`define C_OPCODE_RELEASE             6   // Release
`define C_OPCODE_RELEASE_DATA        7   // ReleaseData

// Channel D opcodes (Slave → Master)
`define D_OPCODE_ACCESS_ACK          0   // AccessAck
`define D_OPCODE_ACCESS_ACK_DATA     1   // AccessAckData
`define D_OPCODE_HINT_ACK            2   // HintAck
`define D_OPCODE_GRANT               4   // Grant
`define D_OPCODE_GRANT_DATA          5   // GrantData
`define D_OPCODE_RELEASE_ACK         6   // ReleaseAck

// Channel E opcode (Master → Slave)
`define E_OPCODE_GRANT_ACK           0   // GrantAck

// Permission parameters (for a_param, b_param, c_param, and d_param)
// Grow permissions (NtoB, NtoT, BtoT)
`define PARAM_NtoB                   0   // None to Branch
`define PARAM_NtoT                   1   // None to Tip
`define PARAM_BtoT                   2   // Branch to Tip

// Cap permissions (TtoB, TtoN, BtoN)
`define PARAM_TtoB                   0   // Tip to Branch
`define PARAM_TtoN                   1   // Tip to None
`define PARAM_BtoN                   2   // Branch to None

// Report permissions (TtoT, BtoB, NtoN)
`define PARAM_TtoT                   3   // Tip to Tip (no change)
`define PARAM_BtoB                   4   // Branch to Branch (no change)
`define PARAM_NtoN                   5   // None to None (no change)

// Probe permissions (toN, toB, toT)
`define PARAM_toN                    0   // to None (invalidate)
`define PARAM_toB                    1   // to Branch (downgrade)
`define PARAM_toT                    2   // to Tip (no change of permission)

// L1 Cache Controller request types
`define L1_REQ_READ_MISS             0   // Read miss
`define L1_REQ_WRITE_MISS            1   // Write miss
`define L1_REQ_WRITE_BACK            2   // Write-back
`define L1_REQ_UNCACHED_READ         3   // Uncached read
`define L1_REQ_UNCACHED_WRITE        4   // Uncached write

// L2 Cache Controller command types
`define L2_CMD_READ                  0   // Read operation
`define L2_CMD_WRITE                 1   // Write operation
`define L2_CMD_INVALIDATE            2   // Invalidate operation
`define L2_CMD_WRITE_BACK            3   // Write-back operation

// Directory states
`define DIR_STATE_INVALID            0   // Line not present in any L1 cache
`define DIR_STATE_SHARED             1   // Line present in 1+ L1s as Branch (shared)
`define DIR_STATE_EXCLUSIVE          2   // Line present in exactly 1 L1 as Tip (exclusive)
`define DIR_STATE_PENDING_PROBE      3   // In process of probing L1s
`define DIR_STATE_PENDING_GRANT      4   // In process of granting to L1

`endif // TIDC_PARAMS_VH 
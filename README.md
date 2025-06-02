# TileLink Inclusive Directory Coherence (TIDC) System

This repository contains a Verilog implementation of a TileLink Inclusive Directory Coherence system, designed to provide cache coherence among four L1 caches and a unified L2 cache using the SiFive TileLink Cached (TL-C) protocol.

## System Overview

The TIDC system implements a directory-based cache coherence protocol using TileLink TL-C. It features:

- **Inclusive Coherence Policy**: Any cache line present in an L1 cache must also be present in the L2 cache
- **Directory-Based Coherence**: The L2 cache maintains a directory of L1 cache line states
- **Multiple Transaction Support**: Each L1 can have multiple outstanding transactions 
- **Protocol Compliance**: Follows the TileLink Cached (TL-C) protocol with five channels (A, B, C, D, E)

## Directory Structure

```
TIDC/
├── rtl/                  # All design files
│   ├── tidc_params.vh    # Common parameters and definitions
│   ├── tilelink_interfaces.v # TileLink channel interfaces
│   ├── source_id_manager.v   # Transaction ID management
│   ├── sink_id_manager.v     # Response ID management
│   ├── l1_*.v            # L1 cache components
│   ├── l2_*.v            # L2 cache components
│   └── tidc_top.v        # Top-level system integration
└── tb/                   # Testbenches
    └── tidc_system_tb.v  # System-level testbench
```

## Key Components

### 1. Source/Sink ID Management
- Each L1 TileLink Adapter has a Source ID Manager to allocate and deallocate transaction IDs
- The L2 TileLink Adapter has a Sink ID Manager to track outstanding Grant messages

### 2. Directory Structure
- The directory is implemented as a direct-mapped structure for simplicity
- Each entry tracks the global coherence state, L1 presence, and tip state vectors

### 3. Request Arbitration
- Round-robin arbitration among L1 requests with channel prioritization (C > A)
- Ensures fairness while maintaining protocol deadlock freedom

### 4. Coherence State Machine
- Implements the TL-C coherence protocol with NtoB, NtoT, BtoT state transitions
- Handles probe chains for invalidation and downgrade operations

## Building and Testing

To build and run the testbench, you'll need a Verilog simulator such as Icarus Verilog, ModelSim, or VCS.

Example command for Icarus Verilog:

```
iverilog -I./rtl -o tidc_sim.out tb/tidc_system_tb.v rtl/*.v
vvp tidc_sim.out
```

## License

[Specify license information here] 
# TIDC (TileLink to Directory Cache) - 2-Master System

A directory-based cache coherence system implementing TileLink protocol for 2 L1 cache masters, optimized for 64-bit systems.

## Overview

TIDC provides directory-based coherence for a 2-L1 cache system using the TileLink protocol. The design is optimized for Verilator simulation with hard-coded array sizes and simplified test infrastructure.

## Repository Structure

```
TIDC/
├── rtl/                   # RTL source files
│   ├── tidc_top.v        # Top module (2 L1 interfaces)
│   ├── directory.v       # Directory coherence engine
│   ├── l2_tilelink_adapter.v # L2 TileLink adapter
│   └── tidc_params.v     # System parameters
├── tb/                   # Testbenches
│   ├── simple_probe_test.v # Basic 2-L1 probe test
│   └── two_master_test.v   # Complete 2-L1 test
├── cpp/                  # Verilator C++ drivers
│   ├── main_simple_probe.cpp
│   └── main_two_master.cpp
├── Makefile             # Build system
├── README.md
└── .gitignore
```

## Quick Start

### Building and Running Tests

```bash
# Run the main 2-master test (default)
make

# Run specific tests
make two-master-test        # Complete 2-L1 coherence test
make simple-probe-test      # Basic probe mechanism test

# View waveforms
make waves                  # Opens GTKWave with simple probe test

# Clean build files
make clean

# Lint check
make lint
```

### Test Descriptions

- **`simple_probe_test`**: Basic 2-L1 scenario testing probe mechanism
  - L1_0 gets shared access → L1_1 gets shared access → L1_0 upgrades to exclusive (probes L1_1)
  
- **`two_master_test`**: Complete 2-L1 coherence validation
  - Tests multiple coherence scenarios with 2 L1 caches
  - Validates directory state transitions and probe responses

## System Architecture

### Core Components

- **`tidc_top.v`**: Top-level module with 2 L1 interfaces
- **`directory.v`**: Directory coherence controller with presence tracking
- **`l2_tilelink_adapter.v`**: Main state machine handling L1-L2 coordination
- **`sink_id_manager.v`**: TileLink sink ID management
- **`source_id_manager.v`**: TileLink source ID management

### Key Features

- **2-L1 Cache Support**: Designed specifically for dual L1 cache configuration
- **Directory Coherence**: MESI-style coherence with directory presence tracking
- **TileLink Protocol**: Full TileLink implementation for cache coherence
- **Verilator Optimized**: Hard-coded array sizes for fast simulation
- **64-bit System**: Optimized for 64-bit addresses and 64-byte cache lines
- **Probe Mechanism**: Sophisticated L1 cache probing for coherence maintenance

## Design Specifications

- **L1 Caches**: 2 masters supported
- **Cache Line Size**: 512 bits (64 bytes)
- **Address Width**: 64 bits
- **Data Width**: 512 bits
- **Protocol**: TileLink with MESI coherence
- **Simulation**: Verilator with C++ testbench drivers

## Development

### Adding New Tests

1. Create testbench in `tb/` directory
2. Create corresponding C++ driver in `cpp/` directory  
3. Add build target to `Makefile`
4. Follow existing naming conventions

### Debugging

- Use `make waves` to generate and view VCD waveforms
- Enable debug output with `$display` statements in testbenches
- Check lint issues with `make lint`


This system provides a clean, focused implementation of directory-based cache coherence for exactly 2 L1 caches on 64-bit systems. 
# TIDC (TileLink to Directory Cache)

This repository contains two variants of the TIDC design:

1. **Standard Variant**: Original parameterized design
2. **Verilator Variant**: De-parameterized version optimized for Verilator simulation

## Repository Structure

```
TIDC/
├── variants/
│   ├── standard/           # Original parameterized version
│   │   ├── rtl/           # RTL source files
│   │   ├── tb/            # Testbenches
│   │   └── Makefile       # Variant-specific Makefile
│   └── verilator/         # De-parameterized verilator version
│       ├── rtl/           # RTL source files
│       ├── tb/            # Testbenches and C++ testbench
│       └── Makefile       # Variant-specific Makefile
├── common/                # Shared utilities (if any)
├── docs/                  # Documentation
├── Makefile              # Top-level Makefile for variant selection
├── README.md
└── .gitignore
```

## Quick Start

### Building and Running Simulations

The top-level Makefile supports both variants. Use the `VARIANT` parameter to select which version to build:

```bash
# Build and run verilator variant (default)
make

# Build and run standard variant
make VARIANT=standard

# Build and run verilator variant explicitly
make VARIANT=verilator

# View waveforms for verilator variant
make VARIANT=verilator waves

# Run lint check on standard variant
make VARIANT=standard lint

# Clean all variants
make clean-all

# Test both variants
make test-all

# List available variants
make list-variants
```

### Variant-Specific Details

#### Standard Variant
- **Location**: `variants/standard/`
- **Features**: Full parameterized design
- **Simulation**: Standard Verilog simulator compatible
- **Build**: `make VARIANT=standard sim`

#### Verilator Variant
- **Location**: `variants/verilator/`  
- **Features**: De-parameterized for Verilator compatibility
- **Simulation**: Verilator with C++ testbench
- **Build**: `make VARIANT=verilator sim` or just `make`

## Development Workflow

### Working with Variants

**Switching between variants**:
   ```bash
   # Work on verilator variant
   cd variants/verilator
   make sim
   
   # Work on standard variant  
   cd variants/standard
   make sim
   ```
**Testing both variants**:
   ```bash
   # Test all variants from root
   make test-all
   ```

## Status

**Current Status: PRODUCTION READY** for multi-L1 cache coherence scenarios.

### **✅ Verilator Variant** (`variants/verilator/`)
- **Multi-L1 Coherence**: ✅ Production ready with 4-L1 validation
- **Probe Mechanism**: ✅ Sophisticated multi-probe generation working 
- **Test Coverage**: ✅ Comprehensive test suite with 3 scenarios
- **Performance**: ✅ ≤300 cycle multi-probe completion validated

**Quick Start**: `cd variants/verilator && make multi-sharer-test`

### **📋 Key Documentation**
- `TIDC_COMPREHENSIVE_TODO.md` - Complete task tracking and next steps
- `variants/verilator/ADVANCED_TESTING_RESULTS.md` - Detailed validation results
- `variants/verilator/QUICK_STATUS.md` - Quick reference for current state

This project has achieved sophisticated directory-based cache coherence with validated multi-L1 probe mechanisms.

## Contributing

When contributing:
1. Determine which variant(s) your changes affect
2. Make changes in the appropriate `variants/` directory
3. Test using the variant-specific workflow
4. Consider impact on other variants
5. Update documentation if needed 
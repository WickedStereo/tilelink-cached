# TIDC Comprehensive Test Suite

This comprehensive test suite significantly extends the coverage of the TileLink Inclusive Directory Coherence (TIDC) system beyond the existing basic tests.

## Test Coverage Comparison

### Existing Tests Coverage
1. **`simple_probe_test.v`**: Basic probe functionality
   - L1_0 reads (shared access)
   - L1_1 reads (shared access) 
   - L1_0 write upgrade (exclusive access) triggers probe to L1_1
   - Basic probe response handling

2. **`two_master_test.v`**: Two-master coherence scenarios
   - Both L1s get shared access to same address
   - L1_0 upgrades to exclusive, L1_1 gets probed
   - Validates basic coherence state transitions

### New Comprehensive Test Coverage

The comprehensive test (`comprehensive_test.v`) adds extensive coverage across **9 test phases**:

#### Phase 1: Basic Coherence Tests
- Extended coherence protocol validation
- Multiple permission transitions (NtoB, BtoT, NtoT)
- Parallel requests to different addresses
- Data validation and error detection

#### Phase 2: Multiple Address Tests  
- Concurrent access to different memory regions
- Address conflict resolution
- Parallel L1 operations without conflicts
- Cross-address coherence validation

#### Phase 3: Stress Testing
- High-frequency request generation
- Variable L2 response delays (configurable)
- Sustained load testing
- Arbitration under pressure

#### Phase 4: Write-back Scenarios
- Explicit write-back operations
- Dirty data eviction handling
- Write-back with probe conflicts
- Data integrity during evictions

#### Phase 5: Error Injection Testing
- L2 error response handling
- Invalid permission requests
- Misaligned address handling
- Error recovery validation

#### Phase 6: Rapid Request Testing
- Back-to-back requests every cycle
- Source/Sink ID management stress
- Request queue overflow handling
- High-throughput scenarios

#### Phase 7: Uncached Operations
- Uncached read/write operations
- Mixed cached/uncached access patterns
- Bypass cache coherence protocols
- Direct memory access testing

#### Phase 8: Corner Cases
- Simultaneous requests to same address
- Write upgrade conflicts
- Rapid permission changes
- Edge case address ranges (0x0, max address)

#### Phase 9: Final Reporting
- Comprehensive statistics collection
- Error analysis and reporting
- Performance metrics

## Enhanced Features

### 1. Sophisticated L2 Memory Model
```verilog
// Configurable response delays
reg [2:0] l2_response_delay; // 1-7 cycle delays
// Realistic memory simulation with timing
```

### 2. Advanced Probe Response Logic
```verilog
// Dirty data tracking per L1
reg l1_0_has_dirty_data;
reg [511:0] l1_0_cached_data;
// Proper dirty data responses during probes
```

### 3. Comprehensive Statistics and Monitoring
- Transaction counting
- Error detection and classification
- Performance metrics
- Real-time progress reporting
- Timeout detection per phase

### 4. Enhanced C++ Test Driver
```cpp
class TestStats {
    int l1_0_requests, l1_1_requests;
    int l1_0_responses, l1_1_responses;
    int l1_0_probes, l1_1_probes;
    int l2_commands, l2_responses;
    int errors_detected;
    // ... detailed statistics tracking
};
```

## Running the Comprehensive Test

### Build and Run
```bash
# Build and run (default target)
make comprehensive-test

# Or build manually
make obj_dir/Vcomprehensive_test
cd obj_dir && ./Vcomprehensive_test
```

### Command Line Options
```bash
# Run with custom parameters
./Vcomprehensive_test --cycles 100000 --no-waves

# Available options:
#   --cycles N     Set maximum simulation cycles (default: 50000)
#   --no-waves     Disable VCD waveform generation  
#   --help         Show help message
```

### Expected Output
```
=== Starting TIDC Comprehensive Test ===
Maximum cycles: 50000
Waveforms: Enabled
==========================================

=== PHASE 1: Basic Coherence Tests ===
Test 1: L1_0 read (shared)
Test 2: L1_1 read same address (shared)
...

=== Progress Report (Cycle 5000) ===
L1_0: 45 reqs, 42 resp, 12 probes
L1_1: 38 reqs, 35 resp, 8 probes
L2:   89 cmds, 89 resp
Errors: 0
=====================================

...

🎉 COMPREHENSIVE TEST: PASSED
All test phases completed successfully with no errors.
```

## Integration with Existing Tests

The comprehensive test complements existing tests:
- Run `simple-probe-test` for basic functionality
- Run `two-master-test` for focused coherence validation  
- Run `comprehensive-test` for full system verification

This provides a layered testing approach from basic functionality to comprehensive stress testing. 
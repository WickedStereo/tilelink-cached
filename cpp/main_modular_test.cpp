// =============================================================================
// Project: TileLink Inclusive Directory Coherence (TIDC) System
// File: main_modular_test.cpp
// Description: C++ wrapper for Verilator simulation of modular testbench
//              Uses the separated Stimulus, DUT, and Monitor architecture
// =============================================================================

#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtest_environment.h"
#include <iostream>
#include <memory>

// Simulation parameters
const int MAX_SIM_TIME = 100000;  // Maximum simulation cycles
const int VCD_START_TIME = 0;     // When to start VCD tracing

int main(int argc, char **argv) {
    // Initialize Verilator
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    
    // Create DUT instance
    auto dut = std::make_unique<Vtest_environment>();
    
    // Create VCD trace
    auto trace = std::make_unique<VerilatedVcdC>();
    dut->trace(trace.get(), 99);
    trace->open("modular_test.vcd");
    
    // Simulation variables
    uint64_t sim_time = 0;
    
    std::cout << "=============================================================================\n";
    std::cout << "TIDC Modular Test Environment - Verilator Simulation\n";
    std::cout << "=============================================================================\n";
    std::cout << "Starting simulation with separated Stimulus, DUT, and Monitor modules...\n";
    std::cout << "VCD trace file: modular_test.vcd\n";
    std::cout << "Maximum simulation time: " << MAX_SIM_TIME << " cycles\n";
    std::cout << "=============================================================================\n\n";
    
    // Simulation loop
    while (sim_time < MAX_SIM_TIME && !Verilated::gotFinish()) {
        // Toggle clock - the test environment generates its own clock
        // We just need to let the simulation run
        
        // Evaluate DUT
        dut->eval();
        
        // Write VCD trace
        if (sim_time >= VCD_START_TIME) {
            trace->dump(sim_time);
        }
        
        // Advance simulation time
        sim_time++;
        
        // Progress indicator every 10000 cycles
        if (sim_time % 10000 == 0) {
            std::cout << "Simulation progress: " << sim_time << " cycles\n";
        }
    }
    
    // Final evaluation
    dut->eval();
    if (sim_time >= VCD_START_TIME) {
        trace->dump(sim_time);
    }
    
    // Cleanup
    trace->close();
    
    // Print simulation summary
    std::cout << "\n=============================================================================\n";
    std::cout << "SIMULATION COMPLETE\n";
    std::cout << "=============================================================================\n";
    std::cout << "Total simulation cycles: " << sim_time << "\n";
    
    if (Verilated::gotFinish()) {
        std::cout << "Simulation finished successfully via $finish\n";
        std::cout << "Check console output above for detailed test results\n";
    } else {
        std::cout << "Simulation terminated due to maximum cycle limit\n";
        std::cout << "WARNING: Test may not have completed fully\n";
    }
    
    std::cout << "VCD trace written to: modular_test.vcd\n";
    std::cout << "=============================================================================\n";
    
    return 0;
} 
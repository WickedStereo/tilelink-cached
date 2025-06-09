#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Venhanced_tb.h"

#include <iostream>
#include <memory>

// Global time for Verilator
vluint64_t main_time = 0;

// Called by $time in Verilog
double sc_time_stamp() {
    return main_time;
}

int main(int argc, char **argv) {
    // Initialize Verilator
    Verilated::commandArgs(argc, argv);
    
    std::cout << "Starting Enhanced TIDC Coherence Testing..." << std::endl;
    
    // Create instance of our module under test
    auto dut = std::make_unique<Venhanced_tb>();
    
    // Initialize VCD tracing
    Verilated::traceEverOn(true);
    auto trace = std::make_unique<VerilatedVcdC>();
    dut->trace(trace.get(), 99);
    trace->open("enhanced_tidc_test.vcd");
    
    // Initialize inputs
    dut->clk = 0;
    
    std::cout << "Running enhanced coherence protocol tests..." << std::endl;
    
    // Run simulation
    const int MAX_SIM_TIME = 200000;  // More time for complex tests
    
    while (!Verilated::gotFinish() && main_time < MAX_SIM_TIME) {
        // Toggle clock
        dut->clk = !dut->clk;
        
        // Evaluate model
        dut->eval();
        
        // Dump trace
        trace->dump(main_time);
        
        // Increment time
        main_time++;
        
        // Progress indicator every 10000 cycles
        if (main_time % 10000 == 0) {
            std::cout << "Simulation time: " << main_time << " time units (clock cycles: " << main_time/2 << ")" << std::endl;
        }
    }
    
    // Final trace dump
    trace->dump(main_time);
    
    if (main_time >= MAX_SIM_TIME) {
        std::cout << "ERROR: Enhanced simulation timeout reached!" << std::endl;
        std::cout << "- Complex coherence tests may require more investigation" << std::endl;
        return 1;
    }
    
    std::cout << "Total simulation time: " << main_time << " time units (clock cycles: " << main_time/2 << ")" << std::endl;
    
    // Clean up
    trace->close();
    dut->final();
    
    std::cout << "Enhanced coherence testing completed successfully!" << std::endl;
    return 0;
} 
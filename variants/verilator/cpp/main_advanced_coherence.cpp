// =============================================================================
// C++ driver for Advanced Coherence Test
// Tests sophisticated cache coherence scenarios with rapid transitions
// Fixed for Verilator compatibility with external clock driving
// =============================================================================

#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vadvanced_coherence_test.h"

// Global time for VCD
vluint64_t main_time = 0;

// Called by $time in Verilog
double sc_time_stamp() {
    return main_time;
}

int main(int argc, char** argv) {
    // Initialize Verilator
    Verilated::commandArgs(argc, argv);
    
    // Create instance of our module
    Vadvanced_coherence_test* top = new Vadvanced_coherence_test;
    
    // Initialize VCD trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("advanced_coherence_test.vcd");
    
    // Initialize inputs
    top->clk = 0;
    top->rst_n = 0;
    
    printf("=== Starting Advanced Coherence Test ===\n");
    printf("Testing sophisticated cache coherence scenarios with rapid transitions.\n\n");
    
    // Run simulation with external clock driving
    while (!Verilated::gotFinish() && main_time < 2000000) {
        // Toggle clock every 5 time units (10ns period)
        if ((main_time % 5) == 0) {
            top->clk = !top->clk;
        }
        
        // Release reset after some cycles
        if (main_time > 100) {
            top->rst_n = 1;
        }
        
        // Evaluate model
        top->eval();
        
        // Dump trace
        tfp->dump(main_time);
        
        // Advance time
        main_time++;
    }
    
    // Cleanup
    tfp->close();
    delete top;
    delete tfp;
    
    printf("\n=== Advanced Coherence Test Completed ===\n");
    
    return 0;
} 
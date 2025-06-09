// =============================================================================
// C++ driver for Complex Coherence Test
// Drives clock and handles Verilator simulation for TIDC complex scenarios
// =============================================================================

#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vcomplex_coherence_test.h"

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
    Vcomplex_coherence_test* top = new Vcomplex_coherence_test;
    
    // Initialize VCD trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("complex_coherence_test.vcd");
    
    // Initialize inputs
    top->clk = 0;
    top->rst_n = 0;
    
    printf("=== Starting Complex Coherence Test ===\n");
    printf("This test exercises multiple sharers, simultaneous probes, and complex coherence patterns.\n\n");
    
    // Run simulation
    while (!Verilated::gotFinish() && main_time < 1000000) {
        // Toggle clock
        if ((main_time % 5) == 0) {
            top->clk = !top->clk;
        }
        
        // Release reset after a few cycles
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
    
    printf("\n=== Complex Coherence Test Completed ===\n");
    
    return 0;
} 
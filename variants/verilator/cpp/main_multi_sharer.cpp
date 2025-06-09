// =============================================================================
// C++ driver for Multi-Sharer Test
// Tests multiple L1s sharing the same cache line with complex probe scenarios
// =============================================================================

#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vmulti_sharer_test.h"

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
    Vmulti_sharer_test* top = new Vmulti_sharer_test;
    
    // Initialize VCD trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("multi_sharer_test.vcd");
    
    // Initialize inputs
    top->clk = 0;
    top->rst_n = 0;
    
    printf("=== Starting Multi-Sharer Test ===\n");
    printf("Testing multiple L1s sharing the same cache line and complex probe scenarios.\n\n");
    
    // Run simulation
    while (!Verilated::gotFinish() && main_time < 500000) {
        // Toggle clock every 5 time units
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
    
    printf("\n=== Multi-Sharer Test Completed ===\n");
    
    return 0;
} 
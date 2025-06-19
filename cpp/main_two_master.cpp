#include <iostream>
#include <memory>
#include <cstdlib>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtwo_master_test.h"

// Required for Verilator tracing
vluint64_t main_time = 0;
double sc_time_stamp() {
    return main_time;
}

int main(int argc, char** argv) {
    // Initialize Verilator
    Verilated::commandArgs(argc, argv);
    
    // Create instance
    auto tb = std::make_unique<Vtwo_master_test>();
    
    // Enable VCD tracing
    Verilated::traceEverOn(true);
    auto trace = std::make_unique<VerilatedVcdC>();
    tb->trace(trace.get(), 99);
    trace->open("two_master_test.vcd");
    
    // Initialize
    tb->clk = 0;
    
    // Run simulation
    int cycle = 0;
    while (!Verilated::gotFinish() && cycle < 10000) {
        // Drive clock low
        tb->clk = 0;
        tb->eval();
        trace->dump(main_time++);
        
        // Drive clock high
        tb->clk = 1;
        tb->eval();
        trace->dump(main_time++);
        
        cycle++;
    }
    
    // Cleanup
    trace->close();
    tb->final();
    
    if (cycle >= 10000) {
        std::cerr << "ERROR: Simulation timeout after " << cycle << " cycles" << std::endl;
        return 1;
    }
    
    std::cout << "Two master test completed successfully in " << cycle << " cycles" << std::endl;
    return 0;
} 
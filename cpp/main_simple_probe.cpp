#include <verilated.h>
#include <verilated_vcd_c.h>
#include <memory>
#include "Vsimple_probe_test.h"

// Required for Verilator tracing
vluint64_t main_time = 0;
double sc_time_stamp() {
    return main_time;
}

int main(int argc, char** argv) {
    // Initialize Verilator
    Verilated::commandArgs(argc, argv);
    
    // Create instance of our module under test
    auto top = std::make_unique<Vsimple_probe_test>();
    
    // Enable waveform dumping
    Verilated::traceEverOn(true);
    auto tfp = std::make_unique<VerilatedVcdC>();
    top->trace(tfp.get(), 0);
    tfp->open("simple_probe_test.vcd");
    
    // Initialize signals
    top->clk = 0;
    
    // Simulation loop with manual clock driving
    for (int cycle = 0; cycle < 100000 && !Verilated::gotFinish(); cycle++) {
        // Drive clock low
        top->clk = 0;
        top->eval();
        tfp->dump(main_time++);
        
        // Drive clock high
        top->clk = 1;
        top->eval();
        tfp->dump(main_time++);
        
        // Progress indication every 1000 cycles
        if (cycle % 1000 == 0) {
            printf("Cycle %d\n", cycle);
        }
    }
    
    if (!Verilated::gotFinish()) {
        printf("Simulation timeout reached\n");
    }
    
    // Cleanup
    tfp->close();
    top->final();
    
    return 0;
} 
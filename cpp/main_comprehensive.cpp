#include <verilated.h>
#include <verilated_vcd_c.h>
#include <memory>
#include <iostream>
#include <iomanip>
#include <chrono>
#include "Vcomprehensive_test.h"

// Required for Verilator tracing
vluint64_t main_time = 0;
double sc_time_stamp() {
    return main_time;
}

class TestStats {
public:
    int total_cycles = 0;
    int l1_0_requests = 0;
    int l1_1_requests = 0;
    int l1_0_responses = 0;
    int l1_1_responses = 0;
    int l1_0_probes = 0;
    int l1_1_probes = 0;
    int l2_commands = 0;
    int l2_responses = 0;
    int errors_detected = 0;
    
    void print_progress(int cycle) {
        if (cycle % 5000 == 0) {
            std::cout << "\n=== Progress Report (Cycle " << cycle << ") ===\n";
            std::cout << "L1_0: " << l1_0_requests << " reqs, " << l1_0_responses << " resp, " << l1_0_probes << " probes\n";
            std::cout << "L1_1: " << l1_1_requests << " reqs, " << l1_1_responses << " resp, " << l1_1_probes << " probes\n";
            std::cout << "L2:   " << l2_commands << " cmds, " << l2_responses << " resp\n";
            std::cout << "Errors: " << errors_detected << "\n";
            std::cout << "=====================================\n";
        }
    }
    
    void print_final_stats() {
        std::cout << "\n" << std::string(60, '=') << "\n";
        std::cout << "=== COMPREHENSIVE TEST STATISTICS ===\n";
        std::cout << std::string(60, '=') << "\n";
        std::cout << "Total simulation cycles: " << total_cycles << "\n";
        std::cout << "L1_0 - Requests: " << l1_0_requests << ", Responses: " << l1_0_responses << ", Probes: " << l1_0_probes << "\n";
        std::cout << "L1_1 - Requests: " << l1_1_requests << ", Responses: " << l1_1_responses << ", Probes: " << l1_1_probes << "\n";
        std::cout << "L2   - Commands: " << l2_commands << ", Responses: " << l2_responses << "\n";
        std::cout << "Total errors detected: " << errors_detected << "\n";
        std::cout << "Request success rate: " << std::fixed << std::setprecision(2) 
                  << (100.0 * (l1_0_responses + l1_1_responses) / (l1_0_requests + l1_1_requests)) << "%\n";
        std::cout << std::string(60, '=') << "\n";
    }
};

int main(int argc, char** argv) {
    // Parse command line arguments
    bool enable_waves = true;
    int max_cycles = 50000;
    
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "--no-waves") {
            enable_waves = false;
        } else if (std::string(argv[i]) == "--cycles" && i + 1 < argc) {
            max_cycles = std::atoi(argv[i + 1]);
            i++;
        } else if (std::string(argv[i]) == "--help") {
            std::cout << "Usage: " << argv[0] << " [options]\n";
            std::cout << "Options:\n";
            std::cout << "  --no-waves     Disable VCD waveform generation\n";
            std::cout << "  --cycles N     Set maximum simulation cycles (default: 50000)\n";
            std::cout << "  --help         Show this help message\n";
            return 0;
        }
    }
    
    // Initialize Verilator
    Verilated::commandArgs(argc, argv);
    
    // Create instance of our module under test
    auto top = std::make_unique<Vcomprehensive_test>();
    
    // Initialize statistics tracking
    TestStats stats;
    
    // Enable waveform dumping if requested
    std::unique_ptr<VerilatedVcdC> tfp;
    if (enable_waves) {
        std::cout << "Enabling waveform capture to comprehensive_test.vcd\n";
        Verilated::traceEverOn(true);
        tfp = std::make_unique<VerilatedVcdC>();
        top->trace(tfp.get(), 99);  // Trace 99 levels of hierarchy
        tfp->open("comprehensive_test.vcd");
    }
    
    // Initialize signals
    top->clk = 0;
    
    std::cout << "=== Starting TIDC Comprehensive Test ===\n";
    std::cout << "Maximum cycles: " << max_cycles << "\n";
    std::cout << "Waveforms: " << (enable_waves ? "Enabled" : "Disabled") << "\n";
    std::cout << "==========================================\n";
    
    auto start_time = std::chrono::high_resolution_clock::now();
    
    // Previous cycle values for edge detection
    bool prev_l1_0_request_valid = false;
    bool prev_l1_1_request_valid = false;
    bool prev_l1_0_data_valid = false;
    bool prev_l1_1_data_valid = false;
    bool prev_l1_0_probe_req_valid = false;
    bool prev_l1_1_probe_req_valid = false;
    bool prev_l2_cmd_valid = false;
    bool prev_l2_response_valid = false;
    
    // Simulation loop with manual clock driving
    for (int cycle = 0; cycle < max_cycles && !Verilated::gotFinish(); cycle++) {
        stats.total_cycles = cycle;
        
        // Drive clock low
        top->clk = 0;
        top->eval();
        if (enable_waves) tfp->dump(main_time++);
        
        // Drive clock high
        top->clk = 1;
        top->eval();
        if (enable_waves) tfp->dump(main_time++);
        
        // Collect statistics on positive clock edge
        // Count new requests (rising edge detection)
        if (top->l1_0_request_valid_out && !prev_l1_0_request_valid) {
            stats.l1_0_requests++;
        }
        if (top->l1_1_request_valid_out && !prev_l1_1_request_valid) {
            stats.l1_1_requests++;
        }
        
        // Count responses
        if (top->l1_0_data_valid_out && !prev_l1_0_data_valid) {
            stats.l1_0_responses++;
            if (top->l1_0_data_error_out) {
                stats.errors_detected++;
                std::cout << "ERROR: L1_0 data error at cycle " << cycle << "\n";
            }
        }
        if (top->l1_1_data_valid_out && !prev_l1_1_data_valid) {
            stats.l1_1_responses++;
            if (top->l1_1_data_error_out) {
                stats.errors_detected++;
                std::cout << "ERROR: L1_1 data error at cycle " << cycle << "\n";
            }
        }
        
        // Count probes
        if (top->l1_0_probe_req_valid_out && !prev_l1_0_probe_req_valid) {
            stats.l1_0_probes++;
        }
        if (top->l1_1_probe_req_valid_out && !prev_l1_1_probe_req_valid) {
            stats.l1_1_probes++;
        }
        
        // Count L2 activity
        if (top->l2_cmd_valid_out && !prev_l2_cmd_valid) {
            stats.l2_commands++;
        }
        if (top->l2_response_valid_out && !prev_l2_response_valid) {
            stats.l2_responses++;
            if (top->l2_response_error_out) {
                stats.errors_detected++;
                std::cout << "ERROR: L2 response error at cycle " << cycle << "\n";
            }
        }
        
        // Update previous values for edge detection
        prev_l1_0_request_valid = top->l1_0_request_valid_out;
        prev_l1_1_request_valid = top->l1_1_request_valid_out;
        prev_l1_0_data_valid = top->l1_0_data_valid_out;
        prev_l1_1_data_valid = top->l1_1_data_valid_out;
        prev_l1_0_probe_req_valid = top->l1_0_probe_req_valid_out;
        prev_l1_1_probe_req_valid = top->l1_1_probe_req_valid_out;
        prev_l2_cmd_valid = top->l2_cmd_valid_out;
        prev_l2_response_valid = top->l2_response_valid_out;
        
        // Print progress periodically
        stats.print_progress(cycle);
        
        // Early termination check for errors
        if (stats.errors_detected > 10) {
            std::cout << "\nToo many errors detected (" << stats.errors_detected 
                      << "), terminating early at cycle " << cycle << "\n";
            break;
        }
    }
    
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    
    if (!Verilated::gotFinish()) {
        std::cout << "\nSimulation completed by timeout (max cycles reached)\n";
    } else {
        std::cout << "\nSimulation completed normally\n";
    }
    
    // Print final statistics
    stats.print_final_stats();
    
    std::cout << "\nSimulation performance:\n";
    std::cout << "Simulation time: " << duration.count() << " ms\n";
    std::cout << "Simulation speed: " << std::fixed << std::setprecision(1) 
              << (stats.total_cycles * 1000.0 / duration.count()) << " cycles/second\n";
    
    // Test result summary
    bool all_tests_passed = (stats.errors_detected == 0) && 
                           (stats.l1_0_requests > 0) && 
                           (stats.l1_1_requests > 0) &&
                           (stats.l1_0_responses > 0) && 
                           (stats.l1_1_responses > 0);
    
    if (all_tests_passed) {
        std::cout << "\n🎉 COMPREHENSIVE TEST: PASSED\n";
        std::cout << "All test phases completed successfully with no errors.\n";
    } else {
        std::cout << "\n⚠️  COMPREHENSIVE TEST: FAILED\n";
        std::cout << "Some test phases failed or errors were detected.\n";
    }
    
    // Cleanup
    if (enable_waves) {
        tfp->close();
        std::cout << "\nWaveform data saved to comprehensive_test.vcd\n";
    }
    top->final();
    
    return all_tests_passed ? 0 : 1;
} 
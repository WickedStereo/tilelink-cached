## Makefile for TIDC System Simulation with Verilator

# Project settings
PROJECT = tidc_system
TB_MODULE = tidc_system_tb
DUT_MODULE = tidc_top

# Enhanced testing
ENHANCED_TB_MODULE = enhanced_tb

# Debug testing
DEBUG_TB_MODULE = debug_tb

# Simple probe testing
SIMPLE_PROBE_TB_MODULE = simple_probe_test

# Multi-sharer testing
MULTI_SHARER_TB_MODULE = multi_sharer_test

# Complex coherence testing
COMPLEX_COHERENCE_TB_MODULE = complex_coherence_test

# Advanced coherence testing
ADVANCED_COHERENCE_TB_MODULE = advanced_coherence_test

# Minimal testing
MINIMAL_TB_MODULE = minimal_test

# Source files
RTL_DIR = rtl
TB_DIR = tb
CPP_DIR = cpp
RTL_SOURCES = $(wildcard $(RTL_DIR)/*.v)
TB_SOURCES = $(TB_DIR)/tidc_system_tb_verilator.v $(CPP_DIR)/main.cpp
ENHANCED_TB_SOURCES = $(TB_DIR)/enhanced_tb.v $(CPP_DIR)/main_enhanced.cpp
DEBUG_TB_SOURCES = $(TB_DIR)/debug_tb.v $(CPP_DIR)/main_debug.cpp
SIMPLE_PROBE_TB_SOURCES = $(TB_DIR)/simple_probe_test.v $(CPP_DIR)/main_simple_probe.cpp
MULTI_SHARER_TB_SOURCES = $(TB_DIR)/multi_sharer_test.v $(CPP_DIR)/main_multi_sharer.cpp
COMPLEX_COHERENCE_TB_SOURCES = $(TB_DIR)/complex_coherence_test.v $(CPP_DIR)/main_complex_coherence.cpp
ADVANCED_COHERENCE_TB_SOURCES = $(TB_DIR)/advanced_coherence_test.v $(CPP_DIR)/main_advanced_coherence.cpp
MINIMAL_TB_SOURCES = $(TB_DIR)/minimal_test.v $(CPP_DIR)/main_minimal.cpp

# Build directory
BUILD_DIR = obj_dir

# Verilator settings
VERILATOR = verilator
VERILATOR_FLAGS = -Wall -Wno-UNUSED -Wno-UNOPTFLAT -Wno-WIDTH -Wno-CASEINCOMPLETE -Wno-STMTDLY -Wno-INFINITELOOP -Wno-SYNCASYNCNET -Wno-CMPCONST -Wno-DECLFILENAME --cc --exe --trace
VERILATOR_INCLUDES = -I$(RTL_DIR)

# C++ settings
CXX_FLAGS = -O3 -std=c++14

# Targets
.PHONY: all clean sim waves enhanced-sim enhanced-waves debug-sim debug-waves simple-probe-test simple-probe-waves multi-sharer-test multi-sharer-waves complex-coherence-test complex-coherence-waves advanced-coherence-test advanced-coherence-waves minimal-test

all: sim

# Build the simulation executable
$(BUILD_DIR)/V$(TB_MODULE): $(RTL_SOURCES) $(TB_SOURCES)
	@echo "Building with Verilator..."
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INCLUDES) \
		--top-module $(TB_MODULE) \
		$(TB_SOURCES) $(RTL_SOURCES) \
		--build -o V$(TB_MODULE)

# Build the enhanced simulation executable
$(BUILD_DIR)/V$(ENHANCED_TB_MODULE): $(RTL_SOURCES) $(ENHANCED_TB_SOURCES)
	@echo "Building enhanced testbench with Verilator..."
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INCLUDES) \
		--top-module $(ENHANCED_TB_MODULE) \
		$(ENHANCED_TB_SOURCES) $(RTL_SOURCES) \
		--build -o V$(ENHANCED_TB_MODULE)

# Build the debug simulation executable
$(BUILD_DIR)/V$(DEBUG_TB_MODULE): $(RTL_SOURCES) $(DEBUG_TB_SOURCES)
	@echo "Building debug testbench with Verilator..."
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INCLUDES) \
		--top-module $(DEBUG_TB_MODULE) \
		$(DEBUG_TB_SOURCES) $(RTL_SOURCES) \
		--build -o V$(DEBUG_TB_MODULE)

# Build the simple probe test executable
$(BUILD_DIR)/V$(SIMPLE_PROBE_TB_MODULE): $(RTL_SOURCES) $(SIMPLE_PROBE_TB_SOURCES)
	@echo "Building simple probe test with Verilator..."
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INCLUDES) \
		--top-module $(SIMPLE_PROBE_TB_MODULE) \
		$(SIMPLE_PROBE_TB_SOURCES) $(RTL_SOURCES) \
		--build -o V$(SIMPLE_PROBE_TB_MODULE)

# Build the multi-sharer test executable
$(BUILD_DIR)/V$(MULTI_SHARER_TB_MODULE): $(RTL_SOURCES) $(MULTI_SHARER_TB_SOURCES)
	@echo "Building multi-sharer test with Verilator..."
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INCLUDES) \
		--top-module $(MULTI_SHARER_TB_MODULE) \
		$(MULTI_SHARER_TB_SOURCES) $(RTL_SOURCES) \
		--build -o V$(MULTI_SHARER_TB_MODULE)

# Build the complex coherence test executable
$(BUILD_DIR)/V$(COMPLEX_COHERENCE_TB_MODULE): $(RTL_SOURCES) $(COMPLEX_COHERENCE_TB_SOURCES)
	@echo "Building complex coherence test with Verilator..."
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INCLUDES) \
		--top-module $(COMPLEX_COHERENCE_TB_MODULE) \
		$(COMPLEX_COHERENCE_TB_SOURCES) $(RTL_SOURCES) \
		--build -o V$(COMPLEX_COHERENCE_TB_MODULE)

# Build the advanced coherence test executable
$(BUILD_DIR)/V$(ADVANCED_COHERENCE_TB_MODULE): $(RTL_SOURCES) $(ADVANCED_COHERENCE_TB_SOURCES)
	@echo "Building advanced coherence test with Verilator..."
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INCLUDES) \
		--top-module $(ADVANCED_COHERENCE_TB_MODULE) \
		$(ADVANCED_COHERENCE_TB_SOURCES) $(RTL_SOURCES) \
		--build -o V$(ADVANCED_COHERENCE_TB_MODULE)

# Build the minimal test executable
$(BUILD_DIR)/V$(MINIMAL_TB_MODULE): $(RTL_SOURCES) $(MINIMAL_TB_SOURCES)
	@echo "Building minimal test with Verilator..."
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INCLUDES) \
		--top-module $(MINIMAL_TB_MODULE) \
		$(MINIMAL_TB_SOURCES) $(RTL_SOURCES) \
		--build -o V$(MINIMAL_TB_MODULE)

# Run the simulation
sim: $(BUILD_DIR)/V$(TB_MODULE)
	@echo "Running simulation..."
	cd $(BUILD_DIR) && ./V$(TB_MODULE)

# Run enhanced simulation
enhanced-sim: $(BUILD_DIR)/V$(ENHANCED_TB_MODULE)
	@echo "Running enhanced coherence tests..."
	cd $(BUILD_DIR) && ./V$(ENHANCED_TB_MODULE)

# Run debug simulation
debug-sim: $(BUILD_DIR)/V$(DEBUG_TB_MODULE)
	@echo "Running debug coherence tests..."
	cd $(BUILD_DIR) && ./V$(DEBUG_TB_MODULE)

# Run simple probe test
simple-probe-test: $(BUILD_DIR)/V$(SIMPLE_PROBE_TB_MODULE)
	@echo "Running simple probe test..."
	cd $(BUILD_DIR) && ./V$(SIMPLE_PROBE_TB_MODULE)

# Run multi-sharer test
multi-sharer-test: $(BUILD_DIR)/V$(MULTI_SHARER_TB_MODULE)
	@echo "Running multi-sharer test..."
	cd $(BUILD_DIR) && ./V$(MULTI_SHARER_TB_MODULE)

# Run complex coherence test
complex-coherence-test: $(BUILD_DIR)/V$(COMPLEX_COHERENCE_TB_MODULE)
	@echo "Running complex coherence test..."
	cd $(BUILD_DIR) && ./V$(COMPLEX_COHERENCE_TB_MODULE)

# Run advanced coherence test
advanced-coherence-test: $(BUILD_DIR)/V$(ADVANCED_COHERENCE_TB_MODULE)
	@echo "Running advanced coherence test..."
	cd $(BUILD_DIR) && ./V$(ADVANCED_COHERENCE_TB_MODULE)

# Run minimal test
minimal-test: $(BUILD_DIR)/V$(MINIMAL_TB_MODULE)
	@echo "Running minimal test..."
	cd $(BUILD_DIR) && ./V$(MINIMAL_TB_MODULE)

# View waveforms (requires GTKWave)
waves: sim
	@echo "Opening waveforms in GTKWave..."
	@if [ -f tidc_system_tb.vcd ]; then \
		gtkwave tidc_system_tb.vcd & \
	else \
		echo "VCD file not found. Make sure simulation ran successfully."; \
	fi

# View enhanced test waveforms
enhanced-waves: enhanced-sim
	@echo "Opening enhanced test waveforms in GTKWave..."
	@if [ -f enhanced_tidc_test.vcd ]; then \
		gtkwave enhanced_tidc_test.vcd & \
	else \
		echo "Enhanced VCD file not found. Make sure enhanced simulation ran successfully."; \
	fi

# View debug test waveforms
debug-waves: debug-sim
	@echo "Opening debug test waveforms in GTKWave..."
	@if [ -f debug_tidc_test.vcd ]; then \
		gtkwave debug_tidc_test.vcd & \
	else \
		echo "Debug VCD file not found. Make sure debug simulation ran successfully."; \
	fi

# View complex coherence test waveforms
complex-coherence-waves: complex-coherence-test
	@echo "Opening complex coherence test waveforms in GTKWave..."
	@if [ -f complex_coherence_test.vcd ]; then \
		gtkwave complex_coherence_test.vcd & \
	else \
		echo "Complex coherence VCD file not found. Make sure complex coherence simulation ran successfully."; \
	fi

# Clean build files
clean:
	@echo "Cleaning build files..."
	rm -rf $(BUILD_DIR)
	rm -f *.vcd
	rm -f *.out

# Quick lint check
lint: $(RTL_SOURCES)
	@echo "Running lint check..."
	$(VERILATOR) --lint-only $(VERILATOR_INCLUDES) $(RTL_SOURCES)

# Help
help:
	@echo "Available targets:"
	@echo "  all         - Build and run simulation (default)"
	@echo "  sim         - Build and run basic simulation"
	@echo "  enhanced-sim - Build and run enhanced coherence tests"
	@echo "  debug-sim   - Build and run debug coherence tests"
	@echo "  simple-probe-test - Build and run simple probe tests"
	@echo "  multi-sharer-test - Build and run multi-sharer tests"
	@echo "  complex-coherence-test - Build and run complex coherence tests"
	@echo "  waves       - Run simulation and open basic waveforms"
	@echo "  enhanced-waves - Run enhanced tests and open waveforms"
	@echo "  debug-waves - Run debug tests and open waveforms"
	@echo "  complex-coherence-waves - Run complex coherence tests and open waveforms"
	@echo "  lint        - Run lint check on RTL"
	@echo "  clean       - Clean build files"
	@echo "  help        - Show this help" 
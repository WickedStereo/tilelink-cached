## Makefile for TIDC 2-Master System Simulation with Verilator

# Project settings
PROJECT = tidc_system
SIMPLE_PROBE_TB_MODULE = simple_probe_test
TWO_MASTER_TB_MODULE = two_master_test
COMPREHENSIVE_TB_MODULE = comprehensive_test
MODULAR_TB_MODULE = test_environment
DUT_MODULE = tidc_top

# Source files
RTL_DIR = rtl
TB_DIR = tb
CPP_DIR = cpp
RTL_SOURCES = $(wildcard $(RTL_DIR)/*.v)
SIMPLE_PROBE_TB_SOURCES = $(TB_DIR)/simple_probe_test.v $(CPP_DIR)/main_simple_probe.cpp
TWO_MASTER_TB_SOURCES = $(TB_DIR)/two_master_test.v $(CPP_DIR)/main_two_master.cpp
COMPREHENSIVE_TB_SOURCES = $(TB_DIR)/comprehensive_test.v $(CPP_DIR)/main_comprehensive.cpp
MODULAR_TB_SOURCES = $(TB_DIR)/test_environment.v $(TB_DIR)/stimulus.v $(TB_DIR)/monitor.v $(CPP_DIR)/main_modular_test.cpp

# Build directory
BUILD_DIR = obj_dir

# Verilator settings
VERILATOR = verilator
VERILATOR_FLAGS = -Wall -Wno-UNUSED -Wno-UNOPTFLAT -Wno-WIDTH -Wno-CASEINCOMPLETE -Wno-STMTDLY -Wno-INFINITELOOP -Wno-SYNCASYNCNET -Wno-CMPCONST -Wno-DECLFILENAME --cc --exe --trace
VERILATOR_INCLUDES = -I$(RTL_DIR)

# C++ settings
CXX_FLAGS = -O3 -std=c++14

# Targets
.PHONY: all clean simple-probe-test two-master-test comprehensive-test modular-test waves lint help

all: modular-test

# Build the simple probe test executable
$(BUILD_DIR)/V$(SIMPLE_PROBE_TB_MODULE): $(RTL_SOURCES) $(SIMPLE_PROBE_TB_SOURCES)
	@echo "Building simple probe test with Verilator..."
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INCLUDES) \
		--top-module $(SIMPLE_PROBE_TB_MODULE) \
		$(SIMPLE_PROBE_TB_SOURCES) $(RTL_SOURCES) \
		--build -o V$(SIMPLE_PROBE_TB_MODULE)

# Build the two master test executable
$(BUILD_DIR)/V$(TWO_MASTER_TB_MODULE): $(RTL_SOURCES) $(TWO_MASTER_TB_SOURCES)
	@echo "Building two master test with Verilator..."
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INCLUDES) \
		--top-module $(TWO_MASTER_TB_MODULE) \
		$(TWO_MASTER_TB_SOURCES) $(RTL_SOURCES) \
		--build -o V$(TWO_MASTER_TB_MODULE)

# Build the comprehensive test executable
$(BUILD_DIR)/V$(COMPREHENSIVE_TB_MODULE): $(RTL_SOURCES) $(COMPREHENSIVE_TB_SOURCES)
	@echo "Building comprehensive test with Verilator..."
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INCLUDES) \
		--top-module $(COMPREHENSIVE_TB_MODULE) \
		$(COMPREHENSIVE_TB_SOURCES) $(RTL_SOURCES) \
		--build -o V$(COMPREHENSIVE_TB_MODULE)

# Build the modular test executable
$(BUILD_DIR)/V$(MODULAR_TB_MODULE): $(RTL_SOURCES) $(MODULAR_TB_SOURCES)
	@echo "Building modular test with Verilator..."
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INCLUDES) \
		--top-module $(MODULAR_TB_MODULE) \
		$(MODULAR_TB_SOURCES) $(RTL_SOURCES) \
		--build -o V$(MODULAR_TB_MODULE)


# Run simple probe test
simple-probe-test: $(BUILD_DIR)/V$(SIMPLE_PROBE_TB_MODULE)
	@echo "Running simple probe test..."
	cd $(BUILD_DIR) && ./V$(SIMPLE_PROBE_TB_MODULE)

# Run two master test
two-master-test: $(BUILD_DIR)/V$(TWO_MASTER_TB_MODULE)
	@echo "Running two master test..."
	cd $(BUILD_DIR) && ./V$(TWO_MASTER_TB_MODULE)

# Run comprehensive test
comprehensive-test: $(BUILD_DIR)/V$(COMPREHENSIVE_TB_MODULE)
	@echo "Running comprehensive test..."
	cd $(BUILD_DIR) && ./V$(COMPREHENSIVE_TB_MODULE)

# Run modular test
modular-test: $(BUILD_DIR)/V$(MODULAR_TB_MODULE)
	@echo "Running modular test..."
	cd $(BUILD_DIR) && ./V$(MODULAR_TB_MODULE)


# View waveforms (requires GTKWave)
waves: simple-probe-test
	@echo "Opening waveforms in GTKWave..."
	@if [ -f simple_probe_test.vcd ]; then \
		gtkwave simple_probe_test.vcd & \
	else \
		echo "VCD file not found. Make sure simulation ran successfully."; \
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
	@echo "  all                - Build and run modular test (default)"
	@echo "  simple-probe-test  - Build and run simple probe test"
	@echo "  two-master-test    - Build and run two master test"
	@echo "  comprehensive-test - Build and run comprehensive test suite"
	@echo "  modular-test       - Build and run modular test (Stimulus + DUT + Monitor)"
	@echo "  waves              - Run simple probe test and open waveforms"
	@echo "  lint               - Run lint check on RTL"
	@echo "  clean              - Clean build files"
	@echo "  help               - Show this help" 
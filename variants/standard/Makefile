## Makefile for TIDC System Simulation - Standard Variant

# Project settings
PROJECT = tidc_system
TB_MODULE = tidc_system_tb
DUT_MODULE = tidc_top

# Source files
RTL_DIR = rtl
TB_DIR = tb
RTL_SOURCES = $(wildcard $(RTL_DIR)/*.v)
TB_SOURCES = $(TB_DIR)/tidc_system_tb.v

# Build directory
BUILD_DIR = build

# Simulator settings (can be changed to iverilog, modelsim, etc.)
SIM = iverilog
SIM_FLAGS = -g2012
WAVE_VIEWER = gtkwave

# Targets
.PHONY: all clean sim waves lint help

all: sim

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile with iverilog (change for other simulators)
$(BUILD_DIR)/$(TB_MODULE): $(RTL_SOURCES) $(TB_SOURCES) | $(BUILD_DIR)
	@echo "Compiling with $(SIM)..."
	$(SIM) $(SIM_FLAGS) -o $@ -I$(RTL_DIR) $(TB_SOURCES) $(RTL_SOURCES)

# Run simulation
sim: $(BUILD_DIR)/$(TB_MODULE)
	@echo "Running simulation..."
	cd $(BUILD_DIR) && ./$(TB_MODULE)

# View waveforms (requires GTKWave)
waves: sim
	@echo "Opening waveforms in GTKWave..."
	@if [ -f $(BUILD_DIR)/tidc_system_tb.vcd ]; then \
		$(WAVE_VIEWER) $(BUILD_DIR)/tidc_system_tb.vcd & \
	elif [ -f tidc_system_tb.vcd ]; then \
		$(WAVE_VIEWER) tidc_system_tb.vcd & \
	else \
		echo "VCD file not found. Make sure simulation ran successfully."; \
	fi

# Clean build files
clean:
	@echo "Cleaning build files..."
	rm -rf $(BUILD_DIR)
	rm -f *.vcd
	rm -f *.out

# Lint check (basic syntax check with iverilog)
lint: $(RTL_SOURCES)
	@echo "Running lint check..."
	$(SIM) -t null -Wall $(SIM_FLAGS) -I$(RTL_DIR) $(RTL_SOURCES)

# Help
help:
	@echo "Available targets:"
	@echo "  all    - Build and run simulation (default)"
	@echo "  sim    - Build and run simulation"
	@echo "  waves  - Run simulation and open waveforms"
	@echo "  lint   - Run lint check on RTL"
	@echo "  clean  - Clean build files"
	@echo "  help   - Show this help"
	@echo ""
	@echo "Simulator settings:"
	@echo "  SIM=$(SIM) (can be changed to modelsim, vcs, etc.)"
	@echo "  SIM_FLAGS=$(SIM_FLAGS)" 
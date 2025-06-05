# TIDC Multi-Variant Makefile
# Supports both standard (parameterized) and verilator (de-parameterized) variants

# Default variant
VARIANT ?= verilator

# Variant directories
STANDARD_DIR = variants/standard
VERILATOR_DIR = variants/verilator

# Validate variant selection
ifeq ($(VARIANT),standard)
    VARIANT_DIR = $(STANDARD_DIR)
    MAKEFILE_PATH = $(STANDARD_DIR)/Makefile
else ifeq ($(VARIANT),verilator)
    VARIANT_DIR = $(VERILATOR_DIR)
    MAKEFILE_PATH = $(VERILATOR_DIR)/Makefile
else
    $(error Invalid VARIANT. Use 'standard' or 'verilator')
endif

.PHONY: all sim waves clean lint help list-variants

# Default target
all: check-variant sim

# Check if variant directory exists
check-variant:
	@if [ ! -d "$(VARIANT_DIR)" ]; then \
		echo "Error: Variant directory $(VARIANT_DIR) does not exist"; \
		echo "Available variants: $$(ls variants/ 2>/dev/null || echo 'none')"; \
		exit 1; \
	fi
	@if [ ! -f "$(MAKEFILE_PATH)" ]; then \
		echo "Error: Makefile not found at $(MAKEFILE_PATH)"; \
		exit 1; \
	fi
	@echo "Building variant: $(VARIANT)"

# Run simulation for selected variant
sim: check-variant
	@$(MAKE) -C $(VARIANT_DIR) sim

# View waveforms for selected variant
waves: check-variant
	@$(MAKE) -C $(VARIANT_DIR) waves

# Clean build files for selected variant
clean: check-variant
	@$(MAKE) -C $(VARIANT_DIR) clean

# Clean all variants
clean-all:
	@echo "Cleaning all variants..."
	@for variant in $$(ls variants/ 2>/dev/null || echo ''); do \
		if [ -f "variants/$$variant/Makefile" ]; then \
			echo "Cleaning $$variant..."; \
			$(MAKE) -C "variants/$$variant" clean; \
		fi; \
	done

# Lint check for selected variant
lint: check-variant
	@$(MAKE) -C $(VARIANT_DIR) lint

# List available variants
list-variants:
	@echo "Available variants:"
	@for variant in $$(ls variants/ 2>/dev/null || echo ''); do \
		echo "  $$variant"; \
	done

# Quick build and test both variants
test-all:
	@echo "Testing all variants..."
	@for variant in $$(ls variants/ 2>/dev/null || echo ''); do \
		if [ -f "variants/$$variant/Makefile" ]; then \
			echo "Testing $$variant..."; \
			$(MAKE) -C "variants/$$variant" sim || echo "$$variant failed"; \
		fi; \
	done

# Help
help:
	@echo "TIDC Multi-Variant Build System"
	@echo ""
	@echo "Usage:"
	@echo "  make [VARIANT=standard|verilator] [target]"
	@echo ""
	@echo "Available targets:"
	@echo "  all           - Build and run simulation (default)"
	@echo "  sim           - Build and run simulation"
	@echo "  waves         - Run simulation and open waveforms"
	@echo "  lint          - Run lint check on RTL"
	@echo "  clean         - Clean build files for selected variant"
	@echo "  clean-all     - Clean build files for all variants"
	@echo "  test-all      - Test all variants"
	@echo "  list-variants - List available variants"
	@echo "  help          - Show this help"
	@echo ""
	@echo "Examples:"
	@echo "  make                              # Build verilator variant (default)"
	@echo "  make VARIANT=standard sim         # Build standard variant"
	@echo "  make VARIANT=verilator waves      # Run verilator with waveforms"
	@echo "  make clean-all                    # Clean all variants" 
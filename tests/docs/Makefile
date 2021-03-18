# Root directory
BUILDROOT = ../..

# Build directory
BUILD_DIR = _docs

# Modules
MODULES = 
MODULES += os/sys os/dev

# Source directories
SOURCE_DIRS = $(addprefix $(BUILDROOT)/, $(MODULES))

all run check:
	export SOURCE_DIRS='$(SOURCE_DIRS)' \
	&& export BUILDROOT='$(BUILDROOT)' \
	&& doxygen Doxyfile -v

clean:
	rm -rf $(BUILDROOT)/$(BUILD_DIR)
# Root directory
BUILDROOT = ../..

# Build directory
BUILD_DIR = build

# Depth to search for C file
MODULES = apps/*

# Source directories
SOURCE_DIRS = $(addprefix $(BUILDROOT)/, $(MODULES))

# Applications Makefile
APPLICATIONS += $(foreach d, $(SOURCE_DIRS), $(subst /Makefile,,$(wildcard $(d)/Makefile)))

all clean:
	for dir in $(APPLICATIONS); do \
		$(MAKE) -C $$dir -f Makefile $@; \
	done

run check:
	for dir in $(APPLICATIONS); do \
		$(MAKE) -C $$dir -f Makefile || exit $$?; \
	done	
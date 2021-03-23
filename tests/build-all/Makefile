# Root directory
BUILDROOT = ../..

# Depth to search for C file
APPLICATIONS = apps/*

# Source directories
APPLICATIONS_DIRS = $(addprefix $(BUILDROOT)/, $(APPLICATIONS))

# Application makefiles
APPLICATIONS_MAKEFILES += $(foreach d, $(APPLICATIONS_DIRS), $(subst /Makefile,,$(wildcard $(d)/Makefile)))

# Boards
BOARDS = posix

all clean:
	@for board in $(BOARDS); do                              \
		for dir in $(APPLICATIONS_MAKEFILES); do            \
			$(MAKE) BOARD=$$board -C $$dir -f Makefile $@;  \
		done                                                \
	done

run check:
	@for board in $(BOARDS); do                                     \
		for dir in $(APPLICATIONS_MAKEFILES); do                    \
			$(MAKE) BOARD=$$board -C $$dir -f Makefile || exit $$?; \
		done                                                        \
	done

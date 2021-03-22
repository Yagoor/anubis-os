# Source directories
SOURCE_DIRS += $(BUILDROOT)/os

# C source files
SOURCE_C += os.c

# Include directories
INCLUDE_DIRS += $(BUILDROOT)/os/include

include $(BUILDROOT)/os/sys/sys.mk

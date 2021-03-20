# Source directories
SOURCE_DIRS += $(BUILDROOT)/board/posix

# C source files
SOURCE_C += clock.c
SOURCE_C += watchdog.c
SOURCE_C += random.c
SOURCE_C += timer.c

# Include directories

# SOC
include $(BUILDROOT)/soc/posix/posix.mk

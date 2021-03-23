# C source files
SOURCE_C += $(APP_C)

# Targets
TARGETS = $(BUILD_DIR)/$(APPNAME)

ifndef BOARD
$(error BOARD is not set)
endif

# Modules
include $(BUILDROOT)/os/os.mk
include $(BUILDROOT)/board/$(BOARD)/$(BOARD).mk

include $(BUILDROOT)/base.mk

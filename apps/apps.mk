# C source files
SOURCE_C += $(APP_C)

# Targets
TARGETS = $(BUILD_DIR)/$(APPNAME)

# Modules
include $(BUILDROOT)/os/os.mk

include $(BUILDROOT)/base.mk

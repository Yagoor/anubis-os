# Modules
MODULES = 
MODULES += os
MODULES += os/sys

# Source directories
SOURCE_DIRS = $(addprefix $(BUILDROOT)/, $(MODULES))

# C source files
SOURCE_C += $(APP_C)
SOURCE_C += $(foreach d, $(SOURCE_DIRS), $(subst $(d)/,,$(wildcard $(d)/*.c)))

# Includes for each module
INCLUDES += $(foreach m, $(foreach d, $(SOURCE_DIRS), $(d)/include), $(addprefix -I , $(m)))

TARGETS = $(BUILD_DIR)/$(APPNAME)

include $(BUILDROOT)/Makefile
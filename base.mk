# Binaries
CC = gcc
MKDIR = mkdir
RM = rm

# Build directory
BUILD_DIR = _build

# General options
C_FLAGS += -Wall -std=c11 -fPIC -MMD -MP
MKDIR_FLAGS += -p
RM_FLAGS += -rf

# Remove optmization and add debug flag if in debug mode
ifeq ($(DEBUG), 1)
C_FLAGS += -O0 -g 
else
C_FLAGS += -O3 -Werror
endif

# Objects from all sources
OBJECTS += $(foreach m, $(SOURCE_C), $(addprefix $(BUILD_DIR)/, $(addsuffix .o,$(basename $(m)))))

DEPS += $(foreach m, $(SOURCE_C), $(addprefix $(BUILD_DIR)/, $(addsuffix .d,$(basename $(m)))))

INCLUDES = $(foreach m, $(INCLUDE_DIRS), $(addprefix -I , $(m)))

# Vpath to allow out-of-tree build
vpath %.c $(SOURCE_DIRS)

# Normal make targets below

all : $(TARGETS)

$(TARGETS): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) -c $(C_FLAGS) $(INCLUDES) $< -o $@

$(BUILD_DIR):
	$(MKDIR) $(MKDIR_FLAGS) $@

clean :
	$(RM) $(RM_FLAGS) $(BUILD_DIR)

-include $(DEPS)
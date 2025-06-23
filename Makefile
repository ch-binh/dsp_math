# ==========================================
#   Unity Project - A Test Framework for C
# ==========================================

# === OS DETECTION ===
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # Not bash
    CLEANUP = del /F /Q
    CLEANDATA = del /F /Q
    MKDIR = mkdir
  else # Bash-like shell (e.g. Git Bash)
    CLEANUP = rm -f
    CLEANDATA = rm -rf
    MKDIR = mkdir -p
  endif
  TARGET_EXTENSION = .exe
else
  CLEANUP = rm -f
  CLEANDATA = rm -rf
  MKDIR = mkdir -p
  TARGET_EXTENSION = .out
endif

# === COMPILER ===
C_COMPILER := gcc
ifeq ($(shell uname -s), Darwin)
  C_COMPILER := clang
endif

# === FLAGS ===
CFLAGS := -std=c99 -Wall -Wextra -Wpointer-arith -Wcast-align -Wwrite-strings \
  -Wswitch-default -Wunreachable-code -Winit-self -Wmissing-field-initializers \
  -Wno-unknown-pragmas -Wstrict-prototypes -Wundef -Wold-style-definition -g

DLFLAGS := -mconsole

# === PATHS ===
UNITY_ROOT  := thirdparties/Unity
SRC_DIR     := src
TEST_DIR    := test
RUNNER_DIR  := $(TEST_DIR)/test_runners
BUILD_DIR   := build
DATA_DIR    := data

# === FILES ===
SRC_SRC       := $(wildcard $(SRC_DIR)/*.c)
TEST_SRC      := $(wildcard $(TEST_DIR)/Test*.c)
RUNNER_SRC    := $(wildcard $(RUNNER_DIR)/*.c)
UNITY_SRC     := $(UNITY_ROOT)/src/unity.c
UNITY_FIXTURE := $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c

SRC_FILES := $(UNITY_SRC) $(UNITY_FIXTURE) $(SRC_SRC) $(TEST_SRC) $(RUNNER_SRC)
OBJ_FILES := $(patsubst %.c, $(BUILD_DIR)/%.o, $(notdir $(SRC_FILES)))

# === TARGET ===
TARGET_BASE := test_all
TARGET      := $(BUILD_DIR)/$(TARGET_BASE)$(TARGET_EXTENSION)

# === INCLUDE + DEFINES ===
INC_DIRS := -I$(SRC_DIR) -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src
SYMBOLS  := -DUNITY_FIXTURE_NO_EXTRAS 
SYMBOLS  += -D_CONFIG_UNIT_TEST 
# for assertion ============================={
SYMBOLS  += -D__USE_FULL_ASSERTION
# for assertion =============================}
# for double ============================={
#SYMBOLS  += -D__CONFIG_USE_DOUBLE__
#SYMBOLS  += -DUNITY_INCLUDE_DOUBLE
#SYMBOLS  += -DUNITY_DOUBLE_PRECISION
#=========================================}
ifeq ($(LOG),1)
SYMBOLS += -D_CONFIG_UNIT_TEST_LOG
endif

# === DEFAULT ===
default: $(TARGET)

all: clean rm_data default 

run: rm_data default 
	@echo "==== Running Tests ===="
	@./$(TARGET) -v
	
clean:
	$(CLEANUP) $(BUILD_DIR)/* $(TARGET) 

rm_data:
	$(CLEANDATA) $(DATA_DIR)/* 

# === BUILD TARGET ===
$(TARGET): $(OBJ_FILES) | $(BUILD_DIR)
	$(C_COMPILER) $(CFLAGS) $(DLFLAGS) $(OBJ_FILES) -o $@

# === BUILD RULE FOR OBJECTS ===
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(C_COMPILER) $(CFLAGS) $(SYMBOLS) $(INC_DIRS) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c | $(BUILD_DIR)
	$(C_COMPILER) $(CFLAGS) $(SYMBOLS) $(INC_DIRS) -c $< -o $@

$(BUILD_DIR)/%.o: $(RUNNER_DIR)/%.c | $(BUILD_DIR)
	$(C_COMPILER) $(CFLAGS) $(SYMBOLS) $(INC_DIRS) -c $< -o $@

$(BUILD_DIR)/%.o: $(UNITY_ROOT)/src/%.c | $(BUILD_DIR)
	$(C_COMPILER) $(CFLAGS) $(SYMBOLS) $(INC_DIRS) -c $< -o $@

$(BUILD_DIR)/%.o: $(UNITY_ROOT)/extras/fixture/src/%.c | $(BUILD_DIR)
	$(C_COMPILER) $(CFLAGS) $(SYMBOLS) $(INC_DIRS) -c $< -o $@

# === BUILD DIR ===
$(BUILD_DIR):
	$(MKDIR) $(BUILD_DIR)

# === CLEAN ===


# === CI BUILD ===
ci: CFLAGS += -Werror
ci: all

.PHONY: all clean ci
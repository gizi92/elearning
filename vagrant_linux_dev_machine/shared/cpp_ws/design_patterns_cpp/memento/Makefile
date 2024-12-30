# Compiler
CXX = g++

# C++ version
CXXVERSION = -std=c++20

# Compiler flags
CXXFLAGS_RELEASE = -O2 $(CXXVERSION)
CXXFLAGS_DEBUG = -g $(CXXVERSION)

# Directories
BUILD_DIR = build
RELEASE_DIR = $(BUILD_DIR)/release
DEBUG_DIR = $(BUILD_DIR)/debug

# Target executable
TARGET = memento

# Source file
SRC = memento.cpp

# Default target
all: release

# Ensure build directories exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(RELEASE_DIR): | $(BUILD_DIR)
	mkdir -p $(RELEASE_DIR)

$(DEBUG_DIR): | $(BUILD_DIR)
	mkdir -p $(DEBUG_DIR)

# Release build
release: $(RELEASE_DIR)/$(TARGET)

$(RELEASE_DIR)/$(TARGET): $(SRC) | $(RELEASE_DIR)
	        $(CXX) $(CXXFLAGS_RELEASE) -o $(RELEASE_DIR)/$(TARGET) $(SRC)

# Debug build
debug: $(DEBUG_DIR)/$(TARGET)

$(DEBUG_DIR)/$(TARGET): $(SRC) | $(DEBUG_DIR)
	$(CXX) $(CXXFLAGS_DEBUG) -o $(DEBUG_DIR)/$(TARGET) $(SRC)

# Clean up
clean:
	        rm -rf $(BUILD_DIR)

.PHONY: all release debug clean

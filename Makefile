# Define the build directory path
BUILD_DIR = build

# Default target executed when you just type 'make'
.PHONY: all
all: build

# 1. Configure step (Generates build files and compile_commands.json)
.PHONY: configure
configure:
	cmake -B $(BUILD_DIR) -S .

# 2. Build step (Compiles the code without changing directories)
.PHONY: build
build: configure
	cmake --build $(BUILD_DIR)

# 3. Run step (Compiles first, then runs the binary)
.PHONY: run
run: build
	./$(BUILD_DIR)/coop

# 4. Clean step (Deletes the build folder entirely)
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)


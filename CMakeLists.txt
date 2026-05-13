# 1. Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# 2. Define the project name and language
project(MyCProject LANGUAGES C)

# Add this line to force CMake to generate the LSP file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 3. Specify the C standard (e.g., C11)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 4. Include the 'include' directory for header lookups
include_directories(include)

# 5. List source files and create the executable
add_executable(coop
  src/main.c
  src/animal.c
  src/cat.c
)


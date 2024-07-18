# Makefile for Server Project

# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Target executable
TARGET = server

# Source and object files
SRC = src/main.cpp
OBJ = $(SRC:.cpp=.o)

# Library source and object files
LIB_SRC = lib/string_to_int.cpp
LIB_OBJ = lib/string_to_int.o

# Library file
LIB = libstring_to_int.a

# Default target
all: $(TARGET)

# Compile library
$(LIB): $(LIB_OBJ)
	ar rcs $(LIB) $(LIB_OBJ)

# Link object files and libraries to create the executable
$(TARGET): $(OBJ) $(LIB)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) -L. -lstring_to_int

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -Iinclude -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(TARGET) $(OBJ) $(LIB) $(LIB_OBJ)

# Phony targets
.PHONY: all clean

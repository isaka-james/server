# Makefile for IsakaJames Server Project

# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Target executable
TARGET = server

# Source and object files
SRC = src/main.cpp
OBJ = $(SRC:.cpp=.o)

# Library source and object files
LIB_SRC = lib/strings_int_play.cpp
LIB_OBJ = lib/strings_int_play.o

# Library file
LIB = libstrings_play.a

# Default target
all: $(TARGET)

# Compile library
$(LIB): $(LIB_OBJ)
	ar rcs $(LIB) $(LIB_OBJ)

# Link object files and libraries to create the executable
$(TARGET): $(OBJ) $(LIB)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) -L. -lstrings_play

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -Iinclude -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(TARGET) $(OBJ) $(LIB) $(LIB_OBJ)

# Phony targets
.PHONY: all clean

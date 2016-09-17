# Compiler
CC = gcc
CXX = g++

# Compile options
CFLAGS = -Wall -O2
CXXFLAGS = -Wall -O2 -std=c++11

# Libraries
LIBS =

# Library include path
INCLUDES = -I./include

# Output executable file name
TARGET = chkNum

# Source code file name
SRCS = chkNum.cpp

# Object files
OBJ = $(SRCS:.cpp=.o)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) $(OBJ) -o $(TARGET)

$(OBJ): $(SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) -c $(SRCS)

# Clean compiled files
clean:
	@rm -rf $(TARGET) $(OBJ)



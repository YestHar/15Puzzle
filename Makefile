# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra
# Source files
SRCS = main.cpp \
        Board.cpp \
        Controller.cpp \
        Game.cpp \
        Visualization.cpp
# Header files
HEADERS = Board.hpp \
           Controller.hpp \
           Game.hpp \
           Visualization.hpp
# Output executable
TARGET = 15Puzzle

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(SRCS:.cpp=.o)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $^

# Rule to compile .cpp files to .o files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

# Clean up the build
clean:
	rm -f $(TARGET) *.o

# Phony targets
.PHONY: all clean

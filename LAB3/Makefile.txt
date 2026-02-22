CXX = g++
CXXFLAGS = -std=c++17 -O3 -Wall -Wextra -fopenmp -march=native
TARGET = correlate
SOURCES = main.cpp correlate.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp correlate.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET) 200 300 1 4

.PHONY: all clean run

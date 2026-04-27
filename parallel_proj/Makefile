CXX      = g++
CXXFLAGS = -std=c++17 -O2 -pthread -Wall -Wextra

TARGET = dag_scheduler
SRCS   = main.cpp scheduler.cpp
OBJS   = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

run: all
	./$(TARGET)

.PHONY: all clean run

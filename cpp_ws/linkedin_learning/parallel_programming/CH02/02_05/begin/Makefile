# Execution Scheduling Demo Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++11 -pthread
TARGET	 = execution_scheduling_demo
SRC		 = execution_scheduling_demo.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)
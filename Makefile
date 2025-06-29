CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = main.cpp generator/graph_generator.cpp
INC = -I./generator -I./utils

OUT = dead_cells

all:
	$(CXX) $(CXXFLAGS) $(SRC) $(INC) -o $(OUT)

clean:
	rm -f $(OUT)

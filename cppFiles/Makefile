CXX=g++
INC_DIR = ../hppFiles
CXXFLAGS = -c -Wall -I$(INC_DIR) -std=c++17

all: compile link

compile:
	$(CXX) $(CXXFLAGS) chessman.cpp converter.cpp main.cpp pawn.cpp
link:
	$(CXX) -std=c++17 -o main chessman.o converter.o main.o pawn.o
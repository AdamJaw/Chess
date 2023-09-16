CXX=g++
INC_DIR = ../hppFiles
CXXFLAGS = -c -Wall -I$(INC_DIR) -Isrc/include -std=c++17

all: compile link

compile:
	$(CXX) $(CXXFLAGS) chessman.cpp converter.cpp main.cpp pawn.cpp board.cpp
link:
	$(CXX) -std=c++17 chessman.o converter.o main.o pawn.o board.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
CXX=g++
INC_DIR = ../hppFiles
CXXFLAGS = -c -Wall -I$(INC_DIR) -Isrc/include -std=c++17

all: compile link

compile:
	$(CXX) $(CXXFLAGS) main.cpp board.cpp pawn.cpp chessman.cpp converter.cpp
link:
	$(CXX) -std=c++17 main.o board.o pawn.o chessman.o converter.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
CXX=g++
INC_DIR = ../hppFiles
CXXFLAGS = -c -Wall -I$(INC_DIR) -Isrc/include -std=c++17

all: compile link

compile:
	$(CXX) $(CXXFLAGS) main.cpp board.cpp converter.cpp pawn.cpp rook.cpp knight.cpp bishop.cpp queen.cpp king.cpp binaryboard.cpp
link:
	$(CXX) -std=c++17 main.o board.o converter.o pawn.o rook.o knight.o bishop.o queen.o king.o binaryboard.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
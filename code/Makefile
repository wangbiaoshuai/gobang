all: game.o

CXXFLAGS = -std=c++11 -O2 -Wall

game.o: src/game.cc
	$(CXX) -c $^ -o bin/game.o


.PHOYN: clean

clean:
	$(RM) -f bin/*

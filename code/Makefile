all: gobang

CXXFLAGS = -std=c++11 -O2 -Wall -g

gobang: main.o game.o
	$(CXX) -o gobang bin/main.o bin/game.o $(CXXFLAGS)

main.o: src/main.cc
	$(CXX) -c $^ -o bin/main.o $(CXXFLAGS)

game.o: src/game.cc
	$(CXX) -c $^ -o bin/game.o $(CXXFLAGS)


.PHOYN: clean

clean:
	$(RM) -f bin/* gobang

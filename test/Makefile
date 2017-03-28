all: test_target bin_test_gobang

INCLUDE = -I./include \
		  -I../code/src \

LIBS = -Wl,-R,"./lib" \
	   -L./lib -lgtest

CXXFLAGS = $(INCLUDE) \
		   $(LIBS) \
		   -std=c++11 -lpthread -Wall -O2

test_target:
	$(MAKE) -C ../code

bin_test_gobang: src/test_gobang.cc ../code/bin/game.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

.PHONY: clean

clean:
	$(RM) bin_test_gobang

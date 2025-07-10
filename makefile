CXX=g++
CXXFLAGS= -std=c++11 -Wall -Wextra -pedantic -g


.PHONY: all main test valgrind clean

all: Main test

Main: SquareMat.cpp main.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) SquareMat.cpp main.cpp -o matApp

test: SquareMat.cpp tests.cpp doctest.h
	$(CXX) $(CXXFLAGS) SquareMat.cpp tests.cpp -o testApp

valgrind: matApp testApp
	valgrind --leak-check=full --show-leak-kinds=all ./matApp
	valgrind --leak-check=full --show-leak-kinds=all ./testApp


clean:
	rm -f matApp testApp 


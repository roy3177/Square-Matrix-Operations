CXX=g++
CXXFLAGS= -std=c++11 -Wall -Wextra -pedantic -g
SRC=SquareMat.cpp
HEADERS=SquareMat.hpp
MAIN=main.cpp
TEST=tests.cpp
DOCTEST=doctest.h

TARGET_MAIN=matApp
TARGET_TEST=testApp

.PHONY: all main test valgrind clean

all: Main test

Main: $(SRC) $(MAIN) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) $(MAIN) -o $(TARGET_MAIN)

test: $(SRC) $(TEST) $(HEADERS) $(DOCTEST)
	$(CXX) $(CXXFLAGS) $(SRC) $(TEST) -o $(TARGET_TEST)

valgrind:test
	valgrind ./$(TARGET_TEST)

clean:
	rm -f $(TARGET_MAIN) $(TARGET_TEST)


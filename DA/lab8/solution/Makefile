CXX = g++
CXXFLAGS = -std=c++11 -O2 -Wextra -Wall -Werror -Wno-sign-compare -Wno-unused-result -pedantic
FILES = main.cpp
NAME = solution

all: main

main:
	$(CXX) $(CXXFLAGS) $(FILES) -o $(NAME)

clean:
	rm -f *.o $(NAME)
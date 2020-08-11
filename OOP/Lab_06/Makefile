CC = g++
FLAGS = -std=c++11 -Wall -Werror -Wno-sign-compare -Wno-unused-result
FILES = *.cpp
PROG = run

run: all
	./$(PROG)

all:
	$(CC) $(FLAGS) -o $(PROG) $(FILES)

clean:
	rm -f *.o run
CXX_FLAG = --std=c++11 -g

all: game tests
game: main.o cards.o utility.o
	g++ $(CXX_FLAG) -o game main.o cards.o utility.o

cards.o: cards.cpp
	g++ -c $(CXX_FLAG) cards.cpp

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

utility.o: utility.cpp
	g++ -c $(CXX_FLAG) utility.cpp

tests: tests.o cards.o utility.o
	g++ $(CXX_FLAG) -o tests tests.o cards.o utility.o
tests.o: tests.cpp
	g++ -c $(CXX_FLAG) tests.cpp

clean:
	rm -f main main *.o game

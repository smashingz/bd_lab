SRC = lab1
.PHONY: all clean

all: $(SRC).o
	g++ -o $(SRC).out $(SRC).o `pkg-config --libs --cflags libpqxx`

$(SRC).o: main.cpp
	g++ -g -c -o $(SRC).o main.cpp

clean:
	rm -f *.o *.out

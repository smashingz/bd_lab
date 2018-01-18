.PHONY: all clean

SRC = lab1
LIBS = libpqxx gtkmm-3.0
INCLUDE = `pkg-config $(LIBS) --cflags --libs`

all: $(SRC).o
	g++ -o $(SRC).out $(SRC).o $(INCLUDE)

$(SRC).o: main.cpp
	g++ -g -c -o $(SRC).o main.cpp $(INCLUDE)

clean:
	rm -f *.o *.out

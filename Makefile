.PHONY: all clean

SRC = main.cpp connection.cpp
BIN = lab1
LIBS = libpqxx gtkmm-3.0
INCLUDE = `pkg-config $(LIBS) --cflags --libs`

all: $(patsubst %.cpp, %.o, $(wildcard *.cpp))
	g++ -o $(BIN).out *.o $(INCLUDE)

%.o: %.c
	g++ -g -c -o %@ %<

clean:
	rm -f *.o *.out

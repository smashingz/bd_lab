.PHONY: all clean

all: main.cpp
	g++ main.cpp `pkg-config --libs --cflags libpqxx`

clean:
	rm -f *.o *.out

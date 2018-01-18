.PHONY: all clean

SRC = main.cpp connection.cpp
BIN = lab1
LIBS = libpqxx gtkmm-3.0
INCLUDE = `pkg-config $(LIBS) --cflags --libs`

all: $(BIN).o
	g++ -o $(BIN).out $(BIN).o $(INCLUDE)

$(BIN).o: main.cpp 
	g++ -g -c -o $(BIN).o $(SRC) $(INCLUDE)

clean:
	rm -f *.o *.out

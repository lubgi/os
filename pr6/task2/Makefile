CC = gcc
CXXFLAGS += -std=c11

EXECUTABLE = program

OBJECTS = main.o

all: compile

compile: $(OBJECTS)
	gcc -o $(EXECUTABLE) $(OBJECTS)

run: all
	./$(EXECUTABLE)

clean:
	rm -f -r $(OBJECTS) $(EXECUTABLE)
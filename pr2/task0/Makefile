CC = gcc

EXECUTABLE = program

OBJECTS = point.o coordinates.o pointnode.o main.o

all: compile

compile: $(OBJECTS)
	gcc -o $(EXECUTABLE) $(OBJECTS)

run: all
	./$(EXECUTABLE)

clean:
	rm -f -r $(OBJECTS) $(EXECUTABLE)
CC = gcc

EXECUTABLE = program

OBJECTS = main.o functions.o

all: compile

compile: $(OBJECTS)
	gcc -o $(EXECUTABLE) $(OBJECTS)

run:
	./$(EXECUTABLE) $(x)

clean:
	rm -f -r $(OBJECTS) $(EXECUTABLE)


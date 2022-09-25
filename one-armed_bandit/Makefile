CC = gcc

EXECUTABLE = program

OBJECTS = main.o combination.o machine.o player.o

all: compile

compile: $(OBJECTS)
	gcc -o $(EXECUTABLE) $(OBJECTS)

run: all
	./$(EXECUTABLE)

clean:
	rm -f -r $(OBJECTS) $(EXECUTABLE)
CC = gcc

EXECUTABLE = program

OBJECTS = subject.o student.o main.o

all: compile

compile: $(OBJECTS)
	gcc -o $(EXECUTABLE) $(OBJECTS)

run: all
	./$(EXECUTABLE)

clean:
	rm -f -r $(OBJECTS) $(EXECUTABLE)
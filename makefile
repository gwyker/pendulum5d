
CC = g++
CFLAGS = -g 
COPTFLAGS = 
LIBFLAGS = -lglut -lGLU -lGL -lm -lGLEW libSOIL.a
HEADERS = prototypes.h SOIL.h
OBJECTS = display.o motion.o loadtextures.o

all : pristine pendulum clean

pendulum : main.o $(OBJECTS)
	$(CC) main.o $(OBJECTS) -o pendulum $(LIBFLAGS)

main.o : main.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c main.cpp

display.o : display.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c display.cpp

motion.o : motion.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c motion.cpp

loadtextures.o : loadtextures.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c loadtextures.cpp

clean :
	rm *.o

pristine :
	rm -f *.o
	rm -f *~
	touch *.cpp

ctags :
	ctags *.cpp

CC = gcc
CFLAGS = -Wall -std=c99
CPPFLAGS = -I ../include
LDFLAGS= -L . -lm -llab #?
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

all: The_Labyrinth_Game

The_Labyrinth_Game: Labyrinth.o lab.o #libgame.a
	$(CC) -o The_Labyrinth_Game Labyrinth.o lab.o

Labyrinth.o: Labyrinth.c lab.h

lab.o: lab.c lab.h

#libgame.a : lab.o
#	ar rcs libgame.a $^

.PHONY: clean
clean:
	rm *.o The_Labyrinth_Game
#!/bin/makefile

OFILES=Affichage.o Espion.o IA.o Image.o Input.o Jeu.o Moteur.o main.o Rect.o Joueur.o
EXEC=exec

SRC=$(wildcard *.cpp)
HEADER=$(wildcard *.hpp)

LDFLAGS=-lSDL2 -lSDL2_ttf -lSDL2_image
CFLAGS=-Wall -Wextra -ansi -pedantic -Wextra -Wchar-subscripts -Wdouble-promotion -Werror -Wcomment -Wformat -Wno-parentheses

CC=g++

CLEAN=*.o *~

all:$(EXEC)

$(EXEC):$(OFILES) $(SRC) $(HEADER)
	$(CC) -g $^ -o $@ $(LDFLAGS)

%.o:%.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f $(EXEC) $(OFILES)

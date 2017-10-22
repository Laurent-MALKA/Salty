#!/bin/makefile

OFILES=Affichage.o Arme.o Clavier.o Direction.o Espion.o IA.o Image.o Input.o Jeu.o Joueur.o Moteur.o main.o Rect.o Sound.o
EXEC=Salty

SRC=$(wildcard *.cpp)
HEADER=$(wildcard *.hpp)

LDFLAGS=-lSDL2 -lSDL2_ttf -lSDL2_image
CFLAGS=-Wall -Wextra -Wfloat-equal -Wchar-subscripts -Wdouble-promotion -Werror -Wcomment -Wformat -Wno-parentheses -Wno-ignored-qualifiers

CC=g++

CLEAN=*.o *~

all:$(EXEC)

$(EXEC):$(OFILES)
	$(CC) -g $^ -o $@ $(LDFLAGS)

main.o:Jeu.hpp
Jeu.o:Sound.hpp Affichage.hpp Moteur.hpp Espion.hpp Clavier.hpp Joueur.hpp IA.hpp
Espion.o:Rect.hpp Image.hpp Direction.hpp
IA.o:Espion.hpp
Joueur.o:Espion.hpp Input.hpp Arme.hpp
Moteur.o: Moteur.hpp Clavier.hpp

%.o:%.cpp
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f $(EXEC) $(OFILES)
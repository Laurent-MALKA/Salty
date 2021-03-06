//
// Created by laurent on 10/21/17.
//

#ifndef SALTY_JEU_HPP
#define SALTY_JEU_HPP

#include "Sound.hpp"
#include <vector>
#include <SDL2/SDL.h>
#include "Espion.hpp"
#include "Clavier.hpp"
#include "Affichage.hpp"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "params.hpp"
#include "Joueur.hpp"
#include "IA.hpp"
#include "Moteur.hpp"

class Jeu {
public:
    Jeu();

    virtual ~Jeu();

    void gameLoop();

    void initEspion();

    SDL_Window *getWindow() const;

    SDL_Renderer *getRend() const;

    void resetEspions(Joueur* j1, Joueur* j2) ;

private:
    SDL_Window *window;
    SDL_Renderer *rend;

    Affichage affichage;

    std::vector<Espion *> espions;

    Clavier keyboard;
    Sound sound;
};


#endif //SALTY_JEU_HPP

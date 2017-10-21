//
// Created by laurent on 10/21/17.
//

#ifndef SALTY_JEU_HPP
#define SALTY_JEU_HPP


#include <vector>
#include <SDL2/SDL.h>
#include "Espion.hpp"

class Jeu {
public:
    Jeu();

    virtual ~Jeu();

private:
    SDL_Window *window;
    SDL_Renderer *rend;

    std::vector<Espion> espions;
};


#endif //SALTY_JEU_HPP

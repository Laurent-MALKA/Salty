//
// Created by laurent on 10/21/17.
//

#include "Jeu.hpp"

Jeu::Jeu() {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Salty", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, 0);
    rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Jeu::~Jeu() {
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
}

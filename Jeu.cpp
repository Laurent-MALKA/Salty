//
// Created by laurent on 10/21/17.
//

#include "Jeu.hpp"


Jeu::Jeu() {
    window = SDL_CreateWindow("Salty", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W_WIDTH, W_HEIGHT, 0);
    rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    initEspion();
}

Jeu::~Jeu() {
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
}

void Jeu::gameLoop() {

    while (keyboard.isStillReleased(SDL_SCANCODE_ESCAPE)) {
        keyboard.update();
        affichage.display(rend, espions);
        SDL_Delay(16);
    }
}

void Jeu::initEspion() {
    SDL_Surface *surface = IMG_Load("../espion.png");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    Image image(texture);

    espions.push_back(
            Joueur(image, Input(SDL_SCANCODE_W, SDL_SCANCODE_S, SDL_SCANCODE_A, SDL_SCANCODE_D, SDL_SCANCODE_E)));
    espions.push_back(
            Joueur(image, Input(SDL_SCANCODE_8, SDL_SCANCODE_5, SDL_SCANCODE_4, SDL_SCANCODE_6, SDL_SCANCODE_9)));
    for (int i = 0; i < 15; ++i) {
        espions.push_back(IA(image));
    }
}

SDL_Window *Jeu::getWindow() const {
    return window;
}

void Jeu::setWindow(SDL_Window *window) {
    Jeu::window = window;
}

SDL_Renderer *Jeu::getRend() const {
    return rend;
}

void Jeu::setRend(SDL_Renderer *rend) {
    Jeu::rend = rend;
}

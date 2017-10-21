//
// Created by laurent on 10/21/17.
//

#include <vector>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_system.h>
#include <SDL2/SDL_image.h>
#include "Affichage.hpp"

void Affichage::init(SDL_Renderer *rend) {
    SDL_Surface *surface = IMG_Load("../img/background.jpg");
    bg = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
}

void Affichage::display(SDL_Renderer *rend, const std::vector<Espion *> &espions) {
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 0);
    SDL_RenderClear(rend);


    afficherBackground(rend);
    for (int i = 0; i < espions.size(); ++i) {
        afficherPersonnage(rend, (Joueur *) espions[i]);
    }

    SDL_RenderPresent(rend);
}

void Affichage::afficherBackground(SDL_Renderer *rend) {
    SDL_RenderCopy(rend, bg, NULL, NULL);
}

void Affichage::afficherPersonnage(SDL_Renderer *rend, const Espion *espion) {
    SDL_Rect rect = {};
    rect.x = espion->getR().getX();
    rect.y = espion->getR().getY();
    rect.w = espion->getR().getW();
    rect.h = espion->getR().getH();

    SDL_RendererFlip flip = (espion->getDir().getHorizontal() == -1) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;

    SDL_RenderCopyEx(rend, espion->getImg().getTx(), NULL, &rect, 0, NULL, flip);
}

Affichage::~Affichage() {
    SDL_DestroyTexture(bg);
}

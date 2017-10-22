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
    afficherPersonnage(rend, (Joueur *) espions[0]);
    afficherPersonnage(rend, (Joueur *) espions[1]);
    for (int i = 2; i < espions.size(); ++i) {
        afficherPersonnage(rend, espions[i]);
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

    SDL_RenderCopyEx(rend, espion->getTexture(), NULL, &rect, 0, NULL, flip);
}

void Affichage::afficherPersonnage(SDL_Renderer *rend, const Joueur *espion) {
    afficherPersonnage(rend, (Espion *) espion);
    if (espion->getArme().estSortie()) {
        SDL_Rect rect = {};
        rect.x = espion->getArme().getR().getX();
        rect.y = espion->getArme().getR().getY();
        rect.w = espion->getArme().getR().getW();
        rect.h = espion->getArme().getR().getH();

        SDL_Point point = {0, 0};

        SDL_RenderCopyEx(rend, espion->getArme().getTexture(), nullptr, &rect, -espion->getArme().getAngle(),
                         &point, espion->getArme().getFlip());
    }

}

Affichage::~Affichage() {
    SDL_DestroyTexture(bg);
}





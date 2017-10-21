//
// Created by laurent on 10/21/17.
//

#include <vector>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_system.h>
#include "Affichage.hpp"

void Affichage::display(SDL_Renderer *rend, const std::vector<Espion> &espions) {
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
    SDL_RenderClear(rend);


    afficherBackground(rend);
    for (int i = 0; i < espions.size(); ++i) {
        afficherPersonnage(rend, espions[i]);
    }

    SDL_RenderPresent(rend);
}

void Affichage::afficherBackground(SDL_Renderer *rend) {

}

void Affichage::afficherPersonnage(SDL_Renderer *rend, const Espion &espion) {
    SDL_Rect rect = {};
    rect.x = espion.getR().getX();
    rect.y = espion.getR().getY();
    rect.w = espion.getR().getW();
    rect.h = espion.getR().getH();

    SDL_RendererFlip flip = (espion.getDir().getHorizontal() == -1) ? SDL_FLIP_VERTICAL : SDL_FLIP_NONE;

    SDL_RenderCopyEx(rend, espion.getImg().getTx(), NULL, &rect, 0, NULL, flip);
}

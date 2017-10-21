//
// Created by laurent on 10/21/17.
//

#ifndef SALTY_AFFICHAGE_HPP
#define SALTY_AFFICHAGE_HPP


#include <vector>
#include "Espion.hpp"
#include "Joueur.hpp"

class Affichage {
public:
    virtual ~Affichage();

    void init(SDL_Renderer *rend);

    void display(SDL_Renderer *rend, const std::vector<Espion *> &espions);

private:
    SDL_Texture *bg;

    void afficherBackground(SDL_Renderer *rend);

    void afficherPersonnage(SDL_Renderer *rend, const Espion *espion);
};


#endif //SALTY_AFFICHAGE_HPP

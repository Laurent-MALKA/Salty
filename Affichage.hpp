//
// Created by laurent on 10/21/17.
//

#ifndef SALTY_AFFICHAGE_HPP
#define SALTY_AFFICHAGE_HPP


#include <vector>
#include "Espion.hpp"
#include "Joueur.hpp"
#include <string>
#include "params.hpp"
#include <vector>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_system.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Affichage {
public:
    virtual ~Affichage();

    void init(SDL_Renderer *rend);

    void display(SDL_Renderer *rend, const std::vector<Espion *> &espions);

    SDL_Texture *getBg() const;

    void setBg(SDL_Texture *bg);

    void changerBackground(SDL_Renderer*, std::string path);

    void displayBackgroundOnly(SDL_Renderer *rend);

private:
    SDL_Texture* bg;
    SDL_Texture* nomJ1;
    SDL_Texture* nomJ2;
    SDL_Texture* rond_vert;
    SDL_Texture* rond_rouge;

    void afficherBackground(SDL_Renderer *rend);

    void afficherPersonnage(SDL_Renderer *rend, const Espion *espion);

    void afficherPersonnage(SDL_Renderer *rend, const Joueur *espion, int i);

};


#endif //SALTY_AFFICHAGE_HPP

//
// Created by laurent on 10/21/17.
//

#include "Affichage.hpp"

void Affichage::init(SDL_Renderer *rend) {
    SDL_Surface *surface = IMG_Load("../img/ecran_titre.png");
    SDL_Surface* s;
    SDL_Surface* s2;
    TTF_Font* font;
    SDL_Color color={0,0,0,0};

    font = TTF_OpenFont("../font/Roboto-Regular.ttf", 20);
    bg = SDL_CreateTextureFromSurface(rend, surface);

    s=TTF_RenderText_Solid(font, "Joueur1 :", color);
    nomJ1=SDL_CreateTextureFromSurface(rend, s);

    s2=TTF_RenderText_Solid(font, "Joueur2 :", color);
    nomJ2=SDL_CreateTextureFromSurface(rend, s2);

    rond_rouge = SDL_CreateTextureFromSurface(rend, IMG_Load("../img/rond_rouge.png"));
    rond_vert = SDL_CreateTextureFromSurface(rend, IMG_Load("../img/rond_vert.png"));

    SDL_FreeSurface(s);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
}

void Affichage::display(SDL_Renderer *rend, const std::vector<Espion *> &espions) {
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 0);
    SDL_RenderClear(rend);

    afficherBackground(rend);
    afficherPersonnage(rend, (Joueur *) espions[0], 1);
    afficherPersonnage(rend, (Joueur *) espions[1], 2);
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

void Affichage::afficherPersonnage(SDL_Renderer *rend, const Joueur *espion, int indice) {

    SDL_Texture* rond1;
    SDL_Texture* rond2;
    SDL_Texture* nom;
    SDL_Rect rect1;
    SDL_Rect rect2;
    SDL_Rect rect3;
    SDL_Rect rect;

    if(indice==1){
        rect1.x=25;
        nom=nomJ1;
    }
    else{
        rect1.x=W_WIDTH-220;
        nom=nomJ2;
    }

    rect1.y=20;
    rect1.w=100;
    rect1.h=20;

    rect2.x=rect1.x+rect1.w+20;
    rect2.y=rect1.y;
    rect2.w=30;
    rect2.h=30;

    rect3.x=rect2.x+rect2.w+10;
    rect3.y=rect1.y;
    rect3.w=30;
    rect3.h=30;

    afficherPersonnage(rend, (Espion *) espion);

    if (espion->getArme().estSortie()) {
        rect.x = espion->getArme().getR().getX();
        rect.y = espion->getArme().getR().getY();
        rect.w = espion->getArme().getR().getW();
        rect.h = espion->getArme().getR().getH();

        SDL_Point point = {0, 0};

        SDL_RenderCopyEx(rend, espion->getArme().getTexture(), nullptr, &rect, -espion->getArme().getAngle(),
                         &point, espion->getArme().getFlip());
    }

    if(espion->getNbRounds()>0){
        rond1=rond_vert;
        if(espion->getNbRounds()>1){
            rond2=rond_vert;
        }
        else{
            rond2=rond_rouge;
        }
    }
    else{
        rond1=rond_rouge;
    }

    if(indice==1){

    }

    SDL_RenderCopy(rend, nom, NULL, &rect1);
    SDL_RenderCopy(rend, rond1, NULL, &rect2);
    SDL_RenderCopy(rend, rond2, NULL, &rect3);

    SDL_DestroyTexture(nom);
    SDL_DestroyTexture(rond1);
    SDL_DestroyTexture(rond2);

}

Affichage::~Affichage() {
    SDL_DestroyTexture(bg);
    SDL_DestroyTexture(rond_vert);
    SDL_DestroyTexture(rond_rouge);
    SDL_DestroyTexture(nomJ1);
    SDL_DestroyTexture(nomJ2);
}

void Affichage::changerBackground(SDL_Renderer* rend, std::string path) {
    bg=SDL_CreateTextureFromSurface(rend, IMG_Load(path.c_str()));
}

SDL_Texture *Affichage::getBg() const {
    return bg;
}

void Affichage::setBg(SDL_Texture *bg) {
    Affichage::bg = bg;
}

void Affichage::displayBackgroundOnly(SDL_Renderer *rend) {
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
    SDL_RenderClear(rend);

    SDL_RenderCopy(rend, bg, NULL, NULL);

    SDL_RenderPresent(rend);
}





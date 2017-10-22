//
// Created by bruno on 21/10/17.
//

#include "Arme.hpp"

Arme::Arme(Image *image) :r(0, 0, 50, 15) , image(image) {
    flip= SDL_FLIP_NONE;
    sortie=false;
    angle = 0;
}

const Rect &Arme::getR() const {
    return r;
}

void Arme::setPos(int x, int y) {
    r.setX(x);
    r.setY(y);
}

SDL_Texture *Arme::getTexture() const {
    return image->getTexture(0);
}

bool Arme::estSortie() const {
    return sortie;
}

void Arme::setSortie(bool sortie) {
    Arme::sortie = sortie;
}

double Arme::getAngle() const {
    return angle;
}

void Arme::setAngle(double angle) {
    Arme::angle = fmod(angle, 360);
}

SDL_RendererFlip Arme::getFlip() const {
    return flip;
}

void Arme::setFlip(SDL_RendererFlip flip) {
    Arme::flip = flip;
}

//
// Created by bruno on 21/10/17.
//

#include "Arme.hpp"
#include "Rect.hpp"

Arme::Arme(const Image &img) : img(img), r(0,0,15,30)  {
    sortie=false;
}

const Rect &Arme::getR() const {
    return r;
}

void Arme::setR(const Rect &r) {
    Arme::r = r;
}

const Image &Arme::getImg() const {
    return img;
}

void Arme::setImg(const Image &img) {
    Arme::img = img;
}

bool Arme::estSortie() const {
    return sortie;
}

void Arme::setSortie(bool sortie) {
    Arme::sortie = sortie;
}

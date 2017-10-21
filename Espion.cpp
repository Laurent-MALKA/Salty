//
// Created by laurent on 10/21/17.
//

#include "Espion.hpp"

Espion::Espion(const Rect &r, const Image &img) : r(r), img(img), dir(), mort(false), v(5) {

}

void Espion::mourir(){
    //Animation mort
}

bool Espion::estMort() const {
    return mort;
}

const Direction &Espion::getDir() const {
    return dir;
}

const int Espion::getV() const {
    return v;
}

const Rect &Espion::getR() const {
    return r;
}

const Image &Espion::getImg() const {
    return img;
}

void Espion::setR(const Rect &r) {
    Espion::r = r;
}

void Espion::setImg(const Image &img) {
                    Espion::img = img;
}

void Espion::setMort(bool estMort) {
    Espion::mort = estMort;
}

void Espion::setDir(const Direction &dir) {
    Espion::dir = dir;
}

//
// Created by laurent on 10/21/17.
//

#include "Espion.hpp"
#include "params.hpp"

Espion::Espion(Image *img) : r(0, 0, 0, 0), img(img), dir(), v(5), mort(false), indiceAnimation(0), frame(0) {

    Espion::r.setW(50);
    Espion::r.setH(75);
    Espion::r.setX(rand()%(W_WIDTH-r.getW()));
    Espion::r.setY(rand()%(W_HEIGHT-r.getH()));
}

void Espion::mourir() {
    mort=true;
    indiceAnimation = 3;
    int t = r.getW();
    r.setW(r.getH());
    r.setH(t);
}

void Espion::deplacement(){
    int newX=Espion::dir.getHorizontal()*Espion::v+Espion::r.getX();
    int newY=Espion::dir.getVertical()*Espion::v+Espion::r.getY();;
    int pW=Espion::r.getW();
    int pH=Espion::r.getH();

    if(newX<0){
        newX=0;
    }
    else if(newX>W_WIDTH-pW){
        newX=W_WIDTH-pW;
    }

    if(newY<0){
        newY=0;
    }
    else if(newY>W_HEIGHT-pH){
        newY=W_HEIGHT-pH;
    }

    Espion::r.setX(newX);
    Espion::r.setY(newY);
    animationSuivante();
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

void Espion::setR(const Rect &r) {
    Espion::r = r;
}

void Espion::setMort(bool estMort) {
    Espion::mort = estMort;
}

void Espion::setDir(const Direction &dir) {
    Espion::dir = dir;
}

void Espion::setDirHorizontal(int horizontal) {
    dir.setHorizontal(horizontal);
}

void Espion::setDirVertical(int vertical) {
    dir.setVertical(vertical);
}

SDL_Texture *Espion::getTexture() const {
    return img->getTexture(indiceAnimation);
}

void Espion::animationSuivante() {
    ++frame;
    if (frame > 10 && (dir.getVertical() || dir.getHorizontal())) {
        frame = 0;
        indiceAnimation = 1 - indiceAnimation;
    }
}

//
// Created by bruno on 21/10/17.
//

#ifndef SALTY_ARME_H
#define SALTY_ARME_H


#include "Image.hpp"
#include "Rect.hpp"

class Arme {
public:
    Arme(const Image &img);

    const Rect &getR() const;

    void setPos(int x, int y);

    const Image &getImg() const;

    void setImg(const Image &img);

    void setSortie(bool sortie);

    bool estSortie() const;

    double getAngle() const;

    void setAngle(double angle);

    SDL_RendererFlip getFlip() const;

    void setFlip(SDL_RendererFlip flip);

private:
    Rect r;
    Image img;
    bool sortie;
    double angle;
    SDL_RendererFlip flip;

};


#endif //SALTY_ARME_H

//
// Created by laurent on 10/21/17.
//

#ifndef SALTY_ESPION_HPP
#define SALTY_ESPION_HPP


#include <SDL2/SDL_render.h>
#include "Rect.hpp"
#include "Image.hpp"
#include "Direction.hpp"
#include <ctime>

class Espion {
public:
    Espion(Image *img);

    void mourir();

    virtual void deplacement();

    const int getV() const;

    const Rect &getR() const;

    SDL_Texture *getTexture() const;

    void setR(const Rect &r);

    bool estMort() const;

    const Direction &getDir() const;

    void setMort(bool mort);

    void setDir(const Direction &dir);

    void setDirHorizontal(int horizontal);

    void setDirVertical(int vertical);

    void animationSuivante();

protected:
    int nbFrames;
    int indiceAnimation;
    const int v;
    Rect r;
    Image *img;
    bool mort;
    Direction dir;
};


#endif //SALTY_ESPION_HPP

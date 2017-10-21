//
// Created by laurent on 10/21/17.
//

#ifndef SALTY_ESPION_HPP
#define SALTY_ESPION_HPP


#include <SDL2/SDL_render.h>
#include "Rect.hpp"
#include "Image.hpp"
#include "Direction.hpp"

class Espion {
public:
    Espion(Image img);

    void mourir();

    virtual void deplacement() =0;

    const int getV() const;

    const Rect &getR() const;

    const Image &getImg() const;

    void setR(const Rect &r);

    void setImg(const Image &img);

    bool estMort() const;

    const Direction &getDir() const;

    void setMort(bool mort);

    void setDir(const Direction &dir);

protected:
    const int v;
    Rect r;
    Image img;
    bool mort;
    Direction dir;
};


#endif //SALTY_ESPION_HPP

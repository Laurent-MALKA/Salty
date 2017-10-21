//
// Created by laurent on 10/21/17.
//

#ifndef SALTY_IMAGE_HPP
#define SALTY_IMAGE_HPP


#include <SDL2/SDL_render.h>

class Image {

public:
    Image(SDL_Texture *tx);

    SDL_Texture *getTx() const;

    void setTx(SDL_Texture *tx);

private:
    SDL_Texture*  tx;
};


#endif //SALTY_IMAGE_HPP

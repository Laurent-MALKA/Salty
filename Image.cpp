//
// Created by laurent on 10/21/17.
//

#include "Image.hpp"

Image::Image(SDL_Texture *tx) : tx(tx) {

}

SDL_Texture *Image::getTx() const {
    return tx;
}

void Image::setTx(SDL_Texture *tx) {
    Image::tx = tx;
}


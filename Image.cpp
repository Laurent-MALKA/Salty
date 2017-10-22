//
// Created by laurent on 10/21/17.
//

#include "Image.hpp"

SDL_Texture *Image::getTexture(int i) const {
    return textures[i];
}

void Image::addTexture(SDL_Texture *texture) {
    textures.push_back(texture);
}


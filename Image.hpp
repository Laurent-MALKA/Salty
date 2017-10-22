//
// Created by laurent on 10/21/17.
//

#ifndef SALTY_IMAGE_HPP
#define SALTY_IMAGE_HPP


#include <SDL2/SDL_render.h>
#include <vector>

class Image {
public:
    void addTexture(SDL_Texture *texture);

    SDL_Texture *getTexture(int i) const;


private:
    std::vector<SDL_Texture *> textures;
};


#endif //SALTY_IMAGE_HPP

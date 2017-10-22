//
// Created by laurent on 10/22/17.
//

#ifndef SALTY_SOUND_HPP
#define SALTY_SOUND_HPP

#include <SDL2/SDL_audio.h>

class Sound {
public:
    Sound();

    virtual ~Sound();

private:
    SDL_AudioSpec wav_spec;
    Uint32 wav_length;
    Uint8 *wav_buffer;

};


#endif //SALTY_SOUND_HPP

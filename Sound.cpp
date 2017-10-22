//
// Created by laurent on 10/22/17.
//

#include "Sound.hpp"

Sound::Sound() {
    SDL_LoadWAV("../sounds/musique.wav", &wav_spec, &wav_buffer, &wav_length);

}

Sound::~Sound() {
    SDL_FreeWAV(wav_buffer);
}

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

void Sound::init() {
    wav_spec.freq = 22050;
    wav_spec.format = AUDIO_S16;
    wav_spec.channels = 2;
    wav_spec.samples = 1024;
//    wav_spec.callback = audioCallback;
    wav_spec.userdata = NULL;

    if (SDL_OpenAudio(&wav_spec, NULL) < 0) {
        fprintf(stderr, "Erreur d'ouverture audio: %s\n", SDL_GetError());
    }
}

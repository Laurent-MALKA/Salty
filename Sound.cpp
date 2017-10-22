//
// Created by laurent on 10/22/17.
//

#include "Sound.hpp"

Sound::Sound(std::string path) : wav_length(), wav_buffer(), wav_spec(), audio_pos(), audio_len(){
    SDL_LoadWAV(path.c_str(), &wav_spec, &wav_buffer, &wav_length);
    init();
}

Uint32 Sound::getWav_length() const {
    return wav_length;
}

void Sound::setWav_length(Uint32 wav_length) {
    Sound::wav_length = wav_length;
}

Uint8 *Sound::getWav_buffer() const{
    return wav_buffer;
}

void Sound::setWav_buffer(Uint8 *wav_buffer) {
    Sound::wav_buffer = wav_buffer;
}

const SDL_AudioSpec &Sound::getWav_spec() const {
    return wav_spec;
}

void Sound::setWav_spec(const SDL_AudioSpec &wav_spec) {
    Sound::wav_spec = wav_spec;
}

Uint8 *Sound::getAudio_pos() const {
    return audio_pos;
}

void Sound::setAudio_pos(Uint8 *audio_pos) {
    Sound::audio_pos = audio_pos;
}

Uint32 Sound::getAudio_len() const {
    return audio_len;
}

void Sound::setAudio_len(Uint32 audio_len) {
    Sound::audio_len = audio_len;
}

void Sound::setWav_specCallbackEtUserdata(SDL_AudioCallback callback){
    wav_spec.callback=callback;
    wav_spec.userdata=NULL;
}

void Sound::init(){
    //wav_spec.callback= my_audio_callback;
    //wav_spec.userdata=NULL;
    audio_pos=wav_buffer;
    audio_len=wav_length;

    if ( SDL_OpenAudio(&wav_spec, NULL) < 0 ){
        fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
        exit(-1);
    }
}

Sound::~Sound() {
    SDL_FreeWAV(wav_buffer);
}
// audio callback function
// here you have to copy the data of your audio buffer into the
// requesting audio buffer (stream)
// you should only copy as much as the requested length (len)
void Sound::my_audio_callback(void *userdata, Uint8 *stream, unsigned len) {

    if (audio_len ==0)
        return;

    len = ( len > audio_len ? audio_len : len );
    //SDL_memcpy (stream, audio_pos, len); 					// simply copy from one buffer into the other
    SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);// mix from one buffer into another

    audio_pos += len;
    audio_len -= len;

    //Pour ne pas avoir l'erreur de variable inutilisée
    wav_spec.userdata=userdata;

}
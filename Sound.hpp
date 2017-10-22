//
// Created by laurent on 10/22/17.
//

#ifndef SALTY_SOUND_HPP
#define SALTY_SOUND_HPP

#include <string>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_audio.h>

class Sound {
public:
    Sound(std::string path);

    virtual ~Sound();

    Uint32 getWav_length() const;

    void setWav_length(Uint32 wav_length);

    Uint8 *getWav_buffer() const;

    void setWav_buffer(Uint8 *wav_buffer);

    const SDL_AudioSpec &getWav_spec() const;

    void setWav_spec(const SDL_AudioSpec &wav_spec);

    Uint8 *getAudio_pos() const;

    void setAudio_pos(Uint8 *audio_pos);

    Uint32 getAudio_len() const;

    void setAudio_len(Uint32 audio_len);

    void setWav_specCallbackEtUserdata(SDL_AudioCallback callback);


private:
    Uint32 wav_length;
    Uint8* wav_buffer;
    SDL_AudioSpec wav_spec;
    Uint8 *audio_pos;
    Uint32 audio_len;

    void init();

    void my_audio_callback(void *userdata, Uint8 *stream, unsigned len);
};

#endif //SALTY_SOUND_HPP

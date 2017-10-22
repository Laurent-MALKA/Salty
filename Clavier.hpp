//
// Created by laurent on 10/21/17.
//

#ifndef SALTY_CLAVIER_HPP
#define SALTY_CLAVIER_HPP


#include <SDL2/SDL_quit.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_system.h>
#include <SDL2/SDL_events.h>

class Clavier {
public:
    Clavier();

    ~Clavier();

    void update();

    bool isStillPressed(SDL_Scancode scancode) const;

    bool isStillReleased(SDL_Scancode scancode) const;

    bool isJustPressed(SDL_Scancode scancode) const;

    bool isJustReleased(SDL_Scancode scancode) const;

    bool isStillPressed(int scancode) const;

    bool isStillReleased(int scancode) const;

    bool isJustPressed(int scancode) const;

    bool isJustReleased(int scancode) const;

    bool isKeyboardReleased();

private:
    Uint8 *keyboard;
    bool *currentState;
    bool *previousState;

};


#endif //SALTY_CLAVIER_HPP

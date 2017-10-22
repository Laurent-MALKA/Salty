//
// Created by laurent on 10/21/17.
//

#include "Clavier.hpp"

Clavier::Clavier() {
    keyboard = (Uint8 *) SDL_GetKeyboardState(NULL);
    currentState = (bool *) malloc(SDL_NUM_SCANCODES * sizeof(bool));
    previousState = (bool *) malloc(SDL_NUM_SCANCODES * sizeof(bool));

    for (int i = 0; i < SDL_NUM_SCANCODES; ++i) {
        *(currentState + i) = keyboard[i];
        *(previousState + i) = false;
    }
}

Clavier::~Clavier() {
    free(currentState);
    free(previousState);
}

void Clavier::update() {
    SDL_PumpEvents();
    for (int i = 0; i < SDL_NUM_SCANCODES; ++i) {
        *(previousState + i) = *(currentState + i);
        *(currentState + i) = keyboard[i];
    }
}

bool Clavier::isStillPressed(SDL_Scancode scancode) const {
    return previousState[scancode] && currentState[scancode];
}

bool Clavier::isStillReleased(SDL_Scancode scancode) const {
    return !previousState[scancode] && !currentState[scancode];
}

bool Clavier::isJustPressed(SDL_Scancode scancode) const {
    return !previousState[scancode] && currentState[scancode];
}

bool Clavier::isJustReleased(SDL_Scancode scancode) const {
    return previousState[scancode] && !currentState[scancode];
}

bool Clavier::isStillPressed(int scancode) const {
    return previousState[scancode] && currentState[scancode];
}

bool Clavier::isStillReleased(int scancode) const {
    return !previousState[scancode] && !currentState[scancode];
}

bool Clavier::isJustPressed(int scancode) const {
    return !previousState[scancode] && currentState[scancode];
}

bool Clavier::isJustReleased(int scancode) const {
    return previousState[scancode] && !currentState[scancode];
}

bool Clavier::isKeyboardReleased() {
    bool out = true;
    for (int i = 0; i < SDL_NUM_SCANCODES; ++i) {
        if (*(currentState + i))
            out = false;
    }

    return out;
}

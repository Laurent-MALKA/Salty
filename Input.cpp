//
// Created by laurent on 10/21/17.
//

#include "Input.hpp"

Input::Input(int haut, int bas, int droite, int gauche, int attaque)
        : haut(haut), bas(bas), droite(droite), gauche(gauche), attaque(attaque) {}

int Input::getHaut() const {
    return haut;
}

int Input::getBas() const {
    return bas;
}

int Input::getDroite() const {
    return droite;
}

int Input::getGauche() const {
    return gauche;
}

int Input::getAttaque() const {
    return attaque;
}

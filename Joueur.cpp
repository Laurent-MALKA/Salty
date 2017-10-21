//
// Created by laurent on 10/21/17.
//


#include "Joueur.hpp"

Joueur::Joueur(const Rect &r, const Image &img, Input input) : Espion(r, img), cdMax(100) {
    Joueur::cdAtq=0;
    Joueur::nbRounds=0;
    Joueur::input=input;
}

const Input &Joueur::getInput() const {
    return input;
}

void Joueur::setCdAtq(int cdAtq) {
    Joueur::cdAtq = cdAtq;
}

void Joueur::setInput(const Input &input) {
    Joueur::input = input;
}

const int Joueur::getCdAtq() const {
    return cdAtq;
}

const int Joueur::getCdMax() const {
    return cdMax;
}

int Joueur::getNbRounds() const {
    return nbRounds;
}

void Joueur::setNbRounds(int nbRounds) {
    Joueur::nbRounds = nbRounds;
}
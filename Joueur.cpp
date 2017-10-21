//
// Created by laurent on 10/21/17.
//


#include "Joueur.hpp"

Joueur::Joueur(const Image img, const Input input) : cdMax(100), cdAtq(0), nbRounds(0), input(input), Espion(img){
}

void Joueur::deplacement(){
    if(cdAtq==0) {
        Espion::deplacement();
        if(dir.getHorizontal()==1){
            //Animation marche vers droite
        }
        else if(dir.getHorizontal()==-1){
            //Animation marhce vers gauche
        }
        else{
            //Animation idle
        }
    }
    else {
        if (cdAtq == cdMax) {
            //Animation attaque
        }
        cdAtq--;
    }
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
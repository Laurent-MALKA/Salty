//
// Created by laurent on 10/21/17.
//


#include "Joueur.hpp"

Joueur::Joueur(Image *img, Input input, Arme arme) : cdMax(100), cdAtq(0), nbRounds(0), input(input), Espion(img),
                                                     arme(arme) {
}

void Joueur::deplacement(){
    if(cdAtq==0) {
        Espion::deplacement();
    }
    else {
        cdAtq--;
        if(cdAtq==0){
            arme.setSortie(false);
        }
    }
}

void Joueur::attaque(){
    cdAtq = cdMax;
    int xWeapon;
    int yWeapon;

    if (dir.getHorizontal() == 1 && dir.getVertical() == -1) {
        arme.setAngle(45);
        xWeapon = r.getX() + r.getW();
        yWeapon = r.getY();
    } else if (dir.getHorizontal() == 0 && dir.getVertical() == -1) {
        arme.setAngle(90);
        xWeapon = r.getX() + r.getW() / 2 - arme.getR().getH() / 2;
        yWeapon = r.getY();
    } else if (dir.getHorizontal() == -1 && dir.getVertical() == -1) {
        arme.setAngle(135);
        xWeapon = r.getX();
        yWeapon = r.getY();
    } else if (dir.getHorizontal() == -1 && dir.getVertical() == 0) {
        arme.setAngle(180);
        xWeapon = r.getX();
        yWeapon = r.getY() + r.getH() / 2 - arme.getR().getH() / 2;
    } else if (dir.getHorizontal() == -1 && dir.getVertical() == 1) {
        arme.setAngle(225);
        xWeapon = r.getX();
        yWeapon = r.getY() + r.getH();
    } else if (dir.getHorizontal() == 0 && dir.getVertical() == 1) {
        arme.setAngle(270);
        xWeapon = r.getX() + r.getW() / 2 - arme.getR().getH() / 2;
        yWeapon = r.getY() + r.getH();
    } else if (dir.getHorizontal() == 1 && dir.getVertical() == 1) {
        arme.setAngle(315);
        xWeapon = r.getX() + r.getW();
        yWeapon = r.getY() + r.getH();
    } else {
        arme.setAngle(0);
        xWeapon = r.getX() + r.getW();
        yWeapon = r.getY() + r.getH() / 2 - arme.getR().getH() / 2;
    }

    arme.setFlip((dir.getHorizontal() == -1) ? SDL_FLIP_VERTICAL : SDL_FLIP_NONE);


    arme.setPos(xWeapon, yWeapon);
    arme.setSortie(true);
}

const Arme &Joueur::getArme() const {
    return arme;
}

void Joueur::setArme(const Arme &arme) {
    Joueur::arme = arme;
};

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

void Joueur::setArmeSortie(bool t){
    arme.setSortie(t);
}

bool Joueur::hasJustAttacked() {
    return cdAtq > cdMax - 10;
}

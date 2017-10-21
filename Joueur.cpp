//
// Created by laurent on 10/21/17.
//


#include "Joueur.hpp"

Joueur::Joueur(const Image img, const Input input, const Arme arme) : cdMax(100), cdAtq(0), nbRounds(0), input(input), Espion(img), arme(arme){
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
        if(cdAtq==0){
            arme.setSortie(false);
        }
    }
}

void Joueur::attaque(){
    int xWeapon;
    int yWeapon;
    int wWeapon;
    int hWeapon;

    if(dir.getHorizontal()==1){
        xWeapon=r.getX()+r.getW();
        yWeapon=r.getY()+(r.getH()+arme.getR().getH())/2;
        wWeapon=arme.getR().getH();
        hWeapon=arme.getR().getW();
    }
    else if(dir.getHorizontal()==-1){
        xWeapon=r.getX()-arme.getR().getW();
        yWeapon=r.getY()+(r.getH()+arme.getR().getH())/2;
        wWeapon=arme.getR().getH();
        hWeapon=arme.getR().getW();
    }

    else if(dir.getVertical()==-1){
        xWeapon=r.getX()+(r.getW()+arme.getR().getW())/2;
        yWeapon=r.getY();
        wWeapon=arme.getR().getW();
        hWeapon=arme.getR().getH();
    }

    else{
        xWeapon=r.getX()+(r.getW()+arme.getR().getW())/2;
        yWeapon=r.getY()+r.getH();
        wWeapon=arme.getR().getW();
        hWeapon=arme.getR().getH();
    }

    Rect r(xWeapon, yWeapon, wWeapon, hWeapon);
    arme.setR(r);
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
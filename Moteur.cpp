//
// Created by laurent on 10/21/17.
//

#include <vector>
#include <SDL2/SDL_image.h>
#include "Joueur.hpp"
#include "Clavier.hpp"
#include "Moteur.hpp"

void Moteur::lecture(Joueur *j, const Clavier &keyboard) {
    if (keyboard.isStillPressed(j->getInput().getDroite()) && keyboard.isStillPressed(j->getInput().getGauche())) {
        j->setDirHorizontal(0);
    } else if (keyboard.isStillPressed(j->getInput().getDroite())) {
        j->setDirHorizontal(1);
    } else if (keyboard.isStillPressed(j->getInput().getGauche())) {
        j->setDirHorizontal(-1);
    } else {
        j->setDirHorizontal(0);
    }

    if (keyboard.isStillPressed(j->getInput().getHaut()) && keyboard.isStillPressed(j->getInput().getBas())) {
        j->setDirVertical(0);
    } else if (keyboard.isStillPressed(j->getInput().getHaut())) {
        j->setDirVertical(-1);
    } else if (keyboard.isStillPressed(j->getInput().getBas())) {
        j->setDirVertical(1);
    } else {
        j->setDirVertical(0);
    }

    if (!j->getArme().estSortie() && keyboard.isStillPressed(j->getInput().getAttaque())) {
        j->attaque();
    }

}

void Moteur::deplacements(std::vector<Espion *> espions) {
    for(int i=0; i<espions.size(); i++){
        if (!espions[i]->estMort())
            espions[i]->deplacement();
    }
}

void Moteur::testTouche(std::vector<Espion *> espions) {
    Joueur * jAct;

    for(int i=0; i<2; i++){
        jAct=(Joueur *) espions[i];
        if (jAct->hasJustAttacked()) {
            for(int j=0; j<espions.size(); j++){
                if (i != j && !espions[j]->estMort()
                    &&
                    (jAct->getR().getX() >= espions[j]->getR().getX() &&
                     jAct->getR().getX() <= espions[j]->getR().getX() + espions[j]->getR().getW()
                        || jAct->getR().getX()<=espions[j]->getR().getX() && jAct->getR().getX()+jAct->getR().getW()>=espions[j]->getR().getX())
                    &&
                    (jAct->getR().getY() >= espions[j]->getR().getY() &&
                     jAct->getR().getY() <= espions[j]->getR().getY() + espions[j]->getR().getH()
                        || jAct->getR().getY()<=espions[j]->getR().getY() && jAct->getR().getY()+jAct->getR().getH()>=espions[j]->getR().getY()))
                {
                    espions[j]->mourir();
                }
            }
        }
    }
}

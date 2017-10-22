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

    int oldx;
    int oldy;
    int oldw;
    int oldh;
    double angle;

    int x;
    int y;
    int w;
    int h;

    int jx;
    int jy;
    int jw;
    int jh;

    for(int i=0; i<2; i++){
        jAct=(Joueur *) espions[i];

        oldx = jAct->getArme().getR().getX();
        oldy = jAct->getArme().getR().getY();
        oldw = jAct->getArme().getR().getW();
        oldh = jAct->getArme().getR().getH();
        angle = jAct->getArme().getAngle();

        x = (int) ((angle > 0 && angle < 45 || angle > 315 && angle < 360) ? oldx : oldx - oldh * sin(angle));
        y = (int) ((angle > 0 && angle < 90) ? oldy : oldy - oldh * cos(angle));
        w = (int) (oldh * sin(angle) + oldw * cos(angle));
        h = (int) (oldh * cos(angle) + oldw * sin(angle));

        jx = jAct->getR().getX();
        jy = jAct->getR().getY();
        jw = jAct->getR().getW();
        jh = jAct->getR().getH();

        if (jAct->hasJustAttacked()) {
            for(int j=0; j<espions.size(); j++){
                if (i != j && !espions[j]->estMort()
                    &&
                    !(jx > x + w || jy > y + h || x > jx + jw || y > jy + jh))
                {
                    espions[j]->mourir();
                }
            }
        }
    }
}

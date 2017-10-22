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

    double angle;
    int x1, x2, x3;
    int y1, y2, y3;

    int x;
    int y;
    int w;
    int h;

    int jx;
    int jy;
    int jh;

    int ex;
    int ey;
    int ew;
    int eh;

    for(int i=0; i<2; i++){
        jAct=(Joueur *) espions[i];

        if (jAct->hasJustAttacked()) {
            jx = jAct->getR().getX();
            jy = jAct->getR().getY();
            jh = jAct->getR().getH();

            x1 = jx - 50;
            x2 = x1 + 50;
            x3 = x2 + 50;

            y1 = jy + jh / 2 - 75;
            y2 = y1 + 50;
            y3 = y2 + 50;

            angle = jAct->getArme().getAngle();

            w = 50;
            h = 50;

            switch ((int) angle) {
                case 0:
                    x = x3;
                    y = y2;
                    break;
                case 45:
                    x = x3;
                    y = y1;
                    break;
                case 90:
                    x = x2;
                    y = y1;
                    break;
                case 135:
                    x = x1;
                    y = y1;
                    break;
                case 180:
                    x = x1;
                    y = y2;
                    break;
                case 225:
                    x = x1;
                    y = y3;
                    break;
                case 270:
                    x = x2;
                    y = y3;
                    break;
                default:
                    x = x3;
                    y = y3;
                    break;
            }
            for(int j=0; j<espions.size(); j++){
                ex = espions[j]->getR().getX();
                ey = espions[j]->getR().getY();
                ew = espions[j]->getR().getW();
                eh = espions[j]->getR().getH();
                if (i != j && !espions[j]->estMort()
                    &&
                    !(ex > x + w || ey > y + h || x > ex + ew || y > ey + eh))
                {
                    espions[j]->mourir();
                }
            }
        }
    }
}

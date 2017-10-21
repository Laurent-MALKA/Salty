//
// Created by laurent on 10/21/17.
//

#include "Joueur.hpp"
#include "Clavier.hpp"
#include "Moteur.hpp"

void Moteur::lecture(Joueur &j, const Clavier &keyboard) {
    if (keyboard.isStillPressed(j.getInput().getDroite()) && j.getInput().getGauche()) {
        j.setDirHorizontal(0);
    } else if (keyboard.isStillPressed(j.getInput().getDroite())) {
        j.setDirHorizontal(1);
    } else if (keyboard.isStillPressed(j.getInput().getGauche())) {
        j.setDirHorizontal(-1);
    }

    if (keyboard.isStillPressed(j.getInput().getHaut()) && j.getInput().getBas()) {
        j.setDirVertical(0);
    } else if (keyboard.isStillPressed(j.getInput().getHaut())) {
        j.setDirVertical(1);
    } else if (keyboard.isStillPressed(j.getInput().getBas())) {
        j.setDirVertical(-1);
    }

    if (!j.getCdAtq() && keyboard.isStillPressed(j.getInput().getAttaque())) {
        j.setCdAtq(j.getCdMax());
    }

}
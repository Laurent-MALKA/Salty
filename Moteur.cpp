//
// Created by laurent on 10/21/17.
//

#include "Joueur.hpp"
#include "Clavier.hpp"
#include "Moteur.hpp"

void Moteur::lecture(Joueur &j1, Joueur &j2, const Clavier &keyboard) {
    if (keyboard.isStillPressed(j1.getInput().getDroite()) && j1.getInput().getGauche()) {
        j1.setDirHorizontal(0);
    } else if (keyboard.isStillPressed(j1.getInput().getDroite())) {
        j1.setDirHorizontal(1);
    } else if (keyboard.isStillPressed(j1.getInput().getGauche())) {
        j1.setDirHorizontal(-1);
    }

    if (keyboard.isStillPressed(j1.getInput().getHaut()) && j1.getInput().getBas()) {
        j1.setDirVertical(0);
    }
}

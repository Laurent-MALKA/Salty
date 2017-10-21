//
// Created by laurent on 10/21/17.
//

#include "Joueur.hpp"
#include "Clavier.hpp"
#include "Moteur.hpp"

void Moteur::lecture(Joueur &j1, Joueur &j2, const Clavier &keyboard) {
    if (keyboard.isStillPressed(j1.getInput().getDroite()) && j1.getInput().getGauche()) {

    }
}

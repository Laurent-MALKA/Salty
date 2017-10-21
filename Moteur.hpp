//
// Created by laurent on 10/21/17.
//

#ifndef SALTY_MOTEUR_HPP
#define SALTY_MOTEUR_HPP


#include "Joueur.hpp"
#include "Clavier.hpp"

class Moteur {
public:
    static void lecture(Joueur &j, const Clavier &keyboard);

};


#endif //SALTY_MOTEUR_HPP

//
// Created by laurent on 10/21/17.
//

#ifndef SALTY_MOTEUR_HPP
#define SALTY_MOTEUR_HPP


#include "Joueur.hpp"
#include "Clavier.hpp"

class Moteur {
public:
    static void lecture(Joueur *j, const Clavier &keyboard);

    static void deplacements(std::vector<Espion *> espions);

    static void testTouche(std::vector<Espion *> espions, Image mort);
};


#endif //SALTY_MOTEUR_HPP

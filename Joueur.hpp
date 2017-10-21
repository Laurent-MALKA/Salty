//
// Created by laurent on 10/21/17.
//

#ifndef SALTY_JOUEUR_HPP
#define SALTY_JOUEUR_HPP


#include "Espion.hpp"
#include "Input.hpp"

class Joueur: public Espion {
public:
    Joueur(Image img, Input input);

    const int getCdAtq() const;

    const int getCdMax() const;

    int getNbRounds() const;

    void setNbRounds(int nbRounds);

    const Input &getInput() const;

    void setCdAtq(int cdAtq);

    void setInput(const Input &input);

    void deplacement();

private:
    int cdAtq;
    const int cdMax;
    int nbRounds;
    Input input;
};


#endif //SALTY_JOUEUR_HPP

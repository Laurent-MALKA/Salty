//
// Created by laurent on 10/21/17.
//

#ifndef SALTY_JOUEUR_HPP
#define SALTY_JOUEUR_HPP


#include "Espion.hpp"
#include "Input.hpp"

class Joueur: public Espion {
public:
    Joueur(const Rect &r, const Image &img, Input input);

    const int getCdAtq() const;

    const int getCdMax() const;

    int getNbRounds() const;

    void setNbRounds(int nbRounds);

    const Input &getInput() const;

    void setCdAtq(int cdAtq);

    void setInput(const Input &input);

private:
    int cdAtq;
    const int cdMax;
    int nbRounds;
    Input input;
};


#endif //SALTY_JOUEUR_HPP

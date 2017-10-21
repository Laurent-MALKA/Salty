//
// Created by laurent on 10/21/17.
//

#ifndef SALTY_INPUT_HPP
#define SALTY_INPUT_HPP

class Input {
public:
    Input(int haut, int bas, int droite, int gauche, int attaque);

    int getHaut() const;

    int getBas() const;

    int getDroite() const;

    int getGauche() const;

    int getAttaque() const;

private:
    int haut;
    int bas;
    int droite;
    int gauche;
    int attaque;

};


#endif //SALTY_INPUT_HPP

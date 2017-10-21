//
// Created by bruno on 21/10/17.
//

#ifndef SALTY_ARME_H
#define SALTY_ARME_H


#include "Image.hpp"
#include "Rect.hpp"

class Arme {
public:
    Arme(const Image &img);

    const Rect &getR() const;

    void setR(const Rect &r);

    const Image &getImg() const;

    void setImg(const Image &img);

    void setSortie(bool sortie);

    bool estSortie() const;

private:
    Rect r;
    Image img;
    bool sortie;
};


#endif //SALTY_ARME_H

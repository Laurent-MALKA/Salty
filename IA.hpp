//
// Created by laurent on 10/21/17.
//

#ifndef SALTY_IA_HPP
#define SALTY_IA_HPP


#include "Espion.hpp"

class IA: public Espion {
public:
    IA(const Rect &r, const Image &img);
    void deplacement();

};


#endif //SALTY_IA_HPP

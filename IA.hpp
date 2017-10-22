//
// Created by laurent on 10/21/17.
//

#ifndef SALTY_IA_HPP
#define SALTY_IA_HPP

#include "Espion.hpp"
#include "params.hpp"

class IA: public Espion {
public:
    IA(Image *img);
    void deplacement();
};


#endif //SALTY_IA_HPP

//
// Created by laurent on 10/21/17.
//

#ifndef SALTY_IA_HPP
#define SALTY_IA_HPP

#include <time.h>
#include "Espion.hpp"

class IA: public Espion {
public:
    IA(const Image &img);
    void deplacement();

    int getFrame() const;

    void setFrame(int frame);

private:
    int frame;
};


#endif //SALTY_IA_HPP

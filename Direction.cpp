//
// Created by laurent on 10/21/17.
//

#include "Direction.hpp"



void Direction::setVertical(int ver) {
    if (ver == -1 || ver == 0 || ver == 1)
        Direction::vertical = ver;
}

void Direction::setHorizontal(int hor) {
    if (hor == -1 || hor == 0 || hor == 1)
        Direction::horizontal = hor;
}

int Direction::getVertical() const {
    return vertical;
}

int Direction::getHorizontal() const {
    return horizontal;
}
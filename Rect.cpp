//
// Created by laurent on 10/21/17.
//

#include "Rect.hpp"

Rect::Rect(int x, int y, int w, int h) {
    Rect::x=x;
    Rect::y=y;
    Rect::w=w;
    Rect::h=h;
}

int Rect::getX() const {
    return x;
}

int Rect::getY() const {
    return y;
}

int Rect::getW() const {
    return w;
}

int Rect::getH() const {
    return h;
}

void Rect::setX(int x) {
    Rect::x = x;
}

void Rect::setY(int y) {
    Rect::y = y;
}

void Rect::setW(int w) {
    Rect::w = w;
}

void Rect::setH(int h) {
    Rect::h = h;
}

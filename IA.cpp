//
// Created by laurent on 10/21/17.
//

#include "IA.hpp"

IA::IA(Image *img) : Espion(img), frame(0) {
}

void IA::deplacement(){
    int r;

    r=rand()%3;
    if(r==0 && frame%20==0){
        r=rand()%3;
        if(r>=1){
            r=rand()%3-1;
            IA::dir.setHorizontal(r);
            r=rand()%3-1;
            IA::dir.setVertical(r);
        }
    }

    Espion::deplacement();

    IA::frame=(IA::frame+1)%9999;
}

int IA::getFrame() const {
    return frame;
}

void IA::setFrame(int frame) {
    IA::frame = frame;
}

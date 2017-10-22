//
// Created by laurent on 10/21/17.
//

#include "IA.hpp"

IA::IA(Image *img) : Espion(img), cptFrame(0) {
}

void IA::deplacement(){
    int random;

    random=rand()%3;
    if(random==0 && cptFrame%20==0){
        random = rand() % 4 - 1;

        if (Espion::r.getX() <= 102) {
            if (random == 2) {
                random = 1;
            }
        } else if (Espion::r.getX() + Espion::r.getW() >= W_WIDTH - 102) {
            if (random == 2) {
                random = -1;
            }
        } else {
            random = rand() % 3 - 1;
        }

        IA::dir.setHorizontal(random);

        random = rand() % 4 - 1;

        if (Espion::r.getY() <= 102) {
            if (random == 2) {
                random = 1;
            }
        } else if (Espion::r.getY() + Espion::r.getH() >= W_HEIGHT - 102) {
            if (random == 2) {
                random = -1;
            }
        } else {
            random = rand() % 3 - 1;
        }

        IA::dir.setVertical(random);
    }

    cptFrame=(cptFrame+1)%9999;
}

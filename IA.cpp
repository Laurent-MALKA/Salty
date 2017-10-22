//
// Created by laurent on 10/21/17.
//

#include "IA.hpp"

IA::IA(Image *img) : Espion(img) {
}

void IA::deplacement(){
    int rand;

    rand=rand()%3;
    if(rand==0 && frame%20==0){
        rand = rand() % 4 - 1;

        if (Espion::r.getX() <= 102) {
            if (rand == 2) {
                rand = 1;
            }
        } else if (Espion::r.getX() + Espion::r.getW() >= W_WIDTH - 102) {
            if (rand == 2) {
                rand = -1;
            }
        } else {
            rand = rand() % 3 - 1;
        }

        IA::dir.setHorizontal(rand);

        rand = rand() % 4 - 1;

        if (Espion::r.getY() <= 102) {
            if (rand == 2) {
                rand = 1;
            }
        } else if (Espion::r.getY() + Espion::r.getH() >= W_HEIGHT - 102) {
            if (rand == 2) {
                rand = -1;
            }
        } else {
            rand = rand() % 3 - 1;
        }

        IA::dir.setVertical(rand);
    }
}

//
// Created by laurent on 10/21/17.
//

#ifndef SALTY_DIRECTION_HPP
#define SALTY_DIRECTION_HPP


class Direction {
public:
    Direction() : vertical(0), horizontal(0) {}

    void setVer(int ver) {
        if (ver == -1 || ver == 0 || ver == 1)
            Direction::vertical = ver;
    }

    void setHor(int hor) {
        if (hor == -1 || hor == 0 || hor == 1)
            Direction::horizontal = hor;
    }

    int getVer() const {
        return vertical;
    }

    int getHor() const {
        return horizontal;
    }

private:
    int vertical;
    int horizontal;
};


#endif //SALTY_DIRECTION_HPP

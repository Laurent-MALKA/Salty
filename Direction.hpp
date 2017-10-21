//
// Created by laurent on 10/21/17.
//

#ifndef SALTY_DIRECTION_HPP
#define SALTY_DIRECTION_HPP


class Direction {
public:
    Direction() : vertical(0), horizontal(0) {}

    void setVertical(int ver);

    void setHorizontal(int hor);

    int getVertical() const;

    int getHorizontal() const;

private:
    int vertical;
    int horizontal;
};


#endif //SALTY_DIRECTION_HPP

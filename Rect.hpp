//
// Created by laurent on 10/21/17.
//

#ifndef SALTY_RECT_HPP
#define SALTY_RECT_HPP


class Rect {
public:
    Rect(int x, int y, int w, int h);

    int getX() const;

    int getY() const;

    int getW() const;

    int getH() const;

    void setX(int x);

    void setY(int y);

    void setW(int w);

    void setH(int h);

protected:
        int x;
        int y;
        int w;
        int h;
};


#endif //SALTY_RECT_HPP

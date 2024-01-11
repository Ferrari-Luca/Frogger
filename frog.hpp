#pragma once
#include "utils.hpp"
#include "point-rectangle.hpp"
#include <vector>

class Lane;
class Frog {
    Rectangle r;
    double step = windowWidth / 13.0;
    int currentLaneIndex = 12;
    double speed = 0;

public:

    Frog(Point center={windowWidth / 2.0, 25.0 * windowHeight / 26}, int w=casesize - 20, int h=casesize - 20);
    int getCurrentLaneIndex();
    Rectangle getR(){return r;}
    void setSpeed(double speed){this->speed=speed;}
    void draw() const;

    void jump(int direction);

    void move();

    void checkInBounds();

    void dead();

    void win();

    void reset();
};



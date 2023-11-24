
#ifndef FROGGER_VEHICULES_H
#define FROGGER_VEHICULES_H

#include <point-rectangle.h>

using namespace std;

const double refreshPerSecond = 60;
const int windowWidth = 780;
const int windowHeight = 780;
const int casesize = windowWidth / 13;


class SlidingObject {
    bool isDeadly;
    double speed;
    Rectangle physicalBorder;

public:
    SlidingObject(bool isDeadly, double speed, Rectangle physicalBorder)
            : isDeadly(isDeadly), speed(speed), physicalBorder(physicalBorder) {}

    void setPosition(Point newPosition);

    Point getPosition();

    void draw();

    void slide();

    bool getIsDeadly() const;

    double getSpeed() const { return speed; }

    Rectangle const getPhysical() const { return physicalBorder; }
};

class Car : public SlidingObject {
public:
    Car(double carSpeed, const Point &carPosition)
            : SlidingObject(true, carSpeed, {carPosition, casesize, casesize, FL_BLACK, FL_BLACK}) {
    }
};

class Log : public SlidingObject {
public:
    Log(double carSpeed, const Point &carPosition)
            : SlidingObject(false, carSpeed,
                            {carPosition, casesize, casesize, fl_rgb_color(165, 42, 42), fl_rgb_color(165, 42, 42)}) {
    }
};

#endif //FROGGER_VEHICULES_H

#ifndef FROGGER_VEHICULES_HPP
#define FROGGER_VEHICULES_HPP

#include "point-rectangle.hpp"

class SlidingObject {
protected:
    bool isDeadly;
    double speed;
    Rectangle physicalBorder;

public:
    SlidingObject(bool isDeadly, double speed, Rectangle physicalBorder)
            : isDeadly(isDeadly), speed(speed), physicalBorder(physicalBorder) {}

    void setPosition(Point newPosition);

    Point getPosition();

    virtual void draw();

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
    Log(double logSpeed, const Point &logPosition)
            : SlidingObject(false, logSpeed,
                            {logPosition, casesize, casesize, fl_rgb_color(165, 42, 42), fl_rgb_color(165, 42, 42)}) {
    }
};

class Turtle : public SlidingObject {
    double delay;
    bool diving;
    public:
        Turtle(double turtleSpeed, const Point &turtlePosition, double delay);              
    
        void draw() override;
        static void updateStateCallback(void *userdata);
        void updateState();

    // Fonction pour démarrer la minuterie
};
#endif //FROGGER_VEHICULES_HPP

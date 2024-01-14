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

    virtual void draw();
    void slide();
    void setCenter(Point point){physicalBorder.setCenter(point);}
    void changeIsDeadly();

    bool getIsDeadly() const;
    double getSpeed() const { return speed; }
    Rectangle getPhysical() { return physicalBorder; }
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

class Nenuphar : public SlidingObject {
public :
    Nenuphar(const Point &nenupharPosition)
            : SlidingObject(false, 0, {nenupharPosition, casesize, casesize, fl_rgb_color(8, 71, 23),
                                       fl_rgb_color(8, 71, 23)}) {}

    void draw() override;
};

#endif //FROGGER_VEHICULES_HPP

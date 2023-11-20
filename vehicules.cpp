#include "point-rectangle.cpp"  // Assurez-vous que le fichier point-rectangle.cpp est inclus correctement
const int windowWidth = 780;
const int windowHeight = 780;
const int casesize = 780/13;

class SlidingObject {
    bool isDeadly;
    int speed;
    Rectangle physicalBorder;

public:
    SlidingObject(bool isDeadly, int speed, Rectangle& physicalBorder)
            : isDeadly(isDeadly), speed(speed), physicalBorder(physicalBorder) {}
    void setPosition(Point newPosition);
    Point getPosition();
    void draw();
    void slide();
};


void SlidingObject::draw() {
    physicalBorder.draw();
}

void SlidingObject::slide(){
    Point currentCenter = physicalBorder.getCenter();
    if (currentCenter.x > windowWidth + 100) {
        currentCenter.x = 0;
    }
    currentCenter.x += speed;
    physicalBorder.setCenter(currentCenter);}


class Car : public Vehicle {
public:
    Car(double carSpeed, const Point& carPosition)
        : Vehicle(true, carSpeed, {carPosition, casesize,casesize, FL_RED, FL_RED}) {
        // Autres initialisations spécifiques à Car si nécessaire
    }
};

class Log : public Vehicle {
public:
    Car(double carSpeed, const Point& carPosition)
        : Vehicle(false, carSpeed, {carPosition, casesize,casesize, FL_BROWN, FL_BROWN}) {
        // Autres initialisations spécifiques à Car si nécessaire
    }
};























class Turtle : public SlidingObject {
    int delay;
    bool isUnderwater;
public:
    void setIsUnderwater();

    bool getIsUnderwater();
};

void Turtle::setIsUnderwater() {
    isUnderwater = not isUnderwater;
}

bool Turtle::getIsUnderwater() {
    return isUnderwater;
}

#include "point-rectangle.cpp"  // Assurez-vous que le fichier point-rectangle.cpp est inclus correctement

class SlidingObject {
    bool isDeadly;
    int speed;
    Rectangle physicalBorder;

public:
    SlidingObject(bool isDeadly, int speed, Rectangle physicalBorder)
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

class Car : public SlidingObject {

public:
    Car(Point position, int speed, Rectangle physicalBorder={windowWidth/13, windowHeight / 13, FL_BLACK, FL_RED})
            : SlidingObject(true, speed, physicalBorder) {}
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

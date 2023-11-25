#include "frog.hpp"

Frog::Frog(Point center, int w, int h, vector<Lane> &lanes) :
        r(center, w, h, FL_BLACK, FL_GREEN), lanes(lanes) {}

void Frog::draw() {
    r.draw();
}

void Frog::jump(int direction) {
    Point currentCenter = r.getCenter();
    if (direction == FL_Left) {
        currentCenter.x -= step;
    } else if (direction == FL_Right) {
        currentCenter.x += step;
    } else if (direction == FL_Up) {
        currentCenter.y -= step;
        currentLaneIndex -= 1;
    } else if (direction == FL_Down) {
        currentCenter.y += step;
        currentLaneIndex += 1;
    }
    r.setCenter(currentCenter);
}


void Frog::move() {
    Point currentCenter = r.getCenter();
    currentCenter.x += speed;
    r.setCenter(currentCenter);
}

void Frog::checkCollision() {
    bool noCollisionDetected = true;
    for (const auto &object: lanes[currentLaneIndex].getLaneObjects()) {
        if (r.checkCollision(object->getPhysical())) {
            noCollisionDetected = false;
            if (not object->getIsDeadly()) {
                if (not object->getSpeed()){ // on est sur un nénuphar
                    object->changeIsDeadly();
                    win();
                }
                speed = object->getSpeed(); }
            else {
                dead();
            }
            break;
        }
    }

    if (noCollisionDetected) {
        speed = 0;
        if (lanes[currentLaneIndex].getIsDeadly()) {
            dead();
        }
    }
}

void Frog::checkInBounds() {
    if (r.getCenter().x > windowWidth || r.getCenter().x < 0 || r.getCenter().y > windowHeight || r.getCenter().y < 0)
        dead();
}

void Frog::dead() {
    r.setCenter({windowWidth / 2.0, 25.0 * windowHeight / 26});
    currentLaneIndex = 12;
    cout <<"dead"<<endl;

}

void Frog::win() {
    r.setCenter({windowWidth / 2.0, 25.0 * windowHeight / 26});
    currentLaneIndex = 12;
    cout <<"won"<<endl;
}

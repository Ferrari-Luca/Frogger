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
            if (not object->getIsDeadly()) { speed = object->getSpeed(); }
            else {
                r.setCenter({windowWidth / 2, 25 * windowHeight / 26});
                currentLaneIndex = 12;
            }
            break;
        }
    }

    if (noCollisionDetected) {
        speed = 0;
        if (lanes[currentLaneIndex].getIsDeadly()) {
            r.setCenter({windowWidth / 2, 25 * windowHeight / 26});
            currentLaneIndex = 12;
        }
    }
}


// void Frog::setLane(vector<Lane> &laness) {
//     lanes = laness;
// }


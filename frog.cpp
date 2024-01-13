#include "frog.hpp"

Frog::Frog(Point center, int w, int h)
        : r(center, w, h, FL_BLACK, FL_GREEN) {
}

void Frog::draw() const {
    r.draw();
}

void Frog::jump(int direction) {
    if (!isDead() && !isVictorious()) {
        numberOfMoves += 1;
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
}


void Frog::move() {
    Point currentCenter = r.getCenter();
    currentCenter.x += speed;
    r.setCenter(currentCenter);
}

int Frog::getCurrentLaneIndex() {
    return currentLaneIndex;
}

void Frog::checkInBounds() {
    if (r.getCenter().x > windowWidth || r.getCenter().x < 0 || r.getCenter().y > windowHeight || r.getCenter().y < 0) {
        dead();
    }
}

void Frog::resetPosition() {
    r.setCenter({windowWidth / 2.0, 25.0 * windowHeight / 26});
    currentLaneIndex = 12;
}

void Frog::reset() {
    resetPosition();
    lives = 3;
    victories = 0;
}

void Frog::dead() {
    resetPosition();
    decrementLives();
}

void Frog::win() {
    resetPosition();
    incrementVictories();

}


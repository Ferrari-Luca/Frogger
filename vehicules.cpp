#include "vehicules.hpp"

bool SlidingObject::getIsDeadly() const {
    return isDeadly;
}

void SlidingObject::draw() {
    physicalBorder.draw();
}

void SlidingObject::slide() {
    Point currentCenter = physicalBorder.getCenter();
    if (currentCenter.x >= windowWidth + casesize * 6 + windowWidth / 26) {
        currentCenter.x = -5 * casesize + windowWidth / 26;
    }
    currentCenter.x += speed;
    physicalBorder.setCenter(currentCenter);
}

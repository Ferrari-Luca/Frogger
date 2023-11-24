#include "lane.hpp"

Lane::Lane(const LaneInfo &info, Point center) : rect(center, windowWidth, casesize) {
    isDeadly = (info.lanetype == 'R') ? true : false;
    Fl_Color color = (info.lanetype == 'R') ? FL_BLUE : FL_DARK3;
    if (info.lanetype == 'N') {
        color = FL_WHITE;
    }
    rect.setFillColor(color);
    rect.setFrameColor(color);

    for (int i = 0; i < info.gameobject.size(); i++) {
        Point object_center{static_cast<double>((i - 5) * casesize + windowWidth / 26), rect.getCenter().y};
        if (info.gameobject[i] == 'C') {
            laneObjects.push_back(Car(info.speed, object_center));
        }
        if (info.gameobject[i] == 'L') {
            laneObjects.push_back(Log(info.speed, object_center));
        }
    }
}

void Lane::update() {
    for (auto &object: laneObjects) {
        object.slide();
    }
}

void Lane::draw() {
    fl_draw_box(FL_FLAT_BOX, rect.getCenter().x - windowWidth / 2, rect.getCenter().y - casesize / 2, windowWidth,
                casesize, rect.getColor());
    for (auto &object: laneObjects) {
        object.draw();
    }
}

bool Lane::getIsDeadly() const {
    return isDeadly;
}

const std::vector<SlidingObject> &Lane::getLaneObjects() const {
    return laneObjects;
}

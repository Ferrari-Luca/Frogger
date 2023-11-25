
#include "lane.hpp"


Lane::Lane(const LaneInfo &info, Point center) : rect(center, windowWidth, casesize) {
    isDeadly = info.lanetype == 'R';
    Fl_Color color = (info.lanetype == 'R') ? FL_BLUE : FL_DARK3;
    if (info.lanetype == 'N') {
        color = FL_WHITE;
    }
    rect.setFillColor(color);
    rect.setFrameColor(color);

    for (int i = 0; i < (int) info.gameobject.size(); i++) {
        Point object_center{static_cast<double>((i - 5) * casesize + windowWidth / 26.0), rect.getCenter().y};
        if (info.gameobject[i] == 'C') {
            laneObjects.push_back(make_unique<Car>(info.speed, object_center));
        } else if (info.gameobject[i] == 'L') {
            laneObjects.push_back(make_unique<Log>(info.speed, object_center));
        } else if (info.gameobject[i] == 'T') {
            laneObjects.push_back(make_unique<Turtle>(info.speed, object_center, 0));
        } else if (info.gameobject[i] == 't') {
            laneObjects.push_back(make_unique<Turtle>(info.speed, object_center, 1.0));
        } else if (info.gameobject[i] == 'N') {
            laneObjects.push_back(make_unique<Nenuphar>(object_center));
        }
    }
}

void Lane::update() {
    for (auto &object : laneObjects) {
        object->slide();
    }
}

void Lane::draw() {
    fl_draw_box(FL_FLAT_BOX, rect.getCenter().x - windowWidth / 2.0, rect.getCenter().y - casesize / 2.0, windowWidth,
                casesize, rect.getColor());
    for (auto &object : laneObjects) {
        object->draw();
    }
}

bool Lane::getIsDeadly() const {
    return isDeadly;
}

const vector<unique_ptr<SlidingObject>> &Lane::getLaneObjects() const {
    return laneObjects;
}

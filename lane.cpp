#include "lane.hpp"


Lane::Lane(const LaneInfo &info, Point center) : rect(center, windowWidth, casesize) {
    if (info.lanetype == 'R' || info.lanetype == 'W') isDeadly=true;
    else isDeadly=false;
    Fl_Color color = (info.lanetype == 'R') ? FL_BLUE : FL_DARK3;
    if (info.lanetype == 'N') {
        color = FL_WHITE;
    }
    rect.setFillColor(color);
    rect.setFrameColor(color);

    for (int i = 0; i < (int) info.gameobject.size(); i++) {
        Point object_center{static_cast<double>((i - 5) * casesize + windowWidth / 26.0), rect.getCenter().y};

        Point initial_center = object_center;
        if (info.gameobject[i] == 'C') {
            laneObjects.push_back(make_shared<Car>(info.speed, object_center));
            initialPosition.push_back(initial_center);
        } else if (info.gameobject[i] == 'L') {
            laneObjects.push_back(make_shared<Log>(info.speed, object_center));
            initialPosition.push_back(initial_center);
        } else if (info.gameobject[i] == 'T') {
            laneObjects.push_back(make_shared<Turtle>(info.speed, object_center, 0));
            initialPosition.push_back(initial_center);
        } else if (info.gameobject[i] == 't') {
            laneObjects.push_back(make_shared<Turtle>(info.speed, object_center, 1.0));
            initialPosition.push_back(initial_center);
        } else if (info.gameobject[i] == 'N') {
            laneObjects.push_back(make_shared<Nenuphar>(initial_center));
            initialPosition.push_back(initial_center);
        }
    }
}

void Lane::update() {
    for (auto &object : laneObjects) {
        object->slide();
    }
}

void Lane::draw() const{
    fl_draw_box(FL_FLAT_BOX, rect.getCenter().x - windowWidth / 2.0, rect.getCenter().y - casesize / 2.0, windowWidth,
                casesize, rect.getColor());
    for (auto &object : laneObjects) {
        object->draw();
    }
}

bool Lane::getIsDeadly() const {
    return isDeadly;
}

const vector<shared_ptr<SlidingObject>> &Lane::getLaneObjects() const {
    return laneObjects;
}

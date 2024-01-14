#include "lane.hpp"

Lane::Lane(const LaneInfo &info, Point center) : rect(center, windowWidth, casesize), isDeadly(info.lanetype == 'R' || info.lanetype == 'W') {
    Fl_Color color;
    if (info.lanetype == 'R') {
        color = FL_BLUE;
    } else if (info.lanetype == 'N') {
        color = FL_WHITE;
    } else {
        color = FL_DARK3;
    }
    rect.setFillColor(color);
    rect.setFrameColor(color);
    initializeObjects(info, center);
}

void Lane::initializeObjects(const LaneInfo &info, const Point& center) {
    for (int i = 0; i < (int) info.gameobject.size(); i++) {
        Point object_center{static_cast<double>((i - 5) * casesize + windowWidth / 26.0), center.y};
        if (info.gameobject[i] == '_') continue;
        auto object = createObject(info.gameobject[i], info.speed, object_center);
        if (object) {
            laneObjects.push_back(std::move(object));
            initialPosition.push_back(object_center);
        }
    }
}

std::shared_ptr<SlidingObject> Lane::createObject(char type, double speed, const Point &center) {
    switch (type) {
        case 'C': return std::make_shared<Car>(speed, center);
        case 'L': return std::make_shared<Log>(speed, center);
        case 'T': return std::make_shared<Turtle>(speed, center, false);
        case 't': return std::make_shared<Turtle>(speed, center, true);
        case 'N': return std::make_shared<Nenuphar>(center);
        default: throw std::invalid_argument("Unknown object type");
    }
}


void Lane::update() {
    for (auto &object: laneObjects) {
        object->slide();
    }
}

void Lane::draw() const {
    fl_draw_box(FL_FLAT_BOX,rect.getCenter().x-windowWidth/2.0,
    rect.getCenter().y-casesize/2.0,windowWidth,casesize,rect.getColor());
    for (const auto &object: laneObjects) {
        object->draw();
    }
}

bool Lane::getIsDeadly() const {
    return isDeadly;
}

const std::vector<std::shared_ptr<SlidingObject>> &Lane::getLaneObjects() const {
    return laneObjects;
}

void Lane::setVisited(bool state) {
    visited = state;
}

bool Lane::wasVisited() const {
    return visited;
}

void Lane::reset() {
    for (size_t i = 0; i < laneObjects.size(); ++i) {
        laneObjects[i]->setCenter(initialPosition[i]);
        if (!laneObjects[i]->getSpeed() && laneObjects[i]->getIsDeadly()){ // on est sur un nénuphar
            laneObjects[i]->changeIsDeadly();
    }
}
}
#pragma once

#include "vehicules.hpp"
#include "gametype.hpp"
#include <vector>
#include <memory>

class Lane {
private:
    std::vector<std::shared_ptr<SlidingObject>> laneObjects;
    std::vector<Point> initialPosition;
    Rectangle rect;
    bool isDeadly;
    bool visited = false;

    void initializeObjects(const LaneInfo &info, const Point& center);
    std::shared_ptr<SlidingObject> createObject(char type, double speed, const Point &center);

public:
    Lane(const LaneInfo &info, Point center);
    void update();
    void draw() const;

    bool getIsDeadly() const;
    const std::vector<std::shared_ptr<SlidingObject>> &getLaneObjects() const;

    void setVisited(bool state);
    bool wasVisited() const;
    void reset();
};

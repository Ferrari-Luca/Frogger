#pragma once

#include "vehicules.hpp"
#include "gametype.hpp"

class Lane {
    vector<shared_ptr<SlidingObject>> laneObjects;
    vector<Point> initialPosition;
    bool isDeadly;
    Rectangle rect;
    bool visited = false;

public:
    Lane(const LaneInfo &info, Point center);

    void update();

    void draw() const;

    bool getIsDeadly() const;

    const vector<shared_ptr<SlidingObject>> &getLaneObjects() const;

    void setVisited() { visited = true; }

    void setNotVisited() { visited = false; }

    bool wasVisited() const { return visited; }

    void reset() {
        for (size_t i = 0; i < laneObjects.size(); ++i) {
            laneObjects[i]->setCenter(initialPosition[i]);
        }
    };
};



#ifndef LANE_HPP
#define LANE_HPP

#include <vector>
#include "SlidingObject.hpp"

struct LaneInfo{
    char lanetype;
    double speed;
    string gameobject;
};

class Lane {
    std::vector<SlidingObject> laneObjects;
    bool isDeadly;
    Rectangle rect;

public:
    Lane(const LaneInfo& info, Point center);

    void update();
    void draw();
    bool getIsDeadly() const;
    const std::vector<SlidingObject>& getLaneObjects() const;
};

#endif // LANE_HPP

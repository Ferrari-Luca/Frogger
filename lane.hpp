#ifndef LANE_HPP
#define LANE_HPP

#include <vehicules.hpp>
#include <gamedata.hpp>

class Lane {
    vector<SlidingObject> laneObjects;
    bool isDeadly;
    Rectangle rect;

public:
    Lane(const LaneInfo &info, Point center);

    void update();

    void draw();

    bool getIsDeadly() const;

    const vector<SlidingObject> &getLaneObjects() const;
};

#endif // LANE_HPP

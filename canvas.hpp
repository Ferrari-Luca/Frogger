#ifndef CANVAS_HPP
#define CANVAS_HPP

#include "frog.hpp"

class Canvas {
    Frog player;
    vector<Lane> lanes;

public:
    explicit Canvas(const std::vector<LaneInfo>& level,
           Point frogCenter = {windowWidth / 2.0, 25.0 * windowHeight / 26},
           int frogWidth = casesize - 20,
           int frogHeight = casesize - 20);

    void draw();
    void update();
    void keyPressed(int keyCode);
};

#endif // CANVAS_HPP

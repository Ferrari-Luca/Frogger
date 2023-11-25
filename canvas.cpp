#include "canvas.hpp"

Canvas::Canvas(const std::vector<LaneInfo> &level, Point frogCenter, int frogWidth, int frogHeight)
        : player(frogCenter, frogWidth, frogHeight, lanes) {
    for (size_t i = 0; i < level.size(); ++i) {
        Point laneCenter{windowWidth / 2.0, static_cast<double>(i * casesize) + casesize / 2.0};
        lanes.emplace_back(level[i], laneCenter);
    }
}

void Canvas::draw() {
    for (auto &lane: lanes) {
        lane.draw();
    }
    player.draw();
}

void Canvas::update() {
    player.checkInBounds();
    player.checkCollision();
    player.move();
    for (auto &lane: lanes) {
        lane.update();
    }
}

void Canvas::keyPressed(int keyCode) {
    player.jump(keyCode);
}

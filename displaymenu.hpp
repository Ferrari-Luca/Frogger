#pragma once
#include "view_interface.hpp"
#include "utils.hpp"

class DisplayMenu : public ViewInterface {
public:
    Button lvl1, lvl2, lvl3, lvl4, classic, quitButton;

    DisplayMenu() {
        lvl1 = {50, 100, 200, 50, "LVL 1"};
        lvl2 = {300, 100, 200, 50, "LVL 2"};
        lvl3 = {550, 100, 200, 50, "LVL 3"};
        lvl4 = {50, 200, 200, 50, "LVL 4"};
        classic = {300, 200, 200, 50, "Classic Mode"};
        quitButton = {550, 200, 200, 50, "Quitter"};
    }

    void draw() override {
        fl_draw_box(FL_FLAT_BOX, 0, 0, windowWidth, windowWidth + 100, fl_rgb_color(0, 100, 0));
        lvl1.draw();
        lvl2.draw();
        lvl3.draw();
        lvl4.draw();
        classic.draw();
        quitButton.draw();
    }
};

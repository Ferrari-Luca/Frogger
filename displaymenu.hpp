#pragma once
#include "utils.hpp"

class DisplayMenu {
public:
    struct Button {
        int x, y, width, height;
        string label;

        bool contains(int px, int py) const {
            return px >= x && px <= x + width && py >= y && py <= y + height;
        }
    };

    Button lvl1, lvl2, lvl3, lvl4, classic, quitButton;

    DisplayMenu() {
        lvl1 = {50, 100, 200, 50, "LVL 1"};
        lvl2 = {300, 100, 200, 50, "LVL 2"};
        lvl3 = {550, 100, 200, 50, "LVL 3"};
        lvl4 = {50, 200, 200, 50, "LVL 4"};
        classic = {300, 200, 200, 50, "Classic Mode"};
        quitButton = {550, 200, 200, 50, "Quitter"};
    }

    void draw() {
        // Dessiner tous les boutons
        fl_draw_box(FL_FLAT_BOX, 0, 0, windowWidth, windowWidth+100, fl_rgb_color(0, 100, 0));
        drawButton(lvl1);
        drawButton(lvl2);
        drawButton(lvl3);
        drawButton(lvl4);
        drawButton(classic);
        drawButton(quitButton);
    }

private:
    void drawButton(const Button &button) {
        fl_draw_box(FL_UP_BOX, button.x, button.y, button.width, button.height, FL_BLUE);
        fl_color(FL_BLACK);
        fl_font(FL_HELVETICA, 16);
        fl_draw(button.label.c_str(), button.x + 10, button.y + button.height / 2);
    }
};

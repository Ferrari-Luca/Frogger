#pragma once

#include <memory>
#include <FL/Fl.H>
#include "level.hpp"

class DisplayLevel {
    std::shared_ptr<GameModel const> gamemodel;

public:
    struct Button {
        int x, y, width, height;
        string label;

        bool contains(int px, int py) const {
            return px >= x && px <= x + width && py >= y && py <= y + height;
        }
    };
    Button menu;
    explicit DisplayLevel(std::shared_ptr<GameModel const> gamemodel)
        : gamemodel(std::move(gamemodel)) {
            menu = {550, 800, 150, 50, "Menu"};
        }
    void drawButton(const Button &button) {
        fl_draw_box(FL_UP_BOX, button.x, button.y, button.width, button.height, FL_BLUE);
        fl_color(FL_BLACK);
        fl_font(FL_HELVETICA, 16);
        fl_draw(button.label.c_str(), button.x + 10, button.y + button.height / 2);
    }
    void draw() {
        const Level& currentlevel = gamemodel->getCurrentLevel();
        currentlevel.draw();
        drawButton(menu);

    }
};

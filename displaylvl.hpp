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

    struct Message {
        int x, y, width, height;
        string text;
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

    void drawAllMessages() const {
        Message lives = {30, 790, 150, 25, "Lives : " + to_string(gamemodel->getPlayerLives())};
        Message score = {30, 820, 150, 25, "Score : " + to_string(gamemodel->getLevelScore())};
        Message highScore = {30, 850, 150, 25, "HS : " + to_string(gamemodel->getLevelHighScore())};
        drawMessage(lives);
        drawMessage(score);
        drawMessage(highScore);
    }

    void drawMessage(const Message &message) const {
        fl_draw_box(FL_UP_BOX, message.x, message.y, message.width, message.height, FL_BLUE);
        fl_color(FL_BLACK);
        fl_font(FL_HELVETICA, 20);
        fl_draw(message.text.c_str(), message.x + 5, message.y + 20);
    }

    void drawEndMessage() {
        fl_draw_box(FL_UP_BOX, 200, 800, 335, 50, FL_BLACK);
        fl_color(FL_RED);
        fl_font(FL_HELVETICA, 25);
        if (gamemodel->isPlayerDead()) {
            fl_draw("Game Over, you're dead!", 205, 830);
        } else {
            fl_draw("Congratulations, you won!", 205, 830);
        }
    }

    void draw() {
        const Level &currentlevel = gamemodel->getCurrentLevel();
        currentlevel.draw();
        drawButton(menu);
        drawAllMessages();
        if (gamemodel->gameHasEnded()) {
            this->drawEndMessage();
        }
    }
};

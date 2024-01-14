#pragma once
#include <memory>
#include "view_interface.hpp"
#include "level.hpp"


class DisplayLevel : public ViewInterface {
    std::shared_ptr<GameModel const> gamemodel;

public:
    struct Message {
        int x, y, width, height;
        std::string text;

        void draw() const {
            fl_draw_box(FL_FLAT_BOX, x, y, width, height, FL_BLUE);
            fl_color(FL_BLACK);
            fl_font(FL_HELVETICA, 20);
            fl_draw(text.c_str(), x + 5, y + 20);
        }
    };
    Button menu;
    Button highScore;

explicit DisplayLevel( std::shared_ptr<GameModel const> model)
    : gamemodel(std::move(model)), menu({550, 800, 150, 50, "Menu"}), highScore({30,850,150,25,""}){}

    void draw() override {
        gamemodel->getCurrentLevel().draw();
        menu.draw();
        drawGameStatusMessages();
        if (gamemodel->gameHasEnded()) {
            drawEndMessage();}
        else{
        fl_draw_box(FL_FLAT_BOX, 200, 800, 335, 50, fl_rgb_color(0, 100, 0));}
    }

private:
    void drawGameStatusMessages() const {
        Message lives({30, 790, 150, 25, "Lives: " + std::to_string(gamemodel->getPlayerLives())});
        Message score({30, 820, 150, 25, "Score: " + std::to_string(gamemodel->getLevelScore())});
        Message hScore({30, 850, 150, 25, "HS: " + std::to_string(gamemodel->getLevelHighScore())});
        lives.draw();
        score.draw();
        hScore.draw();
    }

    void drawEndMessage() {
        fl_draw_box(FL_FLAT_BOX, 200, 800, 335, 50, FL_BLACK);
        fl_color(FL_RED);
        fl_font(FL_HELVETICA, 25);
        if (gamemodel->isPlayerDead()) {
            fl_draw("Game Over, you're dead!", 205, 830);
        } else {
            fl_draw("Congratulations, you won!", 205, 830);
        }
    }
};

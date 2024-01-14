#pragma once

#include "gamemodel.hpp"
#include "level.hpp"
#include "displaylvl.hpp"
#include "displaymenu.hpp"
//#include <FL/Fl.h>

class ControlBoard {
    std::shared_ptr<GameModel> gamemodel;
    DisplayLevel &displayLevel;
    DisplayMenu &displayMenu;

public:
    explicit ControlBoard(std::shared_ptr<GameModel> model, DisplayLevel &dLevel, DisplayMenu &dMenu)
            : gamemodel{std::move(model)}, displayLevel(dLevel), displayMenu(dMenu) {}

    void handleClick(int x, int y) {
        if (gamemodel->getGameState() == GameState::InMenu) {
            handleMenuClick(x, y);
        } else if (gamemodel->getGameState() == GameState::InGame) {
            handleLevelClick(x, y);
        }
    }

    void handleMenuClick(int x, int y) {
        int levelIndex = -1;
        if (displayMenu.lvl1.contains(x, y)) levelIndex = 1;
        else if (displayMenu.lvl2.contains(x, y)) levelIndex = 2;
        else if (displayMenu.lvl3.contains(x, y)) levelIndex = 3;
        else if (displayMenu.lvl4.contains(x, y)) levelIndex = 4;
        else if (displayMenu.classic.contains(x, y)) {
        gamemodel->setClassicMode(true);
        levelIndex = 1;
         }
        else if (displayMenu.quitButton.contains(x, y)) {
          gamemodel->saveHighScores();
          exit(0); // Quitte l'application
       }

        if (levelIndex != -1) {
            gamemodel->setCurrentLvl(levelIndex);
            gamemodel->setGameState(GameState::InGame);
            gamemodel->resetLevel();}
    }

    void handleLevelClick(int x, int y) {
        if (displayLevel.menu.contains(x, y)) {
            gamemodel->setGameState(GameState::InMenu);
            gamemodel->setClassicMode(false);
        }
        else if(displayLevel.highScore.contains(x,y)){
            gamemodel->resetHighScores();
        }
    }

    bool processEvent(int event) {
        int x = Fl::event_x();
        int y = Fl::event_y();

        switch (event) {
            case FL_PUSH:
                handleClick(x, y);
                break;
            case FL_KEYDOWN:
                if (gamemodel->getGameState() == GameState::InGame) {
                    switch (Fl::event_key()) {
                        case 'r':
                            gamemodel->resetLevel();
                            break;
                        default:
                            gamemodel->currentLevelPlayerJump();
                    }

                }
                break;
            default:
                return false;
        }
        return true;
    }
};
#pragma once
#include "gamemodel.hpp"
#include "level.hpp"
#include "displaylvl.hpp"
#include "displaymenu.hpp"

class ControlBoard {
  std::shared_ptr<GameModel> gamemodel;
  DisplayLevel& displayLevel;
  DisplayMenu& displayMenu;

 public:
  explicit ControlBoard(std::shared_ptr<GameModel> model, DisplayLevel& dLevel, DisplayMenu& dMenu)
      : gamemodel{std::move(model)}, displayLevel(dLevel), displayMenu(dMenu) {}

  bool handleClick(int x, int y) {
    int levelIndex = -1; 
    if (displayMenu.lvl1.contains(x, y)) {
      levelIndex = 1;
    } else if (displayMenu.lvl2.contains(x, y)) {
      levelIndex = 2;
    } else if (displayMenu.lvl3.contains(x, y)) {
      levelIndex = 3;
    } else if (displayMenu.lvl4.contains(x, y)) {
      levelIndex = 4;
    }

    if (levelIndex != -1) {
       gamemodel->setCurrentLvl(levelIndex);
       gamemodel->setGameState(GameState::InGame);
    }
  }
  bool processEvent(int event) {
    switch (gamemodel->getGameState()) {
        case GameState::InMenu:
            return processMenuEvent(event);
        case GameState::InGame:
            return processLevelEvent(event);
        case GameState::InEditor:
            // Gérer l'événement pour l'éditeur si nécessaire
            break;
    }
    return false;
}

  bool processMenuEvent(int event) {
    switch (event) {
      case FL_PUSH: {
        handleClick(Fl::event_x(),Fl::event_y());
      }
      case FL_KEYDOWN:
        
      default:
        return false;
    }
    return false;
  }


  bool processLevelEvent(int event) {
    switch (event) {
      case FL_PUSH: {
        if (displayLevel.menu.contains(Fl::event_x(),Fl::event_y())){
            gamemodel->setGameState(GameState::InMenu);
            gamemodel->resetLevel();
        }
      }
      case FL_KEYDOWN:
        gamemodel->getCurrentLevel().getPlayer().jump(Fl::event_key());
      default:
        return false;
    }
    return false;
  }
};

#pragma once

#include "level.hpp"
#include "gametype.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <memory>

class GameModel {
private:
    Frog player;
    std::vector<std::vector<LaneInfo>> levelinfos;
    std::vector<Level> levels;
    int currentlvl;
    GameState gameState;
    bool classicMode = false;
    std::vector<int> highScores;
    void initializeLevels();

public:
    GameModel();
    void setCurrentLvl(int index);
    void resetLevel();

    GameState getGameState() const;
    void setGameState(GameState newState);

    const Level& getCurrentLevel() const;
    Level& getCurrentLevel();

    const Frog& getPlayer() const;
    bool gameHasEnded() const;
    bool isPlayerDead() const;
    int getPlayerLives() const;
    int getLevelScore() const;
    int getLevelHighScore() const;
    void currentLevelPlayerJump();

    void setClassicMode(bool mode);
    bool isClassicMode() const;
    void nextLevel();

    void update();

    void loadHighScores();
    void saveHighScores();
    void resetHighScores();

};
#pragma once

#include "frog.hpp"
#include "lane.hpp"
#include "gametype.hpp"

class Level {
    Frog &player;
    vector<Lane> initialLaneInfos;
    int highScore = 0;
    int currentScore = -10;

public:
    vector<Lane> lanes;

    explicit Level(Frog &player, std::vector<LaneInfo> level);

    void resetAll();

    void resetLanes();

    int getCurrentScore() const { return currentScore; }

    void setHighscore() { highScore = currentScore; }

    void updateHighScore();

    void resetScore() { currentScore = 0; }

    int getHighScore() const { return highScore; }

    void updateScore();

    void incrementScore(int value) { currentScore += value; }

    void draw() const;

    void checkCollision();

    void update();

    void resetLanesVisited();

    void keyPressed(int keyCode);


    const std::vector<Lane> &getLanes() const {
        return lanes;
    }

    Frog &getPlayer() {
        return player;
    }

    const Frog &getPlayer() const {
        return player;
    }
};



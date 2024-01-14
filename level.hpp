#pragma once

#include "frog.hpp"
#include "lane.hpp"
#include "gametype.hpp"
#include <vector>

class Level {
    Frog &player;
    std::vector<Lane> lanes;
    int& highScore;
    int currentScore = -10;
    std::chrono::steady_clock::time_point levelStartTime;
    std::chrono::seconds levelDuration{120};

public:
    explicit Level(int& highScoreRef, Frog &player, std::vector<LaneInfo> level);

    void resetAll();
    void resetLanes();
    void resetScore();
    void resetLanesVisited();

    void update();
    void draw() const;
    void checkCollision();
    void keyPressed(int keyCode);
    void updateScore();
    void updateHighScore();

    void incrementScore(int value);

    int getCurrentScore() const;
    int getHighScore() const;

    const std::vector<Lane>& getLanes() const;
    Frog& getPlayer();
    const Frog& getPlayer() const;

    void startLevel();
    float getTimeRemainingFraction() const;
};



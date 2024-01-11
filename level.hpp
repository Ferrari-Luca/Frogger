#pragma once

#include "frog.hpp"
#include "lane.hpp"
#include "gametype.hpp" 

class Level {
    Frog& player;
    vector<Lane> initialLaneInfos;

public:
    vector<Lane> lanes;
    explicit Level(Frog& player, std::vector<LaneInfo> level);

    void resetLanes();
    void draw() const;
    void checkCollision();
    void update();
    void keyPressed(int keyCode);
    const std::vector<Lane>& getLanes() const {
        return lanes;
    }
    Frog& getPlayer() {
        return player;
    }

    const Frog& getPlayer() const {
        return player;
    }
};



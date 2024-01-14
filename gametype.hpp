// GameTypes.hpp
#pragma once

#include <string>
#include <vector>

struct LaneInfo {
    char lanetype;
    double speed;
    string gameobject;
};

enum GameState {InMenu, InGame, InEditor};

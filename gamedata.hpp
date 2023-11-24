#ifndef GAMEDATA_HPP
#define GAMEDATA_HPP

#include <utils.hpp>

struct LaneInfo {
    char lanetype;
    double speed;
    string gameobject;
};

class GameData {
    vector<LaneInfo> froggerLevel1;

public:
    GameData();

    vector<LaneInfo> getLevel();
};

#endif // GAMEDATA_HPP

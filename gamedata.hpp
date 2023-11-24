#ifndef GAMEDATA_HPP
#define GAMEDATA_HPP

#include <vector>
#include <string>

struct LaneInfo {
    char lanetype;
    double speed;
    std::string gameobject;
};

class GameData {
    std::vector<LaneInfo> froggerLevel1;

public:
    GameData();

    std::vector<LaneInfo> getLevel();
};

#endif // GAMEDATA_HPP

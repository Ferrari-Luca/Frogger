#ifndef GAMEDATA_HPP
#define GAMEDATA_HPP

#include "utils.hpp"

struct LaneInfo {
    char lanetype;
    double speed;
    string gameobject;
};

class GameData {
    vector<vector<LaneInfo>> levels;

public:
    GameData();  // Déclaration du constructeur
    // void addLevel(const vector<LaneInfo>& level);
    // void modifyLevel(int index, const vector<LaneInfo>& modifiedLevel);
    vector<LaneInfo> getLevel(int index);
};

#endif // GAMEDATA_HPP

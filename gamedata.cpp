#include "gamedata.hpp"

GameData::GameData() {
    froggerLevel1 = {
            {'N', 1,   "________________________"},
            {'R', -1.5,"_LLL_LLL___LLL____LLL___"},
            {'R', 2,   "______LLLLLLLLLLL_______"},
            {'R', -6,  "__LL___LL___LL___LL___LL"},
            {'R', 1,   "_______LL___LL______LL__"},
            {'R', -3,  "__LLLL__________LLLL____"},
            {'N', 0,   "________________________"},
            {'S', 1,   "C__C__C__C__C__C__C__C__"},
            {'S', -1.5,"_________________CCCCC__"},
            {'S', 5,   "_________CC_____________"},
            {'S', -10, "____________C_C_________"},
            {'S', 1,   "CC____CC____CC____CC____"},
            {'N', 0,   "________________________"}
    };
}

std::vector<LaneInfo> GameData::getLevel() {
    return froggerLevel1;
}

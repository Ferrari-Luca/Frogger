#include "gamedata.hpp"

GameData::GameData() {
    levels = {
            {
                {'N', 1,   "______N__N_N_N__N_______"},
                {'R', -1.5,"_ttt_TTT___TTT____TTT___"},
                {'R', 4,   "______LLLLL________LLLLL"},
                {'R', -6,  "__TT___TT___tt___TT___TT"},
                {'R', 1,   "_______LL___LL______LL__"},
                {'R', -3,  "__TTTT__________tttt____"},
                {'N', 0,   "________________________"},
                {'S', 1,   "C__C__C__C__C__C__C__C__"},
                {'S', -1.5,"_________________CCCCC__"},
                {'S', 5,   "_________CC_____________"},
                {'S', -10, "____________C_C_________"},
                {'S', 1,   "CC____CC____CC____CC____"},
                {'N', 0,   "________________________"}
            },
            // Ajoutez d'autres niveaux au besoin
        };
    }

vector<LaneInfo> GameData::getLevel(int index){
    return levels[index];
}

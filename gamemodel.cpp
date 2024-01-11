#include "gamemodel.hpp"

GameModel::GameModel() {
    levelinfos = {
        // LVL1
        {
            {'W', 1,   "______N__N_N_N__N_______"},
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
        // LVL2
        {
            {'W', 1,   "______N__N_N_N__N_______"},
            {'R', -2,  "_TT_ttt___ttt_TT___TTT__"},
            {'R', 5,   "______LLLLLLL_____LLLL__"},
            {'R', -4,  "TT__tt__TT___TT___tt__TT"},
            {'R', 3,   "LL____LL_____LL___LL____"},
            {'R', -5,  "tttt_____TTTT______tttt_"},
            {'N', 0,   "________________________"},
            {'S', -3,  "C__C__C____C__C____C__C_"},
            {'S', 2,   "_______CCCCC___CCCCC____"},
            {'S', -6,  "_CC_______CC_________CC_"},
            {'S', 8,   "C__C____________C_C__C_C"},
            {'S', 0,   "____CC____CC____CC______"},
            {'N', 0,   "________________________"}
        },
        // LVL3
        {
            {'W', 1,   "______N__N_N_N__N_______"},
            {'R', 4,   "TTT__ttt_TTT__ttt__TTT__"},
            {'R', -1,  "LLLL________LLLL___LLLL_"},
            {'R', 6,   "___tt___TT___TT___tt____"},
            {'R', -7,  "__LL___LL______LL___LL__"},
            {'R', 1,   "___tttt__________TTTT___"},
            {'N', 0,   "________________________"},
            {'S', -2,  "__C__C__C__C__C__C__C___"},
            {'S', 3.5, "C___CCCCC________CCCCC__"},
            {'S', -9,  "CC________CC_______CC___"},
            {'S', 1,   "___C_C________C_C__C_C__"},
            {'S', -1,  "CC____CC____CC____CC____"},
            {'N', 0,   "________________________"}
        },
        // LVL4
        {
        {'W', 4,   "______N__N_N_N__N_______"},
        {'R', -2.5,"TT___TTT__ttt_TTT__TTT__"},
        {'R', 3,   "L___LLLL___LLLLL____LLL_"},
        {'R', -7,  "tt__TT___tt___TT__tt___T"},
        {'R', 2.5, "LL____LL____LL____LL____"},
        {'R', -1,  "tttt___TTTT____tttt_____"},
        {'N', 0,   "________________________"},
        {'S', 6,   "_C__C__C_C__C__C_C__C___"},
        {'S', -4,  "____CCCCC______CCCCC____"},
        {'S', 2,   "__CC____CC____CC________"},
        {'S', -10, "_C_____________C_____C_C"},
        {'S', 3.5, "CC________CC______CC____"},
        {'N', 0,   "________________________"}
        }
    };
    // Création des niveaux à partir des informations
    for (const auto& levelinfo : levelinfos) {
        levels.emplace_back(player,levelinfo);
    }
}

void GameModel::setCurrentLvl(int index) {
    currentlvl=index;
}

void GameModel::resetLevel() {
        getCurrentLevel().resetLanes();
        player.reset();

}

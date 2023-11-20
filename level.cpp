#include <iostream>
#include <vector>
#include <string>

struct LaneInfo{
    string gameobject;
    double speed;
    char lanetype;
}
class GameData() {
    // Vecteur de paires (string, float) représentant le niveau de Frogger avec des points
    std::vector<LaneInfo> froggerLevel1 = {
        LaneInfo{"R", 1, "________________________"},
        LaneInfo{"R", 1.5, "_LLL_LLL___LLL____LLL___"},
        LaneInfo{"R", 2, "____LLLLLLLLLLLLL_______"},
        LaneInfo{"R", 1, "___LL_____LL___LL___LL__"},
        LaneInfo{"R", 1, "_______LL___LL______LL__"},
        LaneInfo{"R", 3, "__LLLL__________LLLL____"},
        LaneInfo{"S", 0, "________________________"},
        LaneInfo{"S", 1, "C__C__C__C__C__C__C__C__"},
        LaneInfo{"S", 1.5, "_________________CCCCC__"},
        LaneInfo{"S", 3, "_________CC_____________"},
        LaneInfo{"S", 2, "________________________"},
        LaneInfo{"S", 1, "CC____CC____CC____CC____"},
        LaneInfo{"S", 0, "________________________"}

    };
    public:
        std::vector<LaneInfo> getLevel(){
            return froggerLevel1;
        }
}

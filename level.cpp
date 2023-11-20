#include <iostream>
#include <vector>
#include <string>

struct LaneInfo{
    string gameobject;
    double speed;
    char lanetype;
}
int main() {
    // Vecteur de paires (string, float) représentant le niveau de Frogger avec des points
    std::vector<LaneInfo> froggerLevel = {
        LaneInfo{"S",0,"________________________"},
        LaneInfo{1,"_LLL_LLL___LLL____LLL___"},
        LaneInfo{"____LLLLLLLLLLLLL_______", 1.5},
        LaneInfo{"___LL_____LL___LL___LL__", 2,},
        LaneInfo{"_______LL___LL______LL__", 1},
        LaneInfo{"__LLLL__________LLLL____", 3},
        LaneInfo{"________________________", 0},
        LaneInfo{"C__C__C__C__C__C__C__C__", 1},
        LaneInfo{"_________________CCCCC__", 1.5},
        LaneInfo{"_________CC_____________", 3},
        LaneInfo{"________________________", 2},
        LaneInfo{"CC____CC____CC____CC____", 1},
        LaneInfo{"________________________", 0}
    };

    // Affichage du niveau avec les nombres associés
    for (const auto& pair : froggerLevel) {
        std::cout << "String : " << pair.first << ", Float : " << pair.second << std::endl;
    }

    return 0;
}

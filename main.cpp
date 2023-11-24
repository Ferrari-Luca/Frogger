#include <FL/Fl.H>
#include "maiwindows.hpp"
#include "gamedata.hpp"

using namespace std;

const double refreshPerSecond = 60;
const int windowWidth = 780;
const int windowHeight = 780;
const int casesize = windowWidth/13;

int main(int argc, char* argv[]) {
    GameData gamedata;
    MainWindow window(gamedata.getLevel());
    window.show(argc, argv);
    return Fl::run();
}

#include "mainwindows.hpp"
#include "gamedata.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    GameData gamedata;
    MainWindow window(gamedata.getLevel(0));
    window.show(argc, argv);
    return Fl::run();
}

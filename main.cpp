#include "mainwindows.hpp"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <unistd.h>

void showSplashScreen() {
    Fl_Window *splashWindow = new Fl_Window(900, 1000,windowWidth, windowHeight+100, "Frogger");

    // Box pour "FROGGER" sans italique
    Fl_Box *splashBoxTitle = new Fl_Box(0, 250, 900, 100, "FROGGER");
    splashBoxTitle->labelfont(FL_BOLD);
    splashBoxTitle->labelsize(48);
    splashBoxTitle->labeltype(FL_SHADOW_LABEL);

    // Box pour les noms en italique
    Fl_Box *splashBoxNames = new Fl_Box(0, 350, 900, 100, "Aleksandra Otto\nLuca Ferrari");
    splashBoxNames->labelfont(FL_BOLD + FL_ITALIC);
    splashBoxNames->labelsize(36);
    splashBoxNames->labeltype(FL_SHADOW_LABEL);

    splashWindow->show();

    splashWindow->end();

    // Force FLTK à rafraîchir et à traiter les événements
    Fl::flush();
    Fl::check();

    // Attendre cinq secondes
    sleep(1);

    splashWindow->hide();
    delete splashBoxTitle;
    delete splashBoxNames;
    delete splashWindow;
}



int main(int argc, char *argv[]) {
    showSplashScreen();
    MainWindow window;
    window.show(argc, argv);
    return Fl::run();
}

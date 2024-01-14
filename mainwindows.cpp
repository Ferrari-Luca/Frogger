#include "mainwindows.hpp"
#include <FL/Fl.H>

MainWindow::MainWindow()
    : Fl_Window(900, 1000, windowWidth, windowHeight+100, "Frogger"), 
      model(std::make_shared<GameModel>()),
      displayBoard(model),
      displayMenu(),
      controllBoard(model, displayBoard, displayMenu) {
    Fl::add_timeout(1.0 / refreshPerSecond, Timer_CB, this);
    resizable(this);
}

void MainWindow::draw() {
    GameState currentState = model->getGameState();
    switch (currentState) {
        case GameState::InMenu:
            displayMenu.draw();
            break;
        case GameState::InGame:
            displayBoard.draw();
            break;
        case GameState::InEditor:
            // Dessiner l'éditeur (si implémenté)
            break;
    }
}

int MainWindow::handle(int event) {
    return controllBoard.processEvent(event);
}

void MainWindow::Timer_CB(void *userdata) {
    auto *win = static_cast<MainWindow *>(userdata);
    win->model->update();
    win->redraw();
    Fl::repeat_timeout(1.0 / refreshPerSecond, Timer_CB, userdata);
}
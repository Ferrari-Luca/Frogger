#include "mainwindows.hpp"

MainWindow::MainWindow(const std::vector<LaneInfo> &level)
        : Fl_Window(900, 900, windowWidth, windowHeight, "Lab 2"), canvas(level) {
    Fl::add_timeout(1.0 / refreshPerSecond, Timer_CB, this);
    resizable(this);
}

void MainWindow::draw() {
    Fl_Window::draw();
    canvas.draw();
}

int MainWindow::handle(int event) {
    switch (event) {
        case FL_MOVE:
            return 1;
        case FL_PUSH:
            return 1;
        case FL_KEYDOWN:
            canvas.keyPressed(Fl::event_key());
            return 1;
    }
    return 0;
}

void MainWindow::Timer_CB(void *userdata) {
    MainWindow *o = static_cast<MainWindow *>(userdata);
    o->canvas.update();
    o->redraw();
    Fl::repeat_timeout(1.0 / refreshPerSecond, Timer_CB, userdata);
}

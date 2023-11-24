#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "canvas.hpp"

class MainWindow : public Fl_Window {
    Canvas canvas;

public:
    MainWindow(const std::vector<LaneInfo> &level);

    void draw() override;

    int handle(int event) override;

    static void Timer_CB(void *userdata);
};

#endif // MAINWINDOW_HPP

#pragma once
#include "gamemodel.hpp"
#include "displaylvl.hpp"
#include "displaymenu.hpp"
#include "controller.hpp"
#include "leveleditor.hpp"
#include <FL/Fl_Window.H>
#include <memory>

class MainWindow : public Fl_Window {
    std::shared_ptr<GameModel> model;
    DisplayLevel displayBoard;
    DisplayMenu displayMenu;
    ControlBoard controllBoard;
    

public:
    explicit MainWindow();
    void draw() override;
    int handle(int event) override;

private:
    static void Timer_CB(void* userdata);
};

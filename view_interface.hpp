#pragma once
#include <FL/Fl.H>         
#include <FL/fl_draw.H>    
#include <string>

class ViewInterface {
public:
    struct Button {
        int x, y, width, height;
        std::string label;

        bool contains(int px, int py) const {
            return px >= x && px <= x + width && py >= y && py <= y + height;
        }

        void draw() const {
            fl_draw_box(FL_UP_BOX, x, y, width, height, FL_BLUE);
            fl_color(FL_BLACK);
            fl_font(FL_HELVETICA, 16);
            fl_draw(label.c_str(), x + 10, y + height / 2);
        }
    };

    virtual void draw() = 0; // Pure virtual function for drawing the view
    virtual ~ViewInterface() {} // Virtual destructor for proper cleanup
};

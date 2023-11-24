#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <string>
#include <math.h>
#include <time.h>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <memory>

#ifndef FROGGER_POINT_RECTANGLE_H
#define FROGGER_POINT_RECTANGLE_H

struct Point {
    double x, y;
};

class Rectangle {
private:
    Point center;
    int w, h;
    Fl_Color frameColor;
    Fl_Color fillColor;

public:
    Rectangle(Point center, int w, int h,
              Fl_Color frameColor = FL_BLACK,
              Fl_Color fillColor = FL_WHITE);

    void draw();

    void setFillColor(Fl_Color newFillColor);

    void setFrameColor(Fl_Color newFrameColor);

    void setCenter(Point newCenter);

    Point getCenter() const;

    Fl_Color getColor() { return fillColor; }

    bool checkCollision(Rectangle r);

    int getWidth() { return w; }

    int getHeight() { return h; }
};


#endif //FROGGER_POINT_RECTANGLE_H

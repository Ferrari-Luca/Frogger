#ifndef FROGGER_POINT_RECTANGLE_H
#define FROGGER_POINT_RECTANGLE_H

#include "utils.hpp"

struct Point {
    double x, y;
};

class Rectangle {
private:
    Point center;
    double w, h;
    Fl_Color frameColor;
    Fl_Color fillColor;

public:
    Rectangle(Point center, double w, double h,
              Fl_Color frameColor = FL_BLACK,
              Fl_Color fillColor = FL_WHITE);

    void draw() const;
    void setFillColor(Fl_Color newFillColor);
    void setFrameColor(Fl_Color newFrameColor);
    void setCenter(Point newCenter);

    Point getCenter() const;
    Fl_Color getColor() const { return fillColor; }
    double getWidth() const { return w; }
    double getHeight() const { return h; }
    bool checkCollision(Rectangle r) const;
};

#endif //FROGGER_POINT_RECTANGLE_H

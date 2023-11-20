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

using namespace std;
const int windowWidth = 780;
const int windowHeight = 780;

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

    bool contains(Point p);

    void setCenter(Point newCenter);

    Point getCenter() const;
};

// Implémentation du constructeur
Rectangle::Rectangle(Point center, int w, int h,
                     Fl_Color frameColor,
                     Fl_Color fillColor)
        : center(center), w(w), h(h), frameColor(frameColor), fillColor(fillColor) {
    // Vous pouvez ajouter d'autres opérations d'initialisation ici si nécessaire
}

void Rectangle::draw() {
    // Ajout de dessins
    fl_draw_box(FL_FLAT_BOX, center.x - w / 2, center.y - w / 2, w, h, fillColor);
    fl_draw_box(FL_BORDER_FRAME, center.x - w / 2, center.y - w / 2, w, h, frameColor);
}

void Rectangle::setFillColor(Fl_Color color) {
    fillColor = color;
}

void Rectangle::setFrameColor(Fl_Color color) {
    frameColor = color;
}

bool Rectangle::contains(Point p) {
    return ((center.x - w / 2 < p.x && p.x < center.x + w / 2) && (center.y - h / 2 < p.y && p.y < center.y + h / 2));
}

Point Rectangle::getCenter() const {
    return center;
}

void Rectangle::setCenter(Point newCenter) {
    center = newCenter;
}
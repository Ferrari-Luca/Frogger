#include <point-rectangle.h>

// Implémentation du constructeur
Rectangle::Rectangle(Point center, int w, int h,
                     Fl_Color frameColor,
                     Fl_Color fillColor)
        : center(center), w(w), h(h), frameColor(frameColor), fillColor(fillColor) {
    // Vous pouvez ajouter d'autres opérations d'initialisation ici si nécessaire
}

bool Rectangle::checkCollision(Rectangle other) {
    double thisLeft = center.x - w / 2;
    double thisRight = center.x + w / 2;
    double thisTop = center.y - h / 2;
    double thisBottom = center.y + h / 2;

    double otherLeft = other.getCenter().x - other.getWidth() / 2;
    double otherRight = other.getCenter().x + other.getWidth() / 2;
    double otherTop = other.getCenter().y - other.getHeight() / 2;
    double otherBottom = other.getCenter().y + other.getHeight() / 2;

    return (
            thisLeft < otherRight &&
            thisRight > otherLeft &&
            thisTop < otherBottom &&
            thisBottom > otherTop
    );
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

Point Rectangle::getCenter() const {
    return center;
}

void Rectangle::setCenter(Point newCenter) {
    center = newCenter;
}

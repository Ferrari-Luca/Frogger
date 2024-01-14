#include "frog.hpp"

Frog::Frog(Point center, int w, int h)
        : r(center, w, h, FL_BLACK, FL_GREEN),orientation(UP) {
}

#include <FL/fl_draw.H>
// ... autres inclusions ...

void Frog::draw() const {
    // Dessin du corps de la grenouille
    r.draw();

    Point center = r.getCenter();
    int w = r.getWidth();
    int h = r.getHeight();

    // Configuration pour les yeux
    int eyeSize = std::min(w, h) / 4;  // Taille des yeux
    int eyeOffsetX = w / 4;            // Décalage horizontal des yeux
    int eyeOffsetY = h / 4;            // Décalage vertical des yeux

    // Configuration pour les pattes
    int legLength = std::min(w, h) / 3; // Longueur des pattes
    int legWidth = legLength / 4;       // Largeur des pattes

    fl_color(FL_GREEN); // Couleur des pattes

    // Dessiner les pattes en fonction de l'orientation
    switch (orientation) {
        case UP:
        case DOWN:
            // Pattes latérales
            fl_rectf(center.x - w / 2 - legWidth, center.y - legLength / 2, legWidth, legLength);
            fl_rectf(center.x + w / 2, center.y - legLength / 2, legWidth, legLength);
            break;
        case LEFT:
        case RIGHT:
            // Pattes verticales
            fl_rectf(center.x - legLength / 2, center.y - h / 2 - legWidth, legLength, legWidth);
            fl_rectf(center.x - legLength / 2, center.y + h / 2, legLength, legWidth);
            break;
    }

    fl_color(FL_WHITE); // Couleur des yeux

    // Dessiner les yeux en fonction de l'orientation
    switch (orientation) {
        case UP:
            fl_pie(center.x - eyeOffsetX - eyeSize / 2, center.y - eyeOffsetY - eyeSize / 2, eyeSize, eyeSize, 0, 360);
            fl_pie(center.x + eyeOffsetX - eyeSize / 2, center.y - eyeOffsetY - eyeSize / 2, eyeSize, eyeSize, 0, 360);
            break;
        case DOWN:
            fl_pie(center.x - eyeOffsetX - eyeSize / 2, center.y + eyeOffsetY - eyeSize / 2, eyeSize, eyeSize, 0, 360);
            fl_pie(center.x + eyeOffsetX - eyeSize / 2, center.y + eyeOffsetY - eyeSize / 2, eyeSize, eyeSize, 0, 360);
            break;
        case LEFT:
            fl_pie(center.x - eyeOffsetX - eyeSize / 2, center.y - eyeOffsetY - eyeSize / 2, eyeSize, eyeSize, 0, 360);
            fl_pie(center.x - eyeOffsetX - eyeSize / 2, center.y + eyeOffsetY - eyeSize / 2, eyeSize, eyeSize, 0, 360);
            break;
        case RIGHT:
            fl_pie(center.x + eyeOffsetX - eyeSize / 2, center.y - eyeOffsetY - eyeSize / 2, eyeSize, eyeSize, 0, 360);
            fl_pie(center.x + eyeOffsetX - eyeSize / 2, center.y + eyeOffsetY - eyeSize / 2, eyeSize, eyeSize, 0, 360);
            break;
    }
}


void Frog::jump(int direction) {
    if (!isDead() && !isVictorious()) {
        numberOfMoves += 1;
        Point currentCenter = r.getCenter();
        switch (direction) {
            case 'q':
            case 'w':
            case FL_Left:
                currentCenter.x -= step;
                orientation = LEFT;
                break;
            case 'd':
            case FL_Right:
                currentCenter.x += step;
                orientation = RIGHT;
                break;
            case 'z':
            case 'a':
            case FL_Up:
                currentCenter.y -= step;
                orientation = UP;
                currentLaneIndex -= 1;
                break;
            case 's':
            case FL_Down:
                if (currentLaneIndex<12){
                currentCenter.y += step;
                orientation = DOWN;
                currentLaneIndex += 1;}
                break;
            default:
                break;
        }
        r.setCenter(currentCenter);
    }
}


void Frog::move() {
    Point currentCenter = r.getCenter();
    currentCenter.x += speed;
    r.setCenter(currentCenter);
}

int Frog::getCurrentLaneIndex() {
    return currentLaneIndex;
}

void Frog::checkInBounds() {
    if (r.getCenter().x > windowWidth || r.getCenter().x < 0 || r.getCenter().y > windowHeight || r.getCenter().y < 0) {
        dead();
    }
}

void Frog::resetPosition() {
    r.setCenter({windowWidth / 2.0, 25.0 * windowHeight / 26});
    currentLaneIndex = 12;
}

void Frog::resetVictories() {victories = 0;}

void Frog::resetLives() { lives = 3; }

void Frog::reset() {
    resetPosition();
    resetVictories();
    resetLives();
}

void Frog::dead() {
    resetPosition();
    decrementLives();
}

void Frog::win() {
    resetPosition();
    incrementVictories();

}


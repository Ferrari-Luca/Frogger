#ifndef FROGGER_FROG_H
#define FROGGER_FROG_H

#include <lane.hpp>

class Frog {
    Rectangle r;
    double step = windowWidth / 13;
    vector<Lane> &lanes;  // Référence à l'attribut lanes du Canvas
    int currentLaneIndex = 12;
    double speed = 0;
public:
    Frog(Point center, int w, int h, vector<Lane> &lanes);

    void draw();

    void jump(int direction);

    void move();

    void checkCollision();

    void treatCollision(SlidingObject *object);

    Lane *getLane() const;

    void setLane(vector<Lane> &lanes);
};

#endif //FROGGER_FROG_H

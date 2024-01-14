#pragma once

#include "utils.hpp"
#include "point-rectangle.hpp"
#include <vector>

class Lane;
enum Orientation { LEFT, RIGHT, UP, DOWN };

class Frog {
    Rectangle r;
    double step = windowWidth / 13.0;
    int currentLaneIndex = 12;
    double speed = 0;
    int lives = 3;
    int victories = 0;
    int numberOfMoves = 0;
    Orientation orientation;

public:

    Frog(Point center = {windowWidth / 2.0, 25.0 * windowHeight / 26}, int w = casesize - 20, int h = casesize - 20);

    int getCurrentLaneIndex();
    int getNumberOfMoves() const { return numberOfMoves; }
    int getLives() const { return lives; }
    Rectangle getR() { return r; }

    void decrementLives() { lives -= 1; }
    void incrementVictories() { victories += 1; }

    bool isDead() const { return lives == 0; }
    bool isVictorious() const { return victories == 5; }
    bool isEndOfGame() const { return isVictorious() || isDead(); }

    void setSpeed(double speed) { this->speed = speed; }
    void draw() const;

    void jump(int direction);
    void move();
    void checkInBounds();
    void dead();
    void win();

    void reset();
    void resetNumberOfMoves() { numberOfMoves = 0; }
    void resetPosition();
    void resetVictories();
    void resetLives();
    void timeisup(){{if(!isVictorious()){lives=0;}}}

};



#include "level.hpp"

Level::Level(Frog &player, std::vector<LaneInfo> level) : player(player) {
    for (size_t i = 0; i < level.size(); ++i) {
        Point laneCenter{windowWidth / 2.0, static_cast<double>(i * casesize) + casesize / 2.0};
        lanes.emplace_back(level[i], laneCenter);
    }
}

void Level::draw() const {
    for (auto &lane: lanes) {
        lane.draw();
    }
    player.draw();
}

void Level::checkCollision() {
    bool noCollisionDetected = true;
    int currentLaneIndex = player.getCurrentLaneIndex();
    Rectangle r = player.getR();
    // Itération sur les objets de la voie courante.
    for (const auto &object: lanes[currentLaneIndex].getLaneObjects()) {
        // Vérifiez la collision avec l'objet.
        if (r.checkCollision(object->getPhysical())) {
            noCollisionDetected = false;

            // Gestion des comportements en fonction de l'état de l'objet (mortel ou non, etc.)
            if (!object->getIsDeadly()) {
                // Si l'objet n'est pas mortel.
                if (!object->getSpeed()) { // on est sur un nénuphar
                    object->changeIsDeadly();
                    player.win();
                }
                player.setSpeed(object->getSpeed());
            } else {
                // Si l'objet est mortel.
                player.dead();
            }
            break;
        }
    }

    // Gestion du cas où aucune collision n'a été détectée.
    if (noCollisionDetected) {
        player.setSpeed(0);
        if (lanes[currentLaneIndex].getIsDeadly()) {
            player.dead();
        }
    }
}

void Level::update() {
    player.checkInBounds();
    updateScore();
    checkCollision();
    player.move();
    for (auto &lane: lanes) {
        lane.update();
    }
}

void Level::keyPressed(int keyCode) {
    player.jump(keyCode);
}

void Level::updateScore() {
    int index = getPlayer().getCurrentLaneIndex();
    if (not lanes.at(index).wasVisited()) {
        lanes.at(index).setVisited();
        if (getPlayer().getCurrentLaneIndex() == 0) {
            incrementScore(512 - getPlayer().getNumberOfMoves());
            resetLanesVisited();
            getPlayer().resetNumberOfMoves();
        }
        incrementScore(10);
    }
    updateHighScore();
}

void Level::updateHighScore() {
    if (getHighScore() < getCurrentScore()) {
        setHighscore();
    }
}

void Level::resetAll() {
    resetLanesVisited();
    resetLanes();
    resetScore();
}

void Level::resetLanesVisited() {
    for (auto &lane: lanes) { lane.setNotVisited(); }
}

void Level::resetLanes() {
    for (auto &lane: lanes) {
        lane.reset();
    }
}


#include "level.hpp"

Level::Level(int &highScoreRef, Frog &player, std::vector<LaneInfo> level) : player(player), highScore(highScoreRef) {
    for (size_t i = 0; i < level.size(); ++i) {
        Point laneCenter{windowWidth / 2.0, static_cast<double>(i * casesize) + casesize / 2.0};
        lanes.emplace_back(level[i], laneCenter);
    }
    startLevel();
}

void Level::draw() const {
    for (auto &lane: lanes) {
        lane.draw();
    }
    player.draw();
    int barWidth = static_cast<int>(getTimeRemainingFraction() * windowWidth);
    fl_draw_box(FL_FLAT_BOX, 0, windowHeight - 10, barWidth, 10, FL_GREEN);
}

void Level::checkCollision() {
    /*
     * Méthode permettant de déterminer si une collison a eu entre le joueur et les véhicules de la rangée où il se
     * trouve et de vérifier les conditions de mort/victoire
     */
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
                if (!(bool)object->getSpeed()) { // on est sur un nénuphar
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
    if (getTimeRemainingFraction() <= 0.0f) {
        player.timeisup();
    }
    // Mise à jour du joueur, score et déplacement des véhicules
    player.checkInBounds();
    updateScore();
    checkCollision();
    player.move();
    for (auto &lane: lanes) {
        lane.update();
    }
}

void Level::updateScore() {
    int index = player.getCurrentLaneIndex();
    Lane &currentLane = lanes.at(index);

    if (not currentLane.wasVisited()) {
        // La rangée courante n'a pas encore été visitée
        currentLane.setVisited(true);
        if (player.getCurrentLaneIndex() == 0) {
            // Joueur a atteint un nénuphare
            incrementScore(512 - player.getNumberOfMoves());
            // Réinitialisation des lignes visitées et du nombre de sauts réalisés
            resetLanesVisited();
            player.resetNumberOfMoves();
        }
        incrementScore(10);
    }
    updateHighScore();
}

void Level::updateHighScore() {
    if (getHighScore() < currentScore) {
        highScore = currentScore;
    }
}


void Level::resetAll() {
    resetLanesVisited();
    resetLanes();
    resetScore();
    resetPlayer();
    startLevel();

}

void Level::resetPlayer() {
    getPlayer().reset();
}

void Level::resetLanesVisited() {
    for (auto &lane: lanes) { lane.setVisited(false); }
}

void Level::resetLanes() {
    for (auto &lane: lanes) {
        lane.reset();
    }
}

void Level::resetScore() { currentScore = 0; }

void Level::incrementScore(int value) {
    currentScore += value;
}

int Level::getCurrentScore() const {
    return currentScore;
}

int Level::getHighScore() const {
    return highScore;
}

Frog &Level::getPlayer() {
    return player;
}

void Level::startLevel() {
    levelStartTime = std::chrono::steady_clock::now();
}

float Level::getTimeRemainingFraction() const {
    auto now = std::chrono::steady_clock::now();
    auto timeElapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - levelStartTime);
    return std::max(0.0f, static_cast<float>(levelDuration.count() * 1000 - timeElapsed.count()) /
            (float) (levelDuration.count() * 1000));
}
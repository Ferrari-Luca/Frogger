#include "level.hpp"

Level::Level(Frog& player, std::vector<LaneInfo> level):player(player){
    for (size_t i = 0; i < level.size(); ++i) {
        Point laneCenter{windowWidth / 2.0, static_cast<double>(i * casesize) + casesize / 2.0};
        lanes.emplace_back(level[i], laneCenter);
        // initialLaneInfos.emplace_back(level[i], laneCenter);
        // initialLaneInfos=lanes;
    }
}

void Level::draw() const{
    for (auto &lane: lanes) {
        lane.draw();
    }
    player.draw();
}

void Level::checkCollision(){
    bool noCollisionDetected = true;
    int currentLaneIndex= player.getCurrentLaneIndex();
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
                std::cout<<"piii";
                player.dead();
            }
            break;
        }
    }

    // Gestion du cas où aucune collision n'a été détectée.
    if (noCollisionDetected) {
        player.setSpeed(0);
        if (lanes[currentLaneIndex].getIsDeadly()) {
            std::cout<<"piaa";
            player.dead();
        }
    }
    std::cout<<"ttt";
}
void Level::update() {
    player.checkInBounds();
    checkCollision();
    player.move();
    for (auto &lane: lanes) {
        lane.update();
    }
}

void Level::keyPressed(int keyCode) {
    player.jump(keyCode);
}
void Level::resetLanes() {
    std::cout<<"ppp";
    for (auto &lane: lanes){
        lane.reset();
    }
    // lanes.clear();
    // for (const auto& info : initialLaneInfos) {
    //     Point laneCenter{windowWidth / 2.0, static_cast<double>(lanes.size() * casesize) + casesize / 2.0};
    //     lanes.emplace_back(info, laneCenter);
    // }
    // std::cout<<"aaa";
}

// int main(){
// std::cout<<"je t\'aime de tout mon cœur!";
// std::cout<<"je t\'aime encore plus <3 <3 <3 <3 <3 <3!!!!!!!!!!!!!";
// printf("yfgudhijlsljdioehue43s")
// return 0;
// }
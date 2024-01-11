#pragma once
#include "level.hpp"
#include "gametype.hpp"



class GameModel {
    Frog player;
    vector<vector<LaneInfo>> levelinfos;
    vector<Level> levels;
    int currentlvl;
    GameState gameState;  // Attribut pour l'état du jeu

public:
    GameModel();  // Déclaration du constructeur
    void setCurrentLvl(int index);

    // Getter pour l'état du jeu
    GameState getGameState() const {
        return gameState;
    }

    // Setter pour l'état du jeu
    void setGameState(GameState newState) {
        gameState = newState;
    }

    void resetLevel();

    const Level& getCurrentLevel() const{
        if (currentlvl >= 0 && currentlvl <= levels.size()) {
            return levels[currentlvl-1];
        } else {
            throw std::out_of_range("Current level index is out of rangetr");
        }
    }


    Level& getCurrentLevel(){
        if (currentlvl >= 0 && currentlvl <= levels.size()) {
            return levels[currentlvl-1];
        } else {
            throw std::out_of_range("Current level index is out of range");
        }
    }

    int getCurrentLevelIndex(){
        return currentlvl;
    }
};

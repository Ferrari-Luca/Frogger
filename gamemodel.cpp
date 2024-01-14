#include "gamemodel.hpp"

GameModel::GameModel() {
    loadHighScores();
    initializeLevels();
}

void GameModel::initializeLevels() {
    /*
     * Méthode chargant la représentation d'un niveau à partir d'un fichier où sont présentées ligne par lignes les
     * rangées et leurs informations
     */
    std::string line;
    for (int levelNum = 1; levelNum <= num_levels; ++levelNum) {
        std::ifstream levelFile("level" + std::to_string(levelNum) + ".txt");
        std::vector<LaneInfo> levelInfo;
        
        if (levelFile.is_open()) {
            // Chargement ligne par ligne des caractères représentant les informations d'une rangée
            while (getline(levelFile, line)) {
                std::istringstream iss(line);
                char lanetype;
                double speed;
                std::string gameobject;

                // Initialisation des données nécessaire pour représenter la rangée lue
                iss >> lanetype >> speed >> gameobject;
                levelInfo.push_back({lanetype, speed, gameobject});
            }
            // Initialisation des rangées du niveau
            levels.emplace_back(highScores[levelNum],player, levelInfo);
        } else {
            std::cerr << "Erreur : Impossible d'ouvrir le fichier level" << levelNum << ".txt" << std::endl;
        }
    }
}


void GameModel::setCurrentLvl(int index) {
    currentlvl = index;
}

void GameModel::resetLevel() {
    getCurrentLevel().resetAll();
}

GameState GameModel::getGameState() const {
    return gameState;
}

void GameModel::setGameState(GameState newState) {
    gameState = newState;
}

const Level& GameModel::getCurrentLevel() const {
        if (currentlvl >= 0 && currentlvl <= (int) levels.size()) {
            return levels[currentlvl - 1];
        } else {
            throw std::out_of_range("Current level index is out of range");
        }
    }

Level& GameModel::getCurrentLevel() {
        if (currentlvl >= 0 && currentlvl <= (int) levels.size()) {
            return levels[currentlvl - 1];
        } else {
            throw std::out_of_range("Current level index is out of range");
        }
    }

bool GameModel::gameHasEnded() const {
        return player.isEndOfGame();
    }

bool GameModel::isPlayerDead() const {
        return player.isDead();
    }

int GameModel::getPlayerLives() const {
        return player.getLives();
    }

int GameModel::getLevelScore() const {
        return levels[currentlvl-1].getCurrentScore();
    }

int GameModel::getLevelHighScore() const {
        return levels[currentlvl-1].getHighScore();
    }

void GameModel::setClassicMode(bool mode) 
    { classicMode = mode; }

bool GameModel::isClassicMode() const 
    { return classicMode; }

void GameModel::nextLevel() {
    // Passage au niveau suivant
    if (currentlvl < (int) levels.size()) {
        // Réinitialisation de position de joueur et de nénuphares atteint
        player.resetPosition();
        player.resetVictories();
        // Changement du niveau courant
        setCurrentLvl(currentlvl + 1);

    } else {
        classicMode=false;
    }
}

void GameModel::update(){
    if (gameState == GameState::InGame){
        levels[currentlvl-1].update();
    }
    // Passage au niveau suivant si joueur victorieux en mode classique
    if (isClassicMode() && player.isVictorious()) {
            nextLevel();
}}

void GameModel::loadHighScores() {
    std::ifstream file("highscores.txt");
    std::string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            int score;
            std::istringstream iss(line);
            if (iss >> score) {
                highScores.push_back(score);
            } 
        }
    } 
}

void GameModel::saveHighScores() {
    std::ofstream file("highscores.txt");
    if (file.is_open()) {
        for (int score : highScores) {
            file << score << std::endl;
        }
    }
}

void GameModel::resetHighScores() {
    std::fill(highScores.begin(), highScores.end(), 0);
    saveHighScores(); 
}

void GameModel::currentLevelPlayerJump(){
    player.jump(Fl::event_key());
}
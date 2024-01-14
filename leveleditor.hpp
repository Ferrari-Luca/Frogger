// #pragma once
// #include "view_interface.hpp"
// #include "gamemodel.hpp"
// #include <FL/Fl_Input.H>
// #include <FL/Fl_Group.H>
// #include <sstream>
// #include <vector>
// #include <string>

// class LevelEditor : public ViewInterface {
//     std::shared_ptr<GameModel> gamemodel;
//     std::vector<Fl_Input*> cells;
//     Fl_Group *editorGroup;

//     std::vector<std::string> formatLevelInfos() {
//         const auto& levelInfos = gamemodel->getCurrentLevelInfos();
//         std::vector<std::string> formattedLevelInfos;
//         for (const auto& laneInfo : levelInfos) {
//             std::stringstream ss;
//             ss << laneInfo.lanetype << " " << laneInfo.speed << " " << laneInfo.gameobject;
//             formattedLevelInfos.push_back(ss.str());
//         }
//         return formattedLevelInfos;
//     }

// public:
//     explicit LevelEditor(std::shared_ptr<GameModel>& model) 
//         : ViewInterface(), gamemodel(model) {
//         editorGroup = new Fl_Group(0, 0, 900, 1000);
//         editorGroup->begin();
//         editorGroup->end();
//         editorGroup->hide(); // Cache le groupe par défaut
//     }

//     ~LevelEditor() {
//         for (auto* cell : cells) {
//             delete cell;
//         }
//         delete editorGroup;
//     }

//     void draw() override {
//         // Assurez-vous que le groupe d'éditeurs est visible
//         editorGroup->show();

//         // Dessiner chaque cellule d'entrée
//         for (auto &cell : cells) {
//             cell->show();
//         }
//     }

//     void loadCurrentLevel() {
//         auto levelData = formatLevelInfos();

//         // Effacer les entrées existantes
//         for (auto* cell : cells) {
//             editorGroup->remove(cell);
//             delete cell;
//         }
//         cells.clear();

//         // Créer de nouvelles entrées pour chaque ligne de levelData
//         int y = 10;
//         for (auto &line : levelData) {
//             Fl_Input *input = new Fl_Input(10, y, 880, 25);
//             input->value(line.c_str());
//             cells.push_back(input);
//             y += 30;
//         }
//     }

//     // Méthodes pour sauvegarder, annuler les modifications, etc.
// };

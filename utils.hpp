
#pragma once

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <vector>
#include <string>
#include <memory>
#include <cmath>
#include <iostream>

using namespace std;

const double refreshPerSecond = 60;
const int windowWidth = 780;
const int windowHeight = 780;
const int casesize = windowWidth / 13;
const int frogWidth = casesize - 20;
const int frogHeight = casesize - 20;
const int num_levels = 4;

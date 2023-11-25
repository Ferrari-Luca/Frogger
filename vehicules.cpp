#include "vehicules.hpp"

const long double pi = 3.141592653589793238462643383279502884L;
bool SlidingObject::getIsDeadly() const {
    return isDeadly;
}

void SlidingObject::draw() {
    physicalBorder.draw();
}

void SlidingObject::slide() {
    Point currentCenter = physicalBorder.getCenter();
    if (currentCenter.x >= windowWidth + casesize * 6 + windowWidth / 26.0 && speed>0) {
        currentCenter.x = -5 * casesize + windowWidth / 26.0;
    }
    else if (currentCenter.x <= -(casesize * 6 + windowWidth / 26.0) && speed < 0) {
    currentCenter.x = windowWidth + 5 * casesize - windowWidth / 26.0;
}

    currentCenter.x += speed;
    physicalBorder.setCenter(currentCenter);
}

Turtle::Turtle(double turtleSpeed, const Point &turtlePosition, double delay)
                : SlidingObject(false, turtleSpeed,
                                {turtlePosition, casesize, casesize, FL_MAGENTA, FL_MAGENTA}),delay(delay),diving(false){
                                if (delay){Fl::add_timeout(delay, updateStateCallback, this);}                
    }
void Turtle::draw(){
    if (!diving){
    Point center = physicalBorder.getCenter();
    double r = casesize/2.0;
    array<Point, 37> points{};
  for (unsigned i = 0; i < 36; i++) {
    points.at(i) = {static_cast<double>(center.x + r * sin(i * 10 * pi / 180)),

                    static_cast<double>(center.y + r * cos(i * 10 * pi / 180))};
  }
  points[36] = points[0];
  fl_color(physicalBorder.getColor());
  fl_begin_polygon();
  for (auto &point : points) {
    fl_vertex(point.x, point.y);
  }
  fl_end_polygon();
  fl_color(physicalBorder.getColor());
  fl_begin_line();
  for (auto &point : points) {
    fl_vertex(point.x, point.y);
  }
  fl_end_line();
}}

// void Turtle::startTimer() {
//     // Ajouter une minuterie pour la prochaine mise à jour d'état
//     Fl::add_timeout(delay, [](void *obj) {
//         Turtle *turtle = static_cast<Turtle *>(obj);
//         turtle->updateState();
//         if (turtle->diving) {
//             cout << "miam" << endl;
//         } else {
//             cout << "mim" << endl;
//         }
//     }, static_cast<void*>(this));
// }

void Turtle::updateStateCallback(void *userdata) {
    Turtle *o = static_cast<Turtle *>(userdata);
    o->updateState();
    // Réinitialiser le minuteur
    Fl::repeat_timeout(o->delay, updateStateCallback, userdata);
}

void Turtle::updateState() {
    diving = !diving;
    isDeadly = !isDeadly;
}
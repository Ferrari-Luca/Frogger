
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <string>
#include <math.h>
#include <time.h>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace std;
const int windowWidth = 780;
const int windowHeight = 780;
const double refreshPerSecond = 60;

struct Point {
  double x, y;
};

class Rectangle {
 private:
  Point center; 
  int w, h;    
  Fl_Color frameColor;
  Fl_Color fillColor;

 public:
  Rectangle(Point center, int w, int h,
            Fl_Color frameColor = FL_BLACK,
            Fl_Color fillColor = FL_WHITE);

  void draw();
  void setFillColor(Fl_Color newFillColor);
  void setFrameColor(Fl_Color newFrameColor);
  bool contains(Point p);
  void setCenter(Point newCenter);
  Point getCenter() const;
};

// Implémentation du constructeur
Rectangle::Rectangle(Point center, int w, int h,
                     Fl_Color frameColor,
                     Fl_Color fillColor)
    : center(center), w(w), h(h), frameColor(frameColor), fillColor(fillColor) {
  // Vous pouvez ajouter d'autres opérations d'initialisation ici si nécessaire
}

void Rectangle::draw() {
  // Ajout de dessins
  fl_draw_box(FL_FLAT_BOX, center.x-w/2, center.y-w/2, w, h, fillColor);
  fl_draw_box(FL_BORDER_FRAME, center.x-w/2, center.y-w/2, w, h, frameColor);
}

void Rectangle::setFillColor(Fl_Color color) {
  fillColor = color;
}

void Rectangle::setFrameColor(Fl_Color color) {
  frameColor = color;
}

bool Rectangle::contains(Point p) {
  return ((center.x - w/2 < p.x && p.x < center.x + w/2) && (center.y - h/2 < p.y && p.y < center.y + h/2));
}

Point Rectangle::getCenter() const {
  return center;
}

void Rectangle::setCenter(Point newCenter) {
  center = newCenter;
}

class Frog {
  Rectangle r;
  double step=windowWidth/13;
 public:
  Frog(Point center, int w, int h);
  void draw();
  void jump(int direction);
  void move(double speed);
 
};

Frog::Frog(Point center, int w, int h):
  r(center, w, h, FL_BLACK, FL_GREEN) {}

void Frog::draw() {
  r.draw(); // Draw the rectangle
}

void Frog::jump(int direction) {
  // Obtient les coordonnées actuelles du centre du rectangle
  Point currentCenter = r.getCenter();
  
  // Ajuste les coordonnées en fonction de la direction
  if (direction == FL_Left) {
    currentCenter.x -= step;
  } else if (direction == FL_Right) {
    currentCenter.x += step;
  } else if (direction == FL_Up) {
    currentCenter.y -= step;
  } else if (direction == FL_Down) {
    currentCenter.y += step;
  }
  r.setCenter(currentCenter);}
  
void Frog::move(double speed){
  Point currentCenter = r.getCenter();
  if (currentCenter.x > windowWidth+100) {
      currentCenter.x = 0;}
  currentCenter.x += speed;
  r.setCenter(currentCenter);
}

class Lane{};

class Canvas {
  Frog player;
  vector<vector<Lane>>> lanes;

public:
  Canvas(Point frogCenter = {windowWidth/26, windowHeight/26}, int frogWidth = windowWidth/13, int frogHeight = windowHeight/13, int level=1)
      : player(frogCenter, frogWidth, frogHeight),lanes=level.getlevel(level) {
        for lane in lanes{lane.initialize()}
      }

  void draw() {
    player.draw();
  }

  void update(){
    player.move(2);
  }
  void keyPressed(int keyCode) {
    player.jump(keyCode);
  }
};
  


/* ------ DO NOT EDIT BELOW HERE (FOR NOW) ------ */
class MainWindow : public Fl_Window {
  Canvas canvas;

 public:
  MainWindow() : Fl_Window(900, 900, windowWidth, windowHeight, "Lab 2") {
    Fl::add_timeout(1.0/refreshPerSecond, Timer_CB, this);
    resizable(this);
  }

  void draw() override {
    Fl_Window::draw();
    canvas.draw();
  }

  int handle(int event) override {
    switch (event) {
      case FL_MOVE:
        return 1;
      case FL_PUSH:
        return 1;
      case FL_KEYDOWN:
        canvas.keyPressed(Fl::event_key());
        return 1;
    }
    return 0;
  }

  static void Timer_CB(void *userdata) {
    MainWindow *o = static_cast<MainWindow*>(userdata);
    o->canvas.update();
    o->redraw();
    Fl::repeat_timeout(1.0/refreshPerSecond, Timer_CB, userdata);
  }
};

int main(int argc, char *argv[]) {
  MainWindow window;
  window.show(argc, argv);
  return Fl::run();
}

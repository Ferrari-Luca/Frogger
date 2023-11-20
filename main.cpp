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

const double refreshPerSecond = 60;
const int windowWidth = 390;
const int windowHeight = 390;
const int casesize = windowWidth/13;

struct Point {
    double x, y;
};

class Rectangle {
private:
    // Point center;
    // int w, h;
    // Fl_Color frameColor;
    // Fl_Color fillColor;

public:
    Point center;
    int w, h;
    Fl_Color frameColor;
    Fl_Color fillColor;
    Rectangle(Point center, int w, int h,
              Fl_Color frameColor = FL_BLACK,
              Fl_Color fillColor = FL_WHITE);

    void draw();
    void setFillColor(Fl_Color newFillColor);
    void setFrameColor(Fl_Color newFrameColor);
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
    fl_draw_box(FL_FLAT_BOX, center.x - w / 2, center.y - w / 2, w, h, fillColor);
    fl_draw_box(FL_BORDER_FRAME, center.x - w / 2, center.y - w / 2, w, h, frameColor);
}
void Rectangle::setFillColor(Fl_Color color) {
    fillColor = color;
}

void Rectangle::setFrameColor(Fl_Color color) {
    frameColor = color;
}
Point Rectangle::getCenter() const {
    return center;
}
void Rectangle::setCenter(Point newCenter) {
    center = newCenter;
}

class Frog {
    Rectangle r;
    double step = windowWidth / 13;
public:
    Frog(Point center, int w, int h);
    void draw();
    void jump(int direction);
    void move(double speed);
};
//////////////////////////////////////////////////////////////////
class SlidingObject {
    bool isDeadly;
    double speed;
    Rectangle physicalBorder;

public:
    SlidingObject(bool isDeadly, double speed, Rectangle physicalBorder)
            : isDeadly(isDeadly), speed(speed), physicalBorder(physicalBorder) {}
    void setPosition(Point newPosition);
    Point getPosition();
    void draw();
    void slide();
};


void SlidingObject::draw() {
    physicalBorder.draw();
}

void SlidingObject::slide(){
    Point currentCenter = physicalBorder.getCenter();
    if (currentCenter.x >= windowWidth + casesize*6+windowWidth/26) {
        currentCenter.x = -5 * casesize + windowWidth / 26;
    }
    currentCenter.x += speed;
    physicalBorder.setCenter(currentCenter);}


class Car : public SlidingObject {
public:
    Car(double carSpeed, const Point& carPosition)
        : SlidingObject(true, carSpeed, {carPosition, casesize,casesize, FL_BLACK, FL_BLACK}) {
    }
};

class Log : public SlidingObject {
public:
    Log(double carSpeed, const Point& carPosition)
        : SlidingObject(false, carSpeed, {carPosition, casesize,casesize, fl_rgb_color(165, 42, 42), fl_rgb_color(165, 42, 42)}) {
    }
};

Frog::Frog(Point center, int w, int h) :
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
    r.setCenter(currentCenter);
}

void Frog::move(double speed) {
    Point currentCenter = r.getCenter();
    if (currentCenter.x > windowWidth + 100) {
        currentCenter.x = 0;
    }
    currentCenter.x += speed;
    r.setCenter(currentCenter);
}
////////////////////////////////////////////////////////////
struct LaneInfo{
    char lanetype;
    double speed;
    string gameobject;
};

class GameData{
    // Vecteur de paires (string, float) représentant le niveau de Frogger avec des points
    vector<LaneInfo> froggerLevel1 = {
        {'R', 1,   "________________________"},
        {'R', 1.5, "_LLL_LLL___LLL____LLL___"},
        {'R', 2,   "______LLLLLLLLLLL_______"},
        {'R', 6,   "___LL_____LL___LL___LL__"},
        {'R', 1,   "_______LL___LL______LL__"},
        {'R', 3,   "__LLLL__________LLLL____"},
        {'S', 0,   "________________________"},
        {'S', 1,   "C__C__C__C__C__C__C__C__"},
        {'S', 1.5, "_________________CCCCC__"},
        {'S', 5,   "_________CC_____________"},
        {'S', 10,  "____________C_C_________"},
        {'S', 1,   "CC____CC____CC____CC____"},
        {'S', 0,   "________________________"}

    };
    public:
        vector<LaneInfo> getLevel(){
            return froggerLevel1;
        }
};
////////////////////////////////////////////////////////////
class Lane {
    vector<SlidingObject> laneobjects;
    bool isDeadly;
    Rectangle r;
public:
    Lane(LaneInfo info, Point center) : r(center,windowWidth,casesize) {
        isDeadly = (info.lanetype == 'R') ? true : false;
        Fl_Color color = (info.lanetype == 'R') ? FL_YELLOW : FL_BLUE;
        if (color == FL_BLUE) {
              cout << "Bleu" <<FL_BLUE << endl;
          } else {
              cout << "Jaune" <<FL_YELLOW<< endl;
          }
        r.setFillColor(color);
        r.setFrameColor(color);
        for (int i = 0; i < info.gameobject.size(); i++) {
            // Point object_center{static_cast<double>((i-5) * casesize + windowWidth / 26),r.getCenter().y};
            Point object_center{static_cast<double>((i - 5) * casesize + windowWidth / 26),r.getCenter().y};
            cout << "object Center: (" << object_center.x << ", " << object_center.y << ")" << endl;
            if (info.gameobject[i] == 'C') {
                laneobjects.push_back(Car(info.speed,object_center));
            }
            if (info.gameobject[i] == 'L') {
                laneobjects.push_back(Log(info.speed,object_center));
            }
        }
        cout<<r.fillColor<<" "<<r.center.y<<" "<<r.w<<" "<<r.h<<endl;
    }
    void update(){
      for (auto &object : laneobjects){
                object.slide();
    }}
    void draw();
};

void Lane::draw() {
    // r.draw();
    for (auto &object : laneobjects){
                object.draw();}
}
///////////////////////////////////////////////
class Canvas {
    Frog player;
    vector<Lane> lanes;

public:
    Canvas(vector<LaneInfo> level,Point frogCenter = {windowWidth/2, 25*windowHeight / 26}, int frogWidth = windowWidth / 13,
           int frogHeight = windowHeight / 13)
            : player(frogCenter, frogWidth, frogHeight) {
        for (size_t i = 0; i < level.size(); ++i) {
            Point lanecenter{windowWidth/2,static_cast<double>(i * casesize + windowWidth / 26)};
            cout << "lane Center: (" << lanecenter.x << ", " << lanecenter.y << ")" << endl;
            lanes.push_back(Lane(level[i],lanecenter));
        }
    }

    void draw() {
        for (auto &lane : lanes){
            lane.draw();}
        player.draw();
    }

    void update() {
        player.move(0);
        for (auto &lane : lanes){
            lane.update();
    }}

    void keyPressed(int keyCode) {
        player.jump(keyCode);
    }
};


/* ------ DO NOT EDIT BELOW HERE (FOR NOW) ------ */
class MainWindow : public Fl_Window {
    Canvas canvas;

public:
    MainWindow(const vector<LaneInfo>& level) : Fl_Window(900, 900, windowWidth, windowHeight, "Lab 2"),canvas(level) {
        Fl::add_timeout(1.0 / refreshPerSecond, Timer_CB, this);
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
        MainWindow *o = static_cast<MainWindow *>(userdata);
        o->canvas.update();
        o->redraw();
        Fl::repeat_timeout(1.0 / refreshPerSecond, Timer_CB, userdata);
    }
};

int main(int argc, char *argv[]) {
    GameData gamedata;
    MainWindow window(gamedata.getLevel());
    window.show(argc, argv);
    return Fl::run();
}

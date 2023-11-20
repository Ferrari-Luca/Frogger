#include <vehicules.cpp>
#include <level.cpp>

const double refreshPerSecond = 60;


class Frog {
    Rectangle r;
    double step = windowWidth / 13;
public:
    Frog(Point center, int w, int h);

    void draw();

    void jump(int direction);

    void move(double speed);

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

class Lane {
    vector<SlidingObject> laneobjects;
    bool isDeadly;
    Rectangle r;
public:
    Lane(LaneInfo info, Rectangle r) : r(r) {
        if (info.lanetype == "R") { isDeadly = true; }
        else { isDeadly = false; }
        for (int i = 0; i < sizeof(info.gameobject); i++) {
            if (info.gameobject[i] == "C") {
                laneobjects.push_back(SlidingObject(true, info.speed,
                                                    {{(double) -5 * windowWidth / 13 + i *
                                                                                       windowWidth / 13 +
                                                      windowWidth / 26, r.getCenter().y},
                                                     windowWidth / 13, windowHeight, FL_BLACK, FL_RED}));
            }


        }
    }
    vector<SlidingObject> getObjects();
    void draw();
};

vector<SlidingObject> Lane::getObjects() {
    return laneobjects;
}

void Lane::draw() {
    r.draw();
}

class Canvas {
    Frog player;
    vector<Lane> lanes;

public:
    Canvas(Point frogCenter = {windowWidth / 26, windowHeight / 26}, int frogWidth = windowWidth / 13,
           int frogHeight = windowHeight / 13, vector<LaneInfo> froggerLevel1 = {
            LaneInfo{"R", 1, "__________________________"},
            LaneInfo{"R", 1.5, "_LLL_LLL___LLL____LLL___"},
            LaneInfo{"R", 2, "____LLLLLLLLLLLLL_____"},
            LaneInfo{"R", 1, "___LL_____LL___LL___LL__"},
            LaneInfo{"R", 1, "_______LL___LL______LL__"},
            LaneInfo{"R", 3, "__LLLL__________LLLL____"},
            LaneInfo{"S", 0, "________________________"},
            LaneInfo{"S", 1, "C__C__C__C__C__C__C__C__"},
            LaneInfo{"S", 1.5, "_________________CCCCC__"},
            LaneInfo{"S", 3, "_________CC_____________"},
            LaneInfo{"S", 2, "________________________"},
            LaneInfo{"S", 1, "CC____CC____CC____CC____"},
            LaneInfo{"S", 0, "________________________"}})
            : player(frogCenter, frogWidth, frogHeight) {
        for (int laneNumber = 1; laneNumber <= froggerLevel1.size(); laneNumber++) {
            lanes.push_back(Lane(froggerLevel1.at(laneNumber),
                                 {{0, (double) laneNumber * (windowHeight / 13)}, windowWidth, windowHeight / 13}));
        }
    }

    void draw() {
        for (auto &lane : lanes){
            lane.draw();
            for (auto &object : lane.getObjects()){
                object.draw();
            }
        }
        player.draw();
    }

    void update() {
        player.move(2);
        for (auto &lane : lanes){
            for (auto &object : lane.getObjects()){
                object.slide();
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
    MainWindow window;
    window.show(argc, argv);
    return Fl::run();
}

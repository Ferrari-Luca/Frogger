// #include <FL/Fl.H>
// #include <FL/fl_draw.H>
// #include <FL/Fl_Double_Window.H>
// #include <FL/Fl_Box.H>
// #include <string>
// #include <math.h>
// #include <time.h>
// #include <chrono>
// #include <iostream>
// #include <random>
// #include <vector>
// #include <memory>
// using namespace std;

// const double refreshPerSecond = 60;
// const int windowWidth = 780;
// const int windowHeight = 780;
// const int casesize = windowWidth/13;

// struct Point {
//     double x, y;
// };

// class Rectangle {
// private:
//     Point center;
//     int w, h;
//     Fl_Color frameColor;
//     Fl_Color fillColor;

// public:
//     Rectangle(Point center, int w, int h,
//               Fl_Color frameColor = FL_BLACK,
//               Fl_Color fillColor = FL_WHITE);

//     void draw();
//     void setFillColor(Fl_Color newFillColor);
//     void setFrameColor(Fl_Color newFrameColor);
//     void setCenter(Point newCenter);
//     Point getCenter() const;
//     Fl_Color getColor(){return fillColor;}
//     bool checkCollision(Rectangle r);
//     int getWidth(){return w;}
//     int getHeight(){return h;}
// };

// // Implémentation du constructeur
// Rectangle::Rectangle(Point center, int w, int h,
//                      Fl_Color frameColor,
//                      Fl_Color fillColor)
//         : center(center), w(w), h(h), frameColor(frameColor), fillColor(fillColor) {
//     // Vous pouvez ajouter d'autres opérations d'initialisation ici si nécessaire
// }

// bool Rectangle::checkCollision(Rectangle other) {
//     double thisLeft = center.x - w / 2;
//     double thisRight = center.x + w / 2;
//     double thisTop = center.y - h / 2;
//     double thisBottom = center.y + h / 2;

//     double otherLeft = other.getCenter().x - other.getWidth() / 2;
//     double otherRight = other.getCenter().x + other.getWidth() / 2;
//     double otherTop = other.getCenter().y - other.getHeight() / 2;
//     double otherBottom = other.getCenter().y + other.getHeight() / 2;

//     return (
//         thisLeft < otherRight &&
//         thisRight > otherLeft &&
//         thisTop < otherBottom &&
//         thisBottom > otherTop
//     );
// }


// void Rectangle::draw() {
//     // Ajout de dessins
//     fl_draw_box(FL_FLAT_BOX, center.x - w / 2, center.y - w / 2, w, h, fillColor);
//     fl_draw_box(FL_BORDER_FRAME, center.x - w / 2, center.y - w / 2, w, h, frameColor);
// }
// void Rectangle::setFillColor(Fl_Color color) {
//     fillColor = color;
// }

// void Rectangle::setFrameColor(Fl_Color color) {
//     frameColor = color;
// }
// Point Rectangle::getCenter() const {
//     return center;
// }
// void Rectangle::setCenter(Point newCenter) {
//     center = newCenter;
// }


// //////////////////////////////////////////////////////////////////
// class SlidingObject {
//     bool isDeadly;
//     double speed;
//     Rectangle physicalBorder;

// public:
//     SlidingObject(bool isDeadly, double speed, Rectangle physicalBorder)
//             : isDeadly(isDeadly), speed(speed), physicalBorder(physicalBorder) {}
//     void setPosition(Point newPosition);
//     Point getPosition();
//     void draw();
//     void slide();
//     bool getIsDeadly() const;
//     double getSpeed() const{return speed;}
//     Rectangle const getPhysical() const{return physicalBorder;}
// };


// bool SlidingObject::getIsDeadly() const {
//     return isDeadly;
// }

// void SlidingObject::draw() {
//     physicalBorder.draw();
// }

// void SlidingObject::slide(){
//     Point currentCenter = physicalBorder.getCenter();
//     if (currentCenter.x >= windowWidth + casesize*6+windowWidth/26) {
//         currentCenter.x = -5 * casesize + windowWidth / 26;
//     }
//     currentCenter.x += speed;
//     physicalBorder.setCenter(currentCenter);}


// class Car : public SlidingObject {
// public:
//     Car(double carSpeed, const Point& carPosition)
//         : SlidingObject(true, carSpeed, {carPosition, casesize,casesize, FL_BLACK, FL_BLACK}) {
//     }
// };

// class Log : public SlidingObject {
// public:
//     Log(double carSpeed, const Point& carPosition)
//         : SlidingObject(false, carSpeed, {carPosition, casesize,casesize, fl_rgb_color(165, 42, 42), fl_rgb_color(165, 42, 42)}) {
//     }
// };

// ////////////////////////

// struct LaneInfo{
//     char lanetype;
//     double speed;
//     string gameobject;
// };

// class GameData{
//     // Vecteur de paires (string, float) représentant le niveau de Frogger avec des points
//     vector<LaneInfo> froggerLevel1 = {
//         {'N', 1,   "________________________"},
//         {'R', 1.5, "_LLL_LLL___LLL____LLL___"},
//         {'R', 2,   "______LLLLLLLLLLL_______"},
//         {'R', 6,   "___LL_____LL___LL___LL__"},
//         {'R', 1,   "_______LL___LL______LL__"},
//         {'R', 3,   "__LLLL__________LLLL____"},
//         {'N', 0,   "________________________"},
//         {'S', 1,   "C__C__C__C__C__C__C__C__"},
//         {'S', 1.5, "_________________CCCCC__"},
//         {'S', 5,   "_________CC_____________"},
//         {'S', 10,  "____________C_C_________"},
//         {'S', 1,   "CC____CC____CC____CC____"},
//         {'N', 0,   "________________________"}

//     };
//     public:
//         vector<LaneInfo> getLevel(){
//             return froggerLevel1;
//         }
// };

// class Lane {
//     vector<SlidingObject> laneobjects;
//     bool isDeadly;
//     Rectangle rect;
// public:
//     Lane(LaneInfo info, Point center) : rect(center,windowWidth,casesize) {
//         cout << "lanee Center: (" << rect.getCenter().x << ", " << rect.getCenter().y << ")" << endl;
//         isDeadly = (info.lanetype == 'R') ? true : false;
//         Fl_Color color = (info.lanetype == 'R') ? FL_BLUE : FL_DARK3;
//         if (info.lanetype == 'N'){color=FL_WHITE;}
//         rect.setFillColor(color);
//         rect.setFrameColor(color);
//         for (int i = 0; i < info.gameobject.size(); i++) {
//             Point object_center{static_cast<double>((i - 5) * casesize + windowWidth / 26),rect.getCenter().y};
//             if (info.gameobject[i] == 'C') {
//                 laneobjects.push_back(Car(info.speed,object_center));
//             }
//             if (info.gameobject[i] == 'L') {
//                 laneobjects.push_back(Log(info.speed,object_center));
//             }
//         }
//     }
//     void update(){
//       for (auto &object : laneobjects){
//                 object.slide();
//     }}

//     void draw(){
//         // cout << "laneee Center: (" << rect.getCenter().x << ", " << rect.getCenter().y << ")" << endl;
//         // rect.draw();
//         fl_draw_box(FL_FLAT_BOX, rect.getCenter().x - windowWidth / 2, rect.getCenter().y - casesize / 2, windowWidth, casesize, rect.getColor());
//         for (auto &object : laneobjects){
//                     object.draw();}
//         }
//     bool getIsDeadly() const {
//         return isDeadly;
//     }
//     const vector<SlidingObject>& getLaneObjects() const {
//         return laneobjects;
//     }
// };


// class Frog {
//     Rectangle r;
//     double step = windowWidth / 13;
//     vector<Lane>& lanes;  // Référence à l'attribut lanes du Canvas
//     int currentLaneIndex=12;
//     double speed=0;
// public:
//     Frog(Point center, int w, int h,vector<Lane>& lanes);
//     void draw();
//     void jump(int direction);
//     void move();
//     void checkCollision();
//     void treatCollision(SlidingObject* object);
//     Lane* getLane() const;
//     void setLane(vector<Lane> &lanes);
// };

// Frog::Frog(Point center, int w, int h,vector<Lane>& lanes) :
//         r(center, w, h, FL_BLACK, FL_GREEN),lanes(lanes){}

// void Frog::draw() {
//     r.draw(); 
// }

// void Frog::jump(int direction) {
//     Point currentCenter = r.getCenter();
//     if (direction == FL_Left) {
//         currentCenter.x -= step;
//     } 
//     else if (direction == FL_Right) {
//         currentCenter.x += step;
//     }
//     else if (direction == FL_Up) {
//         currentCenter.y -= step;
//         currentLaneIndex-=1;
//     } 
//     else if (direction == FL_Down) {
//         currentCenter.y += step;
//         currentLaneIndex+=1;
//     }
//     r.setCenter(currentCenter);
// }


// void Frog::move() {
//     Point currentCenter = r.getCenter();
//     currentCenter.x += speed;
//     r.setCenter(currentCenter);
// }

// void Frog::checkCollision() {
//     bool noCollisionDetected = true;
//     cout <<currentLaneIndex<<endl;
//     for (const auto& object : lanes[currentLaneIndex].getLaneObjects()){
//     if (r.checkCollision(object.getPhysical())){
//         noCollisionDetected = false;
//         if (not object.getIsDeadly()){speed= object.getSpeed();}
//         else{r.setCenter({windowWidth/2, 25*windowHeight / 26});
//         currentLaneIndex=12;}
//         break;
//     }}
    
//     if (noCollisionDetected){
//       speed=0;
//       if(lanes[currentLaneIndex].getIsDeadly()){
//         r.setCenter({windowWidth/2, 25*windowHeight / 26});
//         currentLaneIndex=12;
//       }}}
    

// // void Frog::treatCollision(SlidingObject* object){
// //   if (object){
// //     if (not object->getIsDeadly()){
// //         speed = object->getSpeed();
// //     }
// //     else{
// //       r.setCenter({windowWidth/2, 25*windowHeight / 26});
// //     }}
// //   else{speed=0;}
// // }

// // Lane* Frog::getLane() const {
// //     return lanes[currentLaneIndex].get();
// // }

// void Frog::setLane(vector<Lane> &laness) {
//     lanes = laness;
// }
// ////////////////////////////////////////////////////////////

// class Canvas {
//     Frog player;
//     vector<Lane> lanes;

// public:
//     Canvas(vector<LaneInfo> level,
//            Point frogCenter = {windowWidth/2, 25*windowHeight / 26},
//            int frogWidth = casesize-20,
//            int frogHeight = casesize-20)
//         : 
//           player(frogCenter, frogWidth, frogHeight, lanes) {
//         for (size_t i = 0; i < level.size(); ++i) {
//             Point lanecenter{windowWidth/2, static_cast<double>(i * casesize) + casesize/2};
//             lanes.push_back(Lane(level[i], lanecenter));
//         }
//         // player.setLane(lanes); 
//     }

//     void draw() {
//         for (auto &lane : lanes){
//             lane.draw();}
//         player.draw();
//     }

//     void update() {
//         player.checkCollision();
//         player.move();
//         for (auto &lane : lanes){
//             lane.update();
//     }}

//     void keyPressed(int keyCode) {
//         player.jump(keyCode);
//     }
// };


// /* ------ DO NOT EDIT BELOW HERE (FOR NOW) ------ */
// class MainWindow : public Fl_Window {
//     Canvas canvas;

// public:
//     MainWindow(const vector<LaneInfo>& level) : Fl_Window(900, 900, windowWidth, windowHeight, "Lab 2"),canvas(level) {
//         Fl::add_timeout(1.0 / refreshPerSecond, Timer_CB, this);
//         resizable(this);
//     }

//     void draw() override {
//         Fl_Window::draw();
//         canvas.draw();
//     }

//     int handle(int event) override {
//         switch (event) {
//             case FL_MOVE:
//                 return 1;
//             case FL_PUSH:
//                 return 1;
//             case FL_KEYDOWN:
//                 canvas.keyPressed(Fl::event_key());
//                 return 1;
//         }
//         return 0;
//     }

//     static void Timer_CB(void *userdata) {
//         MainWindow *o = static_cast<MainWindow *>(userdata);
//         o->canvas.update();
//         o->redraw();
//         Fl::repeat_timeout(1.0 / refreshPerSecond, Timer_CB, userdata);
//     }
// };

// int main(int argc, char *argv[]) {
//     GameData gamedata;
//     MainWindow window(gamedata.getLevel());
//     window.show(argc, argv);
//     return Fl::run();
// }

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include <cmath>
#include <vector>

class Point {
public:
    float x, y;
    Point(float x, float y) : x(x), y(y) {}
};

class Rectangle {
    Point center;
    int w, h;
    Fl_Color fillColor, frameColor;
    Point velocity; // Vecteur de vitesse

public:
    Rectangle(Point center, int w, int h, Point velocity, Fl_Color frameColor = FL_BLACK, Fl_Color fillColor = FL_WHITE);
    void draw() const;
    void update();
};

Rectangle::Rectangle(Point center, int w, int h, Point velocity, Fl_Color frameColor, Fl_Color fillColor)
    : center(center),
    w(w),
    h(h),
    fillColor(fillColor),
    frameColor(frameColor),
    velocity(velocity) {}

void Rectangle::draw() const{
    // Dessin du rectangle rempli
    fl_color(fillColor);
    fl_rectf(center.x - w / 2, center.y - h / 2, w, h);

    // Dessin du contour du rectangle
    fl_color(frameColor);
    fl_rect(center.x - w / 2, center.y - h / 2, w, h);

    // Utilisation de fl_draw_box pour dessiner le rectangle rempli avec le contour
    fl_draw_box(FL_FLAT_BOX, center.x - w / 2, center.y - h / 2, w, h, frameColor);
}

void Rectangle::update() {
    if (center.y > 1000) {
        center.y = 0;
    }
    center.x += velocity.x;
    center.y += velocity.y;
}

class MainWindow : public Fl_Window {
    std::vector<Rectangle> rectangles;

public:
    MainWindow() : Fl_Window(900, 900, "Rectangle Animation") {
        // Initialisation des rectangles avec différentes positions et vitesses
        rectangles.push_back(Rectangle(Point(100.0, -200.0), 50, 100, Point(0, 6)));
        rectangles.push_back(Rectangle(Point(200.0, -200.0), 50, 100, Point(0, 3)));
        rectangles.push_back(Rectangle(Point(300.0, -200.0), 50, 100, Point(0, 2)));
        rectangles.push_back(Rectangle(Point(400.0, -200.0), 50, 100, Point(0, 4)));
        rectangles.push_back(Rectangle(Point(500.0, -200.0), 50, 100, Point(0, 1)));
        rectangles.push_back(Rectangle(Point(600.0, -200.0), 50, 100, Point(0, 5)));
        rectangles.push_back(Rectangle(Point(700.0, -200.0), 50, 100, Point(0, 0.5)));

        Fl::add_timeout(1.0 / 60, Timer_CB, this);
        resizable(this);
    }

    void draw() override {
        Fl_Window::draw();
        for (const auto& rectangle : rectangles) {
            rectangle.draw();
        }
    }

    void updateRectangles() {
        for (auto& rectangle : rectangles) {
            rectangle.update();
        }
    }

    static void Timer_CB(void* userdata) {
        MainWindow* o = static_cast<MainWindow*>(userdata);
        o->updateRectangles();
        o->redraw();
        Fl::repeat_timeout(1.0 / 60, Timer_CB, userdata);
    }
};

int main() {
    MainWindow window;
    window.show();
    return Fl::run();
}


#include <iostream>
#include <vector>
#include <memory>

struct Lane {
    // Définir la structure de votre Lane ici
};

int main() {
    // Supposez que vous avez déjà un vecteur de lanes
    std::vector<Lane> lanes = /* ... */;

    // Supposez que vous avez un pointeur intelligent unique qui pointe vers un élément de lanes
    std::unique_ptr<Lane> ptrToLane = /* ... */;

    // Trouver l'itérateur correspondant à l'élément pointé par le pointeur
    auto it = std::find(lanes.begin(), lanes.end(), *ptrToLane);

    // Vérifier si l'élément pointé est dans le vecteur lanes
    if (it != lanes.end()) {
        // Avancer l'itérateur vers l'élément suivant
        ++it;

        // Vérifier si nous avons atteint la fin du vecteur
        if (it != lanes.end()) {
            // Mettez à jour le pointeur pour pointer vers l'élément suivant
            ptrToLane.reset(new Lane(*it));
        } else {
            // Vous êtes déjà à la fin du vecteur, faites quelque chose en conséquence
            std::cout << "Le pointeur est déjà à la fin du vecteur." << std::endl;
        }
    } else {
        // Le pointeur ne pointe pas vers un élément valide dans le vecteur lanes
        std::cout << "Le pointeur ne pointe pas vers un élément valide dans le vecteur lanes." << std::endl;
    }

    // À ce stade, ptrToLane pointe vers l'élément suivant (s'il existe) dans le vecteur lanes

    return 0;
}

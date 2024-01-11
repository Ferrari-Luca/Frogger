// #include <FL/Fl.H>
// #include <FL/Fl_Window.H>
// #include <FL/Fl_Image.H>
// #include <FL/Fl_Box.H>
// #include <FL/Fl_PNG_Image.H>

// int main(int argc, char **argv)
// {
//     Fl_Window *window = new Fl_Window(1024, 1024);

//     Fl_PNG_Image *img = new Fl_PNG_Image("/Users/lucaferrari/VisualCode_C++/Frogger/menu.png");

 
//     Fl_Box *box = new Fl_Box(0, 0, img->w(), img->h());
//     box->image(img);
//     window->end();
//     window->show(argc, argv);

//     return Fl::run();
// }




// // #include <opencv2/opencv.hpp>

// // int main() {
// //     // Chargement de l'image
// //     cv::Mat image = cv::imread("menu.png", cv::IMREAD_UNCHANGED);

// //     if (image.empty()) {
// //         std::cerr << "Error: Image not found!" << std::endl;
// //         return -1;
// //     }

// //     // Accès aux données de l'image
// //     const uchar* bits = image.ptr<uchar>(0);
// //     Fl_RGB_Image *img(bits,400,400)
// //     Fl_Window *window = new Fl_Window(1024, 1024);


// //     // Utiliser `bits` pour vos besoins
// //     // ...

// //     return 0;
// // }

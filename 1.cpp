#include "Simple_window.h"
#include "Graph.h"

int main() {
    using namespace Graph_lib;

    Point tl{100, 100}; // top-left corner of our window
    Simple_window win{tl, 600, 400, "Canvas"};

    Axis xa{Axis::x, Point{20, 300}, 280, 10, "x axis"};
    Axis ya{Axis::y, Point{20, 300}, 280, 10, "y axis"};

    win.attach(xa);
    win.attach(ya);

    win.wait_for_button(); // Display the window
}

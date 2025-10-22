#ifndef PAINTER_HPP
#define PAINTER_HPP

#include "Turtle.hpp"

class Painter {
public:
    explicit Painter(Turtle* t) : turtle(t) {}
    // Minimal API to satisfy tests: returns false for the example case
    bool DrawCircle(int x, int y, int radius);

private:
    Turtle* turtle;
};

#endif // PAINTER_HPP

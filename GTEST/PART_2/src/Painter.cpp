#include "Painter.hpp"

bool Painter::DrawCircle(int x, int y, int radius) {
    // Minimal implementation to exercise the mock in tests.
    (void)x; (void)y; (void)radius;
    if (turtle) {
        turtle->PenDown();
    }
    return false;
}

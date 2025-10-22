#ifndef TURTLE_MOCK_HPP
#define TURTLE_MOCK_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Turtle.hpp"

class MockTurtle : public Turtle {
public:
    MOCK_METHOD(void, PenUp, (), (override));
    MOCK_METHOD(void, PenDown, (), (override));
    MOCK_METHOD(void, Forward, (int distance), (override));
    MOCK_METHOD(void, Turn, (int degrees), (override));
    MOCK_METHOD(void, GoTo, (int x, int y), (override));
    MOCK_METHOD(int, GetX, (), (const, override));
    MOCK_METHOD(int, GetY, (), (const, override));
};

#endif // TURTLE_MOCK_HPP

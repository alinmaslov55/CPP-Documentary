#include <gtest/gtest.h>
#include "../src/Queue.hpp"
#include <memory>

using namespace gtest_part_1;

class QueueTest : public ::testing::Test {
protected:

    std::unique_ptr<Queue<int>> intQueue;

    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).
        intQueue = std::make_unique<Queue<int>>();
    }
};

TEST_F(QueueTest, addingAndDeletingOneElement) {
    // before adding one element

    EXPECT_EQ(intQueue->getSize(), 0) << "1";
    EXPECT_TRUE(intQueue->isEmpty()) << "2";
    EXPECT_THROW(intQueue->peek(), std::underflow_error) << "3";

    // adding 1
    intQueue->enqueue(1);

    // size verification
    EXPECT_EQ(intQueue->peek(), 1) << "4";
    EXPECT_EQ(intQueue->getSize(), 1) << "5";
    EXPECT_FALSE(intQueue->isEmpty()) << "6";

    // removing 1
    intQueue->dequeue();

    // after removal verification
    EXPECT_EQ(intQueue->getSize(), 0) << "7";
    EXPECT_TRUE(intQueue->isEmpty()) << "8";
    EXPECT_THROW(intQueue->peek(), std::underflow_error) << "9";
}
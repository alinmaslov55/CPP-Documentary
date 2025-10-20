#ifndef QUEUE_HPP
#define QUEUE_HPP


#include <iostream>
#include <stdexcept>

namespace gtest_part_1 {

template <typename T>
class Queue {
public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        ++size;
    }

    void dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        --size;
        if (isEmpty()) {
            rear = nullptr;
        }
    }

    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return front->data;
    }

    bool isEmpty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    size_t size;
};

} // namespace gtest_part_1

#endif // QUEUE_HPP
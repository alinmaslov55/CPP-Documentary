#include <iostream>

class MyClass {
private:
    static int counter; // Private static variable

public:
    // Public method to access the private static variable
    static void incrementCounter() {
        counter++;
    }

    static int getCounter() {
        return counter;
    }
};

// Definition of the static variable outside the class
int MyClass::counter = 0;

int main() {
    MyClass::incrementCounter();
    MyClass::incrementCounter();

    std::cout << "Counter: " << MyClass::getCounter() << std::endl; // Output: Counter: 2

    // MyClass::counter = 10; // Error: 'counter' is private and cannot be accessed directly

    return 0;
}

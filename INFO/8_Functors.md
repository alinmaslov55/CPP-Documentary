# Functors

- \(Function Object) is a class or a struct that overloads the ```operator()``` \(function call opartor). This allows and object to be called as a class.
- Used in scenarios
    1. sorting
    2. passing callable objects to algorithms
    3. encapsulating state with callable behaviour

## Key Features

1. Encapsulation of state
    - Functors can maintain internal state, unlike normal functions
2. Flexibility
    - They can be customized for specific behaviors by designing the class
3. Use with STL Algorithms like ```std::sort```, ```std::for_each```

### Basic Functor

```cpp
#include <iostream>

// Define a functor
class Multiply {
    int factor; // Encapsulated state
public:
    Multiply(int f) : factor(f) {}

    // Overload operator()
    int operator()(int x) const {
        return x * factor;
    }
};

int main() {
    Multiply timesTwo(2); // Create a functor

    // Use the functor
    std::cout << "2 * 3 = " << timesTwo(3) << std::endl; // Output: 6

    // Use with another value
    Multiply timesFive(5);
    std::cout << "5 * 4 = " << timesFive(4) << std::endl; // Output: 20

    return 0;
}
```

### Functor with STL Algorithm

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Define a functor
struct Print {
    void operator()(int x) const {
        std::cout << x << " ";
    }
};

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Use the functor with std::for_each
    std::for_each(numbers.begin(), numbers.end(), Print());

    return 0;
}
```

### Comparison with Lambda Functions

- Functors are similar to lambdas in functionality, but lambdas are typically more concise for simple operations. Use functors when you need to encapsulate more complex behavior or maintain state across calls

## Lambda Functions

- This is an anonymous function that you can define and use inline. It’s often used to pass small, temporary functions as arguments to algorithms or to encapsulate functionality without the need to define a full-fledged named function.

### Basic Syntax

```cpp
[capture_list](parameters) -> return_type {
    // function body
};
```

- **Capture List** - Specifies which variables from the surrounding scope are available to the lambda
- **Parameters** - The inputs to the lambda
- **Return Type** - Specifies the type of the value returned by the lambda
- **Function Body** - Logic of the lambda

### Examples of Lambda Functions

#### Basic Lambda

```cpp
#include <iostream>

int main() {
    auto greet = []() { // A lambda without parameters
        std::cout << "Hello, World!" << std::endl;
    };

    greet(); // Call the lambda
    return 0;
}
```

#### Lambda with Parameters

```cpp
#include <iostream>

int main() {
    auto add = [](int a, int b) {
        return a + b;
    };

    std::cout << "5 + 3 = " << add(5, 3) << std::endl; // Output: 8
    return 0;
}
```

### Capturing Variables

1. By value \(=)
    - Makes a copy of the variables from the enclosing scope
2. By reference \(&)
    - Allows the lambda to modify the variables in the enclosing scope

```cpp
#include <iostream>

int main() {
    int x = 5, y = 10;

    // Capture by value
    auto captureValue = [x]() {
        std::cout << "x (by value): " << x << std::endl;
    };

    // Capture by reference
    auto captureReference = [&y]() {
        y += 5;
        std::cout << "y (by reference): " << y << std::endl;
    };

    captureValue();
    captureReference();
    std::cout << "y after lambda: " << y << std::endl; // y is modified

    return 0;
}
```

### Lambdas with STL Algorithms

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5};

    // Sort in descending order
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;
    });

    // Print the sorted numbers
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n << " ";
    });

    return 0;
}
```

### Generic Lambdas (C++14 and later)

- You can use ```auto``` in the parameter list to make lambdas generic

```cpp
#include <iostream>

int main() {
    auto multiply = [](auto a, auto b) {
        return a * b;
    };

    std::cout << "2 * 3 = " << multiply(2, 3) << std::endl;       // Integers
    std::cout << "2.5 * 3.5 = " << multiply(2.5, 3.5) << std::endl; // Floats

    return 0;
}
```

### Stateful Lambdas

- Lambdas can have internal state using the ```mutable``` keyword

```cpp
#include <iostream>

int main() {
    int count = 0;

    auto increment = [count]() mutable {
        ++count;
        return count;
    };

    std::cout << increment() << std::endl; // Output: 1
    std::cout << increment() << std::endl; // Output: 2

    return 0;
}
```

## Passing ```this``` in member function

- In order to modify the variables inside of a class with a lambda function we must pass the ```this``` as a capture

```cpp

class Base {
    int count{0};
    functiong(){
        auto f = [this] () {
            count++;
            std::cout << count << std::endl;
        }
        f();
        auto f2 = [obj=this] () {
            obj->count++;
            std::cout << obj->count << std::endl;
        }
        f2();
    }

};

int  main(){
    Base instance;

    instance.functiong();

    return 0;
}

```

### Notes on Lambdas

- \[=] captures everything by value
- \[&] captures everything by reference

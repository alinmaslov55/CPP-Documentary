# Design Patterns

- **Design Patterns** are reusable solutions to common software problems
- They provide a structured approach to coding
- Make software **Scalable**, **Maintainable**, and **Efficient**

## Types of Design Patterns

- Classified in 3 categories

### Creational Patterns

- Focus on object creation, while hiding instantiation details

| Pattern | Description |
|-|-|
| Singleton | Ensures a class has only on instance |
| Factory Method | Creates objects without specifying the exact class |
| Abstract Factory | Creates Family of Related objects without specifying concrete classes |
| Builder | Separates object construction from its representation |
| Prototype | Creates objects by copying an existing object |

### Structural Patterns

- Organise classes and objects for Efficient Relationships

| Pattern | Description |
|-|-|
| Adapter | Converts one interface to another (USB to HDMI converter) |
| Bridge | Decouples abstraction from implemention for flexibility |
| Composite | Treats Individual Objects and Groups of Objects the same way |
| Decorator | Adds behaviour to an object dynamically |
| Facade | Provides a simplified interface to a complex system |
| Flyweight | Shares Objects efficiently to reduce memory usage |
| Proxy | Controls access to another object |

### Behavioral Patterns

- Determine how objects communicate while reducing dependacies

| Pattern | Description |
|-|-|
| Observer | Notifies multiple objects communicate while reducing dependencies |
| Strategy | Defines interchangeable algorithms for a task |
| Command | Encapsulates a request as an object |
| State | Allows an object to change behaviour when its state changes |
| Chain of Responsability | Passes requests alomg a chain of handlers |
| Mediator | Centralizes communication between objects |
| Memento | Saves and restores an objects state |
| Visitor | Defines operations on object structures without modifying them |
| Interpreter | Defines a grammar and interpreter for a language |
| Template Method | Defines the skeleton of an algorithm but allows subclasses to customize steps |

### Most Used Patterns

**Singleton** - When only one instance is needed
**Factory Method** - When you want to delegate Object Creation
**Observer** - For Event Based Systems(UI Updates)
**Decorator** - To add features without modifying a class
**Facade** - To simplify interactions with complex systems

## Singleton

- creational pattern that ensures a class has **only one instance** and provides a **global point of access** to that instance

### Keys for Singleton

1. **Private Construtor** -> Prevents Direct Instantiation
2. **Static Method (getInstance)** -> Provides access to the instance
3. **Static Pointer (instance)** -> Stores the single instance
4. **Deleted Copy Constructor and Copy Assigment Operator** -> Prevents Duplication

### Examples of Singleton

1. Basic

    ```cpp
    #include <iostream>

    class Singleton {
    private:
        static Singleton* instance; // Static instance pointer

        // Private constructor prevents instantiation
        Singleton() {
            std::cout << "Singleton Instance Created" << std::endl;
        }

    public:
        // Delete copy constructor & assignment operator
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;

        // Static method to provide global access to the instance
        static Singleton* getInstance() {
            if (!instance) {
                instance = new Singleton(); // Create only if not already created
            }
            return instance;
        }

        void showMessage() {
            std::cout << "Hello from Singleton!" << std::endl;
        }
    };

    // Initialize static instance to nullptr
    Singleton* Singleton::instance = nullptr;

    int main() {
        // Get the single instance of the class
        Singleton* s1 = Singleton::getInstance();
        s1->showMessage();

        Singleton* s2 = Singleton::getInstance(); // Returns the same instance
        std::cout << "Same instance? " << (s1 == s2) << std::endl; // Output: 1 (true)

        return 0;
    }
    ```

2. Thread Example

    ```cpp
    #include <mutex>

    class Singleton {
    private:
        static Singleton* instance;
        static std::mutex mtx; // Mutex for thread safety

        Singleton() {}

    public:
        static Singleton* getInstance() {
            std::lock_guard<std::mutex> lock(mtx); // Ensure only one thread accesses
            if (!instance) {
                instance = new Singleton();
            }
            return instance;
        }
    };

    Singleton* Singleton::instance = nullptr;
    std::mutex Singleton::mtx;
    ```

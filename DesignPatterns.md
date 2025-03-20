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

## Factory Method

- Creational Pattern used to create objects without exposing the creation logic to the client

### Keys for Factory Method

1. **Factory Method** - A method in the factory class responsible for creating and returning objects
2. **Product** - The objetc that is created by factory method, can be abstract class or interface
3. **Concrete Product** - The actual class that implements the product interface
4. **Creator(Factory Class)** - A class that contains the factory method
5. **Client** - The class that uses the factory to obtain the product, doesn't know the specific class, but the interface

### Example of Factory Method

```cpp
#include <iostream>
#include <memory>

// Abstract Product
class Vehicle {
public:
    virtual void drive() = 0;
    virtual ~Vehicle() {}
};

// Concrete Product - Car
class Car : public Vehicle {
public:
    void drive() override {
        std::cout << "Driving a car!" << std::endl;
    }
};

// Concrete Product - Truck
class Truck : public Vehicle {
public:
    void drive() override {
        std::cout << "Driving a truck!" << std::endl;
    }
};

// Factory Class
class VehicleFactory {
public:
    static std::shared_ptr<Vehicle> createVehicle(const std::string& type) {
        if (type == "car") {
            return std::make_shared<Car>();
        } else if (type == "truck") {
            return std::make_shared<Truck>();
        }
        return nullptr; // Invalid type
    }
};

int main() {
    // Using the factory to create vehicles
    auto vehicle1 = VehicleFactory::createVehicle("car");
    if (vehicle1) vehicle1->drive();

    auto vehicle2 = VehicleFactory::createVehicle("truck");
    if (vehicle2) vehicle2->drive();

    return 0;
}
```

## Observer Design Pattern

- Behavioural design pattern that allows one object **(subject)** to notify multiple other objects **(Observers)** about changes in its state

### Keys for Observer Design Pattern

1. **Subject** - the object that maintains the state and sends notifications to observers when its state changes. Provides methods to *attach*, *detach* and *notify* **observers**
2. **Observer** - The objects that are interested in the state of the **subject**. subject updates -> observer changes
3. **Concrete Subject** - A class that implements the **subject** interface
4. **Concrete Observer** - A class that implements the **Observer** interface

### Example of Observer Design Pattern

```cpp
#include <iostream>
#include <vector>
#include <memory>
#include <string>

// Observer Interface
class Observer {
public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
    virtual ~Observer() {}
};

// Subject Interface
class Subject {
public:
    virtual void registerObserver(std::shared_ptr<Observer> observer) = 0;
    virtual void removeObserver(std::shared_ptr<Observer> observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() {}
};

// Concrete Subject (WeatherData)
class WeatherData : public Subject {
private:
    std::vector<std::shared_ptr<Observer>> observers;
    float temperature;
    float humidity;
    float pressure;
    
public:
    void setMeasurements(float temp, float hum, float press) {
        temperature = temp;
        humidity = hum;
        pressure = press;
        notifyObservers();  // Notify observers when data changes
    }

    void registerObserver(std::shared_ptr<Observer> observer) override {
        observers.push_back(observer);
    }

    void removeObserver(std::shared_ptr<Observer> observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers() override {
        for (auto& observer : observers) {
            observer->update(temperature, humidity, pressure);
        }
    }
};

// Concrete Observer (PhoneApp)
class PhoneApp : public Observer {
private:
    std::string name;
public:
    PhoneApp(const std::string& appName) : name(appName) {}

    void update(float temperature, float humidity, float pressure) override {
        std::cout << "Phone App [" << name << "] - New Weather Data: "
                  << "Temperature: " << temperature << ", Humidity: " << humidity 
                  << ", Pressure: " << pressure << std::endl;
    }
};

// Concrete Observer (WeatherDisplay)
class WeatherDisplay : public Observer {
private:
    std::string name;
public:
    WeatherDisplay(const std::string& displayName) : name(displayName) {}

    void update(float temperature, float humidity, float pressure) override {
        std::cout << "Weather Display [" << name << "] - New Weather Data: "
                  << "Temperature: " << temperature << ", Humidity: " << humidity 
                  << ", Pressure: " << pressure << std::endl;
    }
};

int main() {
    // Create weather data (subject)
    auto weatherData = std::make_shared<WeatherData>();

    // Create observers (PhoneApp, WeatherDisplay)
    auto phoneApp = std::make_shared<PhoneApp>("WeatherAlert");
    auto weatherDisplay = std::make_shared<WeatherDisplay>("Dashboard");

    // Register observers
    weatherData->registerObserver(phoneApp);
    weatherData->registerObserver(weatherDisplay);

    // Simulate weather data changes
    weatherData->setMeasurements(30.5f, 65.0f, 1013.0f);
    weatherData->setMeasurements(32.0f, 70.0f, 1012.0f);

    return 0;
}
```

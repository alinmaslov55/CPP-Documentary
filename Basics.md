# Basics od C++

## Procedural Programming vs OOP

### Summary

- This is a small Table:

| Features | Procedural Programming | OOP |
|----|----|----|
| Structure |Functions/Procedures | Classes/Objects |
| Encapsulation | Limited | High |
| Reusability | Limited | High (Inheritance, Polymorphism) |
| Data Control | Minimal | Strong (Access Modifiers) |
| Complexity Mgmt. | Basic (Top-down) | Advanced (Bottom-up) |

### Overview

| Features | Procedural Programming | OOP |
|----|----|----|
| Structure and Organization| Organizes code into functions (or procedures) that operate on data. It follows a top-down approach where the program is divided into procedures or routines. | Organizes code into objects, which combine data and behavior. It follows a bottom-up approach where the program is divided into objects representing real-world entities. |
| Data and Function Encapsulation | Procedural Programming: Data is often stored globally or passed to functions, which can lead to less control over data access. There is limited encapsulation, meaning data and functions are separated. | OOP: Encapsulates data within objects, allowing better control over access to data through access modifiers like private, protected, and public. This encapsulation ensures that only specific methods can modify the object’s data. |
| Modularity and Reusability | Procedural Programming: Functions can be reused, but reusability across different programs is limited because functions usually rely on global data and specific program structures | OOP: Promotes reusability through classes, inheritance, and polymorphism, which allow objects and methods to be reused or extended in other programs or modules. |
| Abstraction and Complexity Management | Procedural Programming: Manages complexity by breaking down tasks into procedures, but as the codebase grows, it can become challenging to manage data and functions separately. | OOP: Provides better abstraction by allowing developers to represent real-world concepts through objects and classes, which helps manage complex codebases more effectively. |
| Data Security and Access Control | Procedural Programming: Security can be harder to enforce since there’s less control over which functions can access or modify certain data. | OOP: Allows for better data security through encapsulation, meaning data can be kept private within an object, with access granted only through specific methods. |
| Examples of Languages | Procedural Programming: C, Fortran, and older versions of languages like Pascal are often used for procedural programming. | OOP: C++, Java, Python (when used in OOP style), and Ruby are commonly used for OOP. |

## The 4 Priciples of OOP

- The four main principles of Object-Oriented Programming (OOP) are **Encapsulation**, **Abstraction**, **Inheritance**, and **Polymorphism**. These principles help make code more modular, reusable, and easier to manage

| Priciple | Description | Purpose |
|---|---|---|
| Encapsulation | Bundles data and methods, restricting direct access to some components | Data protection, complexity management |
| Abstraction | Hides complex details, showing only essentials | Simplifies interaction, hides complexity |
| Inheritance | Allows new classes to inherit from existing ones | Code reuse, hierarchical relationship |
| Polymorphism | Enables methods to do different things based on context | Flexibility, method specialization |

### Encapsulation

#### Small Summary of Encapsulation

| Criteria | Description |
|------|------|
| Definition | Encapsulation is the concept of bundling data (attributes) and methods (functions) within a class, and restricting direct access to some of the class's components. |
| Purpose | To protect data from unauthorized access and misuse, and to manage complexity by hiding internal details. |
| Example | Using private or protected access modifiers in C++ or Java to restrict direct access to class properties, making them accessible only through public methods. |

### Abstraction

#### Small Summary of Abstraction

| Criteria | Description |
|------|------|
| Definition | Abstraction involves hiding complex implementation details and showing only the essential features of an object. |
| Purpose | To reduce complexity and increase readability by only exposing necessary information. |
| Example | Defining a base class with an abstract method, like draw() in a Shape class, without specifying how each shape (e.g., Circle, Square) will implement draw(). This allows each subclass to provide its own implementation. |

### Inheritance

#### Small Summary of Inheritance

| Criteria | Description |
|------|------|
| Definition | Inheritance allows a new class (derived or subclass) to inherit properties and methods from an existing class (base or superclass). |
| Purpose | To promote code reuse and establish a hierarchical relationship between classes. |
| Example | Creating a base class Animal with common attributes like species and methods like eat(), and then creating subclasses like Dog and Cat that inherit these attributes and methods, but also have their unique methods. |

### Polymorfism

#### Small Summary of Polymorfism

| Criteria | Description |
|------|------|
| Definition | Polymorphism enables objects to be treated as instances of their parent class, allowing the same method to behave differently based on the object calling it. |
| Purpose | To allow flexibility and extendability by enabling methods to do different things based on the context. |
| Types | Polymorphism can be compile-time (method overloading) or runtime (method overriding). |
| Example | In C++, a base class Shape may have a method draw(), and subclasses like Circle and Square can override this method to provide their specific implementations. When called on a Shape reference, the appropriate draw() method is executed based on the object type. |

## CLASS vs. STRUCT

- Both are used to define user-defined data structures.
- Similar, but differ in terms of access modifiers and intended usage

### Default Access Modifiers

**Class** - members are *private* by default.
**Struct** - members are *public* by default.

### Intended Usage

**Class** - Generaly used to define more complex data types and behaviours *(Encapsulation is a primary focus and data protection)*
**Struct** - Intended for sipler data structures that hold data without complex behaviour. *Structs can also include methods, inhertance*.

### Inheritance Comparison

**Class** - Derived classes are private by default
**Struct** - Are inherited publicly

### Memory Layout and Performance

There is no difference

### Usage in C++ Best Practices

**Class** - When encapsulation is needed, complex logic, and protection of internal data
**Struct** - For plain data structures

## Function Overloading

**Function Overloading** is a feature in C++ that allows to define functions with the same name, but with different parameter list

### Key Points of Function Overloading

1. Different Parameter Types or Number of Paramenters
2. Purpose of Function Overloading
   - To improve code readability and maintainability
   - To allow a single function to handle differnt type of input
3. How it works
   - During the compilation, the compiler determines which version of function to be called

### Example of code

```cpp
#include <iostream>
using namespace std;

// Overloaded functions with different parameter types
void print(int value) {
    cout << "Integer: " << value << endl;
}

void print(double value) {
    cout << "Double: " << value << endl;
}

void print(string value) {
    cout << "String: " << value << endl;
}

// Overloaded functions with a different number of parameters
void display(int value) {
    cout << "Single integer: " << value << endl;
}

void display(int value1, int value2) {
    cout << "Two integers: " << value1 << " and " << value2 << endl;
}

int main() {
    print(10);             // Calls print(int)
    print(10.5);           // Calls print(double)
    print("Hello World");  // Calls print(string)

    display(5);            // Calls display(int)
    display(5, 10);        // Calls display(int, int)

    return 0;
}

```

## Function Overriding

- This is a concept of polymophism that occurs when a derived class defines a function with the same name, return type and arguments as a function in the base class.

### **Key Points**
  
1. Inheritance: Function overrideing happens between derived classes and base classes
2. Virtual Functions: The base class function should be marked as virtual to enable overriding
3. Same Signature: The function should have the same name, return type and arguments as in the base class
4. Overriding Keyword(C++11): It's recommended to use ```override``` keyword in the derived class to indicate that this function is meant to be override a virtual function

### Example Code

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() const {  // Virtual function
        cout << "Display from Base class\n";
    }
};

class Derived : public Base {
public:
    void display() const override {  // Overridden function
        cout << "Display from Derived class\n";
    }
};

int main() {
    Base* basePtr = new Derived();
    basePtr->display();  // Calls Derived class's display()
    
    delete basePtr;
    return 0;
}
```

- Virtual Keyword ensure that the function is overridden

## INHERITANCE

### Basic concepts

- **Base Class** - The class being inherited from.
- **Derived Class** - The class that inherites from base class.
- **Syntax**
  
```cpp
class Derived: access_specifier Base {
    //members
};
```

### Types of Inheritance

| Type | Description |
|-|-|
| **Single Inheritance** | A derived class inherits from only one base class |
| **Multiple Inheritance** | A derived class inherits from more than one base class|
| **Multilevel Inheritance** | A chain of inheritance where a derived class inherits from another derived class |
| **Hierarchical Inherintance** | Multiple classes inherit from the same base class |
| **Hybrid Inheritance** | A mix of two or more of the above types |

### Access Specifiers in Inheritance

| Access Specifier in Derived Class | Public Members in Base | Protected Members in Base | Private Members in Base |
|-|-|-|-|
| Public Inheritance | Public | Protected | Not Accessible |
| Protected Inheritance | Protected | Protected | Not Accessible |
| Private Inheritance | Private| Private | Not Accessible |

### Constructors and Destructors in Inheritance

- The base class constructor is called first, then the derived class constructor
- When destructing, the derived class destructor is called first, followed by the base class destructor
- If the base class constructor requires parameters, they should be provided in the initialization list of the derived class constructor

```cpp
class Base {
public:
    Base(int val) { /*...*/ }
};

class Derived : public Base {
public:
    Derived(int val) : Base(val) { /*...*/ }
};
```

### Function Overriding in Inheritance

- Derived classes can redefine (override) base class member functions.
- To ensure the function in the base class is virtual, it is marked with the virtual keyword.
- Overridden functions in derived classes can use the override keyword for clarity and safety.

```cpp
class Base {
public:
    virtual void show() {
        std::cout << "Base show()" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived show()" << std::endl;
    }
};
```

### Virtual Inheritance

- Virtual inheritance prevents duplication of the base class when multiple inheritance is used.
- This is helpful when dealing with diamond inheritance (a derived class has two or more parent classes that share a common base class).

```cpp
class Base {
    // Common base class
};

class Derived1 : virtual public Base {
    // Inherits Base virtually
};

class Derived2 : virtual public Base {
    // Inherits Base virtually
};

class FinalDerived : public Derived1, public Derived2 {
    // No duplication of Base
};
```

### Accessing Base Class Members in Derived Class

- The ```Base::``` syntax allows accessing base class members from within the derived class when needed.
- This is helpful for resolving ambiguity in multiple inheritance or accessing overridden base functions.

### Best Practice

- Prefer public inheritance if the derived class is a true subtype of the base class ("is-a" relationship).
- Avoid multiple inheritance unless necessary. Use composition over inheritance if a "has-a" relationship is more suitable.
- Use virtual destructors in base classes when using inheritance to ensure proper cleanup.
- Clearly document any use of virtual inheritance to prevent confusion in complex class hierarchies.

## ABSTRACT CLASSES

- An **Abstract** class is designed to be used as a base class that cannot be instantiated on its own
- It provides blueprint for derived classes through *Pure Virtual Functions*.

### Characteristics of Abstract Classes

#### Constain Pure Virtual Functions

- Must have at least one pure virtual function

```cpp
class Abstract{
    public:
        virtual void func() = 0;
        // is virtual
        // is assigned =0
};
```

- Cannot be instantiated

### Defining and Using Abstract Classes

```cpp
#include <iostream>
using namespace std;

class Shape {                    // Abstract class
public:
    virtual void draw() = 0;     // Pure virtual function
    virtual double area() = 0;   // Pure virtual function
};

class Circle : public Shape {    // Concrete class
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    void draw() override {
        cout << "Drawing a Circle" << endl;
    }

    double area() override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape { // Concrete class
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void draw() override {
        cout << "Drawing a Rectangle" << endl;
    }

    double area() override {
        return width * height;
    }
};

int main() {
    Shape* shapes[] = {new Circle(5), new Rectangle(4, 6)};

    for (Shape* shape : shapes) {
        shape->draw();
        cout << "Area: " << shape->area() << endl;
    }

    for (Shape* shape : shapes) {
        delete shape;
    }
    return 0;
}
```

### Benefits of Abstract Classes

- Enforces a Contract - Derived classes must implement specific functions
- Enables Polymorfism - Abstract classes allow for dynamic polymorphism, where the derived class's behavior can be accessed through base class pointers
- Design Flexibility - Abstract classes help model real-world entities by defining an interface without specifying all details, which can then be customized by subclasses.

### Abstract Classes vs. Interfaces

In C++, There's no separate concept of an "interface" as in other languages. Abstract classes with only pure virtual functions can act like interfaces, but C++ allows allows abstract classes to constain non-pure virtual functions and even data members, offering more flexibility

## Virtual DESTRUCTOR

- A virtual Destructor is essential when dealing with inheritance, particularly when deleting derived class objects through a base class pointer. Without a virtual destructor, only the base class destructor would be called, potentially, leading to resource leaks or undefined behaviour
- Virtual Destrcutor ensures that derived class's destructor is called before the base class one, enabling proper clean-up

### WITHOUT VIRTUAL DESCTRUCTOR

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    ~Base() {          // Non-virtual destructor
        cout << "Base destructor called" << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {       // Destructor for derived class
        cout << "Derived destructor called" << endl;
    }
};

int main() {
    Base* ptr = new Derived(); // Base pointer to Derived object
    delete ptr;                // Only calls Base destructor!
    return 0;
}
// Output: Base destructor called
```

### WITH VIRTUAL DESCTRUCTOR \(SOLUTION)

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {         // Virtual destructor
        cout << "Base destructor called" << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {              // Destructor for derived class
        cout << "Derived destructor called" << endl;
    }
};

int main() {
    Base* ptr = new Derived(); // Base pointer to Derived object
    delete ptr;                // Calls Derived destructor, then Base destructor
    return 0;
}
// Output:
// Derived destructor called
// Base destructor called
```

### Key Points

1. **Base Class Destructor Should be Virtual** - If a class is meant to be used as a base class it should always be made virtual
2. **Order of Destruction** - When deleting an object, the destructor of the derived class, followed by the base class one
3. **Performance Overhead** - Slight performance overhead due to virtual function table, but is negligible copared to the issues that it avoids
4. **Automatic in Derived Classes** - When the base class destructor is virtual, the destructor of all derived classes are automatically virtual

### When not to use VIRTUAL DESTRUCTOR

- If a class is not intended to be used as a base class

## POLYMORFISM

- One of the Core Concepts of OOP
- It allows objects of different classes to be treated as objects of a common base class, enabling a single interface to represent different underlying forms.
- It enhaces flexibility and maintainability in code
- It allows the same function or method to behave differently based on the object it is acting upon
- Polymorphism enables:
  1. Function Overloading
  2. Operator Overloading
  3. Virtual Functions

### Types of Polymorfism

1. Compile-time Polymorphism \(Static Polymorphism)
2. Run-time Polymorphism \(Dynamic Polymorphism)

#### Compile-time Polymorphism

##### I. Function Overloading

- Has it's own topic

##### II. Operator Overloading

- Has it's own topic

##### III. Template Metaprogramming

#### Run-Time Polymorfism

##### Virtual Functions

- Virtual Functions enable derived classes to provide specific implementations of functions defined in the base class. This facilitates dynamic binding, where the call to a function is resolved at runtime based on the object's actual type.

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() { // Virtual function
        cout << "Base class show function called." << endl;
    }

    virtual ~Base() {} // Virtual destructor
};

class Derived : public Base {
public:
    void show() override { // Override keyword for clarity
        cout << "Derived class show function called." << endl;
    }
};

int main() {
    Base* ptr;
    Derived obj;
    ptr = &obj;

    ptr->show(); // Calls Derived::show() due to virtual function
    return 0;
}
// Output: Derived class show function called
```

###### Key Points for this

- Declared using the ```virtual``` keyword in the base class.
- The ```override``` keyword in the derived class ensures that the function is indeed overriding a base class virtual function.
- Facilitates polymorphic behavior, allowing the correct function to be called based on the object's actual type.

### Benefits of PolyMorphism

1. **Flexibility and Extensibility**
   - New classes can be introduced with minimal changes
   - Faciliates adding new functionalities without modifying exiting systems
2. **Code Reusability**
3. **Maintainability**
4. **Runtime decision making**
   - Decisions about what function to execute are made at runtime

### Common Uses of Polymorphism

1. **Graphical User Interface** - Widget like buttons, sliders
2. **Game Development** - Different game objects(players, enemies, NPCs)
3. **File Handling** - Different file types inherit from a base and imlement specific read/write functions
4. **Design Patterns**
   - *Strategy Pattern* - Encapsulates algorithms
   - *Factory Pattern* - Creates objects without specifing the exact class

### Best Practices with Polymorphism

1. Use Virtual Destructors
2. Prefer ```override``` keyword in derived classes to prevent accidental mismatches
3. Limit the use of Multiple Inheritance
4. Avoid object Slicing - When passing objects by value, ensure that only the base part is copied to prevent losing derived class information
5. Leverage Smart Pointers
6. Understand VTables
7. Minimize Runtime Overhead

## Polymorfism and Inheritance

- Polymorphism allows a derived class to be treated as a base class, typically by using pointers or references.
- It enables runtime method binding (dynamic polymorphism) via virtual functions.

### Polymorfism vs Inheritance

- *Inheritance* is a mechanism for creating a new class from an existing class, establishing a relationship where the derived class inherits attributes and behaviors from the base class.
- *Polymorphism* allows objects of different classes related by inheritance to be treated uniformly, typically by invoking overridden functions through base class pointers or references.

```cpp
Base* basePtr = new Derived();
basePtr->show(); // Calls Derived::show() due to polymorphism
```

## ENCAPSULATION

- Fundamental concept in OOP
- It involves bundling data and methods that operate on that data into a single unit, known as class
- Ensures that the internal state of an object is hidden from the outside world

### Access Modifiers

- **Private** - members accesible only in the class itself
- **Protected** - members are accessible in the class itself and in the derived classes
- **Public** - members are accessible anywhere in the program

### Benefits of Encapsulation

- **Data Security** - Prevents from accessing sensitive data
- **Modularity and Maintainability** - changes inside the class don't require changes outside the class
- **Code Reusability**
- **Data Integrity**

## ABSTRACTION

- Concept of OOP
- Focuses on exposing only the essential features of an object while hiding the underlying details

### How it works in C++

1. **Using Abstract Classes** - Abstract classes define a structure for classes that share common features. They may include pure virtual functions, which are methods that have no implementation in the base class and must be overridden in derived classes.
2. **Using Interfaces** - An interface in C++ is a class that consists only of pure virtual functions. By defining interfaces, classes ensure they follow a specific behavior without exposing implementation details.

### Features of Abstraction

- **Hides Complexity**
- **Defines a Contract**
- **Supports Polymorphism**

### REAL-WORLD ANALOGY

- Think of a TV remote as an abstraction. The remote provides a simple interface (e.g., power button, volume control, channel selection) that allows you to operate the TV without knowing the complex circuitry and programming inside the TV itself. Similarly, abstraction in C++ allows you to interact with an object without needing to understand its internal workings.

## Constructor and Destructor

| Feature | Constructor | Destructor |
|-|-|-|
| Purpose | Initializes an object | Cleans up resources when object is destroyed |
| Name | Same as class | Same as class, prefixed with ~ |
| Return Type | None | None |
| Parameters | Can have parameters | Cannot have parameters |
| Overloading | Can be overloaded | Cannot be overloaded |
| Automatic Call | When object is created | When object goes out of scope or is deleted |

### Characteristics of Constructor

1. **Same name as Class**
2. **No return type**
3. **Automatic Call**
4. **Overloadable**
5. **Default Constructor** - if no constructor is defined, there is a default constructor

### Characteristics of Destructor

1. **Same name as Class with a Tilde ~**
2. **No return type**
3. **No Arguments**
4. **Automatic Call**
5. **One destructor per Class**

## COPY CONSTRUCTOR

- This is a special constructor that creates a new object as a copy of an existing object
- It is invloved in the following cases
  1. When an object is initialized with another object of the same type
  2. When an object is passed by value to a function
  3. When an object is returned by value from a function
- Its purpose is to create a copy of an existing object with the same values

### Syntax of Copy constructor

```cpp
Classname(const Classname &obj);
```

- It takes a reference to an object
- It is defined in a way that avoids recursive calls by taking the parameter as a reference

### Example

```cpp
#include <iostream>
using namespace std;

class Array {
private:
    int* data;
    int size;

public:
    // Parameterized Constructor
    Array(int s) : size(s) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = i + 1;  // Initialize array with values
        }
        cout << "Parameterized Constructor called for Array of size " << size << endl;
    }

    // Copy Constructor for deep copy
    Array(const Array &other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        cout << "Copy Constructor called" << endl;
    }

    // Destructor
    ~Array() {
        delete[] data;  // Free allocated memory
        cout << "Destructor called for Array of size " << size << endl;
    }

    // Display Array Elements
    void display() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array arr1(5);      // Calls parameterized constructor
    Array arr2 = arr1;  // Calls copy constructor

    cout << "Contents of arr1: ";
    arr1.display();

    cout << "Contents of arr2 (copy of arr1): ";
    arr2.display();

    return 0;
}
// Parameterized Constructor called for Array of size 5
// Copy Constructor called
// Contents of arr1: 1 2 3 4 5 
// Contents of arr2 (copy of arr1): 1 2 3 4 5 
// Destructor called for Array of size 5
// Destructor called for Array of size 5
```

### Why use COPY CONSTRUCTOR?

- To avoid **shallow copy**

1. *Shallow Copy* - Copies the pointer directly
2. *Deep Copy* - Allocates separate memory for each object

### When is Copy Constructor Called?

1. **Initialization** - ```Classname obj2 = obj1;``` or ```Classname obj2(obj1);```
2. **Function calls by value** - When an object is passed to a function by value
3. **Return by Value** - When a function returns an object by value

### Summary for Copy Constructor

| Feature | Shallow Copy | Deep Copy |
|-|-|-|
| Memory Allocation | Copies the pointer | Allocates separate memory |
| Behavior | Multiple objects share memory | Each object has its own memory |
| Safety | May cause errors and crashes | Prevents memory-related issues |
| Use Case | For simple data members | For dynamically allocated resources |

## ASSIGNMENT OPERATOR

- is also known as the copy assignment operator
- it overloads the ```=``` operator
- It is used to copy data from one object to an already existing object of the same class

### Syntax of Assignment Operator

```cpp
Classname& operator=(const Classname &other);
```

### Example of Assignment Operator

```cpp
#include <iostream>
using namespace std;

class Array {
private:
    int* data;
    int size;

public:
    // Parameterized Constructor
    Array(int s) : size(s) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = i + 1;
        }
        cout << "Parameterized Constructor called for Array of size " << size << endl;
    }

    // Copy Constructor for deep copy
    Array(const Array &other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        cout << "Copy Constructor called" << endl;
    }

    // Assignment Operator for deep copy
    Array& operator=(const Array &other) {
        cout << "Assignment Operator called" << endl;

        // Self-assignment check
        if (this == &other) {
            return *this;  // Return current object if assigned to itself
        }

        // Release existing resources
        delete[] data;

        // Copy data from the source object
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }

        return *this;
    }

    // Destructor
    ~Array() {
        delete[] data;
        cout << "Destructor called for Array of size " << size << endl;
    }

    // Display Array Elements
    void display() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array arr1(5);          // Calls parameterized constructor
    Array arr2 = arr1;      // Calls copy constructor
    Array arr3(3);          // Calls parameterized constructor

    arr3 = arr1;            // Calls assignment operator

    cout << "Contents of arr1: ";
    arr1.display();
    cout << "Contents of arr2 (copy of arr1): ";
    arr2.display();
    cout << "Contents of arr3 (after assignment from arr1): ";
    arr3.display();

    return 0;
}
// OUTPUT:
// Parameterized Constructor called for Array of size 5
// Copy Constructor called
// Parameterized Constructor called for Array of size 3
// Assignment Operator called
// Contents of arr1: 1 2 3 4 5 
// Contents of arr2 (copy of arr1): 1 2 3 4 5 
// Contents of arr3 (after assignment from arr1): 1 2 3 4 5 
// Destructor called for Array of size 5
// Destructor called for Array of size 5
// Destructor called for Array of size 5
```

### Comparison of Copy Constructor vs. Assignment Operator

| Feature | Copy Constructor | Assignment Operator |
|-|-|-|
| Purpose | Initializes a new object as a copy of an existing object| Copies data from one existing object to another existing object |
| When Called | When a new object is created from an existing object, e.g., ClassName obj2 = obj1; | When an existing object is assigned to another existing object, e.g., obj2 = obj1; |
| Self-Assignment Check | Not needed | Needed to avoid copying an object onto itself |
| Default Behavior | Shallow copy (if not defined explicitly) | Shallow copy (if not defined explicitly) |
| Resource Management | Allocates new resources for the copied object | Releases existing resources before copying new ones |

### Use Cases of Assignment Operator and Copy Constructor

- Use the *copy constructor* when you need to create a new object based on an existing object.
- Use the *assignment operator* when you want to copy the data from one object to another **already existing** object.

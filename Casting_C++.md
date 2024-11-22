# Casting in C++

- This is the process of converting a variable from one type to another. C++ provides several casting operators to handle different situations.

## C-Style Casting

- This is the traditional way of casting in C and is also supported in C++. It is simple but less safe and can be difficult to read.

```cpp
int a = 10;
double b = (double)a;
```

## Comparison Problem

```cpp
int signedVal = -5;
unsigned int unsignedVal = 3;

if (signedVal < unsignedVal) {
    std::cout << "Signed value is less than unsigned value";
} else {
    std::cout << "Signed value is not less than unsigned value";
}
```

### How to solve the type casting problem

- Using the ```-Wall``` flag when compiling to see the problem
- Using utilities ```std::cmp*```

    1. ```std::cmp_equal```
    2. ```std::cmp_not_equal```
    3. ```std::cmp_less```
    4. ```std::cmp_greater```
    5. ```std::cmp_less_equal```
    6. ```std::cmp_greater_equal```

    ```cpp
    #include <iostream>
    #include <utility> // For std::cmp_less

    int main() {
        int signedVal = -5;
        unsigned int unsignedVal = 3;

        if (std::cmp_less(signedVal, unsignedVal)) {
            std::cout << "signedVal is less than unsignedVal";
        } else {
            std::cout << "signedVal is not less than unsignedVal";
        }

        return 0;
    }
    ```

- It has to be the ```-std=c++20``` standard

## Static Cast and Dynamic Cast

### ```static_cast```

- Performs compile-time type checking and is used for safe and explicit type conversions.

1. Used for **basic type conversions**, such as between numeric types (*int* to *float*)
2. Can cast between related pointer or reference types in class hierarchy
3. No runtime type checking occurs; you are responsible for ensuring the cast is safe.

#### Syntax of static cast

```cpp
static_cast<newtype>(expression)
```

```cpp
int a = 10;
float b = static_cast<float>(a);
```

#### Class Example of Static Cast

```cpp
class Base {};
class Derived : public Base {};

Base * basePtr = new Derived();
Derived * derivedPtr = static_cast<Derived*>(basePtr);
//Downcast (You must ensure this is valid)
```

#### Invalid usage of Static Cast

```cpp
class Base {};
class Unrelated {};

Base * basePtr = new Base();
Unrelated * unrelatedPtr = static_cast<Unrelated*>(basePtr);
//Compiles but is unsafe
```

### ```dynamic_cast```

- Is used for safe conversions within a class hierarchy, and it performs **runtime type checking**.

1. Used only with pointers or references to polymorphic types (i.e., types with at least one ```virtual``` function).
2. If the cast fails:

    - For pointers, it returns ```nullptr```.
    - For references, it throws a ```std::bad_cast``` exception.

3. Ensures the object being cast is of the correct type or derived from it.

#### Syntax

```cpp
dynamic_cast<new_type>(expression)
```

#### Safe Downcasting of Dynamic

```cpp
#include <iostream>
#include <typeinfo>

class Base {
    virtual void func() {} // Polymorphic base class
};

class Derived : public Base {};

int main() {
    Base* basePtr = new Derived();

    // Perform a safe downcast
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        std::cout << "Downcast successful!";
    } else {
        std::cout << "Downcast failed!";
    }

    return 0;
}
```

#### Failing Cast of Dynamic

```cpp
class Base {
    virtual void func() {} // Polymorphic base class
};

class Derived : public Base {};
class Unrelated : public Base {};

Base* basePtr = new Unrelated();

// Attempt a downcast to Derived
Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
if (derivedPtr == nullptr) {
    std::cout << "Downcast failed, basePtr is not of type Derived.";
}
```

### Comparison of static and dynamic casting

| Feature | ```static_cast``` | ```dynamic_cast``` |
|-|-|-|
| Type Checking | Compile_time only | Runtime type checking |
| Safety | No guarantee of Safety; must be used correctly | Ensures safety in class hierarchies |
| Usage Scope | General-Purpose casting (basic-types, pointers, references) | limited to polymorfic class hierarchies |
| Failure Handling | Can lead to undefined behavior | Returns ```nullptr``` or throws ```std::bad_cast``` |
| Performance | Faster (no runtime overhead) | Slower (runtime checks performed) |

### When to use static and dynamic

- ```static_cast```
  
    1. The types are closely related, and you are confident the cast is valid.
    2. You need basic conversions, like between numeric types or upcasting in a hierarchy

- ```dynamic_cast```

    1. You need to safely downcast in a polymorfic class hierarchy
    2. Type checking is crytical to avoid undefined behavior

## ```reinterpret_cast```

- ```reinterpret_cast``` is one of the casting operators in C++, used for low-level type conversions. Unlike ```static_cast``` and ```dynamic_cast```, it is designed for conversions that reinterpret the bitwise representation of an object.

1. Used for conversion between
    - Pointer Types
    - Pointer and Integral Types

2. Does perform type safety checks
3. Typically used for
    - Hardware Interfacing
    - Serealization and Deserialization
    - Specialized Low_level programming tasks

### Use Cases of Reinterpret Cast

#### Casting between Unrelated Pointer types

```cpp
#include <iostream>

struct A {
    int x;
};

struct B {
    float y;
};

int main() {
    A a{42};
    B* b = reinterpret_cast<B*>(&a);

    std::cout << "Reinterpreted value: " << b->y << "\n"; // Output may be garbage
    return 0;
}
```

#### Casting between Pointer and Integral Types

```cpp
#include <iostream>

int main() {
    int x = 42;
    void* ptr = &x; // Void pointer to the integer

    // Reinterpret pointer as an integer
    uintptr_t address = reinterpret_cast<uintptr_t>(ptr);
    std::cout << "Address as integer: " << address << "\n";

    // Reinterpret integer back as pointer
    int* intPtr = reinterpret_cast<int*>(address);
    std::cout << "Value: " << *intPtr << "\n";

    return 0;
}
```

#### Casting between Function Pointers

```cpp
#include <iostream>

void myFunction(int x) {
    std::cout << "Value: " << x << "\n";
}

int main() {
    void (*voidFunc)() = reinterpret_cast<void (*)()>(myFunction);
    reinterpret_cast<void (*)(int)>(voidFunc)(42); // Cast back to the correct signature

    return 0;
}
```

#### Reinterpreting Data

```cpp
#include <iostream>

int main() {
    uint32_t data = 0x41424344; // Represents 'ABCD' in ASCII
    char* chars = reinterpret_cast<char*>(&data);

    std::cout << "Reinterpreted data: ";
    for (int i = 0; i < sizeof(data); ++i) {
        std::cout << chars[i]; // Outputs: ABCD
    }
    std::cout << "\n";

    return 0;
}
```

### Pitfalls of Reinterpret

1. **No Safety** - It does not check if the cast is valid or meaningful.
    - Example: Casting between completely unrelated types may produce garbage data.
2. **Undefined Behavior** - Dereferencing a pointer after a bad cast often leads to undefined behavior.
3. **Platform Dependence** - The results of reinterpreting data may vary across platforms or compilers.

### When to use

1. Low_level Programming
2. Interfacing with APIs
3. Serialization/Deserialization

- Avoid ```reinterpret_cast``` unless you have a strong understanding of the underlying memory layout and behavior of your program. If safety is important, consider alternative approaches like ```std::bit_cast``` (introduced in C++20).

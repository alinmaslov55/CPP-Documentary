# Basics 2

- this is part 2

## SMART POINTERS

### ```std::unique_ptr```

#### Key Features

1. Exclusive ownership - Only one ```std::unique_ptr``` can own a given resource
2. Automatic Resource Management - Automatically deallocates when it goes out of scope
3. No Copying - It can not be copied in order to ensure exclusive ownership
4. Move Semantics - Ownership can be transferred to another ```std::unique_ptr``` via ```std::move```

#### Syntax

- To use the ```std::unique_ptr```, you must include the following header file ```<memory>```
- It can be created via ```std::make_unique<type>```, which provide exception-safe memory allocation

```cpp
std::unique_ptr<int> ptr = std::make_unique<int>(10);
```

- It can be initialized manually

```cpp
std::unique_ptr<int> ptr(new int(10));
//Not recommended, as std::make_unique is safer
```

#### Accessing

- Can be accessed just as other pointers with ```*```

#### Transfer of ownership

```cpp
std::unique_ptr<int> ptr1 = std::make_unique<int>(10);
// std::unique_ptr<int> ptr2 = ptr1; // Error: cannot copy unique_ptr

std::unique_ptr<int> ptr2 = std::move(ptr1); // ptr1 is now null
if (!ptr1) {
    std::cout << "ptr1 is null after move." << std::endl; // it becomes nullptr
}
```

#### Releasing and Reseting

- **Release**: ```release()``` transfers ownership of the managed object to the caller and leaves the unique_ptr empty ```(nullptr)```. It’s useful if you need to pass the raw pointer to a function that takes ownership.

```cpp
std::unique_ptr<int> ptr = std::make_unique<int>(10);
int* rawPtr = ptr.release(); // ptr is now null, and you own rawPtr
delete rawPtr;                // Manually delete to avoid a memory leak
```

- **Reset**: ```reset()``` destroys the managed object, replacing it with a new object or setting it to ```nullptr```.

```cpp
std::unique_ptr<int> ptr = std::make_unique<int>(10);
ptr.reset(new int(20)); // Resets with a new int; deletes the previous int
ptr.reset();            // Deletes the managed object and makes ptr null
```

#### Using with arrays

- ```std::unique_ptr``` also supports arrays, but you need to specify the array type explicitly:

```cpp
std::unique_ptr<int[]> arrayPtr = std::make_unique<int[]>(5);
arrayPtr[0] = 10;
std::cout << "First element: " << arrayPtr[0] << std::endl;
```

#### Custom Deleters

- ```std::unique_ptr``` allows specifying a custom deleter function if you need special cleanup behavior. This is especially useful for managing resources other than raw memory (like file handles or database connections):

```cpp
struct FileCloser {
    void operator()(FILE* file) const {
        if (file) fclose(file);
    }
};

std::unique_ptr<FILE, FileCloser> filePtr(fopen("example.txt", "r"));
// custom deleter invoked when filePtr goes out of scope
```

#### Example of code with ```std::unique_ptr```

```cpp
#include <iostream>
#include <memory>

void uniquePtrExamples() {
    // Basic usage of unique_ptr
    std::unique_ptr<int> ptr = std::make_unique<int>(42);
    std::cout << "Unique pointer value: " << *ptr << std::endl;

    // Move semantics - transferring ownership
    std::unique_ptr<int> ptr2 = std::move(ptr);
    if (!ptr) {
        std::cout << "ptr is now null after move." << std::endl;
    }

    // Resetting unique_ptr
    ptr2.reset(new int(88));
    std::cout << "After reset, ptr2 value: " << *ptr2 << std::endl;

    // Using unique_ptr with arrays
    std::unique_ptr<int[]> arrPtr = std::make_unique<int[]>(3);
    arrPtr[0] = 1;
    arrPtr[1] = 2;
    arrPtr[2] = 3;
    std::cout << "Array values: " << arrPtr[0] << ", " << arrPtr[1] << ", " << arrPtr[2] << std::endl;

    // Custom deleter example
    struct FileDeleter {
        void operator()(FILE* file) const {
            if (file) fclose(file);
        }
    };

    std::unique_ptr<FILE, FileDeleter> filePtr(fopen("example.txt", "w"));
    if (filePtr) {
        std::cout << "File opened successfully." << std::endl;
    }
}

int main() {
    uniquePtrExamples();
    return 0;
}
```

### ```std::shared_ptr```

#### Key feature of ```std::shared_ptr```

1. **Shared Ownership** - Multiple ```shared_ptr``` instances can share ownership of the same resource.
2. **Automatic Reference Counting** - Tracks how many ```shared_ptr```s point to the resource, deleting it only when the count reaches zero.
3. **Thread-Safe Reference Counting** - Reference counting operations are thread-safe, making ```shared_ptr``` safe for multithreaded environments.
4. **Copyable and Movable** - Unlike std::unique_ptr, shared_ptr supports both copy and move semantics.

#### Syntax of shared_ptr

- Creating
  
```cpp
std::shared_ptr<int> ptr = std::make_shared<int>(10);
```

- Creating Manually

```cpp
std::shared_ptr<int> ptr(new int(10)); // Works, but make_shared is preferred
```

#### Reference Counting and Sharing Ownership

```cpp
std::shared_ptr<int> ptr1 = std::make_shared<int>(10);
std::shared_ptr<int> ptr2 = ptr1; // ptr1 and ptr2 now share the same resource

std::cout << "Reference count: " << ptr1.use_count() << std::endl; // Output: 2
// When shared_ptr goes out of scope or is destroyed the refernece count goes down
```

#### Reseting Shared_Ptr

```cpp
ptr1.reset(); // Decreases the reference count of the managed resource
std::cout << "Reference count after reset: " << ptr2.use_count() << std::endl; // Output: 1
```

```cpp
ptr2.reset(new int(20)); // The original resource (10) is deleted, and ptr2 now manages 20
```

#### Avoiding Cyclic References

- A common problem with ```std::shared_ptr``` is cyclic references. This occurs when two or more ```shared_ptr```s reference each other, creating a cycle that prevents the reference count from reaching zero. For example, if **A** holds a shared_ptr to **B**, and **B** holds a shared_ptr back to **A**, neither will be destroyed even if no other parts of the code reference them.

To avoid this, you can use ```std::weak_ptr```, which provides a non-owning reference that doesn’t increase the reference count. More on ```weak_ptr``` below.

#### Using Shared_ptr with Arrays

- While ```unique_ptr``` has explicit support for arrays, shared does not
- They can be managed by specifying a custom deleter

```cpp
std::shared_ptr<int> arrPtr(new int[5], std::default_delete<int[]>());
arrPtr.get()[0] = 10;  // Access the array as usual
std::cout << "First element: " << arrPtr.get()[0] << std::endl;
```

- ```std::default_delete<int[]>``` tells shared_ptr to delete the array when reference count reaches zero

#### Custom deleters

```cpp
struct FileDeleter {
    void operator()(FILE* file) const {
        if (file) fclose(file);
    }
};

std::shared_ptr<FILE> filePtr(fopen("example.txt", "r"), FileDeleter());
```

#### Example of Program

```cpp
#include <iostream>
#include <memory>

void sharedPtrExamples() {
    // Basic usage of shared_ptr
    std::shared_ptr<int> ptr1 = std::make_shared<int>(42);
    std::cout << "Shared pointer value: " << *ptr1 << std::endl;

    // Copying shared_ptr - reference count increases
    std::shared_ptr<int> ptr2 = ptr1;
    std::cout << "Reference count after copy: " << ptr1.use_count() << std::endl; // Output: 2

    // Resetting one shared_ptr decreases reference count
    ptr1.reset();
    std::cout << "Reference count after ptr1 reset: " << ptr2.use_count() << std::endl; // Output: 1

    // Custom deleter example with shared_ptr
    struct FileDeleter {
        void operator()(FILE* file) const {
            if (file) fclose(file);
        }
    };
    
    std::shared_ptr<FILE> filePtr(fopen("example.txt", "w"), FileDeleter());
    if (filePtr) {
        std::cout << "File opened successfully." << std::endl;
    }
}

int main() {
    sharedPtrExamples();
    return 0;
}
```

### ```std::weak_ptr```

- ```std::weak_ptr``` is a smart pointer in C++ that provides a non-owning, weak reference to an object managed by ```std::shared_ptr```. Unlike shared_ptr, weak_ptr does not contribute to the reference count of the managed resource, making it useful for breaking cyclic dependencies that could otherwise prevent resources from being freed.

#### Key Features of ```std::weak_ptr```

- **Non-Ownership** - ```std::weak_ptr``` does not own the resource it references, so it doesn't increase the reference count.
- **Used with ```std::shared_ptr```** - ```weak_ptr``` can only be used with resources managed by shared_ptr.
- **No Automatic Deletion** - Since it doesn't own the resource, weak_ptr cannot trigger the deletion of the resource.
- **Breaking Cyclic References** - Useful for cases where two or more shared_ptrs refer to each other (like in a cyclic data structure), allowing resources to be freed when no other shared_ptr references them.

#### Syntax of ```std::weak_ptr```

- Creation

```cpp
std::shared_ptr<int> sharedPtr = std::make_shared<int>(10);
std::weak_ptr<int> weakPtr = sharedPtr; // weakPtr refers to the resource managed by sharedPtr
```

#### Checking if it is valid

```cpp
if (!weakPtr.expired()) {
    std::cout << "Resource is still alive." << std::endl;
} else {
    std::cout << "Resource has been deleted." << std::endl;
}
```

#### Accessing the resource with ```.lock()```

- To safely access the resource, use ```.lock()```, which returns a ```shared_ptr``` to the resource if it’s still available. If the resource has been deleted, ```.lock()``` returns an empty ```shared_ptr```:

```cpp
std::shared_ptr<int> lockedPtr = weakPtr.lock();
if (lockedPtr) {
    std::cout << "Accessed resource value: " << *lockedPtr << std::endl;
} else {
    std::cout << "Resource is no longer available." << std::endl;
}
```

#### Example of breaking Cyclic Dependencies

```cpp
#include <iostream>
#include <memory>

struct Node {
    int value;
    std::shared_ptr<Node> next;        // Shared ownership of next Node
    std::weak_ptr<Node> previous;      // Weak reference to prevent cyclic dependency

    Node(int val) : value(val) {
        std::cout << "Node created with value: " << value << std::endl;
    }
    ~Node() {
        std::cout << "Node with value " << value << " destroyed." << std::endl;
    }
};

int main() {
    // Create two nodes that reference each other
    std::shared_ptr<Node> node1 = std::make_shared<Node>(1);
    std::shared_ptr<Node> node2 = std::make_shared<Node>(2);

    node1->next = node2;               // node1 owns node2
    node2->previous = node1;           // node2 holds a weak reference to node1

    return 0; // When main exits, both nodes will be properly deleted
}
```

#### Example with ```std::weak_ptr```

```cpp
#include <iostream>
#include <memory>

void demonstrateWeakPtr() {
    std::shared_ptr<int> sharedPtr = std::make_shared<int>(100);
    std::weak_ptr<int> weakPtr = sharedPtr;

    // Check if weak pointer is valid
    if (auto lockedPtr = weakPtr.lock()) { // locks to shared_ptr if resource is available
        std::cout << "Locked weak pointer value: " << *lockedPtr << std::endl;
    } else {
        std::cout << "Resource is no longer available." << std::endl;
    }

    sharedPtr.reset(); // Releases the resource

    // Now weakPtr should be expired
    if (weakPtr.expired()) {
        std::cout << "Resource has been deleted after sharedPtr reset." << std::endl;
    }
}

int main() {
    demonstrateWeakPtr();
    return 0;
}
```

## ```Mutable``` keyword

- This is a keyword that overrides ```const``` keyword
- The mutable keyword in C++ allows modification of a variable captured by value in a lambda function or a non-static data member of a const object. It essentially bypasses the constness of the variable for specific purposes.

### Using ```mutable``` in lambda functions

- By default, lambdas that capture variables by value make them read-only. The mutable keyword allows you to modify these captured variables.

```cpp
[capture_list](parameters) mutable -> return_type {
    // Function body
};
```

```cpp
#include <iostream>

int main() {
    int x = 10;

    auto modifyValue = [x]() mutable {
        x += 5;
        std::cout << "Modified x inside lambda: " << x << std::endl;
    };

    modifyValue(); // Prints: Modified x inside lambda: 15
    std::cout << "Original x outside lambda: " << x << std::endl; // Prints: 10

    return 0;
}
```

- ```x``` is captured by value, so the original variable ```x``` outside the lambda remains unchanged
- ```mutable``` keyword allows modification of the captured copy of ```x```

### Using ```mutable``` with ```const``` member variables

- In a const object, all member functions treat data members as read-only. The mutable keyword allows specific member variables to bypass this restriction and remain modifiable.

```cpp
#include <iostream>

class Counter {
    mutable int count; // Can be modified even in const functions
public:
    Counter() : count(0) {}

    void increment() const {
        ++count; // Allowed because 'count' is mutable
    }

    int getCount() const {
        return count;
    }
};

int main() {
    const Counter counter; // const object
    counter.increment();   // Modifies the mutable member
    counter.increment();

    std::cout << "Counter: " << counter.getCount() << std::endl; // Prints: 2

    return 0;
}
```

### Key points of ```mutable```

1. In Lambdas
    - Enables modification of variables captured by value
    - Useful when you need temporary changes without affecting the original variable
2. In Classes
    - Allows specific data members to remain modifiable, even in ```const``` objects
    - Often used for caching, logging, or reference counters

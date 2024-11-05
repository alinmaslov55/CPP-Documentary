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

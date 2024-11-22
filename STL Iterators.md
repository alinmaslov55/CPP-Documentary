# STL Iterators

## Introduction to iterators

- They are objects that allow you to traverse the elements of a container (like ```std::vector```, ```std::list```)
- Act as bridge between containers and algorithms
- Generalization of a pointer

## Features of Iterators

1. Abstractions - Abstract the details of traversing a container
2. Generalized Access - They work with different types of containers
3. Consistency - Provide a interface across all STL containers

## Types of Iterators

- **Input Iterator** Read-only access, single-pass.
  - Reading a file or stream.
- **Output Iterator** Write-only access, single-pass.
  - Writing to a file or stream.
- **Forward Iterator** Read and write, multi-pass.
  - ```std::forward_list```.
- **Bidirectional Iterator** Move forward and backward.
  - ```std::list```, ```std::set```.
- **Random Access Iterator** Direct access to any element.
  - ```std::vector```, ```std::deque```.

## Operations

- Access: ```*it```, ```it->```
- Traversal: ```++it```, ```it++```, ```it--```, ```it + n```
- Comparison: ```it1 == it2```, ```it1 != it2```

## Example

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3};

    // Using const_iterator
    for (std::vector<int>::const_iterator it = numbers.cbegin(); it != numbers.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}
```

- ```end()``` - represnts a position past the last element
- iterators may be invalidated when container gets modified

## Range access with containers

- Example with custom container
  
```cpp
#include <iostream>
#include <vector>

struct CustomContainer {
    std::vector<int> data;

    auto begin() { return data.begin(); }
    auto end() { return data.end(); }
};

int main() {
    CustomContainer myContainer = {{10, 20, 30}};

    // Range-based for loop
    for (int value : myContainer) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    return 0;
}
```

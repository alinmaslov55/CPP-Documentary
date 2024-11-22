# STL

## ```std::source_location```

```cpp
#include <iostream>
#include <source_location>

void log_message(const std::source_location& location = std::source_location::current()) {
    std::cout << "File: " << location.file_name() << '\n'
              << "Function: " << location.function_name() << '\n'
              << "Line: " << location.line() << '\n'
              << "Column: " << location.column() << '\n';
}

int main() {
    log_message();  // This will log the current location
    return 0;
}
```

### Practical Use Case of ```std::source_location```

- ```std::source_location``` is particularly useful in logging and debugging libraries. For example, you could use it to automatically include the file and line number in your log messages without manually passing this information every time.

## ```std::string```, ```const char*```, ```char*```, string literals

### ```std::string```

- ```#include <string>```

#### Operations

- Accessing Characters

    ```cpp
    std::string str = "Hello";
    std::cout << str[0] << "\n";   // 'H'
    std::cout << str.at(1) << "\n"; // 'e'
    ```

- Concatenation

    ```cpp
    std::string first = "Hello, ";
    std::string second = "World!";
    std::string result = first + second; // "Hello, World!"
    first += "C++"; // "Hello, C++"
    ```

- Finding Substrings

    ```cpp
    std::string str = "This is a sample string";
    size_t pos = str.find("sample"); // Returns index of "sample"
    if (pos != std::string::npos) {
        std::cout << "Found at: " << pos << "\n";
    }
    ```

- Extracting Strings

    ```cpp
    std::string str = "Hello, World!";
    std::string sub = str.substr(7, 5); // "World"
    ```

- Modifying Strings

    ```cpp
    std::string str = "Hello, World!";
    str.insert(7, "beautiful "); // "Hello, beautiful World!"
    str.erase(7, 10);            // "Hello, World!"
    str.replace(7, 5, "C++");    // "Hello, C++!"
    ```

- Comparing Strings

    ```cpp
    std::string str1 = "abc";
    std::string str2 = "xyz";
    if (str1 < str2) {
        std::cout << "str1 is less than str2\n";
    }
    ```

- Iterating Strings

    ```cpp
    std::string str = "C++";
    for (char c : str) {
        std::cout << c << " ";
    }
    // Output: C + +
    ```

- Getting the length of a string

    ```cpp
    std::string str = "Hello";
    std::cout << str.size() << "\n"; // 5
    ```

- Clearing and Checking for Emptiness

    ```cpp
    std::string str = "Hello";
    str.clear(); // Empties the string
    if (str.empty()) {
        std::cout << "String is empty\n";
    }
    ```

### Other

- ```const char*``` - pointer to a null-terminated string
- ```char*``` - pointer to a null-terminated string that cna be modified in C-Style

## ```std::string_view```

- ```#include <string_view>```
- ```std::string_view``` is a lightweight, non-owning view of a string introduced in C++17. It provides a way to work with strings without owning or copying their data, making it efficient for scenarios where you need to pass or manipulate strings without modifying them.

### KeyPoints of ```std::string_view```

1. Non-owning
    - std::string_view does not manage the memory of the string it refers to. It merely "views" the existing data.
2. Lightweight:
    - It avoids the overhead of copying or allocating memory, unlike std::string.
3. Immutable
    - You cannot modify the string data through a std::string_view.
4. Compatible:
    - Works seamlessly with std::string, C-style strings (const char*), and string literals.

### When to use

- To pass read-only string-like to functions without copying them
- When working with substrings or slices of strings
- To avoid the overhead of constructing temporary ```std::string``` objects

### OPerations with ```std::string_view```

- Accessing Characters

```cpp
std::string_view sv = "Hello";
std::cout << sv[0];       // 'H'
std::cout << sv.at(1);    // 'e'
```

- Size and Length

```cpp
std::string_view sv = "Hello";
std::cout << sv.size();   // 5
std::cout << sv.length(); // 5
```

- Substring

```cpp
std::string_view sv = "Hello, World!";
std::string_view sub = sv.substr(7, 5); // "World"
```

- Remove Prefix and Suffix

```cpp
std::string_view sv = "  Hello, World!  ";
sv.remove_prefix(2);      // "Hello, World!  "
sv.remove_suffix(2);      // "Hello, World!"
```

- Comparison

```cpp
std::string_view sv1 = "Hello";
std::string_view sv2 = "World";
if (sv1 < sv2) {
    std::cout << "sv1 is less than sv2";
}
```

- Checking if empty

```cpp
std::string_view sv = "";
if (sv.empty()) {
    std::cout << "String view is empty";
}
```

### Comparison with ```std::string```

| Feature | ```std::string_view``` | ```std::string``` | ```const char*``` |
|-|-|-|-|
| Ownership | Non-owning | Owning | Non-owning |
| Dynamic Size | No | Yes | No |
| Memory Management | No | Automatic | Manual |
| Safety | Bounds-checked | Bounds-checked | no Bounds-checked |
| Efficiency | High(no-copies) | Moderate(copying) | High(no copies) |
| Mutability | Immutable | Mutable |Mutable(if ```char*```) |

## ```std::array```

- ```include <array>```
- Container class that represents a fixed-size sequence of elements

### Operations with ```std::array```

- Accessing elements

```cpp
std::array<int, 3> arr = {1, 2, 3};
std::cout << arr[0];          // Access without bounds checking
std::cout << arr.at(2);       // Access with bounds checking
// std::cout << arr.at(5);    // Throws std::out_of_range
// accessing elements at invalid index with .at throws "std::out_of_range"
```

- Size

```cpp
std::cout << arr.size(); // Output: 3
```

- Iterators
    1. ```begin()```, ```end()``` - to start and to end
    2. ```rbegin()```, ```rend()``` - reverse iterators

- Utilities
    1. ```array.empty()``` - true if empt, false if not
    2. ```array.fill(value)``` - Fills array with size
    3. ```array.swap(other)``` - Swaps the contents of two arrays of the same size and type

```cpp
std::array<int, 3> arr = {1, 2, 3};
arr.fill(0); // All elements set to 0
```

- Accessing Undelying Data
    1. ```array.data()``` - Return pointer to the underlynig array(C-Style APIs)

```cpp
int* rawArray = arr.data();
```

### Comparison of ```std::array``` and C-style arrays

| Feature | ```std::array``` | **C-Style Array** |
|-|-|-|
| Bounds Check | ```at()``` provides | no bound checking |
| Size Access | ```size()``` provides | tracked manually |
| STL | Compatible | Partial/Limited |
| Type-Safe | Safer | Less |
| Initialization | Explicit Initialization | Undefined Behaviour |

## ```std::span```

- ```#include <span>```
- ```std::span``` is a lightweight, non-owning view over a contiguous sequence of elements. Introduced in C++20, it allows you to operate on arrays, std::vectors, or raw pointers in a uniform, safe, and flexible way without taking ownership of the data.
- close to ```std::string_view```

### KeyPoint

1. Non_owning
2. Contiguous Storage - works with std::array, std::vector, rawPointers, string
3. Compile-Time or Run-Time Size
4. Bound Safe
5. Range Compatible

### Operations with ```std::span```

- Element Access

```cpp
std::span<int> sp(arr);
std::cout << sp[0];    // Access without checking
std::cout << sp.at(1); // Access with checking
```

- Size

```cpp
std::cout << sp.size();  // Prints the size of the span
std::cout << sp.empty(); // Prints true or false
```

- Iterators

```cpp
for (auto it = sp.begin(); it != sp.end(); ++it) {
    std::cout << *it << " ";
}
```

- Underlying Data

```cpp
int* ptr = sp.data();
```

### Advantages of ```std::span```

1. Avoid Copies
2. Uniform API
3. Improved Safety
4. Compatibility
5. Sub-Views

### When to use ```std::span```

- Need to pass array to functions without copying
- Uniform way to handle different data structures
- Need Bound-Aware and Type-Safe alternatives to raw Pointers
- Need to create slices or view of data

### Limitation of ```std::span```

```cpp
std::span<int> sp;
{
    int arr[] = {1, 2, 3};
    sp = std::span<int>(arr); // arr goes out of scope
}
// Accessing sp now is undefined behavior!
```

## ```std::vector```

### Operations with ```std::vector```

- Elements Accessing
    1. ```vec[index]``` - without bounds checking
    2. ```vec.at(index)``` - with bounds checking(throws ```std::out_of_range```)
    3. ```vec.front()``` and ```vec.back()``` - first and last elements

- Size and Capacity
    1. ```vec.size()``` - return the number of elements
    2. ```vec.capacity()``` - return the number of elements the vector can hold before reallocation
    3. ```vec.empty()`` - true if the vector is empty
    4. ```vec.resize(n)``` - resizes the vector to hold the given number of elements
- Modifiers
    1. ```vec.push_back(value)``` - adds the value to the end
    2. ```vec.pop_back()``` - removes the value from the end
    3. ```vec.insert(pos, value)``` - insert value at pos
    4. ```vec.erase(pos)``` - removes the element at pos
    5. ```vec.clear()``` - removes all elements
    6. ```vec.swap()``` - Swap content with other vector

### Big Code Example

```cpp
#include <vector>

// 1. Default constructor
std::vector<int> v1;

// 2. Initialize with size
std::vector<int> v2(5); // 5 default-initialized elements (0 for int)

// 3. Initialize with size and value
std::vector<int> v3(5, 10); // 5 elements with value 10

// 4. Initialize from another vector
std::vector<int> v4(v3); // Copy of v3

// 5. Initialize from initializer list
std::vector<int> v5 = {1, 2, 3, 4, 5};

// 6. Initialize from range
std::vector<int> v6(v5.begin() + 1, v5.end() - 1); // {2, 3, 4}


#include <iostream>
#include <vector>

std::vector<int> v = {10, 20, 30, 40};

// 1. Using operator[]
std::cout << v[0]; // 10

// 2. Using at() (with bounds checking)
std::cout << v.at(2); // 30

// 3. Access the first and last elements
std::cout << v.front(); // 10
std::cout << v.back();  // 40

// 4. Access raw pointer to data
int* ptr = v.data();
std::cout << ptr[1]; // 20


std::vector<int> v;

// 1. Add to the end
v.push_back(10); // {10}

// 2. Insert at a position
v.insert(v.begin(), 20); // {20, 10}

// 3. Insert multiple elements
v.insert(v.end(), 3, 5); // {20, 10, 5, 5, 5}

// 4. Insert a range
std::vector<int> toInsert = {30, 40};
v.insert(v.begin() + 1, toInsert.begin(), toInsert.end()); // {20, 30, 40, 10, 5, 5, 5}


std::vector<int> v = {10, 20, 30, 40, 50};

// 1. Remove last element
v.pop_back(); // {10, 20, 30, 40}

// 2. Erase at a position
v.erase(v.begin() + 1); // {10, 30, 40}

// 3. Erase a range
v.erase(v.begin() + 1, v.end()); // {10}

// 4. Clear all elements
v.clear(); // Empty vector


std::vector<int> v = {1, 2, 3};

// 1. Resize to larger size (default-initialized values)
v.resize(5); // {1, 2, 3, 0, 0}

// 2. Resize to smaller size
v.resize(2); // {1, 2}

std::vector<int> v1 = {1, 2};
std::vector<int> v2 = {10, 20, 30};

// Swap contents
v1.swap(v2); // v1 = {10, 20, 30}, v2 = {1, 2}


std::vector<int> v = {10, 20};

// 1. Get size
std::cout << v.size(); // 2

// 2. Get capacity
std::cout << v.capacity(); // >= 2 (capacity may exceed size)

// 3. Check if empty
std::cout << std::boolalpha << v.empty(); // false

// 4. Reserve capacity
v.reserve(10); // Pre-allocate memory for 10 elements

// 5. Shrink to fit
v.shrink_to_fit(); // Reduce capacity to match size


std::vector<int> v = {10, 20, 30};

// 1. Begin and end
for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
}

// 2. Reverse begin and end
for (auto it = v.rbegin(); it != v.rend(); ++it) {
    std::cout << *it << " ";
}

// 3. C++11 range-based loop
for (int val : v) {
    std::cout << val << " ";
}

std::vector<int> v = {10, 20, 30};
std::for_each(v.begin(), v.end(), [](int& n) { n += 10; }); // {20, 30, 40}

std::vector<std::pair<int, int>> v;
v.emplace_back(10, 20); // Avoids creating a temporary pair

```

## ```std::list``` and ```std::forward_list```

### Key Differences

| Feature | ```std::list``` | ```std::forward_list``` |
|-|-|-|
| Traversal | Bidirectional | Unidirectional |
| Memory Usage | Higher(two-pointers) | Lower(one-pointer) |
| Insertion/Deletion | Anywhere | After Specific Positions |
| Operations | Full Suport | Limited Suport |
| Use Cases | Complex Structures requiring frequent insertions and deletions in both directions | Simple structures requiring lightweight, forward -only traversal |

### ```std::forward_list```

- ```#include <forward_list>```
- Lacks operations like ```push_back()```

```cpp
#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> flst = {1, 2, 3, 4};

    // Add elements
    flst.push_front(0); // Prepend at the front

    // Traversing and printing the forward list
    for (int val : flst) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Inserting after a specific element
    auto it = flst.begin();
    flst.insert_after(it, 9); // Insert 9 after the first element

    // Erasing an element
    it = flst.begin();
    flst.erase_after(it); // Erase element after the first

    for (int val : flst) {
        std::cout << val << " ";
    }
    return 0;
}
```

### ```std::list```

- ```#include <list>```
- Supports all standard container operations

```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> lst = {1, 2, 3, 4};

    // Add elements
    lst.push_back(5);  // Append at the end
    lst.push_front(0); // Prepend at the front

    // Traversing and printing the list
    for (int val : lst) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Erasing an element
    auto it = lst.begin();
    std::advance(it, 2); // Move iterator to the 3rd element
    lst.erase(it);

    for (int val : lst) {
        std::cout << val << " ";
    }
    return 0;
}
```

## ```std::deque```

- It is a sequence container that allows fast insertion and deletion at both the beginning and the end. Internally, ```std::deque``` uses a dynamic array of fixed-size blocks, making it efficient for random access and dynamic resizing.
- Double-ended - ```push_back()``` / ```push_front```
- Allows direct acces to element like ```std::vector```
- Solwer random access compared to ```std::vector```

### Use cases of ```std::deque```

- Scenarios requiring frequent additions/removals at both ends of a collection.
- Implementing double-ended queues, stacks, or deques.
- Situations where random access and dynamic resizing are both needed.

### Operations with ```std::deque```

1. Modifiers
   - ```push_back()``` ...
   - ```insert()``` / ```erase()```
2. Access
   - at(index)
   - operator[]
   - front(), back()
3. Capacity
   - size(), empty()
   - resize(new_size)

```cpp
#include <iostream>
#include <deque>

int main() {
    // Create a deque of integers
    std::deque<int> dq;

    // Add elements at the back and front
    dq.push_back(10);
    dq.push_front(5);
    dq.push_back(15);

    // Access elements
    std::cout << "Front: " << dq.front() << ", Back: " << dq.back() << std::endl;

    // Iterate and print all elements
    std::cout << "Deque elements: ";
    for (int val : dq) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Remove elements
    dq.pop_front();
    dq.pop_back();

    // Print size
    std::cout << "Size after pop operations: " << dq.size() << std::endl;

    return 0;
}
```

### Comparison with ```std::vector``` and ```std::list```

| Feature | std::deque | std::vector | std::list |
|-|-|-|-|
| Random Access | Yes | Yes | No |
| Insertion/Deletion | Fast at ends | Slow at front | Fast anywhere |
| Memory Layout | Non-contiguous | Contiguous | Non-contiguous |
| Ideal Use Case | Double-ended queue | Dynamic arrays | Frequent middle operations |

## ```std::set```

- ```#include <set>```
- stores unique elements in a specific order
- It is implemented as a balanced binary search tree(Red-Black tree)
- Operations like insertion, deletion, lookup are \(```O(log n)```)
- Dublicates not allowed
- Custom sorting can be defined using a comparator
  
    ```cpp
    #include <iostream>
    #include <set>

    struct DescendingOrder {
        bool operator()(int a, int b) const {
            return a > b; // Sort in descending order
        }
    };

    int main() {
        std::set<int, DescendingOrder> mySet = {10, 5, 20};

        std::cout << "Set in descending order: ";
        for (int val : mySet) {
            std::cout << val << " ";
        }
        std::cout << std::endl;

        return 0;
    }
    ```

### Operations with ```std::set```

1. Modifiers
   - insert(value)
   - erase(value)
   - clear()
2. Accessors
   - find() - returns an iterator to the element if it exists, if not then .end()
   - count(value) - 1 if it exist, 0 if not
3. Capacity
   - size()
   - empty()

```cpp
#include <iostream>
#include <set>

int main() {
    // Create a set of integers
    std::set<int> mySet;

    // Insert elements
    mySet.insert(10);
    mySet.insert(5);
    mySet.insert(20);

    // Attempt to insert duplicate
    if (!mySet.insert(10).second) {
        std::cout << "10 is already in the set!" << std::endl;
    }

    // Print all elements
    std::cout << "Set elements: ";
    for (int val : mySet) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Check if an element exists
    if (mySet.count(5)) {
        std::cout << "5 exists in the set." << std::endl;
    }

    // Remove an element
    mySet.erase(10);

    // Print after removal
    std::cout << "Set after removing 10: ";
    for (int val : mySet) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

## ```std::unordered_set```

- It is implemented as a hash table, which provides average constant-time (O(1)) complexity for insertion, deletion, and lookup. However, performance may degrade to linear time (O(n)) in the worst case due to hash collisions.
- Elements stored in an arbitrary order, determined by hash value
- Order may change as elements are added or removed
- Unique elements, no dublicates
- Uses a hash table for internal storage
- ```O(1)``` average for insertion, look-up and removal
- Slower than ```std::set``` in worst-case (hash colissions)

### Common Use Cases of ```std::unordered_set```

- Storing and quickly checking membership of unique items.
- Implementing hash-based sets where order does not matter.
- Applications requiring fast lookups without maintaining a sorted order.

### Operations with ```std::unordered_set```

- Same as ```std::set``
- Added **Hash Functions**
    1. bucket_count() - number of buckets in hash_table
    2. bucket_size(bucket_index) - number of elements in bucket
    3. load_factor() - return the ratio of the number of elements to the number of buckets

### Custom Hash Functions

```cpp
#include <iostream>
#include <unordered_set>
#include <string>

// Custom hash function for strings
struct CustomHash {
    std::size_t operator()(const std::string& key) const {
        std::size_t hash = 0;
        for (char ch : key) {
            hash = hash * 31 + ch; // Simple polynomial rolling hash
        }
        return hash;
    }
};

int main() {
    // Create an unordered_set with a custom hash function
    std::unordered_set<std::string, CustomHash> mySet;

    // Insert elements
    mySet.insert("apple");
    mySet.insert("banana");
    mySet.insert("cherry");

    // Print elements
    std::cout << "Unordered set elements: ";
    for (const std::string& val : mySet) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Comparison of ```std::unordered_set``` with ```std::set```

| Feature | std::set | std::unordered_set |
|-|-|-|
| Order | Sorted | Unordered |
| Underlying Structure | Balanced BST | Hash Table |
| Search Complexity | O(log n) | O(1) (average) |
| Duplicate Elements | Not Allowed | Not Allowed |
| Custom Comparator/Hash | Comparator | Hash Function |
| Ideal Use Case | Sorted unique items | Fast membership tests |

## ```std::multiset```

- Same as ```std::set```
- allows dublicates
- Same Member Functions
- Can have custom Comparator
- same header file ```<set>```

Accessors:

```equal_range(value)``` - return a range(pair of iterators) of all instances of the value

### Comparison with ```std::set``` of ```std::multiset```

| Feature | std::set | std::multiset |
|-|-|-|
| Duplicates Allowed | No | Yes |
| Order | Sorted | Sorted |
| Underlying Structure | Balanced BST | Balanced BST |
| Search Complexity | O(log n) | O(log n) |
| Ideal Use Case | Unique elements | Elements with duplicates |

## ```std::unorderd_multimap```

- same as ```std::unordered_set```
- allows dublciates
- can have **custom Hash Function**
- Same Operations, but with the addition of ```equal_range(value)``` which return 2 iterators

## ```std::pair```

- ```#include <utility>```
- used to store a pair of two values - key-value pair
- Two values of potentially different types
- public members - ```.first``` and ```.second```

### Example of ```std::pair```

```cpp
#include <iostream>
#include <utility>

int main() {
    // Create a pair of int and string
    std::pair<int, std::string> myPair(1, "Alice");

    // Access elements
    std::cout << "First: " << myPair.first << "\n";
    std::cout << "Second: " << myPair.second << "\n";

    // Modify elements
    myPair.first = 42;
    myPair.second = "Bob";

    std::cout << "Updated First: " << myPair.first << "\n";
    std::cout << "Updated Second: " << myPair.second << "\n";

    return 0;
}
```

### Use cases of ```std::pair```

1. Key_value Pairs - containers as ```std::map``` and ```std::unordered_map```
2. To return multiple values
3. Coordinates or row/column pairs

### ```std::make_pair```

- helper function to make pairs without specifying the types explicitly

```cpp
#include <iostream>
#include <utility>

int main() {
    // Create a pair using std::make_pair
    auto myPair = std::make_pair(42, "Charlie");

    std::cout << "First: " << myPair.first << "\n";
    std::cout << "Second: " << myPair.second << "\n";

    return 0;
}
```

## ```std::map```, ```std::multimap```, ```std::unordered_map``` and ```std::unordered_multimap```

| Feature | std::map | std::unordered_map | std::multimap | std::unordered_multimap |
|-|-|-|-|-|
| Order of Elements | Sorted by key (ascending) | No specific order | Sorted by key (ascending) | No specific order |
| Duplicate Keys | Not allowed | Not allowed | Allowed (multiple values) | Allowed (multiple values) |
| Underlying Structure | Red-Black Tree (BST) | Hash Table | Red-Black Tree (BST) | Hash Table |
| Insertion Time Complexity | O(log n) | O(1) average | O(log n) | O(1) average |
| Access Time Complexity | O(log n) | O(1) average | O(log n) | O(1) average |
| Search Time Complexity | O(log n) | O(1) average | O(log n) | O(1) average |

### Key Takeaways

- ```std::map``` and ```std::multimap``` store elements in a sorted order and are based on a balanced tree structure.
    1. ```std::map```: Only allows unique keys.
    2. ```std::multimap```: Allows multiple entries for the same key.

- ```std::unordered_map``` and ```std::unordered_multimap``` do not maintain any specific order and are implemented using hash tables.
    1. std::unordered_map: Only allows unique keys.
    2. std::unordered_multimap: Allows multiple entries for the same key.

- **Efficiency** - ```std::unordered_map``` and ```std::unordered_multimap``` tend to have faster average access times (O(1)) compared to ```std::map``` and ```std::multimap``` (```O(log n)```) due to their use of hash tables.

## ```std::stack```

- Is a container adapter in C++ which provides a LIFO interface
- As an adapter it uses another container ```std::vector```, ```std::deque```, or ```std::list```
- by default ```std::deque``` is used

1. **LIFO Structure**
2. **Restricted access**, can only access top element

### Member Functions of ```std::stack```

1. Constructor
    - ```std::stack<T, Container>```
2. Other
    - empty() - checks if stack is empty
    - size() - return number of elements
    - top() - return reference to top element
    - push(const T&) - adds a copy to the stack
    - pop() - only removes the top element
    - emplace(...) - constructs and adds a new element at the top
    - swap(stack&) - Swaps the contents of two stack

## ```std::queue```

- container adapter
- provides a FIFO data structure
- relies on another container(default is ```std::deque```), ```std::list```

### Operations on ```std::queue```

- Constructor
  - ```std::queue<T, container>```
- Other
  - empty() - checks if the queue is empty
  - size() - returns the size
  - front()/back() - return a reference
  - push(const T&) - adds a copy of the given element to the back
  - push(T&&) - Adds a moved element to the back
  - pop() - removes the front element
  - emplace(...) - constructs and adds a new element at the back
  - swap(queue) - Swaps the contents of two queue

## ```std::priority_queue```

- container adapter that supports priority-based retrival of elements
- organizes so high-priority elements are always on top

1. **Heap-based** - implemented as a max-heap by default
2. **Element-Priority** - by default - largest is first
3. Custom Comparison function can be defined
4. **Restricted Access** - can only access top

### Members of ```std::priority_queue```

- Constructor
  - ```std::priority_queue()``` - default constructor
  - ```std::priority_queue(Compare, Container)``` - Custom comparator and container
- Other
  - empty() - checks if empty
  - size() - returns the size of the queue
  - top() - returns a reference to the highest priority element
  - push(const T&) - Adds a copy
  - push(T&&) - Adds a moved element to the queue
  - pop() - removes the highest-priority element from the queue
  - swap(priority_queue) - swaps the contents

- Push and Pop operations are ```O(log n)```

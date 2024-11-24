# Algorithms

## Introduction

- It provides a wide range of algorithms that operate on containers

- If there is a member function of the same function inside the container we want to use, we better use it instead as it has a better complexity and performance

## All algorithms

1. Non-Modifying Sequence Operations
    - These algorithms inspect elements but do not change them.
        - ```std::all_of``` - Checks if all elements satisfy a condition.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {2, 4, 6};
                if (std::all_of(nums.begin(), nums.end(), [](int n) { return n % 2 == 0; })) {
                    std::cout << "All numbers are even\n";
                }
                return 0;
            }
            // checks if all elements satisfy a condition
            // return true, or false
            ```
        - ```std::any_of``` - Checks if any element satisfies a condition.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 3, 5, 8};
                if (std::any_of(nums.begin(), nums.end(), [](int n) { return n % 2 == 0; })) {
                    std::cout << "At least one number is even\n";
                }
                return 0;
            }
            // checks if any element satisfies a condition
            // return true, or false
            ```
        - ```std::none_of``` - Checks if no elements satisfy a condition.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 3, 5};
                if (std::none_of(nums.begin(), nums.end(), [](int n) { return n % 2 == 0; })) {
                    std::cout << "No even numbers\n";
                }
                return 0;
            }
            // checks if no elements satisfy a condition
            // return true if no element satisfies, or false if othewise
            ```
        - ```std::for_each``` - Applies a function to each element.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 3};
                std::for_each(nums.begin(), nums.end(), [](int n) { std::cout << n * n << " "; });
                return 0;
            }
            // applies a function to each element
            // no return
            ```
        - ```std::find``` - Finds the first occurrence of a value.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 3, 4};
                auto it = std::find(nums.begin(), nums.end(), 3);
                if (it != nums.end()) {
                    std::cout << "Found: " << *it << '\n';
                }
                return 0;
            }
            // finds the first occurrence of a value
            // returns an iterator
            ```
        - ```std::find_if``` - Finds the first element satisfying a condition.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 3, 5, 8};
                auto it = std::find_if(nums.begin(), nums.end(), [](int n) { return n % 2 == 0; });
                if (it != nums.end()) {
                    std::cout << "First even number: " << *it << '\n';
                }
                return 0;
            }
            // finds the first element satisfying a condition
            // returns an iterator
            ```
        - ```std::find_if_not``` - Finds the first element that does not satisfy a condition.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {2, 4, 6, 7, 8};
                auto it = std::find_if_not(nums.begin(), nums.end(), [](int n) { return n % 2 == 0; });
                if (it != nums.end()) {
                    std::cout << "First odd number: " << *it << '\n';
                }
                return 0;
            }
            // finds the first element that doesn't satisfy a condition
            // returns an iterator
            ```
        - ```std::adjacent_find``` - Finds the first adjacent pair of equal elements.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 2, 3, 4};
                auto it = std::adjacent_find(nums.begin(), nums.end());
                if (it != nums.end()) {
                    std::cout << "Adjacent pair: " << *it << " and " << *(it + 1) << '\n';
                }
                return 0;
            }
            // finds the first pair of adjacent elements
            // are next to each other and satisfy a condition or are equal by default
            // return a iterator to the first one
            auto it = std::adjacent_find(nums1.begin(), nums1.end(), [](int &i, int &j){
                return (i > j)? true: false;
            });
            ```
        - ```std::count``` - Counts occurrences of a value.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 2, 3, 4};
                int count = std::count(nums.begin(), nums.end(), 2);
                std::cout << "Count of 2: " << count << '\n';
                return 0;
            }
            // counts occurrences of a value
            // return an int
            ```
        - ```std::count_if``` - Counts elements satisfying a condition.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 3, 4, 5};
                int count = std::count_if(nums.begin(), nums.end(), [](int n) { return n % 2 == 0; });
                std::cout << "Count of even numbers: " << count << '\n';
                return 0;
            }
            // counts occurrences of a value that satisfies a condition
            // return an int
            ```
        - ```std::mismatch``` - Finds the first mismatch between two ranges.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums1 = {1, 2, 3};
                std::vector<int> nums2 = {1, 2, 4};
                auto mismatch_pair = std::mismatch(nums1.begin(), nums1.end(), nums2.begin());
                std::cout << "Mismatch at: " << *mismatch_pair.first << " and " << *mismatch_pair.second << '\n';
                return 0;
            }
            // returns the first position where two ranges differ
            // return a pair
            ```
        - ```std::equal``` - Checks if two ranges are equal.
        ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums1 = {1, 2, 3};
                std::vector<int> nums2 = {1, 2, 3};
                if (std::equal(nums1.begin(), nums1.end(), nums2.begin())) {
                    std::cout << "Ranges are equal\n";
                }
                return 0;
            }
            // checks if two ranges are equal
            // returns true, or false
            ```
        - ```std::lexicographical_compare``` - Compares two ranges lexicographically.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums1 = {1, 2, 3};
                std::vector<int> nums2 = {1, 2, 4};
                if (std::lexicographical_compare(nums1.begin(), nums1.end(), nums2.begin(), nums2.end())) {
                    std::cout << "nums1 is less than nums2\n";
                }
                return 0;
            }
            // Compares two ranges lexicographically
            ```
2. Modifying Sequence Operations
    - These algorithms modify the contents of a container.
        - ```std::copy``` - Copies a range to another location.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> source = {1, 2, 3};
                std::vector<int> destination(3); // Ensure enough space

                std::copy(source.begin(), source.end(), destination.begin());

                for (int n : destination) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // copies elements from source to destination
            // destination must be large enough to hold all elements
            // still works if not enough space, but not all elements are copied
            ```
        - ```std::copy_if``` - Copies elements satisfying a condition.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 3, 4, 5};
                std::vector<int> even_nums;

                std::copy_if(nums.begin(), nums.end(), std::back_inserter(even_nums), [](int x) { return x % 2 == 0; });

                for (int n : even_nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // copies elements satisfying a condition
            ```
        - ```std::copy_n``` - Copies a fixed number of elements.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> source = {1, 2, 3, 4, 5};
                std::vector<int> destination(3); // Only 3 elements

                std::copy_n(source.begin(), 3, destination.begin());

                for (int n : destination) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // copies a specified number of elements
            ```
        - ```std::move``` - Moves elements to a new range.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<std::string> source = {"apple", "banana", "cherry"};
                std::vector<std::string> destination(3);

                std::move(source.begin(), source.end(), destination.begin());

                for (const auto& str : destination) {
                    std::cout << str << " ";
                }
                std::cout << "\nSource after move:";
                for (const auto& str : source) {
                    std::cout << str << " ";
                }
                return 0;
            }
            // transfers ownership from one to another
            ```
        - ```std::swap_ranges``` - Swaps the elements of two ranges.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums1 = {1, 2, 3};
                std::vector<int> nums2 = {4, 5, 6};

                std::swap_ranges(nums1.begin(), nums1.end(), nums2.begin());

                for (int n : nums1) {
                    std::cout << n << " ";
                }
                std::cout << "\n";
                for (int n : nums2) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // swaps elements from one range to another
            // both must have the same number of elements
            ```
        - ```std::transform``` - Applies a function to elements and writes the results.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 3, 4};
                std::vector<int> squares(nums.size());

                std::transform(nums.begin(), nums.end(), squares.begin(), [](int x) { return x * x; });

                for (int n : squares) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // applies a function to elements and stores the result in a new range
            ```
        - ```std::replace``` - Replaces all occurrences of a value.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 2, 3, 4};

                std::replace(nums.begin(), nums.end(), 2, 9);

                for (int n : nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // replaces all occurrences of a value with a new value
            ```
        - ```std::replace_if``` - Replaces elements satisfying a condition.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 3, 4, 5};

                std::replace_if(nums.begin(), nums.end(), [](int x) { return x % 2 == 0; }, 0);

                for (int n : nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // replaces all elements satisfying a condition with a new value
            ```
        - ```std::fill``` - Fills a range with a value.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums(5);

                std::fill(nums.begin(), nums.end(), 42);

                for (int n : nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // fills range with specified value
            ```
        - ```std::fill_n``` - Fills a specified number of elements with a value.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums(5);

                std::fill_n(nums.begin(), 3, 42);

                for (int n : nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // fills a specified number of elements with a value
            ```
        - ```std::generate``` - Generates elements using a function.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums(5);
                int x = 1;

                std::generate(nums.begin(), nums.end(), [&]() { return x++; });

                for (int n : nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // generates values for a range using a function
            ```
        - ```std::generate_n``` - Generates a fixed number of elements.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums(5);
                int x = 1;

                std::generate_n(nums.begin(), 3, [&]() { return x++; });

                for (int n : nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // generates values for a specific number of elements using a function
            ```
        - ```std::remove``` - Removes elements equal to a value (shifts them to the end).
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 3, 2, 4};
                auto it = std::remove(nums.begin(), nums.end(), 2);

                // Erase elements to reduce size
                nums.erase(it, nums.end());

                for (int n : nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // removes elements equal to a value
            // by shifting them to the end
            ```
        - ```std::remove_if``` - Removes elements satisfying a condition.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 3, 4, 5};
                auto it = std::remove_if(nums.begin(), nums.end(), [](int x) { return x % 2 == 0; });

                nums.erase(it, nums.end());

                for (int n : nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // removes all elements satisfying a condition
            // shifts them to the end
            ```
        - ```std::unique``` - Removes consecutive duplicate elements.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 1, 2, 2, 3, 3};
                auto it = std::unique(nums.begin(), nums.end());

                nums.erase(it, nums.end());

                for (int n : nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // removes consecutive duplicate elements
            // shifts them to the end
            // a iterator to new logical end is returned
            ```
        - ```std::reverse``` - Reverses the order of elements.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 3, 4};
                std::reverse(nums.begin(), nums.end());

                for (int n : nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // reverses the order of elements
            ```
        - ```std::rotate``` - Rotates elements in a range.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 3, 4, 5};
                std::rotate(nums.begin(), nums.begin() + 2, nums.end());

                for (int n : nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // rotates elements in a range, moving the elements at middle to the beginning
            ```
        - ```std::partition``` - Reorders elements based on a condition.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 3, 4, 5};
                std::partition(nums.begin(), nums.end(), [](int x) { return x % 2 == 0; });

                for (int n : nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // reorders elements in a range, such that elements satisfing a predicate come before those that do not
            ```
        - ```std::stable_partition``` - Stable version of std::partition.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 3, 4, 5};
                std::stable_partition(nums.begin(), nums.end(), [](int x) { return x % 2 == 0; });

                for (int n : nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // works like std::partition
            // but preserves relative order
            ```
3. Sorting and Related Operations
   - These algorithms reorder elements.
        - ```std::sort``` - Sorts a range in ascending order.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {3, 1, 4, 1, 5};

                // Sort in ascending order
                std::sort(nums.begin(), nums.end());

                for (int n : nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // sorts elements, ascending by default
            // a custom compartor can be specified
            std::sort(nums.begin(), nums.end(), std::greater<int>());
            ```
        - ```std::stable_sort``` - Maintains the relative order of equal elements.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<std::pair<int, char>> pairs = {{3, 'a'}, {1, 'b'}, {3, 'c'}, {2, 'd'}};

                // Sort by the first element, preserving the order of equal elements
                std::stable_sort(pairs.begin(), pairs.end(), [](auto a, auto b) {
                    return a.first < b.first;
                });

                for (auto p : pairs) {
                    std::cout << "(" << p.first << ", " << p.second << ") ";
                }
                return 0;
            }
            // sorts a range maintaining the relative order of elements that compare equal
            ```
        - ```std::partial_sort``` - Partially sorts a range.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {4, 2, 5, 1, 3};

                // Sort only the first 3 smallest elements
                std::partial_sort(nums.begin(), nums.begin() + 3, nums.end());

                for (int n : nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // partially sorts a range such that the smallest k elements (up to a specified middle iterator) are sorted
            ```
        - ```std::nth_element``` - Finds the N-th smallest element.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {4, 2, 5, 1, 3};

                // Place the 3rd smallest element in the correct position
                std::nth_element(nums.begin(), nums.begin() + 2, nums.end());

                for (int n : nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // rearranges the range such that the element athe the position n is what it would be if the range were fully sorted
            // elements before it are less than or equal to it
            // elements after are greater or equal to it
            ```
        - ```std::is_sorted``` - Checks if a range is sorted.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 3, 4, 5};

                if (std::is_sorted(nums.begin(), nums.end())) {
                    std::cout << "The range is sorted.\n";
                } else {
                    std::cout << "The range is not sorted.\n";
                }
                return 0;
            }
            // checks if a range is sorted
            // ascending order by default 
            // a custom compartor can be specified
            ```
        - ```std::is_sorted_until``` - Finds the first unsorted element.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 5, 4, 6};

                auto it = std::is_sorted_until(nums.begin(), nums.end());

                std::cout << "First unsorted element: " << *it << "\n";
                return 0;
            }
            // returns an iterator to the first unsorted element
            ```
4. Binary Search Algorithms
   - These require sorted ranges.
        - ```std::binary_search``` - Checks if an element exists.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 3, 4, 5};

                if (std::binary_search(nums.begin(), nums.end(), 3)) {
                    std::cout << "3 is found!\n";
                } else {
                    std::cout << "3 is not found!\n";
                }
                return 0;
            }
            // checks whether a value exists in asorted range
            // the range must be sorted
            ```
        - ```std::lower_bound``` - Finds the first position where an element can be inserted.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 4, 4, 5};

                auto it = std::lower_bound(nums.begin(), nums.end(), 4);

                std::cout << "Lower bound of 4: Index " << (it - nums.begin()) << "\n";
                return 0;
            }
            // finds the first position in a sorted range where a value can be inserted without violating the order
            // return an interator
            // this case : 2 position
            ```
        - ```std::upper_bound``` - Finds the last position where an element can be inserted.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 4, 4, 5};

                auto it = std::upper_bound(nums.begin(), nums.end(), 4);

                std::cout << "Upper bound of 4: Index " << (it - nums.begin()) << "\n";
                return 0;
            }
            // finds the last position in a sorted range where an element can be inserted witout violating the order
            // returns an iterator
            ```
        - ```std::equal_range``` - Finds the range of a value.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 4, 4, 5};

                auto range = std::equal_range(nums.begin(), nums.end(), 4);

                std::cout << "Equal range of 4: Indices " 
                        << (range.first - nums.begin()) << " to " 
                        << (range.second - nums.begin()) << "\n";
                return 0;
            }
            // finds the range of positions for a value in a sorted range
            // combines std::lower_bound and std::upper_bound
            ```
5. Heap Operations
    - A heap is a binary tree-like data structure where
        1. **Max-Heap** - The parent node is greater than or equal to its child nodes
        2. **Min-Heap** - The parent node is less than or equal to its child notes
    - STL uses **Max-Heap** by default
    - These operate on heaps (priority queues).
        - ```std::make_heap``` - Converts a range into a heap.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {3, 1, 4, 1, 5, 9};

                // Convert the range into a Max-Heap
                std::make_heap(nums.begin(), nums.end());

                for (int n : nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // Converts a range of elements into a heap
            // By default its Max-Heap
            ```
        - ```std::push_heap``` - Adds an element to a heap.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {9, 5, 4, 1, 1, 3};
                std::make_heap(nums.begin(), nums.end());

                // Add a new element to the heap
                nums.push_back(6); // Insert at the end
                std::push_heap(nums.begin(), nums.end()); // Maintain the heap property

                for (int n : nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // Adds a new element to the heap while maintaing the heap property
            // The new element should be placed at the end of the range before calling push_heap
            ```
        - ```std::pop_heap``` - Removes the largest element from a heap.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {9, 6, 4, 5, 1, 3, 1};
                std::make_heap(nums.begin(), nums.end());

                // Remove the largest element
                std::pop_heap(nums.begin(), nums.end());
                nums.pop_back(); // Physically remove the last element

                for (int n : nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // removes the largest element (root of the heap) by moving it to the end of the range
            // the heap property is still kept
            // the element is not actually removed from the container
            // it is moved to the end
            ```
        - ```std::sort_heap``` - Sorts elements in a heap.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {9, 6, 4, 5, 1, 3, 1};
                std::make_heap(nums.begin(), nums.end());

                // Sort the heap
                std::sort_heap(nums.begin(), nums.end());

                for (int n : nums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // Converts a heap into a sorted range in ascending order
            // the heap property is destroyed
            // the range becomes fully sorted
            ```
6. Set Operations
    - These require sorted ranges and perform mathematical set operations.
        - ```std::set_union``` - Computes the union of two sets.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> a = {1, 2, 4};
                std::vector<int> b = {2, 3, 5};
                std::vector<int> result;

                std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));

                for (int x : result) {
                    std::cout << x << " ";
                }
                return 0;
            }
            // Computes the union of two sorted ranges
            // all unique elements from both ranges
            // combines elements from both ranges, excluding duplictes
            ```
        - ```std::set_intersection``` - Computes the intersection of two sets.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> a = {1, 2, 4};
                std::vector<int> b = {2, 3, 4};
                std::vector<int> result;

                std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));

                for (int x : result) {
                    std::cout << x << " ";
                }
                return 0;
            }
            // Computes the intersection of two sorted ranges
            // Outputs elements that exist in both ranges
            ```
        - ```std::set_difference``` - Computes the difference of two sets.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> a = {1, 2, 4};
                std::vector<int> b = {2, 3, 4};
                std::vector<int> result;

                std::set_difference(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));

                for (int x : result) {
                    std::cout << x << " ";
                }
                return 0;
            }
            // computes the difference of two sorted ranges
            // elements inthe first but not in the second
            ```
        - ```std::set_symmetric_difference``` - Computes the symmetric difference of two sets.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> a = {1, 2, 4};
                std::vector<int> b = {2, 3, 4};
                std::vector<int> result;

                std::set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));

                for (int x : result) {
                    std::cout << x << " ";
                }
                return 0;
            }
            // Computes the symmetric difference of two ranges
            // Elements in one range or the other, but not both 
            ```
        - ```std::includes``` - Checks if one set is a subset of another.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> a = {1, 2, 3, 4};
                std::vector<int> b = {2, 3};

                if (std::includes(a.begin(), a.end(), b.begin(), b.end())) {
                    std::cout << "b is a subset of a\n";
                } else {
                    std::cout << "b is not a subset of a\n";
                }
                return 0;
            }
            // checks if one sorted range is a subset of another sorted range
            // returns true if all elements in the second range are contained in the first range
            ```
7. Permutations
   - These deal with permutations of a range.
        - ```std::next_permutation``` - Generates the next lexicographical permutation.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 3};

                do {
                    for (int n : nums) {
                        std::cout << n << " ";
                    }
                    std::cout << "\n";
                } while (std::next_permutation(nums.begin(), nums.end()));

                return 0;
            }
            // Generates the next lexicographical permutation of a range
            // if the range is already the largest permutation the function rearranges it to its smallest permutations
            // sorted in ascending order
            // return true, if it creates the next permutation, false if is already in the largest
            ```
        - ```std::prev_permutation``` - Generates the previous lexicographical permutation.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {3, 2, 1};

                do {
                    for (int n : nums) {
                        std::cout << n << " ";
                    }
                    std::cout << "\n";
                } while (std::prev_permutation(nums.begin(), nums.end()));

                return 0;
            }
            // Generates the previous lexicographical permutation of a range
            // if the range is already the smallest permutation the function rearranges it to its largest permutation
            // sorted in descending order
            // return true, if it creates the previous permutation, false if is already in the smallest
            ```
8. Minimum and Maximum
    - Finds the minimum or maximum in a range.
        - ```std::min```, ```std::max``` - Find the minimum or maximum of two values.
            ```cpp
            #include <algorithm>
            #include <iostream>

            int main() {
                int a = 5, b = 10;

                std::cout << "Min: " << std::min(a, b) << "\n"; // Output: 5
                std::cout << "Max: " << std::max(a, b) << "\n"; // Output: 10

                auto comp = [](int x, int y) { return x > y; }; // Reverse order comparison
                std::cout << "Min with custom comparator: " << std::min(a, b, comp) << "\n"; // Output: 10
                return 0;
                // std::min - returns the smaller of two elements
                // std::max - returns the larger of two elements
                // comp - function that can be given as an argument
            }
            ```
        - ```std::minmax``` - Finds both the minimum and maximum of two values.
            ```cpp
            #include <algorithm>
            #include <iostream>

            int main() {
                int a = 15, b = 7;

                auto result = std::minmax(a, b);
                std::cout << "Min: " << result.first << ", Max: " << result.second << "\n"; // Output: Min: 7, Max: 15
                return 0;
            }
            // returns both the minimum and maximum of two values as a pair
            // returns a pair
            ```
        - ```std::min_element```, ```std::max_element``` - Finds the minimum or maximum element in a range.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {7, 2, 9, 4, 6};

                auto min_it = std::min_element(nums.begin(), nums.end());
                auto max_it = std::max_element(nums.begin(), nums.end());

                std::cout << "Min element: " << *min_it << "\n"; // Output: 2
                std::cout << "Max element: " << *max_it << "\n"; // Output: 9
                return 0;
            }
            // std::min_element - finds the smallest element in a range
            // std::max_element - finds the largest element in a range
            // returns an iterator
            ```
        - ```std::minmax_element``` - Finds both the minimum and maximum elements in a range.
            ```cpp
            #include <algorithm>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {3, 5, 1, 7, 2};

                auto result = std::minmax_element(nums.begin(), nums.end());
                std::cout << "Min element: " << *result.first << "\n";  // Output: 1
                std::cout << "Max element: " << *result.second << "\n"; // Output: 7
                return 0;
            }
            // finds both the smallest and the largest elements in a range
            // returns a pair of iterator
            // first - points to the smallest
            // second - points to the largest
            ```
9.  Numeric Operations
    - For numerical ranges.
        - ```std::accumulate``` - Sums elements in a range.
            ```cpp
            #include <numeric>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 3, 4};
                int sum = std::accumulate(nums.begin(), nums.end(), 0);

                std::cout << "Sum: " << sum << std::endl;

                // Using a custom operation (multiplication)
                int product = std::accumulate(nums.begin(), nums.end(), 1, std::multiplies<int>());

                std::cout << "Product: " << product << std::endl;

                return 0;
            }
            // Computes the sum of the elements in a range - default operation is addition
            // operation can be modified by passing a function
            ```
        - ```std::inner_product``` - Computes the inner product of two ranges.
            ```cpp
            #include <numeric>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> vec1 = {1, 2, 3};
                std::vector<int> vec2 = {4, 5, 6};

                int dot_product = std::inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0);

                std::cout << "Dot product: " << dot_product << std::endl; // (1*4 + 2*5 + 3*6)

                return 0;
            }
            // Computes the inner product of two ranges.
            // multiplies corresponding elements from two ranges, sums them up, and optionally applies a custom binary operation
            ```
        - ```std::adjacent_difference``` - Computes differences between adjacent elements.
            ```cpp
            #include <numeric>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {10, 20, 30, 40};
                std::vector<int> diff(nums.size());

                std::adjacent_difference(nums.begin(), nums.end(), diff.begin());

                for (int n : diff) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // Computes the difference between adjacent elements in a range and stores the results in anothe ranges
            // A custom binary operation can be used
            ```
        - ```std::partial_sum``` - Computes prefix sums.
            ```cpp
            #include <numeric>
            #include <vector>
            #include <iostream>

            int main() {
                std::vector<int> nums = {1, 2, 3, 4};
                std::vector<int> prefix_sums(nums.size());

                std::partial_sum(nums.begin(), nums.end(), prefix_sums.begin());

                for (int n : prefix_sums) {
                    std::cout << n << " ";
                }
                return 0;
            }
            // Computes the prefix sum of elements in a range
            // a custom binary operation can be used instead of addition
            ```
10. Miscellaneous
    - ```std::clamp``` - Clamps a value between a minimum and maximum.
        ```cpp
        #include <algorithm>
        #include <iostream>

        int main() {
            int value = 15;
            int min = 10, max = 20;

            int clamped_value = std::clamp(value, min, max);
            std::cout << "Clamped Value: " << clamped_value << std::endl; // Output: 15

            int out_of_bounds = 25;
            clamped_value = std::clamp(out_of_bounds, min, max);
            std::cout << "Clamped Value: " << clamped_value << std::endl; // Output: 20

            return 0;
        }
        // Limits a value to a specified range. If the value is less than the minimum, it returns the minimum.
        // If the value is greater than the maximum, it returns the maximum.
        // Otherwise, it returns the value itself
        ```
    - ```std::sample``` - Selects a random sample from a range.
        ```cpp
        #include <algorithm>
        #include <vector>
        #include <iostream>
        #include <random>

        int main() {
            std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            std::vector<int> sampled(3);

            std::random_device rd;
            std::mt19937 gen(rd()); // Random number generator

            std::sample(numbers.begin(), numbers.end(), sampled.begin(), 3, gen);

            std::cout << "Sampled values: ";
            for (int n : sampled) {
                std::cout << n << " ";
            }
            return 0;
        }
        // Randomly selects a fixed number of elements from a range without modifying the original range
        // Uses a random number generator
        ```
    - ```std::shuffle``` - Randomly shuffles elements in a range.
        ```cpp
        #include <algorithm>
        #include <vector>
        #include <iostream>
        #include <random>

        int main() {
            std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

            std::random_device rd;
            std::mt19937 gen(rd()); // Random number generator

            std::shuffle(numbers.begin(), numbers.end(), gen);

            std::cout << "Shuffled values: ";
            for (int n : numbers) {
                std::cout << n << " ";
            }
            return 0;
        }
        // Randomly reorders (shuffles) the elements in a range
        ```

## Standard Binary Operations (from ```<functional>```)

| Binary Operation | Description | Equivalent Expression |
|-|-|-| 
| std::plus<> | Addition | x + y |
| std::minus<> | Subtraction | x - y |
| std::multiplies<> | Multiplication | x * y |
| std::divides<> | Division | x / y |
| std::modulus<> | Modulus (remainder) | x % y |
| std::equal_to<> | Equality comparison | x == y |
| std::not_equal_to<> | Inequality comparison | x != y |
| std::less<> | Less than comparison | x < y |
| std::less_equal<> | Less than or equal comparison | x <= y |
| std::greater<> | Greater than comparison | x > y |
| std::greater_equal<> | Greater than or equal comparison | x >= y |
| std::logical_and<> | Logical AND | x && y |
| std::logical_or<>	| Logical OR | x \| y |
| std::bit_and<> | Bitwise AND | x & y |
| std::bit_or<> | Bitwise OR | x \| y |
| std::bit_xor<> | Bitwise XOR | x ^ y |

### Examples with Binary operations from ```<functional>```

1. Arithmetic operations
    ```cpp
    #include <functional>
    #include <numeric>
    #include <vector>
    #include <iostream>

    int main() {
        std::vector<int> nums = {1, 2, 3, 4};

        // Sum of elements using std::plus<>
        int sum = std::accumulate(nums.begin(), nums.end(), 0, std::plus<int>());
        std::cout << "Sum: " << sum << std::endl; // Output: 10

        // Product of elements using std::multiplies<>
        int product = std::accumulate(nums.begin(), nums.end(), 1, std::multiplies<int>());
        std::cout << "Product: " << product << std::endl; // Output: 24

        return 0;
    }
    ```
2. Comparison operations
    ```cpp
    #include <functional>
    #include <iostream>
    #include <vector>
    #include <algorithm>

    int main() {
        std::vector<int> nums = {3, 1, 4, 2};

        // Sort in descending order using std::greater<>
        std::sort(nums.begin(), nums.end(), std::greater<int>());

        std::cout << "Descending order: ";
        for (int n : nums) std::cout << n << " "; // Output: 4 3 2 1
        std::cout << std::endl;

        // Check if all elements are equal using std::equal_to<>
        bool all_equal = std::all_of(nums.begin(), nums.end(), [](int n) {
            return std::equal_to<int>()(n, nums[0]);
        });
        std::cout << "All elements equal? " << std::boolalpha << all_equal << std::endl; // Output: false

        return 0;
    }
    ```
3. Logical Operations
    ```cpp
    #include <functional>
    #include <vector>
    #include <iostream>
    #include <algorithm>

    int main() {
        std::vector<bool> flags = {true, true, false};

        // Check if all elements are true using std::logical_and<>
        bool all_true = std::all_of(flags.begin(), flags.end(), [](bool b) {
            return std::logical_and<bool>()(b, true);
        });
        std::cout << "All true? " << std::boolalpha << all_true << std::endl; // Output: false

        // Check if any element is true using std::logical_or<>
        bool any_true = std::any_of(flags.begin(), flags.end(), [](bool b) {
            return std::logical_or<bool>()(b, false);
        });
        std::cout << "Any true? " << std::boolalpha << any_true << std::endl; // Output: true

        return 0;
    }
    ```
4. Bitwise operations
    ```cpp
    #include <functional>
    #include <iostream>

    int main() {
        int a = 6; // Binary: 110
        int b = 3; // Binary: 011

        int and_result = std::bit_and<int>()(a, b); // Binary AND: 010 -> 2
        int xor_result = std::bit_xor<int>()(a, b); // Binary XOR: 101 -> 5

        std::cout << "Bitwise AND: " << and_result << std::endl; // Output: 2
        std::cout << "Bitwise XOR: " << xor_result << std::endl; // Output: 5

        return 0;
    }
    ```

## Numeric Algorithms (from ```<numeric>``` header)

1. ```std::iota```
    - Fills a range with a sequentially increasing values, starting from a specified initial value
    - Each subsequent element is incremented by 1 from the previous
        ```cpp
        #include <numeric>
        #include <vector>
        #include <iostream>

        int main() {
            std::vector<int> nums(5);

            // Fill with sequential values starting from 10
            std::iota(nums.begin(), nums.end(), 10);

            std::cout << "Sequential values: ";
            for (int n : nums) std::cout << n << " "; // Output: 10 11 12 13 14
            std::cout << std::endl;

            return 0;
        }
        ```
2. ```std::reduce```
    - Combines elements of araneg using a binary operation, supporting parallel execution if desired
        ```cpp
        #include <numeric>
        #include <vector>
        #include <iostream>

        int main() {
            std::vector<int> nums = {1, 2, 3, 4, 5};

            // Sum of all elements
            int sum = std::reduce(nums.begin(), nums.end(), 0);
            std::cout << "Sum: " << sum << std::endl; // Output: 15

            // Product of all elements
            int product = std::reduce(nums.begin(), nums.end(), 1, std::multiplies<>());
            std::cout << "Product: " << product << std::endl; // Output: 120

            return 0;
        }
        ```
3. ```std::transform_reduce```
    - Combines element-wise transformations and reduction into a single operation
        ```cpp
        #include <numeric>
        #include <vector>
        #include <iostream>

        int main() {
            std::vector<int> nums = {1, 2, 3, 4};

            // Square each element, then sum
            int result = std::transform_reduce(nums.begin(), nums.end(), 0,
                                                std::plus<>(), // Reduction: sum
                                                [](int x) { return x * x; }); // Transformation: square
            std::cout << "Sum of squares: " << result << std::endl; // Output: 30

            return 0;
        }
        ```
4. ```std::exclusive_scan```
    - Computes the prefix sum of a range, excluding the current element
        ```cpp
        #include <numeric>
        #include <vector>
        #include <iostream>

        int main() {
            std::vector<int> nums = {1, 2, 3, 4};
            std::vector<int> result(nums.size());

            // Exclusive prefix sum
            std::exclusive_scan(nums.begin(), nums.end(), result.begin(), 0);
            std::cout << "Exclusive scan: ";
            for (int r : result) std::cout << r << " "; // Output: 0 1 3 6
            std::cout << std::endl;

            return 0;
        }
        ```
5. ```std::inclusive_scan```
    - Computes the prefix sum of a range, including the current element
        ```cpp
        #include <numeric>
        #include <vector>
        #include <iostream>

        int main() {
            std::vector<int> nums = {1, 2, 3, 4};
            std::vector<int> result(nums.size());

            // Inclusive prefix sum
            std::inclusive_scan(nums.begin(), nums.end(), result.begin());
            std::cout << "Inclusive scan: ";
            for (int r : result) std::cout << r << " "; // Output: 1 3 6 10
            std::cout << std::endl;

            return 0;
        }
        ```
6. ```std::transform_exclusive_scan```
    - Applies a transformation to each element and then computes an exclusive prefix sum
        ```cpp
        #include <numeric>
        #include <vector>
        #include <iostream>

        int main() {
            std::vector<int> nums = {1, 2, 3, 4};
            std::vector<int> result(nums.size());

            // Square each element, then compute exclusive prefix sum
            std::transform_exclusive_scan(nums.begin(), nums.end(), result.begin(), 0,
                                        std::plus<>(), // Reduction: sum
                                        [](int x) { return x * x; }); // Transformation: square
            std::cout << "Transform exclusive scan: ";
            for (int r : result) std::cout << r << " "; // Output: 0 1 5 14
            std::cout << std::endl;

            return 0;
        }
        ```
7. ```std::transform_inclusive_scan```
    - Applies the transformation to each element and then computes an inclusive prefix sum
        ```cpp
        #include <numeric>
        #include <vector>
        #include <iostream>

        int main() {
            std::vector<int> nums = {1, 2, 3, 4};
            std::vector<int> result(nums.size());

            // Square each element, then compute inclusive prefix sum
            std::transform_inclusive_scan(nums.begin(), nums.end(), result.begin(),
                                        std::plus<>(), // Reduction: sum
                                        [](int x) { return x * x; }); // Transformation: square
            std::cout << "Transform inclusive scan: ";
            for (int r : result) std::cout << r << " "; // Output: 1 5 14 30
            std::cout << std::endl;

            return 0;
        }
        ```

## Parallel Algorithms (from ```<execution>``` header)
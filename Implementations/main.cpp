#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <random>
#include <map>
#include <stack>
#include <numeric>
#include <queue>
#include <ranges>
#include <utility>
#include <functional>

void ex1();
void ex2();
void ex3();
void ex4();
void ex6();
void ex8();
void ex9();
void ex10();
void ex11();
void ex12();
void ex13();
void ex14();
void ex15();
int main(){

//    std::cout << std::format("\nint {}, float {}, string {}", 21, 34.0f, "Larisa") << std::endl;
    int option = 0;

    std::cin >> option;

    switch(option){
        case 1:
            ex1();
            break;
        case 2:
            ex2();
            break;
        case 3:
            ex3();
            break;
        case 4:
            ex4();
            break;
        case 6:
            ex6();
            break;
        case 8:
            ex8();
            break;
        case 9:
            ex9();
            break;
        case 10:
            ex10();
            break;
        case 11:
            ex11();
            break;
        case 12:
            ex12();
            break;
        case 13:
            ex13();
            break;
        case 14:
            ex14();
            break;
        case 15:
            ex15();
            break;
        default:
            std::cout << "Invalid option" << std::endl;
    }

    return 0;
}
void ex15(){
    // Create a vector of pairs (std::vector<std::pair<int, int>>) and sort it by the second element of the pair.
    std::vector my_vec{1, 2, 3};

    int sum = std::accumulate(my_vec.begin(), my_vec.end(), 0, std::plus<int>());

    std::cout << sum << std::endl; 

    int r = 1;
    sum = std::accumulate(my_vec.begin(), my_vec.end(), 0, [&](int x, int y){
        return x + y*r++;
    });

    std::cout << sum << std::endl; 
}
void ex14(){
    // Create a vector of pairs (std::vector<std::pair<int, int>>) and sort it by the second element of the pair.
    std::vector<std::pair<char, int>> my_vec{{'a', 4}, {'4', 3}, {'w', 34}, {'e', 12}};

    for_each(my_vec.begin(), my_vec.end(), [](auto pair){
        std::cout << pair.first << " : " << pair.second << std::endl;
    });

    std::sort(my_vec.begin(), my_vec.end(), [](auto first, auto second){
        return first.second < second.second;
    });

    for_each(my_vec.begin(), my_vec.end(), [](auto pair){
        std::cout << pair.first << " : " << pair.second << std::endl;
    });
}
void ex13(){
    // Use std::set_intersection to find the common elements between two std::set<int> objects.
    std::set<int> first{1, 2, 3, 4, 5, 6, 7, 8};
    std::set<int> second{2, 4, 6, 10, 12};

    std::set<int> third;
    std::set_intersection(first.begin(), first.end(), second.begin(), second.end(), std::inserter(third, third.begin()));

    for_each(first.begin(), first.end(), [](int x){
        std::cout << x << " ";
    });
    std::cout << std::endl;
    for_each(second.begin(),second.end(), [](int x){
        std::cout << x << " ";
    });
    std::cout << std::endl;
    for_each(third.begin(), third.end(), [](int x){
        std::cout << x << " ";
    });
    std::cout << std::endl;

}
void ex12(){
    // Write a program to find the maximum and minimum elements in a vector using std::max_element and std::min_element.
    
    std::vector my_vec{1, 5, 5, 10, 5, 6, 5, 8, 9};

    auto pair = std::minmax_element(my_vec.begin(), my_vec.end());

    std::cout << "Smallest : " << *(pair.first);
    std::cout << "Greatest : " << *(pair.second);
    

    std::cout << "Smallest : " << *(pair.first);
    std::cout << "Greatest : " << *(pair.second);

}
void ex11(){
    // Create a std::priority_queue<int> that orders elements in ascending order using a custom comparator.
    std::priority_queue<int, std::vector<int>, decltype(std::greater<int>())> my_queue;

    my_queue.push(4);
    my_queue.push(1);
    my_queue.push(3);
    my_queue.push(2);
    my_queue.push(4);
    my_queue.push(7);
    my_queue.push(5);
    my_queue.push(9);
    my_queue.push(1);
    my_queue.push(5);
    my_queue.push(3);

    while(!my_queue.empty()){
        std::cout << my_queue.top() << " ";
        my_queue.pop();
    }
    std::cout << std::endl;

}
void ex10(){
    // Use std::partition to split a vector of integers into even and odd numbers.
    std::vector my_vec{1, 5, 5, 10, 5, 6, 5, 8, 9};

    std::for_each(my_vec.begin(), my_vec.end(), [](int x){
        std::cout << x << " ";
    });
    std::cout << std::endl;

    std::partition(my_vec.begin(), my_vec.end(), [](int x){
        return ((x % 2) == 1) ? true : false;
    });

    std::for_each(my_vec.begin(), my_vec.end(), [](int x){
        std::cout << x << " ";
    });
    std::cout << std::endl;

}
void ex9(){
    // Create a std::vector<int> with duplicate elements.
    // Remove duplicates using std::unique and resize the vector.
    std::vector my_vec{1, 5, 5, 10, 5, 6, 5, 8, 9};

    std::for_each(my_vec.begin(), my_vec.end(), [](int x){
        std::cout << x << " ";
    });
    std::cout << std::endl;
    std::cout << "Capacity is: " << my_vec.capacity() << std::endl;
    std::sort(my_vec.begin(), my_vec.end());


    auto it = std::unique(my_vec.begin(), my_vec.end());

    my_vec.erase(it, my_vec.end());
    std::for_each(my_vec.begin(), my_vec.end(), [](int x){
        std::cout << x << " ";
    });
    std::cout << std::endl;
    std::cout << "Capacity is: " << my_vec.capacity() << std::endl;
    my_vec.shrink_to_fit();
    std::cout << "Capacity is: " << my_vec.capacity() << std::endl;


}
void ex8(){
    // Use std::transform to square each element in a std::vector<int> and store the result in another vector.
    std::vector my_vec{1, 2, 3, 10, 5, 6, 10, 8, 9};
    std::vector<int> new_vec(my_vec.capacity());

    std::transform(my_vec.begin(), my_vec.end(), new_vec.begin(), [](int x){
        return x*x;
    });
    std::for_each(my_vec.begin(), my_vec.end(), [](int x){
        std::cout << x << " ";
    });
    std::cout << std::endl;
    std::for_each(new_vec.begin(), new_vec.end(), [](int x){
        std::cout << x << " ";
    });
    std::cout << std::endl;
}
void ex6(){
    // Create a std::vector<int> and use std::find to locate a specific value.
    // Replace the value with a new one using std::replace.
    std::vector my_vec{1, 2, 3, 10, 5, 6, 10, 8, 9};
    int num = 10;
    int new_num = 11;
    
    std::for_each(my_vec.begin(), my_vec.end(), [](int x){
        std::cout << x << " ";
    });
    std::cout << "\n";
    
    auto it = std::find(my_vec.begin(), my_vec.end(), num);
    if(it != my_vec.end()){
        std::replace(my_vec.begin(), my_vec.end(), num, new_num);
    }

    std::for_each(my_vec.begin(), my_vec.end(), [](int x){
        std::cout << x << " ";
    });
    std::cout << "\n";
}
void ex4(){
    // Implement a function to reverse a string using a std::stack<char>
    std::string my_string;
    std::cin.ignore();
    std::cout << "Enter String:" << std::endl;
    std::getline(std::cin, my_string);

    std::stack<char> my_stack;
    
    std::for_each(my_string.begin(), my_string.end(), [&my_stack](char c){
        my_stack.push(c);
    });
    std::generate(my_string.begin(), my_string.end(), [&my_stack](){
        char c = my_stack.top();
        my_stack.pop();
        return c;
    });

    std::cout << "Reversed String is: " << std::endl;
    std::cout << my_string << std::endl;
}
void ex3(){
    // Write a program to count the frequency of characters in a string using std::map<char, int>.
    std::string my_string;
    std::cin.ignore();
    std::cout << "Enter String:" << std::endl;
    std::getline(std::cin, my_string);

    std::map<char, int> my_map;

    auto func = [&](char c){
        if(my_map.find(c) != my_map.end()){
            my_map[c]++;
        } else {
            my_map.insert(std::pair<char, int>(c, 1));
        }
    };

    std::for_each(my_string.begin(), my_string.end(), func);

    for_each(my_map.begin(), my_map.end(), [](auto it){
        std::cout << it.first << " : " << it.second << std::endl;
    });
    
}
void ex2(){
    // Using std::set:

    // Insert 10 random integers into a std::set<int>.
    // Print the elements and observe how duplicates are handled automatically.
    // Check if a specific number exists using set::find.
    auto my_set = std::set<int>();
    for(int i = 0; i < 10; ++i) my_set.insert(rand() % 100);

    std::for_each(my_set.begin(), my_set.end(), [](int x){
        std::cout << x << " ";
    });
    std::cout << std::endl;
    auto it = std::find(my_set.begin(), my_set.end(), 93);
    if(it != my_set.end())
    std::cout << *it << std::endl;

}
void ex1(){
    // Create a std::vector<int> and initialize it with 10 random integers.
    // Print the vector using a for loop and std::for_each with a lambda.
    // Sort the vector in ascending order using std::sort.

    std::vector<int> vec(10);
    int x = 0;
    std::generate(vec.begin(), vec.end(), [&x](){
        return x++;
    });

    for_each(vec.begin(), vec.end(), [](int x){
        std::cout << x << " ";
    });

    std::cout << std::endl;

    std::sort(vec.begin(), vec.end(), [](int x, int y){
        return x > y;
    });
    
    for_each(vec.begin(), vec.end(), [](int x){
        std::cout << x << " ";
    });

}
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>
#include <utility>
#include <list>

void ex1();
void ex2();
void ex3();
void ex4();
void ex5();
void ex6();
template<class T>
void print(const T& object){
    std::cout << std::endl;
    for_each(object.begin(), object.end(), [](auto &element){
        std::cout << element << " ";
    });
    std::cout << std::endl;
}

int main(){
    int option = 0;
    std::cout << "Dati option: ";
    std::cin >> option;

    switch(option){
        case 0:
        break;
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
        case 5:
            ex5();
        break;
        case 6:
            ex6();
        break;
        default: 
            std::cout << "wrong" << std::endl;
    }
    return 0;
}
void ex6(){
    std::vector<int> my_array;

    int optiune = 1;
    int element;
    while(optiune){
            std::cout << "1 - Adaugare" << std::endl;
            std::cout << "2 - Cautare" << std::endl;
            std::cin >> optiune;
        switch(optiune){
            case 1:
                std::cout << "Element: ";
                std::cin >> element;
                
            case 0:
                break;

        }
    }

}
void ex5(){
    std::vector<int> my_array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print(my_array);

    auto it = std::remove_if(my_array.begin(), my_array.end(), [](const int& num){
        return (num % 3 == 0 || num % 5 == 0);
    });
    my_array.erase(it, my_array.end());

    print(my_array);
}
void ex4(){
    // Implement a program to find the subarray with the maximum sum in a given array of integers.
    std::vector<int> my_vector = {1, -2, 3, -54, 65, 34, -23, -3, -2, 1, 34};
//
}
void ex3(){
    // Write a program to compute the intersection and union of two arrays and display the results
    std::vector<int> first(10);
    std::vector<int> second(10);
    std::vector<int> intersection(10);
    std::vector<int> union_of(20);

    std::cout << "citire first: " << std::endl;
    for(int i = 0; i < 10; i++){
        std::cin >> first[i];
    }
    std::cout << "citire second: " << std::endl;
    for(int i = 0; i < 10; i++){
        std::cin >> second[i];
    }

    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());

    print(first);
    print(second);
    std::set_intersection(first.begin(), first.end(), second.begin(), second.end(), std::inserter(intersection, intersection.begin()));
    std::set_union(first.begin(), first.end(), second.begin(), second.end(), std::inserter(union_of, union_of.begin()));

    print(intersection);
    std::cout << intersection.size();
    print(union_of);
    std::cout << union_of.size();
}
void ex2(){
    // Sort a list of students based on:
    // Marks in descending order.
    // If marks are the same, sort alphabetically by name.
    std::vector<std::pair<std::string, float>> my_class(5);
    std::cout << "Citim 5 studenti: " << std::endl;
    
    for(int i = 0; i < 5; i++){
        std::pair<std::string, float> new_pair;
        std::cin.ignore();
        std::cout << "Nume: ";
        std::cin >> new_pair.first;
        std::cout << "Grade: ";
        std::cin >> new_pair.second;
        my_class.push_back(new_pair);
    }

    std::cout << std::endl;
    std::for_each(my_class.begin(), my_class.end(), [](const auto& object){
        std::cout << object.first << " : " << object.second << std::endl;
    });
    std::cout << std::endl;
    std::cout << "clasa Sortata: \n";
    std::sort(my_class.begin(), my_class.end(), [](const auto& first, const auto& second){
        if(first.second == second.second){
            return first.first < second.first;
        }
        return first.second > second.second;
    });
    std::cout << std::endl;
    std::for_each(my_class.begin(), my_class.end(), [](const auto& object){
        std::cout << object.first << " : " << object.second << std::endl;
    });
    std::cout << std::endl;
}
void ex1(){
    // Find Closest Pairs
    // Given an array of integers, find two elements with the smallest difference.
    std::vector<int> my_array(10);
    std::vector<int> my_second_array(10);
    int n = 10;
    std::cout << "Citim 10 elemente: \n";
    for(int i = 0; i < n; i++){
        std::cin >> my_array[i];
    }

    // print(my_array);

    std::sort(my_array.begin(), my_array.end());
    std::adjacent_difference(my_array.begin(), my_array.end(), my_second_array.begin());
    
    // print(my_array);
    // print(my_second_array);
    int poz = 0;
    auto i = std::min_element(my_second_array.begin() + 1, my_second_array.end());
    poz = std::distance(my_second_array.begin(), i); 

    std::cout << "The elements are: " << my_array[poz - 1] << " and " << my_array[poz] << std::endl;
}
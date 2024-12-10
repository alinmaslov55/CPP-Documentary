/* Create a program to:

    Take a string input from the user.
    Generate all unique permutations of the string.
    Display the permutations in lexicographical order.*/

#include <iostream>
#include <set>
#include <algorithm>
#include <string>

int main(){
    std::string s_buffer;
    std::set<std::string> my_set;
    std::cin >> s_buffer;
    
    std::sort(s_buffer.begin(), s_buffer.end());
    bool value;
    do{
        std::cout << s_buffer << std::endl;
        value = std::next_permutation(s_buffer.begin(), s_buffer.end());
    }while(value);

    return 0;
}
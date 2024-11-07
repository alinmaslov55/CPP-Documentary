#include <iostream>


const int& fun(const int &arg){
    return arg;
}
int main(){
    const int argc = 1;

    std::cout << argc << std::endl;
    int i = fun(argc);
    std::cout << i << std::endl; // Outputs: 2
    i = i + 1;
    std::cout << i << std::endl; // Outputs: 3

    return 0;
}
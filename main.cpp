#include <iostream>
#include <format>


int main(){

    std::cout << std::format("\nint {}, float {}, string {}", 21, 34.0f, "Larisa") << std::endl;

    return 0;
}
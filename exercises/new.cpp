#include <iostream>
#include <memory>
#include <array>

int main() {
    std::array<int, 10> my_array(10);

    std::rank(my_array);
    return 0;
}

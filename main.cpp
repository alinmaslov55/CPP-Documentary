#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>

int main(){
    std::vector<int> line(9);

    std::iota(line.begin(), line.end(), 1);

    std::reverse(line.begin(), line.end());

    for(auto i = line.rbegin(); i != line.rend(); i++){
        std::cout << *i << std::endl;
    }

    return 0;
}
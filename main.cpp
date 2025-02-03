#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <functional>
#include <utility>
#include <array>
#include <numeric>

template<class T>
std::ostream& operator<<(std::ostream& os, std::list<T>& my_list){
    std::for_each(my_list.begin(), my_list.end(), [&](T& num){
        os << num << " ";
    });
    return os;
}
int main(){
    std::vector<int> my_vec = {1, 2, 5, 6, 7, 9};

    std::make_heap(my_vec.begin(), my_vec.end());

    return 0;
}
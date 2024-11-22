#include <iostream>
#include <list>
#include <forward_list>
#include <iterator>
#include <span>
#include <vector>



void print(const std::span<int> something);

int main(){
    std::list<int> DlinkedList = {0, 1, 3, 432, 123, 78, 4545};

    DlinkedList.remove_if([](int n){ return (n%2)? true : false; });

    std::list<int>::iterator hui = DlinkedList.begin();

    DlinkedList.insert(++hui, 34);

    DlinkedList.erase(hui, DlinkedList.end());
    std::vector<int> vec(DlinkedList.begin(), DlinkedList.end());

    

    std::span<int> const& something = std::span<int>(vec);

    print(something);

    return 0;
}
void print(std::span<int> const something) {
    for(std::span<int>::iterator it = something.begin(); it != something.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
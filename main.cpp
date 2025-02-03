#include <iostream>
#include <thread>
#include <vector>



int main(){

    auto fun = [](int x){
        std::cout << "Hello from thread: "<< std::this_thread::get_id() << std::endl;
        std::cout << "Passed argumets is " << x << std::endl;
    };

    std::vector<std::thread> more_threads;

    for(int i = 0; i < 10; i++){
        more_threads.emplace_back(fun, i + 1);
    }

    for(int i = 0; i < 10; i++){
        more_threads[i].join();
    }
    return 0;
}
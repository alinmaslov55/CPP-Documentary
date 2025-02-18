#include <iostream>
#include <thread>
#include <vector>
#include <mutex>


std::mutex mtx;
static int data = 0;
void func(){
    std::lock_guard<std::mutex> lock(mtx);

    data = data + 1;

}
int main(){

    std::vector<std::thread> threads;

    for(int i = 0; i < 100; i++){
        threads.emplace_back(func);
    }

    for(int i = 0; i < 100; i++){
        threads[i].join();
    }

    std::cout << "data = " << data << std::endl;
    
    return 0;
}
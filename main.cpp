#include <iostream>
#include <future>
#include <mutex>
#include <thread>

std::mutex mtx;
void job1(){
    if(mtx.try_lock()){
        std::cout << "Job1" << std::endl;
        mtx.unlock();
    }
}
void job2(){
    if(mtx.try_lock()){
        std::cout << "Job2" << std::endl;
        mtx.unlock();
    }
}

int main(){
    
    std::thread thread1(job2);
    std::thread thread2(job1);
    
    thread1.join();
    thread2.join();

    return 0;
}
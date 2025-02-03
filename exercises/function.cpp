#include <iostream>
#include <thread>


void test_thread(int x){
    std::cout << "Thread Function" << std::endl;
    std::cout << "x = " << x << std::endl;
}
int main(){

    std::thread my_thread(&test_thread, 100);

    std::cout << "Main Thread" << std::endl;

    for(int i = 0; i <= 100; i++)std::cout << "i = " << i << std::endl;

    my_thread.join();
    return 0;
}
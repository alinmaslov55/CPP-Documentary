# Concurrency

- Multiple tasks running at the same time(appearing to run at the same time).
- Tasks take turns using the CPU by being scheduled in an interleaved manner.

## Comparison with Parallelism

| Features | Concurrency | Parallelism |
|-|-|-|
| Execution Type | Tasks take turns | Tasks run simultaneously |
| Hardware Requirement | Can work on a single-core CPU | Requires multiple core/CPUs |
| Example | Multithreading on a single core | Runing matrix multiplication on a GPU |

**Concurrency is about dealing with multiple tasks at once (interleaved execution), while parallelism is about multiple tasks at the same time.**

## THREAD

- ```std::thread```
- represents a lightweight process
- is move-only(cannot be copied)

```cpp
void test(int x){
    std::cout << "Hello from thread" << std::endl;
    std::cout << "Passed argumets is " << x << std::endl;
}
int main(){

    std::thread first_thread(&test, 100);    

    std::cout << "Hello from main thread" << std::endl;

    first_thread.join(); // waiting for thread to finish execution

    return 0;
}
```

## Lambda functions in threads

```cpp
int main(){

    std::thread first_thread([](int x){
        std::cout << "Hello from thread" << std::endl;
        std::cout << "Passed argumets is " << x << std::endl;
    }, 100);    

    std::cout << "Hello from main thread" << std::endl;

    first_thread.join();

    return 0;
}
```

## Using multiple threads

```cpp
int main(){

    auto fun = [](int x){
        std::cout << "Hello from thread: "<< std::this_thread::get_id() << std::endl;
        std::cout << "Passed argumets is " << x << std::endl;
    };

    std::vector<std::thread> more_threads; // vector for threads

    for(int i = 0; i < 10; i++){
        more_threads.emplace_back(fun, i + 1);
    }

    for(int i = 0; i < 10; i++){ // every threads get destroyed after creating all of
        more_threads[i].join();  // them, because destruction in the same loop means
    }                            // only one thread
    return 0;
}
```

## ```std::jthread```

- requires ```c++20```
- is a thread wrapper that improves upon ```std::thread``` by providing automating joining when thread object gous out of scope
- prevents resource leaks
- suports cooperative cancellation using ```std::stop_token```, which allows threads to be signaled for stopping

```cpp
#include <iostream>
#include <thread>
#include <chrono>

void worker(){
    for(int i = 0; i < 5; i++){
        std::cout << "Worker thread running: " << i << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
int main(){

    std::jthread jt(worker);

    std::cout << "Main thread running\n";

    return 0;
}
```

### Using ```std::stop_token``` for Cancellation

```cpp
#include <iostream>
#include <thread>
#include <chrono>

void worker(std::stop_token st){
    int i = 0;
    while(!st.stop_requested()){
        std::cout << "Worker thread running: " << i++ << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "Worker stopped" << std::endl;
}
int main(){

    std::jthread jt(worker);

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    jt.request_stop();

    return 0;
}
```

## Data Races and its prevention

- This occurs when multiple threads access the same memory location simultaneously, at least one of the accesses is a write, and there is no proper synchronization
- They lead to undifined behaviour

```cpp
static int data = 0;
void func(){
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
// Value of data might differ
```

### Using ```std::mutex``` to fix Data Races

- Stands short for **mutual exclusion**
- Is a synchronization primitive used in multithreading to prevent data races
- Ensures that only one thread at a time can access shared resources

```cpp
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>


std::mutex mtx;
static int data = 0;
void func(){
    mtx.lock();

    data = data + 1;

    mtx.unlock();
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
```

### Deadlock in Multithreading

- Occurs when two or more threads permanently block each other while waiting for resources that are held by other threads
- Results in the program getting stuck indefinitely
- ```mutes.unlock()``` isn't called

```cpp
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>


std::mutex mtx;
static int data = 0;
void func(){
    mtx.lock();

    data = data + 1;

//    mtx.unlock();
// Program will stop
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
```

#### Using ```std::lock_guard``` - mutex wrapper

- Uses RAII method in order to prevent mutex from remaining locked
- Prevents encountering Deadlock
- Useful when encountering/throwing errors

```cpp
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
```

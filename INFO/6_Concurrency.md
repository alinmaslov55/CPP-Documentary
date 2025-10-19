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

### Using ```std::atomic```

- Is a thread-safe wrapper for variables that allows **lock-free** operations on shared data
- Prevents data races without the need of a **mutex**

1. Provides Atomic (indivisible) operations
2. Avoids overhead of locking (```std::mutex```)
3. Used for simple shared variables (```int```, ```int*```)

```cpp
#include <iostream>
#include <thread>

int counter = 0;  // Shared variable (not thread-safe)

void increment() {
    for (int i = 0; i < 100000; ++i) {
        ++counter;  // Data race! Multiple threads modify 'counter'
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Counter: " << counter << "\n";  // Undefined result!
    return 0;
}
```

```cpp
#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter(0);  // Atomic counter (thread-safe)

void increment() {
    for (int i = 0; i < 100000; ++i) {
        ++counter;  // Atomic increment
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Counter: " << counter << "\n";  // Always 200000
    return 0;
}
```

#### Atomic Operations

| Operation | Example |
|-|-|
| Load Value | ```x.load()``` |
| Store Value | ```x.store()``` |
| Fetch and add | ```fetch_add()``` |
| Fetch and substract | ```fetch_sub()``` |
| Compare and Swap | ```x.compare_exchange_strong(expected, new_value)``` |

#### When to use ```std::atomic``` vs ```std::mutex```

| Feature | ```std::atomic``` | ```std::mutex``` |
|-|-|-|
| Prevents Data Race | Yes | Yes |
| Performance | Fast (Lock Free) | Slower (locking) |
| Works on complex data types | No | Yes |
| Works on simpler variables | Yes | Yes |

- Use ```std::atomic``` for simple numeric or pointer variables
- Use ```std::mutex``` for Complex Objects (data structures)

## Condition variable

- is used for synchronization between threads
- it allows threads to wait for a particular condition to become true
- used with ```std::mutex``` and ```std::unique_lock```
- requires ```<condition_variable>```
- method:
    1. boolean - variable for notifying
    2. lock - ```std::unique_lock``` - common lock(```std::mutex``` - variable)
    3. std::condition_variable - that will stop the reporter thread
    4. 2 ```std::thread```s - worker/reporter

```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::mutex gLock;
std::condition_variable gConditionVariable;

int main() {

    int result = 0;
    bool notified = false;

    // reporting thread
    // must wait on work, done by working thread
    std::thread reporter([&](){
        std::unique_lock<std::mutex> lock(gLock);

        if(!notified){
            gConditionVariable.wait(lock);
        }

        std::cout << "Reporter: result is: " << result << std::endl;

    });

    // working thread
    std::thread worker([&](){
        std::unique_lock<std::mutex> lock(gLock);
        // do our work, lock stays

        result = 42 + 1 + 7;
        // work is done
        notified = true;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "Work is complete" << std::endl;
        // wake up a thread that is waiting for some condition
        gConditionVariable.notify_one();
    });

    // joining threads
    reporter.join();
    worker.join();

    std::cout << "Program Complete" << std::endl;

    return 0;
}
```

## ```std::async``` and ```std::future```

- ```async``` - without synchronization
- requires ```<future>```

```cpp
#include <iostream>
#include <future>

int square(int x){
    return x * x;
}

// form std::future<type of the result>
int main(){

    std::future<int> asyncFunction = std::async(&square, 12);

    // the thread is blocked at the .get() operation until
    // the result is computed
    int result = asyncFunction.get();

    std::cout << "Result is: " << result << std::endl;

    return 0;
}
```

### What is ```std::future```

- represents a future result that will be available after an asynchronous operation completes
- operations are launched with ```std::async(&function, parameters)```
- Features
    1. Can check if result is ready using ```.wait()``` or ```.wait_for()```
    2. can retrieve result using ```.get()```
    3. Supports exceptions - will be rethrown by ```.get()```

### What is ```std::async```

- launches a function asynchronously
- returns ```std::future<T>```

### Example of ```std::async``` with background thread loading data

```cpp
#include <iostream>
#include <future>

bool bufferFileLoader(){
    size_t bytes = 0;
    while(bytes < 10000){
        std::cout << "Thread: " << bytes << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        bytes += 1000;
    }


    // by default
    return true;
}

int main(){

    std::future<bool> backgroundThread = std::async(std::launch::async, bufferFileLoader);

    // enum type
    std::future_status status;

    /*
    future_status{
        deferred
        ready
        timeout
    }
    */

    // main program loop

    while(true){
        std::cout << "Main thread is running " << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // waits for the result for a specified duration
        status = backgroundThread.wait_for(std::chrono::milliseconds(1));

        if(status == std::future_status::ready){
            break;
        }
    }


    return 0;
}
```

## ```std::try_lock```

- function that attempts locking a mutex without blocking
- unlike ```lock()```, it immediately returns whether the locking was successful

```cpp
#include <iostream>
#include <future>
#include <mutex>
#include <thread>

// either job1, or job2 is executed, not both
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
```

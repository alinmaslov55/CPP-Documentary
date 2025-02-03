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

#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>
#include <atomic>

std::atomic<int> shared_resource = 0;

void increment_resource(){
    for(int i = 0; i < 20 ; i++){
        shared_resource.fetch_add(1);
        std::cout << std::this_thread::get_id() << " : " << shared_resource << " \n" ;
    }
}

int main() {
    std::thread t1(increment_resource);
    std::thread t2(increment_resource);

    t1.join();
    t2.join();

    std::cout << "Final value of shared_resource: " << shared_resource << std::endl;

    return 0;
}

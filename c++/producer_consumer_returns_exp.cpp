#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <queue>
#include <functional>

std::mutex mtx;
std::condition_variable cv;

std::queue<int> threadSafeQueue;
const int size=100;

class Producer{
  private :
  
  public :
    Producer(){
      std::cout<<"producer class constructor\n";
    }
    
    void produce(std::function<void(int)> producerCallback){
      for(int i = 0; i < size; i++){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,[](){return (threadSafeQueue.size() < size);});
        threadSafeQueue.push(i); 
        std::cout  << "producing : " << i << " \n";
        producerCallback(i);
        cv.notify_one();
      }        
    }
  
};

class Consumer{
  private :
  
  public :
    Consumer(){
      std::cout<<"consumer class constructor\n";      
    }
    
    void consume(std::function<void(int)> consumerCallback){
      for(int i = 0; i < size; i++){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [](){return (!threadSafeQueue.empty());});
        int temp  = threadSafeQueue.front();
        std::cout << "consuming : " << temp << " \n";
        threadSafeQueue.pop();
        consumerCallback(temp);
        cv.notify_one();
      }    
      std::cout << std::endl;
    }
    
};



int main()
{
    std::cout<<"Hello World\n\n";
    
    Producer producer;
    Consumer consumer;
    
    auto producerCallback = [](int data){
      std::cout << "producing final data in callback = " << (data+2) << std::endl;
    };
    auto consumerCallback = [](int data){
      std::cout << "consuming final data in callback = " << (data+2) << std::endl;    
    };
    
    std::thread producer_thread([&producer, &producerCallback](){
        producer.produce(producerCallback);
    });
    std::thread consumer_thread([&consumer, &consumerCallback](){
        consumer.consume(consumerCallback);
    });
    
    producer_thread.join();
    consumer_thread.join();
    
    return 0;
}

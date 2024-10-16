#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

class Producer{
  private :
  
  public :
    Producer(){
        std::cout<<"producer class constructor\n";
    }
    
    void produce(){
        
    }
  
};

class Consumer{
  private :
  
  public :
    Consumer(){
      std::cout<<"consumer class constructor\n";      
    }
    
    void consume(){
        
    }
    
};



int main()
{
    std::cout<<"Hello World\n\n";
    
    Producer producer;
    Consumer consumer;
    
    std::thread producer_thread([&producer](){
        producer.produce();
    });
    std::thread consumer_thread([&consumer](){
        consumer.consume();
    });
    
    producer_thread.join();
    consumer_thread.join();
    
    return 0;
}

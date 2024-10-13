/// thread safe std::queue

#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional> 

#define MAX_SIZE 100;
std::queue<int> t_safe_q;
std::mutex mtx;
std::condition_variable cv;
int count = 0;
bool done = false;

class Producer{
  private :
  
  public :
    void produce(){
      //std::cout << "in producer\n";
      while(true){
        {
          std::unique_lock<std::mutex> lock(mtx);
          cv.wait(lock, [&](){while ((count >= 100) || (!t_safe_q.empty() && !done)); return 1;});
          if(t_safe_q.empty() && done){
              return;
          }
          t_safe_q.push(count++);
        }
      }
    }
    
};

class Consumer{
  private :
  
  public :
    void consume(){
      //std::cout << "in consumer\n";  
      while(true){
        {
          std::unique_lock<std::mutex> lock(mtx);
          cv.wait(lock, [&](){while (t_safe_q.empty());return 1;});
          if(t_safe_q.empty() && done){
            return;
          }
          std::cout << t_safe_q.front() << " ";
          t_safe_q.pop();
          count--;
        }  
      }
    }
        
};


int main()
{
    std::cout<<"Hello World\n";
    
    Producer prod;
    Consumer consumer;
    
    auto prod_cb = [](){};
    auto consumer_cb = [](){};
    
    std::thread thread_prod([&](){
        prod.produce();                              
    });
    
    std::thread thread_consumer([&](){
        consumer.consume();
    });
    
    thread_prod.join();
    thread_consumer.join();

    return 0;
}

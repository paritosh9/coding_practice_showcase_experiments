#include <iostream>
#include <queue>
#include <functional>
#include <mutex> 
#include <condition_variable> 
#include <thread>

std::mutex m ;
std::queue<int> q;
std::condition_variable cv;

int TASK_COUNT=100;
bool done = false;

class Producer{
  public :
    Producer(){return;};
    void produce(const std::function<void(int)> cb){
      for(int i = 0; i<TASK_COUNT; i++){
        {  
          std::unique_lock<std::mutex> lock(m);
          q.push(i);
          cb(i);
        }
      }
      {
        std::unique_lock<std::mutex> lock(m);
        done = true;
      }
    }      
};

class Consumer{
    public :
      Consumer(){};
      void consume(const std::function<void(int)> cb){
        while(true){
          {
            if(q.empty() && done){
                break;
            }
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [](){return !q.empty() || done;});
            int i = q.front();
            q.pop();
            cb(i);
          }    
        }
      }  
};

int main()
{
    std::cout<<"Hello World\n";
    
    auto producer_callback = [](int i){std::cout << "produce task : " << i << std::endl;};
    auto consumer_callback = [](int i){std::cout << "consume task : " << i << std::endl;};
    
    Producer prodcr;
    Consumer consmr;
    
    std::thread thrd_producer([&prodcr, &producer_callback](){
                                            prodcr.produce(producer_callback);
        
    });
                                            
    std::thread thrd_consumer([&consmr, &consumer_callback](){
                                            consmr.consume(consumer_callback);
    });
    
    thrd_producer.join();
    thrd_consumer.join();

    return 0;
}

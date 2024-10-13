/// thread safe std::queue

#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional> 

const int MAX_SIZE = 200;
std::queue<int> t_safe_q;
std::mutex mtx;
std::condition_variable cv1;
std::condition_variable cv2;
//int count = 0;
bool done = false;

class Producer{
  private :
  
  public :
    void produce(const std::function<void(int)> &prod_cb){
      //std::cout << "in producer\n";
      //int count = 0;
      //while(true){
      for(int count = 0; count < 120 ; count++){
        {
          //std::cout <<"here\n";
          std::unique_lock<std::mutex> lock(mtx);
          cv1.wait(lock, [this]{return (done || (t_safe_q.size()) < MAX_SIZE);});
          if(done) return;
          prod_cb(count);
          t_safe_q.push(count++);
          cv1.notify_one();
        }
        //cv.notify_one();
      }
    }
    
};

class Consumer{
  private :
  
  public :
    void consume(const std::function<void(int)> &consumer_cb){
      //std::cout << "in consumer\n";  
      while(true){
      //for(int count = 0; count < 10 ; count++){
        {
          std::unique_lock<std::mutex> lock(mtx);
          cv1.wait(lock, [this]{return (done || !t_safe_q.empty());});
          if(t_safe_q.empty() && done){
            return;
          }
          //std::cout << "consuming" << t_safe_q.front() << std::endl;;
          consumer_cb(t_safe_q.front());
          t_safe_q.pop();
          cv1.notify_one();
          //count--;
        }
        //cv.notify_one();
      }
    }
        
};


int main()
{
    //std::cout<<"Hello World\n";
    
    Producer prod;
    Consumer consumer;
    
    auto prod_cb = [](int a){
        std::cout << "producer call back " << a <<std::endl;
    };
    auto consumer_cb = [](int a){
        std::cout << "consumer call back " << a <<std::endl;
    };
    
    std::thread thread_prod([&prod, &prod_cb](){
        prod.produce(prod_cb);                              
    });
    
    std::thread thread_consumer([&consumer, &consumer_cb](){
        consumer.consume(consumer_cb);
    });
    
    {
      std::unique_lock<std::mutex> lock(mtx);
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
      //std::cout <<done <<std::endl;
      done = true;
    }  
    
    thread_prod.join();
    thread_consumer.join();

    return 0;
}

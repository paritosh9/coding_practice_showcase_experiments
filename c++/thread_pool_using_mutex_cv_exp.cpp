#include <iostream>
#include <vector>
#include <queue>

#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>



class ThreadPool{
  private :
    std::mutex mtx;
    std::condition_variable cv;
    int _threads = 0;
    std::vector<std::thread> v_threads;
    std::queue<std::function<void()>> _taskq;
    bool _stop = false;
    
  public :  
    ThreadPool(int threads) : _threads(threads){
      for (int i=0 ;i < _threads; i++){
        v_threads.emplace_back([this](){
            while(true){
              std::function<void()> task;
             {
              std::unique_lock<std::mutex> lock(mtx);
              cv.wait(lock,[this](){return !_taskq.empty() || _stop;});
              
              if(_taskq.empty() && _stop){
                  return;
              }
              
              task =std::move(_taskq.front());
              _taskq.pop();
              }
              //cv.notify_all();
              task();
            }
          //return 0;  
        }) ;   
      }      
    }; 
    
    ~ThreadPool(){
       
       {
         std::unique_lock<std::mutex> lock(mtx);
         _stop = true;
       }
       
       cv.notify_all();
       
       for(auto &i :v_threads){
           i.join();
       } 
    }
    
    void enqueue_task(std::function<void()> task){
      {
         std::unique_lock<std::mutex> lock(mtx);
         _taskq.emplace(std::move(task));
      }
       cv.notify_one();
    }
};

int main()
{
    std::cout<<"Hello World\n";
    
    ThreadPool tpool(2);
    
    for(int i = 0; i<8 ; i++){
      tpool.enqueue_task([i](){
          std::cout << "Task " << i << " is running on thread "
                 << std::this_thread::get_id() << std::endl;
          std::this_thread::sleep_for(std::chrono::milliseconds(100));
      });
    }
    

    return 0;
}

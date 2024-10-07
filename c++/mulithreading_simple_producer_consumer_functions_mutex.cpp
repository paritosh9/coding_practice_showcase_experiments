#include <iostream>
#include <queue>

#include <condition_variable>
#include <thread>
#include <semaphore>
#include <chrono>
#include <atomic>

int global_count = 0;

struct task_metadata{
  int _id = 0;
  int _data = 0;
  
  task_metadata(int id, int data){
    _id = id;
    _data = data;
  }
};

std::mutex mtx;
std::queue<task_metadata> task_q;
std::condition_variable cv;
bool stop = 0;

/*class Producer {
  public:
    Producer(){
    } 
};

class Consumer{
    public:
      Consumer()
};*/

void producer(){
  for(int i = 0; i <5 ; i++){
      std::unique_lock<std::mutex> lock(mtx);
      cv.wait(lock, [](){return true;});
      task_metadata task(i,i+2);
      task_q.push(task);
      std::cout << "for thread : " << std::this_thread::get_id() << " enqueued task id : " << task._id << " data : " << task._data << std::endl;
      global_count += 1;
      cv.notify_all();
  }
  
}

void consumer(){
   while(true){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [](){if(!task_q.empty()) return true;
                            if(task_q.empty() && stop){
                              return true;}
                            return false;    
                            }
                              ); 
        if(task_q.empty() && stop){
            std::cout << "done \n";
            return ;
        }
        task_metadata task = task_q.front();   
        std::cout << "for thread : " << std::this_thread::get_id() << " dequeued & executing task id : " << task._id << " data : " << task._data << std::endl;
        //std::this_thread::sleep_for(std::chrono::seconds(1));
        task_q.pop();
        global_count += 1;
        cv.notify_all();
   }
}

int main() {
   
    std::cout << "hello world\n";
    
    /*Producer prdcr();
    Consumer cnsmr();
    
    auto producer = [](){};
    auto consumer = [](){};*/
    
    std::thread thrd_prod1(producer);
    std::thread thrd_prod2(producer);
    
    std::thread thrd_consmr1(consumer);
    std::thread thrd_consmr2(consumer);
    
    std::this_thread::sleep_for(std::chrono::seconds(4));
    {
      std::unique_lock<std::mutex> lock(mtx);
      cv.wait(lock, [](){return true;});
      stop = 1;
      cv.notify_all();
    }
    
    thrd_prod1.join();
    thrd_prod2.join();
    thrd_consmr1.join();
    thrd_consmr2.join();
    
    std::cout << "global count = " << global_count << std::endl;
    
    return 0;
}

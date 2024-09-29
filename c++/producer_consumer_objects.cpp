#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>

using namespace std;

struct task{
    int id;
    int data;
};

bool full = false , empty = true;

mutex mtx;
condition_variable cv;
queue<task> taskQ;


class Producer{
    private :
      int _produce_count = 100;
    
    public :
      Producer(int produce_count): _produce_count(produce_count){}
      ~Producer();
      
      void put(){
            cout<<"thrd 1 \n";
             task *t = new task();
            for(int i =0; i< 100; i++){
                //mtx.lock();
                unique_lock<mutex> lock(mtx);
                cv.wait(lock, [](){if(full)cout<<"full waiting\n";return !full;});
                empty = false;
                t->id = i; t->data = i;
                taskQ.push(*t) ;
                cout<< " producer id - " << t->id << " producer data - " << t->data << endl;
                cv.notify_one();
                //mtx.unlock();
            }
      }
};

class Consumer{
    private :
    
    public :
      Consumer(){}
      ~Consumer();
      
      void get(){
          cout<<"thrd 2 \n";
            task *t = new task();
            //for(int j =0; j< 100; j++){
            while(true){
                //mtx.lock();
                if(taskQ.empty()) empty = true;
                unique_lock<mutex> lock(mtx);
                cv.wait(lock, [](){if(empty)cout<<"empty waiting\n";return !empty;});
                *t = taskQ.front();
                cout<< " consumer id - " << t->id << " consumer data - " << t->data << endl;
                taskQ.pop();
                cv.notify_one();
                //mtx.unlock();
            }
      }
            
};


//user condition_variable
/*void producer(){
    cout<<"thrd 1 \n";
    task *t = new task();
    for(int i =0; i< 100; i++){
        //mtx.lock();
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [](){return !full;});
        empty = false;
        t->id = i; t->data = i;
        taskQ.push(*t) ;
        cout<< " producer id - " << t->id << " producer data - " << t->data << endl;
        cv.notify_one();
        //mtx.unlock();
    }
    return;
}

//use forever while loop in consumer instead of for loop, so use conditional variable
void consumer(){
    cout<<"thrd 2 \n";
    task *t = new task();
    //for(int j =0; j< 100; j++){
    while(true){
        //mtx.lock();
        if(taskQ.empty()) empty = true;
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [](){return !empty;});
        *t = taskQ.front();
        cout<< " consumer id - " << t->id << " consumer data - " << t->data << endl;
        taskQ.pop();
        cv.notify_one();
        //mtx.unlock();
    }
    return;
}
*/

int main()
{
    cout <<"Hello World\n";
    //mutex mtx;
    //thread thrd1(producer, std::ref(mtx));
    //thread thrd2(consumer, std::ref(mtx));

    // need to user producer consumer objects,so first maybe use objects to call put get methods
    // later need to check how to register call backs and all

    Producer *producer = new Producer(200);
    Consumer *consumer = new Consumer();
    
    thread thrd1([&](){producer->put();});
    thread thrd2([&](){consumer->get();});
    
    thrd1.join();
    thrd2.join();
    

    return 0;
}

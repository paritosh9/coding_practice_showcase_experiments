#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>

using namespace std;

struct task{
    int id, data;
};

mutex mtx;
condition_variable cv;
queue<task> taskQ;


/*class Producer{
    private :
      //int _id;
      //int _data;
    
    public :
      Producer(){}
      ~Producer();
      
      void put(task t){};
};

class Consumer{
    private :
      //int _id;
      //int _data;
    
    public :
      Consumer(){}
      ~Consumer();
      
      void get(task t){};
};
*/

//user condition_variable
void producer(){
    cout<<"thrd 1 \n";
    task *t = new task();
    for(int i =0; i< 100; i++){
        t->id = i; t->data = i;
        mtx.lock();
        taskQ.push(*t) ;
        cout<< " producer id - " << t->id << " producer data - " << t->data << endl;
        mtx.unlock();
    }
    return;
}

//use forever while loop in consumer instead of for loop, so use conditional variable
void consumer(){
    cout<<"thrd 2 \n";
    task *t = new task();
    for(int j =0; j< 100; j++){
        mtx.lock();
        *t = taskQ.front();
        cout<< " consumer id - " << t->id << " consumer data - " << t->data << endl;
        taskQ.pop();
        mtx.unlock();
    }
    return;
}

int main()
{
    cout <<"Hello World\n";
    //mutex mtx;
    //thread thrd1(producer, std::ref(mtx));
    //thread thrd2(consumer, std::ref(mtx));

    // need to user producer consumer objects,so first maybe use objects to call put get methods
    // later need to check how to register call backs and all

    thread thrd1(producer);
    thread thrd2(consumer);
    
    thrd1.join();
    thrd2.join();
    

    return 0;
}

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

void producer(){
    cout<<"thrd 1 \n";
    for(int i =0; i< 100; i++){
        mtx.lock();
        cout<< " i - " << i << endl;
        mtx.unlock();
    }
    return;
}
void consumer(){
    cout<<"thrd 2 \n";
    for(int j =0; j< 100; j++){
        mtx.lock();
        cout<< " j - " << j << endl;
        mtx.unlock();
    }
    return;
}

int main()
{
    cout <<"Hello World\n";
    thread thrd1(producer);
    thread thrd2(consumer);
    
    thrd1.join();
    thrd2.join();
    

    return 0;
}

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>

using namespace std;

struct task{
    int id, data;
};

mutex mtx;
condition_variable cv;
queue<task> taskQ;


class Producer{
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

int main()
{
    std::cout<<"Hello World";
    
    

    return 0;
}

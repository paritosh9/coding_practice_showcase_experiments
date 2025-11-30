// Online C++ compiler to run C++ program online
// C++ program to illustrate the use of condition variable

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

using namespace std;

mutex mtx;
condition_variable cv;

queue<int> bufferQ;
const int MAX_COUNT = 5;

void producer(){
    for(int i=0; i<9; i++){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []{return bufferQ.size() < MAX_COUNT;});
        
        bufferQ.push(i);
        cout << "Produced: "<< i << endl;
        cv.notify_one();
    }
}

void consumer(){
    for(int i=0; i<9; i++){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []{return bufferQ.size() > 0;});   
        
        int item = bufferQ.front();
        bufferQ.pop();
        cout << "Consumed: " << item << endl;
        cv.notify_one();
    }
    
}

int main(){
    thread t1(producer);
    thread t2(consumer);
    
    t1.join();
    t2.join();
    
    return 1;
}





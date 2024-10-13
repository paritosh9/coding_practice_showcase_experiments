#include <iostream>
#include <mutex>

class ThreadSafe_Singleton{
  private :
    static std::mutex mtx;
    int _data = 0 ;
    std::string _name = "hello";
    
    static ThreadSafe_Singleton *tss;
    
    ThreadSafe_Singleton(){
      std::cout << "Constructing Thread Safe Singleton with name : " << _name << " data : " << _data << std::endl;
    }
    
    ThreadSafe_Singleton(const ThreadSafe_Singleton& tss) = delete; // deleting copy constructor
    const ThreadSafe_Singleton& operator=(ThreadSafe_Singleton& tss) = delete; // deleting copy assignment operator
    
    ThreadSafe_Singleton(ThreadSafe_Singleton&& tss) = delete; // deleting move constructor
    const ThreadSafe_Singleton& operator=(ThreadSafe_Singleton&& tss) = delete; // deleting move assignment operator
  
  public :
    static ThreadSafe_Singleton* getInstance(){
      std::lock_guard<std::mutex> lck_grd(mtx);
      
      if(tss != nullptr){
        std::cout << "tss singleton instance exists, returning the same \n";
        return tss;
      }    
      
      tss = new ThreadSafe_Singleton();
      return tss;
    }
    
    void doSomething() {
        std::cout << "Singleton doing something!\n" << std::endl;
    }
  
};

ThreadSafe_Singleton* ThreadSafe_Singleton::tss = nullptr;
std::mutex ThreadSafe_Singleton::mtx;

int main()
{
    std::cout<<"Hello World\n";
    
    ThreadSafe_Singleton *tss1 = ThreadSafe_Singleton::getInstance();
    ThreadSafe_Singleton *tss2 = ThreadSafe_Singleton::getInstance();
    
    if(tss1 == tss2){
       std::cout << "Same instance!" << std::endl; 
    }
    
    tss1->doSomething();
    tss2->doSomething();

    return 0;
}

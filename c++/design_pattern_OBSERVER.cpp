#include <iostream>
#include <vector>
#include <set>
#include <memory>

class Observer{
  private:
  
  public:
    virtual void update() = 0;
};

class ConcreteObserver1 : public Observer{
  private:
    
  public:
    ConcreteObserver1(){
      std::cout << "constructing ConcreteObserver1\n";
    } 
    
    void update(){
      std::cout << "updating something about ConcreteObserver1\n";    
    }
};

class ConcreteObserver2 : public Observer{
  private:
    
  public:
    ConcreteObserver2(){
      std::cout << "constructing ConcreteObserver2\n";
    }
    
    void update(){
      std::cout << "updating something about ConcreteObserver2\n";    
    } 
};

class Subject{
  private:
  
  public:
    virtual void addObserver(std::shared_ptr<Observer> observer) = 0;;
    virtual void notify() = 0;
};

class ConcreteSubject : public Subject{
  private:
    std::set<std::shared_ptr<Observer>> observer_list;
    
  public:
    ConcreteSubject(){
      std::cout << "constructing ConcreteSubject\n";
    }
    
    void addObserver(std::shared_ptr<Observer> observer){
      if(observer_list.find(observer) == observer_list.end()){
          observer_list.insert(observer);
      }    
    }
    
    void notify(){
        for(auto i : observer_list){
            std::cout << "Notifying : " << std::endl;
            i->update();
        }
    }
      
};

int main()
{
    std::cout << "Hello World\n";
    
    std::unique_ptr<Subject> conc_sub = std::make_unique<ConcreteSubject>();
    std::shared_ptr<ConcreteObserver1> conc_obs1 = std::make_shared<ConcreteObserver1>();
    std::shared_ptr<ConcreteObserver2> conc_obs2 = std::make_shared<ConcreteObserver2>();
    std::shared_ptr<ConcreteObserver1> conc_obs3 = std::make_shared<ConcreteObserver1>();
    std::shared_ptr<ConcreteObserver2> conc_obs4 = std::make_shared<ConcreteObserver2>();
    
    conc_sub->addObserver(conc_obs1);
    conc_sub->addObserver(conc_obs2);
    
    conc_sub->notify();
    
    conc_sub->addObserver(conc_obs3);
    conc_sub->addObserver(conc_obs4);
    
    conc_sub->notify();
    
    return 0;
}

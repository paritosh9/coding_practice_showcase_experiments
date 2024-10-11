#include <iostream>
#include <memory>

class State{
  public:
    virtual void handle() = 0;
    virtual ~State() {};
};

class RedState : public State{
  public:
    void handle() override{
      std::cout << "red state\n";    
    }
};

class YellowState : public State{
  public:
    void handle() override{
      std::cout << "yellow state\n";    
    }
};

class GreenState : public State{
   public:
    void handle() override{
      std::cout << "green state\n";    
    } 
};

class TrafficLight{
    private:
      State* currentState;
    
    public:
      TrafficLight() : currentState(new RedState()){}
};

int main()
{
    std::cout << "Hello World\n";
    
    
    
    

    return 0;
}

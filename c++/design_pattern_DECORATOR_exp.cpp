#include <iostream>
#include <string>

class Beverage{
  private:
    float _cost = 0;
  
  public:
    Beverage(){}
    virtual ~Beverage(){}
    virtual float get_cost() = 0;
    virtual std::string get_type() = 0;
};

class Espresso : public Beverage{
  private:
    float _cost = 0;
    
  public:
    Espresso(float cost):_cost(cost){}
    ~Espresso(){}
    
    float get_cost(){
      return this->_cost;    
    }
    
    std::string get_type(){
      std::string type("espresso");
      return type;
    }
    
};

class Decorator : public Beverage{
  private:
    //Beverage *_beverage;
  
  public:
    Decorator() {}
    //Decorator(){}
    virtual ~Decorator(){}
    virtual float get_cost() = 0;
    virtual std::string get_type() = 0;
};

class Milk : public Decorator{
    private:
      Beverage *_beverage;
      float _cost = 1.2;
    
    public:
      Milk(Beverage *beverage) : _beverage(beverage) {}
      
      float get_cost(){
      return _beverage->get_cost() + _cost;;    
    }
    
    std::string get_type(){
        std::string type(" milk ");
        return _beverage->get_type() + type;
    }
};

class Mocha : public Decorator{
  private:
      Beverage *_beverage;
      float _cost = 1.5;
    
    public:
      Mocha(Beverage *beverage, float cost) : _beverage(beverage), _cost(cost) {}
      
      float get_cost(){
      return _beverage->get_cost() + _cost;;    
    }
    
    std::string get_type(){
        std::string type(" mocha ");
        return _beverage->get_type() + type;
    }    
};

int main()
{
    std::cout<<"Hello World\n";
    
    Beverage *beverage = new Espresso(4.5);
    std::cout << "beverage cost : " << beverage->get_cost() << std::endl;
    std::cout << "beverage type : " << beverage->get_type() << std::endl;
    
    beverage = new Milk(beverage);
    
    std::cout << "\nbeverage cost : " << beverage->get_cost() << std::endl;
    std::cout << "beverage type : " << beverage->get_type() << std::endl;
    
    beverage = new Mocha(beverage, 2.2);
    
    std::cout << "\nbeverage cost : " << beverage->get_cost() << std::endl;
    std::cout << "beverage type : " << beverage->get_type() << std::endl;
    return 0;
}

#include <iostream>

class ParentClass{
  private : 
  
  public : 
    virtual void baseclass(int a){
        std::cout << "base class " << a <<std::endl;
    }
  
};

class ChildClassA : public ParentClass {
  private :
  
  public :
    void baseclass(int a) override{
        std::cout << "child class A : " << a << std::endl;
    }
  
};

class ChildClassB : public ParentClass {
  private :
  
  public :
    void baseclass(int a){
        std::cout << "child class B : " << a <<  std::endl;
    }  
};

int main()
{
    std::cout<<"Hello World\n";
    
    ParentClass *pc = new ParentClass();
    ChildClassA *ccA =  new ChildClassA();
    ChildClassB *ccB = new ChildClassB();
    
    pc->baseclass(1);
    ccA->baseclass(4);
    ccB->baseclass(9);
    
    pc = ccA;
    pc->baseclass(16);
    
    pc = ccB;
    pc->baseclass(25);
    
    ParentClass *pc1 = new ChildClassA();
    pc1->baseclass(36);
    
    return 0;
}

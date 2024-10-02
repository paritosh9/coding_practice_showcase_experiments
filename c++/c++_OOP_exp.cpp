#include <iostream>

template<typename T>
class base{
    private :
      T param;
      T id;
    public :
      base() {
          std::cout << "this is constructor\n";
      }
      
      base(T param, T id){
         this->param = param;
         this->id = id;
         std::cout << "this is parametrized constructor with param : " << param << " id : " << id << std::endl; 
      }
      
      base(const base& b){
        param = b.param;
        id = b.id;
        std::cout << "this is copy constructor with param : " << param << " id : " << id << std::endl;
      }
      
      virtual ~base(){
          std::cout <<"this is base destructor\n";
      }
      
      virtual void print(){
          std::cout << "this is base print virtual function param : " << param << " id : " << id << std::endl;
      }
};

template<typename T>
class derived : public base<T>{
    private:
      T param;
      T id;
    
    public:
      derived(T param, T id){
        this->param = param;
        this->id = id;
        std::cout << "this is parametrized derived constructor with param : " << param << " id : " << id << std::endl;  
      }
      
      ~derived(){
          std::cout <<"this is derived destructor\n";
      }
      
      void print(){
          std::cout << "this is derived print virtual function param : " << param << " id : " << id << std::endl;
      }
};

int main()
{
    std::cout<<"Hello World\n";
    
    base<int> B1;
    base<int> B2(1,6);
    base<int> B3(B2);
    base<int> B4 = B2;
    base<int> B5(11,65);
    
    B4.print();
    B5.print();
    
    derived<int> D1(15,22);
    D1.print();
    
    base<int> *B6 ;
    derived<int> * D2 = new derived<int>(122,234);
    
    B6 = D2;
    delete B6;
    
    
    return 0;
}

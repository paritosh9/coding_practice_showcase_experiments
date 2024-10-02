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
};

int main()
{
    std::cout<<"Hello World\n";
    base<int> B1;
    base<int> B2(1,6);
    base<int> B3(B2);
    base<int> B4 = B2;
    return 0;
}

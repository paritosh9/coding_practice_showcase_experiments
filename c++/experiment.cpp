
#include <iostream>

class experiment {
    private :
      int xyz;
    public :
      int abc;
      void hello_exp() {
          std::cout << "hellow exp\n";
      }
      
      experiment(int value) : xyz(value){
          
      }
};

int main()
{
    experiment exp1(2);
    exp1.hello_exp();
    
    std::cout<<"Hello World";

    return 0;
}

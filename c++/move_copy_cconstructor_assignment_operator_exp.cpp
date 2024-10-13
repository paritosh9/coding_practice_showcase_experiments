#include <iostream>
#include <string>

class exampleClass{
  private :
    std::string _data;
    int _id;
    int *_fill;
    
  public :
    exampleClass(const std::string data, const int id) : _data(data), _id(id){
      _fill = new int[16]();
      for(int i = 0; i<16; i++){
        *(_fill + i) = i*2;
      }
      std::cout << "\nexampleClass constructor\n"; 
    }
    
    //shallow copy constructor
    /*exampleClass(const exampleClass &example){
      this->_data = example.getData();
      this->_id = example.getId();
      this->_fill = example.getFill();
    }*/
    
    //deep copy constructor
    exampleClass(const exampleClass &example){
      std::cout << "\nexampleClass copy constructor\n";
      this->_data = example.getData();
      this->_id = example.getId();
      
      this->_fill = new int[16];
      int *copy_ptr = example.getFill();
      for(int i = 0; i<16; i++){
        *(_fill+i) = *(copy_ptr+i);  
      }
      for(int i = 0; i<16; i++){
        std::cout << *(_fill + i) << " "; 
      }
      std::cout << std::endl;
      //std::cout << example.getFill() << " " << _fill << std::endl;
      delete [] copy_ptr;
    }
    
    //copy assignment operator
    exampleClass& operator=(const exampleClass& example){
      if(this != &example){
        this->_data = example.getData();
        this->_id = example.getId();
        this->_fill = example.getFill();        
      }
      
      std::cout << "\nexampleClass copy assignment operator\n";
      
      for(int i = 0; i<16; i++){
        std::cout << *(_fill + i) << " "; 
      }
      std::cout << std::endl;
      return *this;
    }
    
    //move constructor
    exampleClass(exampleClass&& example){
      std::cout << "\nexampleClass move constructor\n";
      
      this->_data = example._data; 
      this->_id = example._id;
      this->_fill = example._fill;
      
      example._data = "";
      example._id =0;
      example._fill = nullptr;
      
      for(int i = 0; i<16; i++){
        std::cout << *(this->_fill + i) << " "; 
      }
      std::cout << std::endl;
    }
    
    //move assignment operator
    exampleClass& operator=(exampleClass&& example){
      std::cout << "\nexampleClass move assignment operator\n";
      if(this != &example){
        this->_data = example._data; 
        this->_id = example._id;
        delete [] this->_fill;
        this->_fill = example._fill;      
      }
      
      example._data = "";
      example._id =0;
      example._fill = nullptr;
      
      for(int i = 0; i<16; i++){
        std::cout << *(this->_fill + i) << " "; 
      }
      std::cout << std::endl;
      return *this;      
    }
    
    ////////////
    std::string getData() const{
      return this->_data;
    }
    
    int getId() const{
      return this->_id;    
    }
    
    int* getFill() const{
      return this->_fill;    
    }
    
    void setFill(int* fill){
      this->_fill = fill;;    
    }
    
};


int main()
{
    std::cout<<"Hello World\n";
    
    exampleClass example1("hello",4);
    exampleClass example2(example1);
    exampleClass example3("",1);
    example3=example2;
    
    exampleClass example4(std::move(example3));
    
    exampleClass example5("",1);
    example5 = std::move(example4);
    std::cout << example5.getData() << " " << example5.getId();

    return 0;
}

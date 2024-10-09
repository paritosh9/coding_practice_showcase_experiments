#include <iostream>
#include <memory>

struct Node{
    int _id ;
    int _data ;
    
    Node(int id, int data):_id(id), _data(data){}
};

int main()
{
    std::cout<<"Hello World\n";
    
    std::shared_ptr<Node> ptr1 = std::make_shared<Node>(2,24);
    //ptr1->_id = 1;
    //ptr1->_data = 12;
    std::cout << "ptr1 :" << std::endl;
    std::cout << ptr1->_id << std::endl;
    std::cout << ptr1->_data << std::endl << std::endl;
    
    std::shared_ptr<Node> ptr2 = ptr1;
    
    /*if(ptr1 == nullptr){
        std::cout << "ptr1 is nullptr now\n";
    }*/
    
    std::cout << "ptr2 :" << std::endl;
    std::cout << ptr2->_id << std::endl;
    std::cout << ptr2->_data << std::endl << std::endl;
    
    std::unique_ptr<Node> ptr3 = std::make_unique<Node>(3,36);
    std::cout << "ptr3 :" << std::endl;
    std::cout << ptr3->_id << std::endl;
    std::cout << ptr3->_data << std::endl <<std::endl;
    
    std::unique_ptr<Node> ptr4 = std::move(ptr3);
    if(ptr3 == nullptr){
        std::cout << "ptr3 is nullptr now\n";
        
        
    }
    std::cout << "ptr4 :" << std::endl;
    std::cout << ptr4->_id << std::endl;
    std::cout << ptr4->_data << std::endl;
    
    return 0;
}

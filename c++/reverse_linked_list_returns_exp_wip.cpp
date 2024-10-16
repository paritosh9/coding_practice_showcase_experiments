#include <iostream>

struct Node{
  int _data;
  Node *_next = nullptr;
  
  Node(int data) : _data(data) {
    std::cout << "constructing new node with data : " << _data << std::endl;
  };
};

void reverse_linked_list(){
      
}

int main()
{
    std::cout<<"Hello World\n";
    
    Node *head = new Node(4);

    return 0;
}

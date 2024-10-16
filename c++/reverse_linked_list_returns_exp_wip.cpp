#include <iostream>

struct Node{
  int _data;
  Node *_next = nullptr;
  
  Node(int data) : _data(data) {
    std::cout << "constructing new node with data : " << _data << std::endl;
  };
};

Node* reverse_linked_list(Node *head){
  Node *node = head;
  Node *prev = nullptr;
  Node *next = nullptr;
  while(node->_next != nullptr){
    std::cout << "inside while loop\n";
    next = node->_next;
    //node->_next->_next = node;
    node->_next = prev;
    
    prev = node;
    node = next;
  }
  
  node->_next = prev;
  head = node;
  return head;
}

void printList(Node *head){
  Node *node = head;
  while(node != nullptr){
    std::cout << node->_data << " ";
    node = node->_next;
  }  
  std::cout << std::endl;
}

int main()
{
    std::cout<<"Hello World\n";
    
    Node *head = new Node(4);
    Node *next = new Node(5);
    
    head->_next = next;
    
    next = new Node(6);
    head->_next->_next = next;
    next = new Node(7);
    head->_next->_next->_next = next;
    next = new Node(8);
    head->_next->_next->_next->_next = next;
    next = new Node(9);
    head->_next->_next->_next->_next->_next = next;
    next = new Node(33);
    head->_next->_next->_next->_next->_next->_next = next;
    next = new Node(21);
    head->_next->_next->_next->_next->_next->_next->_next = next;
    
    printList(head);
    
    head = reverse_linked_list(head);
    printList(head);

    return 0;
}

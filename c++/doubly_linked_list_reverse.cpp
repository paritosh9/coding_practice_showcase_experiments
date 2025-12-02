#include <iostream>
using namespace std;

struct Node{
  int _data;
  Node *_next;
  Node *_prev;
  
  Node(int data) : _data(data), _next(nullptr), _prev(nullptr){};
};

Node* addNodeAtEnd(Node *head, int data){
    if(head == nullptr){
        head = new Node(data);
        return head;
    }   
    
    Node *curr = head;
    Node *prev = nullptr;
    while(curr != nullptr){
        prev = curr;
        curr = curr->_next;
    }
    prev->_next = new Node(data);
    prev->_next->_prev = prev;
    
    return head;
}

void printList(Node *head){
    if(head == nullptr){
        cout << "Linked list empty " << endl;
    }   
    
    Node *curr = head;
    Node *reverseStart = nullptr;
    cout << endl;
    cout << " normal list" << endl;
    while(curr != nullptr){
        cout << curr->_data << " -> ";
        if(curr->_next == nullptr){
            reverseStart = curr;
        }
        curr = curr->_next;
    }
    
    curr = reverseStart;
    cout << endl;
    cout << "reverse list " << endl;
    while(curr != nullptr){
        cout << curr->_data << " -> ";
        curr = curr->_prev;
    }
}


Node* reverseList( Node *head){
    if(head == nullptr){
       cout <<" linked list empty cannot reverse" << endl; 
    }   
    
    cout << endl << endl;;
    cout << "Reversing list "<< endl;
    Node *curr = head;
    while(curr != nullptr){
        head = curr;
        Node *tmp = curr->_next;
        curr->_next = curr->_prev;
        curr->_prev = tmp;
        curr = tmp;
    }
    
    return head; 
}

int main(){
    
    Node *head = nullptr;
    
    head = addNodeAtEnd(head, 5);
    head = addNodeAtEnd(head, 4);
    head = addNodeAtEnd(head, 9);
    head = addNodeAtEnd(head, 14);
    head = addNodeAtEnd(head, 25);
    
    printList(head);
    
    head = reverseList(head);
    printList(head);
    
}

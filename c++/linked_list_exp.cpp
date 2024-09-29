#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* addNodeAtEnd(Node *head, int data){
        Node *newNode = new Node();
        newNode->data = data; newNode->next = nullptr;
        Node *curr = head;
        while(curr != nullptr){
            curr = curr->next;
            if(curr->next == nullptr){
                curr->next = newNode;
                break;
            }
        }
    return head;
}

Node* addNodeAtStart(Node *head, int data){
    try{
        Node *newNode = new Node();
        newNode->next = head;
        newNode->data = data;
        head = newNode;
    } catch(...){
        std::cout << "Error \n";
        return 0;
    }
    return head;
}

Node* removeNode(Node *head, int data){
    Node *curr = head;
    Node *prev = nullptr;
    while(curr != nullptr) {
        if(curr->data == data){
          if(curr == head){
              head = curr->next;
          } else{
             prev->next = curr->next;
          }
          delete curr;
          return head;
        }
        prev = curr;
        curr = curr->next;
    }    
    return head;
}

Node* reverseList(Node *head){
    if(head == nullptr){
        return 0;
    }
    Node *curr = head, *prev = nullptr, *next;
    
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

void printList(Node *head){
    std::cout << "\nprinting list\n";
    Node *curr = head;
    while(curr != nullptr) {
        std::cout << "  " << curr->data << "  " << std::endl;
        curr = curr->next;
    }    
}

int main()
{
    std::cout<<"Hello World\n";

    Node *head = nullptr;
    
    head = addNodeAtStart(head, 1);
    head = addNodeAtStart(head, 2);
    head = addNodeAtStart(head, 5);
    head = addNodeAtStart(head, 34);
    head = addNodeAtStart(head, 176);
    printList(head);
    
    head = addNodeAtEnd(head, 99);
    head = addNodeAtEnd(head, 122);
    printList(head);
    
    head = reverseList(head);
    printList(head);
    
    head = reverseList(head);
    printList(head);
    
    head = removeNode(head, 7);
    head = removeNode(head, 5);
    head = removeNode(head, 176);
    
    printList(head);
    
    head = addNodeAtEnd(head, 199);
    head = addNodeAtEnd(head, 1122);
    printList(head);
    
    head = reverseList(head);
    printList(head);
    
    return 0;
}

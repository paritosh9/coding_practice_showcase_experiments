#include <iostream>

struct Node {
    int data;
    Node* next;
};

bool addNodeAtStart(Node *head, int data){
    try{
        Node *newNode = new Node();
        newNode->next = head;
        newNode->data = data;
        head = newNode;
    } catch(...){
        std::cout << "Error \n";
        return 0;
    }
    return 1;
}

bool removeNode(Node *head, int data){
    return 1;
}

bool reverseList(Node *head){
    return 1;
}

void printList(Node *head){
    
}

int main()
{
    std::cout<<"Hello World";

    Node *head = new Node();
    head->data = 0;
    head->next = nullptr;
    
    addNodeAtStart(head, 1);
    addNodeAtStart(head, 2);
    addNodeAtStart(head, 5);
    addNodeAtStart(head, 34);
    addNodeAtStart(head, 176);
    
    removeNode(head, 7);
    removeNode(head, 5);
    
    reverseList(head);
    
    return 0;
}

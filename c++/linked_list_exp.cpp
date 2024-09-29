#include <iostream>

struct Node {
    int data;
    Node* next;
};

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
    return head;
}

Node* reverseList(Node *head){
    return head;
}

void printList(Node *head){
    
}

int main()
{
    std::cout<<"Hello World";

    Node *head = new Node();
    head->data = 0;
    head->next = nullptr;
    
    head = addNodeAtStart(head, 1);
    head = addNodeAtStart(head, 2);
    head = addNodeAtStart(head, 5);
    head = addNodeAtStart(head, 34);
    head = addNodeAtStart(head, 176);
    printList(head);
    
    head = removeNode(head, 7);
    head = removeNode(head, 5);
    
    head = reverseList(head);
    
    return 0;
}

#include <iostream>

template<typename T>
class Node {
  public:
    T _data;
    Node* _left;
    Node* _right;

    Node(int data):_data(data), _left(nullptr), _right(nullptr){}
    
};

template<typename T>
class BinaryTree {
  public:
    Node<T>* _root;
    BinaryTree(): _root(nullptr){}
    
    void inserNode();
    void printTree();
};

int main()
{
    std::cout<<"Hello World\n";

    BinaryTree<int> binary_tree;
    
    return 0;
}

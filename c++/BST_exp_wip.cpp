#include <iostream>

class Node{
  /*private :
    int _data;
    Node *_left;
    Node *_right;*/
  
  public:
    int _data;
    Node *_left;
    Node *_right;
    
    Node(int data) : _data(data), _left(nullptr), _right(nullptr) {}
};

class BST{
  private : 
    Node *_root = nullptr;
  
    Node* findMin(Node *node){
      while(node->_left != nullptr){
        node = node->_left;      
      }  
      return node;
    }
    
    Node* insertNode(Node *node, int val){
      if(node == nullptr){
        node = new Node(val);
        return node;
      }  
      
      if(val <= node->_data){
        node->_left = insertNode(node->_left , val);      
      } else if(val > node->_data){
          node->_right = insertNode(node->_right , val);            
      }
      
      return node;
    }
    
    Node* removeNode(Node *node, int val){
      if(val < node->_data){
        node->_left = removeNode(node->_left , val);      
      } else if(val > node->_data){
          node->_right = removeNode(node->_right , val);            
      } else{
          if(node->_left == nullptr){
            node->_data = node->_right->_data;
            delete node->_right;
            node->_right == nullptr;
          } else if(node->_right == nullptr){
              node->_data = node->_left->_data;
              delete node->_left;
              node->_left == nullptr;    
          } else {
              Node *temp = findMin(node->_right);  
              
          }
      }
      
      
      return node;      
    }
    
    void inOrderTraversal(Node *node){
      if(node == nullptr){
        return;      
      }
      
      inOrderTraversal(node->_left);
      std::cout << node->_data << " ";
      inOrderTraversal(node->_right);
    }
    
    public :
      void insertNode(int val){
        _root = insertNode(_root, val);
      }
      
      void removeNode(int val){
        _root = removeNode(_root, val);
      }
      
      void inOrderTraversal(){
          inOrderTraversal(_root);
      }
    
};

int main()
{
    std::cout << "Hello World\n";
    
    BST bst;
    bst.insertNode(100);
    bst.insertNode(12);
    bst.insertNode(22);
    bst.insertNode(14);
    bst.insertNode(114);
    
    bst.inOrderTraversal();

    return 0;
}

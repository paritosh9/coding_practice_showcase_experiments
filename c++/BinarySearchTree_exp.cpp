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
      if(node == nullptr){
        return nullptr;
      }
      
      if(val < node->_data){
        node->_left = removeNode(node->_left , val);      
      } else if(val > node->_data){
          node->_right = removeNode(node->_right , val);            
      } else{
          if(node->_left == nullptr){
            Node* tmp = node->_right;
            delete node;
            return tmp;
          } else if(node->_right == nullptr){
              Node* tmp = node->_left;
              delete node;
              return tmp;    
          }
      
          Node *tmp = findMin(node->_right); 
          node->_data = tmp->_data;
          node->_right = removeNode(node->_right, tmp->_data);
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
          std::cout<<std::endl;
      }
    
};

int main()
{
    std::cout << "Hello World\n";
    
    BST bst;
    bst.insertNode(50);
    bst.insertNode(30);
    bst.insertNode(70);
    bst.insertNode(20);
    bst.insertNode(40);
    bst.insertNode(60);
    bst.insertNode(80);
    
    std::cout << "Inorder traversal: ";
    bst.inOrderTraversal();
    
    bst.removeNode(30);
    std::cout << "Inorder traversal after removing 30: ";
    bst.inOrderTraversal();

    return 0;
}

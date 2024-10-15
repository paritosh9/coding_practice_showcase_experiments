#include <iostream>

class Node{
  private :

  public :
    int _data;
    Node *_left = nullptr;
    Node *_right = nullptr;
    
    Node(int data) : _data(data){
      //std::cout << "created node with data : " << _data << std::endl;
    }
  
};

class BST{
  private :
    Node *_root = nullptr;
    
    Node* insertNodeRecursive(Node* node, int data){
      if(node == nullptr){
        return new Node(data);      
      }
      if(data <= node->_data){
        node->_left = insertNodeRecursive(node->_left, data);
      }else{
        node->_right = insertNodeRecursive(node->_right, data);
      }
      std::cout << "inserting data : " << data << std::endl;
      return node;
    }
    
    void printInOrderTraversal(Node *node){
      if(node == nullptr){
        return;     
      }  
      printInOrderTraversal(node->_left);
      std::cout << node->_data << " " ;
      printInOrderTraversal(node->_right); 
    }
    
    Node* removeNodeRecursive(Node* node, int data){
      if(node == nullptr){
        return nullptr;
      }
      std::cout << "removing \n";
      if(data < node->_data){
        node->_left = removeNodeRecursive(node->_left, data);      
      }else if(data > node->_data){
        node->_right = removeNodeRecursive(node->_right, data);      
      }else{
        if(node->_left == nullptr){
          Node *tmp = node->_right;
          delete node;
          //node->_right = nullptr;
          return tmp;
        }else if(node->_right == nullptr){
          Node *tmp = node->_left;
          delete node;
          //node->_left = nullptr;
          return tmp;
        }else{
          Node *inOrderSuccesorNode = findMin(node->_right);
          node->_data = inOrderSuccesorNode->_data;;
          node->_right = removeNodeRecursive(node->_right, inOrderSuccesorNode->_data);
        }
      }
      
      return node;
        
    }
  
  public :
    void insertNode(int data){
      if(_root == nullptr){
        _root = new Node(data);
        return;
      }
      _root = insertNodeRecursive(_root, data);          
    }
    
    Node* findMin(Node *node){
      while(node->_left != nullptr){
        node = node->_left;      
      }
      return node;
    }
    
    // if root is nullptr, nothing to remove
    // start from root and go left if data less than root data or else go right
    // do that till you find data 
    // replace data with inorder successor, which is smallest element in right subtree of data 
    // replace data with inorder successor & call removeNode on inordersuccessor data from the right subtree if removed data has 2 children
    // continue this till element has no children
    // if no children , delete that node but have to make previous node point to null 
    // if one child , replace it with that child and delete child and make it point to nullptr
    void removeNode(int data){
      if(_root == nullptr){
        std::cout << "Nothing to remove\n";
        return;
      }
      _root = removeNodeRecursive(_root, data);
    }
    
    void printInOrderTraversal(){
      if(_root == nullptr){
        return;     
      }
      Node* node = _root;
      printInOrderTraversal(node);
      std::cout << std::endl;
    }
  
};


int main()
{
    std::cout<<"Hello World\n";
    
    BST bst;
    bst.insertNode(100);
    bst.insertNode(50);
    bst.insertNode(120);
    bst.insertNode(40);
    bst.insertNode(70);
    bst.insertNode(110);
    bst.insertNode(130);
    
    bst.printInOrderTraversal();
    
    //bst.removeNode(70);
    bst.removeNode(100);
    bst.printInOrderTraversal();
    
    bst.removeNode(1000);
    bst.printInOrderTraversal();

    return 0;
}

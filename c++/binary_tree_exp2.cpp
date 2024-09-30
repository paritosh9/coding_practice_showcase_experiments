#include <iostream>
#include <queue>
#include <stack>

template<typename T>
class Node {
  public:
    T _data;
    Node* _left;
    Node* _right;

    Node(T data):_data(data), _left(nullptr), _right(nullptr){}
    
};

template<typename T>
class BinaryTree {
  public:
    Node<T>* _root;
    BinaryTree(): _root(nullptr){}
    
    void insertNode(T value){
      if(_root == nullptr){
          _root = new Node<T>(value);
          return ;
      } 
      
      std::queue<Node<T>*> q;
      q.push(_root);
      while(!q.empty()){
        Node<T> *node = q.front();
        q.pop();
        if((value <= node->_data)){
            if(node->_left){
              q.push(node->_left);
              continue;
            } else {
                Node<T>* newNode = new Node<T>(value);
                node->_left = newNode;
                return;    
            }
        }
        if((value > node->_data)) {
            if(node->_right){
              q.push(node->_right);
              continue;
            } else {
                Node<T>* newNode = new Node<T>(value);
                node->_right = newNode;
                return;    
            }
        }
      }
      return;
    }
    
    void level_order_traversal_printTree(){
      if(_root == nullptr){
          std::cout <<"binary treee empty\n";
          return ;
      }
      std::queue<Node<T>*> q;
      q.push(_root);
      while(!q.empty()){
        Node<T> *node = q.front();
        std::cout << " " << node->_data << " " ;
        if(node->_left){
          q.push(node->_left) ;
        }
        if(node->_right){
          q.push(node->_right) ;
        }
        q.pop();  
      }
    }
    
    void inorder_traversal_iterative_printTree(){
      if(_root == nullptr){
          std::cout <<"binary treee empty\n";
          return ;
      }
      std::stack<Node<T>*> stk;
      Node<T>* node = _root;
      while(node || !stk.empty()){
        
        while(node){
          stk.push(node);
          node = node->_left;
        }
        node = stk.top();
        std::cout << " " << node->_data << " ";
        
        stk.pop();
        node = node->_right;
      }
    }    
    
    void inorder_traversal_recursive_printTree(Node<T>* curr){
        //std::cout << "in inorder_traversal_recursive_printTree\n";
        if(_root == nullptr){
          std::cout <<"binary treee empty\n";
          return ;
        }
        
        if(curr == nullptr){
          //std::cout << " " << curr->_data << " ";
          return;
        }
        
        inorder_traversal_recursive_printTree(curr->_left);
        std::cout << " " << curr->_data << " ";
        inorder_traversal_recursive_printTree(curr->_right);
        
    }
        
    void preorder_traversal_printTree();
    void postorder_traversal_printTree();
    
    void deleteNode(T value);
    
};

int main()
{
    std::cout<<"Hello World\n";

    BinaryTree<int> binary_tree;
    binary_tree.insertNode(121);
    binary_tree.insertNode(21);
    binary_tree.insertNode(133);
    binary_tree.insertNode(4);
    binary_tree.insertNode(12);
    binary_tree.insertNode(74);
    binary_tree.insertNode(55);
    binary_tree.insertNode(124);
    binary_tree.insertNode(188);
    
    std::cout << "level order : ";
    binary_tree.level_order_traversal_printTree();
    
    std::cout << "\n \nin order iterative : ";
    binary_tree.inorder_traversal_iterative_printTree();
    
    std::cout << "\n \nin order recursive : ";
    binary_tree.inorder_traversal_recursive_printTree(binary_tree._root);
    
    
    return 0;
}

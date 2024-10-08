#include <iostream>
#include <queue>

//template<typename T>
struct Node{
    int _data;
    Node* _left = nullptr;
    Node* _right = nullptr;
    
    //Node(int data, Node* left, Node* right):_data(data),_left(left), _right(right){}
    Node(int data):_data(data) {}
};

class BST{
    private:
      //Node* _root = nullptr;
    
    public:
      Node* _root = nullptr;
      
      BST(Node* root, int data):_root(root){
        if(_root == nullptr){
            Node* node = new Node(data);
            _root = node;
        }  
      }
      
      void insert(int data){
        if(_root == nullptr){
          Node* node = new Node(data);
          _root = node;  
        } else{
            Node* tmp = _root;
            while(tmp){
                if(tmp->_data >= data){
                    if(tmp->_left){
                        tmp = tmp->_left;
                    }else{
                      Node* node = new Node(data);
                      tmp->_left = node;
                      return;
                    }
                }else{
                    if(tmp->_right){
                        tmp = tmp->_right;
                    }else{
                       Node* node = new Node(data);
                       tmp->_right = node; 
                       return;
                    }
                }
            }
        } 
      }
      
      Node* findMin(Node* node){
          Node* prev_node = node;
          node = node->_right;
          while(node->_left != nullptr){
            prev_node = node;
            node = node->_left;
          }
          return prev_node;
      }
      
      //WIP
      /*void remov(int data){
        Node* tmp = _root;
        Node* prev_node = nullptr;
        
        while(tmp != nullptr){
          if(data == tmp->_data){
            if(tmp->_left == nullptr && tmp->_right == nullptr){
                delete tmp;
                if(prev_node) prev_node->_left = nullptr;
                return;
            }
            if(tmp->_left != nullptr){
                if(prev_node) prev_node->_left = tmp->_left;
                delete tmp;
                return;
            }
            if(tmp->_right != nullptr){
                if(prev_node) prev_node->_right = tmp->_right;
                delete tmp;
                return;
            }
            Node* find_replacement_inorder_succsr = findMin(tmp);
            tmp->_data = find_replacement_inorder_succsr->_left->_data;
            delete find_replacement_inorder_succsr->_left;
            find_replacement_inorder_succsr->_left = nullptr;
            return;
          }else if(data < tmp->_data){
            prev_node = tmp;
            tmp = tmp->_left;      
          }else if(data > tmp->_data){
            prev_node = tmp;
            tmp = tmp->_right;
          }
        }  
      }*/

      void inorder(Node *node){
        
        if(node == nullptr){
            return;
        }
        inorder(node->_left);
        std::cout << node->_data << " ";
        inorder(node->_right);
        
      }

      void preorder(Node* node){
        if(node == nullptr){
            return;
        }
        std::cout << node->_data << " ";
        preorder(node->_left);
        preorder(node->_right);
        
      }

      void postorder(Node* node){
        if(node == nullptr){
            return;
        }
        postorder(node->_left);
        postorder(node->_right);
        std::cout << node->_data << " ";
      }

      void level_order(Node* node){
        std::queue<Node*> tmpq;
        tmpq.push(node);
        while(!tmpq.empty()){
            //std::cout << "here1\n";
          Node* tmp = tmpq.front();
          if(tmp->_left != nullptr) tmpq.push(tmp->_left);
          if(tmp->_right != nullptr) tmpq.push(tmp->_right);
          std::cout << tmp->_data << " ";
          tmpq.pop();
        }
      }
      
};

int main()
{
    std::cout<<"Hello World\n";
    
    /*Node *root = new Node(50);
    Node *left = new Node(40);*/
    Node* root = nullptr;
    BST *bst = new BST(root, 50);
    bst->insert(40);
    bst->insert(60);
    bst->insert(30);
    bst->insert(65);
    bst->insert(55);
    bst->insert(45);
    bst->insert(70);
    bst->insert(15);
    bst->insert(35);
    bst->insert(63);
    
    bst->inorder(bst->_root);
    std::cout << std::endl;
    
    bst->preorder(bst->_root);
    std::cout << std::endl;
    
    bst->postorder(bst->_root);
    std::cout << std::endl;
    
    bst->level_order(bst->_root);
    std::cout << std::endl;
    
    /*bst->remov(55);
    bst->remov(40);
    std::cout << std::endl;
    
    bst->inorder(bst->_root);
    std::cout << std::endl;
    
    bst->preorder(bst->_root);
    std::cout << std::endl;
    
    bst->postorder(bst->_root);
    std::cout << std::endl;
    
    bst->level_order(bst->_root);
    std::cout << std::endl;*/
    
    return 0;
}

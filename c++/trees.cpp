
#include <iostream>
#include <vector>

using namespace std;

class Node{
        public :
            int _data;
            vector<Node*> _children;
            
            Node(int data) : _data(data){}
            
            void addChildren(Node *child){
                if(child == nullptr){
                    cout << "child is NULL" << endl;
                    return;
                }
                
                this->_children.push_back(child);
                return;
            }
            
            void printChildren(Node *node){
                if(node == nullptr){
                    cout << "node is NULL" << endl;
                    return;    
                }    
                
                for(auto i : node->_children){
                    cout << i->_data <<  " ";
                }
            }
            
            void printParents(){
                
            }
            
            void printLeafNodes(Node *node){
                
            }
    };
    
int main() {
    // Write C++ code here
    // tree
    Node *root = new Node(2);
    Node *n2 = new Node(4);
    Node *n3 = new Node(1);
    Node *n4 = new Node(11);
    Node *n5 = new Node(24);
    
    root->addChildren(n2);
    root->addChildren(n3);
    root->addChildren(n4);
    root->addChildren(n5);
    
    root->printChildren(root);
    
    return 0;
}

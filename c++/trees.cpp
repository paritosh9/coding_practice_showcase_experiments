#include <iostream>
#include <vector>

using namespace std;

class Node {
  public : 
    int _data;
    Node *left;
    Node *right;
    
    Node(int data) : _data(data){
        left = nullptr;
        right = nullptr;
    }
    
    void inOrder(Node *node, vector<int> &result){
        if(node == nullptr){
            return;
        }
        
        inOrder(node->left, result);
        result.push_back(node->_data);
        inOrder(node->right, result);
        
    }
    
    void preOrder(Node *node, vector<int> &result){
        if(node == nullptr){
            return;
        }
        
        result.push_back(node->_data);
        preOrder(node->left, result);
        preOrder(node->right, result);
        
    }
    
    void postOrder(Node *node, vector<int> &result){
        if(node == nullptr){
            return;
        }
        
        postOrder(node->left, result);
        postOrder(node->right, result);
        result.push_back(node->_data);
        
    }
    
};

int main() {
    
    Node *root = new Node(1);
    root->left = new Node(22);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    
    vector<int> result;
    root->inOrder(root, result);
    cout << "inOrder ... " << endl;
    for(int i : result){
        cout << i << " ";
    }
    
    result = {};
    root->preOrder(root, result);
    cout << endl << "preOrder ... " << endl;
    for(int i : result){
        cout << i << " ";
    }
    
    result = {};
    root->postOrder(root, result);
    cout << endl << "postOrder ... " << endl;
    for(int i : result){
        cout << i << " ";
    }
    
    cout << endl;
    

    return 0;
}

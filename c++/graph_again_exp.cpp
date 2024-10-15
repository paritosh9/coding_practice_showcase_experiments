#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <queue>

class Node{
  private :
  
  public : 
    int _data;
    Node(int data) : _data(data){};
  
};

class Edge{
  private :
  
  public :
    int _weight;
    Node *_dst;
    Node *_src;
    
    Edge(int weight, Node* dst, Node* src) : _weight(weight), _dst(dst), _src(src){};
    
};

class Graph{
  private :
  std::set<Node*> _visited_nodes;
  
  public :
    std::unordered_map<Node*, std::vector<Node*>> _adj_list;
    
    void addNode(Node* node){
      if(_adj_list.find(node) == _adj_list.end()){
        _adj_list[node] = {};      
      }    
    }
    
    bool addEdge(Node *src, Node *dst){
      if(src == nullptr || dst == nullptr){
        std::cout << "src dst need to be valid nodes to add edge\n"; 
        return 0;
      }   
      _adj_list[src].push_back(dst);
      return 1;
    }
    
    void removeNode(Node* node);
    void removeEdge(Node *src, Node *dst);
    
    void printGraph(){
      std::cout << "Printing Graph\n";
      
      for(auto i : _adj_list){
        std::cout << i.first->_data << " : ";
        for(auto j : i.second){
          std::cout << j->_data << " " ;   
        }
        std::cout << std::endl;
      }
    }
    
    //store adjacent nodes in queue and pop from it to traverse
    //need to keep track of visited nodes 
    void bfs(Node *node){
      std::queue<Node*> q;
      q.push(node);
      _visited_nodes.insert(node);
      while(!q.empty()){
        Node* temp = q.front();
        std::cout << temp->_data << " ";
        for(auto i : _adj_list[temp]){
          if(_visited_nodes.find(i) == _visited_nodes.end()){
            //std::cout << "pushing : " << i->_data << std::endl;
            q.push(i);
            _visited_nodes.insert(i);
          }
        }
        q.pop();
      }
      std::cout << std::endl;
    }
    
    
    void dfs(Node *node);
    
};

int main()
{
    std::cout<<"Hello World\n";
    
    Graph graph;
    Node *n0 = new Node(0);
    graph.addNode(n0);
    Node *n1 = new Node(1);
    graph.addNode(n1);
    Node *n2 = new Node(2);
    graph.addNode(n2);
    Node *n3 = new Node(3);
    graph.addNode(n3);
    Node *n4 = new Node(4);
    graph.addNode(n4);
    
    graph.addEdge(n0,n1);
    graph.addEdge(n0,n2);
    graph.addEdge(n1,n2);
    graph.addEdge(n1,n3);
    graph.addEdge(n2,n3);
    graph.addEdge(n3,n0);
    graph.addEdge(n1,n4);
    
    graph.printGraph();
    
    graph.bfs(n3);
    
    return 0;
}

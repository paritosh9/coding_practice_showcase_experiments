#include <iostream>
#include <unordered_map>
#include <vector>

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
  
  public :
    std::unordered_map<Node*, std::vector<Node*>> adj_list;
    
    void addNode(Node* node){
      if(adj_list.find(node) == adj_list.end()){
        adj_list[node] = {};      
      }    
    }
    
    bool addEdge(Node *src, Node *dst){
      if(src == nullptr || dst == nullptr){
        std::cout << "src dst need to be valid nodes to add edge\n"; 
        return 0;
      }   
      adj_list[src].push_back(dst);
      return 1;
    }
    
    void removeNode(Node* node);
    void removeEdge(Node *src, Node *dst);
    
    void printGraph(){
      std::cout << "Printing Graph\n";
      
      for(auto i : adj_list){
        std::cout << i.first->_data << " : ";
        for(auto j : i.second){
          std::cout << j->_data << " " ;   
        }
        std::cout << std::endl;
      }
    }
    
    void bfs(Node *node);
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
    
    graph.addEdge(n0,n1);
    graph.addEdge(n0,n2);
    graph.addEdge(n1,n2);
    graph.addEdge(n1,n3);
    graph.addEdge(n2,n3);
    graph.addEdge(n3,n0);
    
    graph.printGraph();
    
    return 0;
}

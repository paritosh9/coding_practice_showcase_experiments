#include <iostream>
#include <vector>
#include <unordered_map>

class Node{
  private :
    //int _value;
    
  public :
    int _value;
    Node(int value) : _value(value){}
    int get_value(){
        return _value;
    }
};

class Edge{
  private : 
    //Node *_src, *_dst;
    //int _weight;
    
  public :
    Node *_src, *_dst;
    int _weight;
    Edge(Node *src, Node *dst, int weight) : _src(src), _dst(dst), _weight(weight) {
    }
};

class Graph{
  private :
    std::unordered_map<Node*, std::vector<Edge*>> _adj_list;
    
  public :
    void addNode(Node *node){
      if(_adj_list.find(node) == _adj_list.end()){
        _adj_list[node] = {}; 
      }
    }
    
    /*void addEdge(Edge *edge){
          
    }*/
    
    void addEdge(Node *src, Node *dst, int weight){
      Edge *edge = new Edge(src, dst, weight);
      _adj_list[src].push_back(edge);  
    }
    
    void printGraph(){
      for(auto i : _adj_list) {
        std::cout << i.first->get_value() << " : ";
        for(auto j : i.second){
          std::cout << j->_dst->_value << " ," << "weight - " << j->_weight << " ";      
        }
        std::cout << std::endl;
      }
      std::cout << std::endl;
    }
    
};


int main()
{
    std::cout<<"Hello World\n";
    
    Node *node0 = new Node(0);
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    
    Graph graph;
    graph.addNode(node0);
    graph.addNode(node1);
    graph.addNode(node2);
    graph.addNode(node3);
    
    graph.printGraph();
    
    graph.addEdge(node0, node1, 1);
    graph.addEdge(node0, node2, 2);
    graph.addEdge(node1, node2, 3);
    graph.addEdge(node1, node3, 4);
    graph.addEdge(node2, node3, 5);
    graph.addEdge(node3, node1, 6);
    
    
    graph.printGraph();

    return 0;
}

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

class Node{
  private :
    //int _data;
    
  public :
    int _data;
    Node(int data):_data(data){
      std::cout <<"Node constructor with data : " << _data << std::endl;
    };
};

class Edge{
  private :
    Node *_src, *_dst;
    //int _weight;
  
  public :
    int _weight;
    Edge(Node *src, Node *dst, int weight):_src(src), _dst(dst), _weight(weight){
      std::cout <<"Edge constructor with src : " << src->_data << " dst : " << dst->_data << " weight : " << _weight << std::endl;    
    }
    
    int getEdgeWeight(){
      return _weight;
    }
    
    std::pair<Node*, Node*> getPair(){
      return std::make_pair(_src,_dst);
    }
  
};

class Graph{
  private : 
    std::unordered_map<Node*, std::vector<Node*>> _adj_list;
    std::vector<std::vector<int>> _weights_adj_list;
    //std::fill(_weights_adj_list.start(), _weights_adj_list.end(), 1000);
    std::set<Node*> _visited_nodes{};
    std::unordered_map<Node*, int> _shortest_paths_dist;
    std::vector<Node*> _shortest_path_route;
    
    std::map<std::pair<Node*, Node*>,int> _edgeWeights; 

  public :
    Graph(int nodes){
        std::cout << "constructing empty graph\n";
    }
    
    void addNode(Node *node){
      if(_adj_list.find(node) == _adj_list.end()){
        _adj_list[node] = {};      
      }    
    }
    
    void addEdge(Edge *e){
      std::cout << "Adding edge with weight : " << e->getEdgeWeight() << std::endl;
      _edgeWeights[e->getPair()] = e->getEdgeWeight();
      _adj_list[e->getPair().first].push_back(e->getPair().second);
    }
    
    void printGraph(){
      for(auto i : _adj_list){
        std::cout << i.first->_data << " : ";
        for(auto j : i.second){
          std::cout << j->_data << " ";      
        }    
        std::cout << std::endl;
      }
      std::cout << std::endl;
    }
    
    // willl start from Node *node 
    // will visit neighbouring nodes and store distances from node to them in _shortest_paths_dist
    // will select shortest adjacent node as next node
    // will check its neighbouring nodes and update _shortest_paths_dist if any calculated distances less than earlier
    // will select closest neighbour and continue above
    // will add nodes to _visited_nodes as we move, and when _visited_nodes == number of nodes in _graph will stop
    // will print _shortest_paths_dist and _shortest_path_route
    void djikstra(Node *node){
      std::cout << "in djikstra\n";
      
      int  size = _adj_list.size();
      std::cout << "size : " <<size <<std::endl;
      
      std::vector<int> v1;
      for(int i = 0; i < size ; i++){
          v1.push_back(1000);    
      }
      for(int i = 0; i < size ; i++){
          _weights_adj_list.push_back(v1);    
      } 
      
      std::cout << "before while loop\n";
      for(auto i : _adj_list){
        _shortest_paths_dist[i.first] = 1000;       
      }
      
      _shortest_path_route.push_back(node);
      
      int smallest_weight = 1000;
      
      while(_visited_nodes.size() < _adj_list.size()){
        std::cout << "inside while loop\n";
        std::cout << _visited_nodes.size() << " " << _adj_list.size() << std::endl;
        _visited_nodes.insert(node);
        for(auto neighbour : _adj_list[node]){
          if(_shortest_paths_dist[neighbour] > _shortest_paths_dist[node] + _edgeWeights[std::make_pair(node, neighbour)]){
            _shortest_paths_dist[neighbour] = _shortest_paths_dist[node] + _edgeWeights[std::make_pair(node, neighbour)];        
          }
          if((smallest_weight > _edgeWeights[std::make_pair(node, neighbour)]) && _visited_nodes.find(neighbour) == _visited_nodes.end()){
            node = neighbour;
            smallest_weight = _edgeWeights[std::make_pair(node, neighbour)];
          }
        }
        _shortest_path_route.push_back(node);
      }
       
      for(auto i : _shortest_paths_dist){
        std::cout << "Node : " << i.first->_data << " , shortest path weight : " << i.second << std::endl;    
      }
    
      for(auto i : _shortest_path_route) {
        std::cout << "Shortest route : " << i << " "  ;  
      }
      std::cout << std::endl;
    }
    

};

int main()
{
    std::cout<<"Hello World\n";
    
    Graph graph(6);
    Node *n0 = new Node(0);
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    
    graph.addNode(n0);
    graph.addNode(n1);
    graph.addNode(n2);
    graph.addNode(n3);
    graph.addNode(n4);
    graph.addNode(n5);
    
    Edge *e0 = new Edge(n0,n1,5);
    Edge *e1 = new Edge(n0,n2,15);
    Edge *e2 = new Edge(n0,n3,4);
    Edge *e3 = new Edge(n1,n2,52);
    Edge *e4 = new Edge(n1,n4,7);
    Edge *e5 = new Edge(n1,n5,9);
    Edge *e6 = new Edge(n2,n4,11);
    Edge *e7 = new Edge(n3,n5,5);
    Edge *e8 = new Edge(n4,n5,14);
    //Edge *e9 = new Edge(n5,n1,22);
    //Edge *e10 = new Edge(n4,n1,15);
    
    graph.addEdge(e0);
    graph.addEdge(e1);
    graph.addEdge(e2);
    graph.addEdge(e3);
    graph.addEdge(e4);
    graph.addEdge(e5);
    graph.addEdge(e6);
    graph.addEdge(e7);
    graph.addEdge(e8);
    //graph.addEdge(e9);
    //graph.addEdge(e10);
    
    graph.djikstra(n0);
    
    graph.printGraph();

    return 0;
}

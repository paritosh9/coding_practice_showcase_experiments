#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <pair>
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
    
  
};

class Graph{
  private : 
    std::unordered_map<Node*, std::vector<Node*>> _adj_list;
    std::vector<std::vector<int>> _weights_adj_list;
    //std::fill(_weights_adj_list.start(), _weights_adj_list.end(), 1000);
    std::set<Node*> _visited_nodes;
    std::unordered_map<Node*, int> _shortest_paths_dist;
    std::vector<Node*> _shortest_path_route;
    
    std::map<std::pair<Node*, Node*>>,int> edgeWeights; 

  public :
  
    void addNode(Node *node){
      //if()    
    };
    
    void addEdge(){
        
      edgeWeights[make_pair(src,dst)] = weight;
    }
    
    void printGraph();
    
    // willl start from Node *node 
    // will visit neighbouring nodes and store distances from node to them in _shortest_paths_dist
    // will select shortest adjacent node as next node
    // will check its neighbouring nodes and update _shortest_paths_dist if any calculated distances less than earlier
    // will select closest neighbour and continue above
    // will add nodes to _visited_nodes as we move, and when _visited_nodes == number of nodes in _graph will stop
    // will print _shortest_paths_dist and _shortest_path_route
    void djikstra(Node *node){
      int  size = _adj_list.size();
      for(int i = 0; i < size ; i++){
        for(int j = 0; j < size ; j++){
          _weights_adj_list[i][j] = 1000;    
        }      
      }  
      
      for(auto i : _adj_list){
        _shortest_paths_dist[i.first] = 1000;       
      }
      
      _shortest_path_route.push_back(node);
      
      while(_visited_nodes.size() < _adj_list.size()){
        _visited_nodes.insert(node);
        for(auto neighbour : _adj_list[node]){
          if(_shortest_paths_dist[neighbour] > _shortest_paths_dist[node] + edgeWeight(node, neighbour) ){
            _shortest_paths_dist[neighbour] = _shortest_paths_dist[node] + edgeWeight(node, neighbour);        
          }
          if(smallest_weight > edgeWeight(node, neighbour)){
            node = neighbour;
          }
          _shortest_path_route.push_back(node);
        }
       }
};

int main()
{
    std::cout<<"Hello World\n";
    
    Graph graph;
    Node *n0 = new Node(0);
    /*graph.addNode(n0);
    graph.addNode(n1);
    graph.addNode(n2);
    graph.addNode(n3);
    graph.addNode(n4);
    graph.addNode(n5);
    
    graph.addEdge(n0,n1,5);
    graph.addEdge(n0,n2,15);
    graph.addEdge(n0,n3,4);
    graph.addEdge(n1,n2,52);
    graph.addEdge(n1,n4,7);
    graph.addEdge(n1,n5,9);
    graph.addEdge(n2,n4,11);
    graph.addEdge(n3,n5,5);
    graph.addEdge(n4,n5,14);
    graph.addEdge(n5,n1,22);
    graph.addEdge(n4,n1,15);*/
    
    graph.djikstra(n0);
    

    return 0;
}

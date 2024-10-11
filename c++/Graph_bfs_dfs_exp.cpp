#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>

class Graph{
  private :
    std::unordered_map<int, std::vector<int>> _adj_list;
    std::set<int> _visited_nodes;
  
  public :
    Graph(int nodes) {
      while(nodes > 0){
        _adj_list[nodes-1] = {};
        nodes--;
      }    
    }
    
    void addNode(int node){
      if(_adj_list.find(node) != _adj_list.end()){
          return;
      } else{
          _adj_list[node] = {};  
      }        
    }
    
    bool addEdge(int src, int dst){
      if(_adj_list.find(src) == _adj_list.end()){
        std::cout << "src node doesnt exist" << std::endl;  
        return 0;
      } else{
          if(std::find(_adj_list[src].begin(), _adj_list[src].end(), dst) == _adj_list[src].end()){
            _adj_list[src].push_back(dst);
            //_adj_list[dst].push_back(src); for bidirectional graphs
          }
      }
      return 1;
    }
    
    void rmNode(int node);
    void rmEdge(int src , int dst);
    
    void printGraph(){
      for(auto i : _adj_list){
        std::cout << i.first << " : " ;
        for(auto j : i.second){
          std::cout << j << " " ;      
        }
        std::cout<<std::endl;
      }
      std::cout<<std::endl;
    }
    
    void BFS(int node){
      std::cout << "Printing BFS : ";
      std::queue<int> q;    
      q.push(node);
     
      _visited_nodes.insert(node);
      while(!q.empty()){
        int curr_node = q.front();
        q.pop();
        std::cout << curr_node << " ";
        
        for(auto i : _adj_list[curr_node]){
          if(_visited_nodes.find(i) == _visited_nodes.end()){
            _visited_nodes.insert(i);
            q.push(i);
          }
        }
      }
      std::cout << std::endl;
      _visited_nodes.clear();
    }
    
    /*void DFS_recurs(int node){
      std::cout << node << " ";
      _visited_nodes.insert(node);
      
      for(auto i : _adj_list[node]){
        if(_visited_nodes.find(i) == _visited_nodes.end()){
          _visited_nodes.insert(i);
          DFS_recurs(i);
        }      
      }
    }
    
    void DFS(int node){
      std::cout << "Printing DFS : ";
      DFS_recurs(node);
      std::cout << std::endl;
      _visited_nodes.clear();
    }*/
    
    void DFS(int node){
      std::cout << "Printing DFS : ";
      std::stack<int> s;
      s.push(node);
      
      while(!s.empty()){
        int curr_node = s.top();
        s.pop();
        
        if(_visited_nodes.find(curr_node) == _visited_nodes.end()){
          _visited_nodes.insert(curr_node);    
          std::cout << curr_node << " ";
          for(auto i : _adj_list[curr_node]){
            if(_visited_nodes.find(i) == _visited_nodes.end()){
              s.push(i);
            }
          }  
        }
        
      }
      std::cout << std::endl;
      _visited_nodes.clear();  
    }
  
};

int main()
{
    std::cout<<"Hello World\n";
    
    Graph graph(4);
    graph.printGraph();
    
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(2,3);
    graph.addEdge(1,3);
    graph.addEdge(3,0);
    
    graph.printGraph();
    graph.BFS(1);
    graph.DFS(1);
    
    graph.addNode(4);
    graph.addEdge(0,4);
    graph.addEdge(4,2);
    graph.addEdge(4,3);
    
    graph.printGraph();
    
    graph.BFS(0);
    graph.DFS(0);
    
    return 0;
}

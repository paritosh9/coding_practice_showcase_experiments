#include <iostream>
#include <vector>
#include <list>

class graph{
  private :
    int _vertices;
    std::vector<std::list<int>> _adj_list;
    
  public :
    graph(int V) : _vertices(V), _adj_list(V){}
    
    void addEdge(int u, int v){
      _adj_list[u].push_back(v);
      //_adj_list[v].push_back(u);
    }
    
    void print_graph(){
        for(int i = 0; i < _vertices; i++){
            std::cout << i << " : ";
            for(auto j : _adj_list[i]){
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    std::cout<<"Hello World\n";
    
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    g.print_graph();
    
    std::cout << std::endl;

    return 0;
}

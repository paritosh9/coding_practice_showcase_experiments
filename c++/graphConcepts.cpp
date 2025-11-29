#include <iostream>
#include <vector>
using namespace std;

class graph{
  private :
    int _vertices;
    vector<vector<int>> _adj_matrix;
    
  public :
    graph(int V) : _vertices(V), _adj_matrix(V,vector<int>(V)){}
    
    void addEdge(int u, int v){
      _adj_matrix[u][v] = 1;
      //_adj_list[v].push_back(u);
    }
    
    void printGraph(){
        for(int i = 0; i < _vertices; i++){
            cout << i << " : ";
            for(int j = 0; j < _vertices; j++){
                cout << _adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    cout<<"Hello World\n";
    
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    g.printGraph();
    
    cout << std::endl;

    return 0;
}


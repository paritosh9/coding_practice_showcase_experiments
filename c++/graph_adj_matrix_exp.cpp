class graph{
  private :
    int _vertices;
    std::vector<std::vector<int>> _adj_matrix;
    
  public :
    graph(int V) : _vertices(V), _adj_matrix(V,std::vector<int>(V)){}
    
    void addEdge(int u, int v){
      _adj_matrix[u][v] = 1;
      //_adj_list[v].push_back(u);
    }
    
    void print_graph(){
        for(int i = 0; i < _vertices; i++){
            std::cout << i << " : ";
            for(int j = 0; j < _vertices; j++){
                std::cout << _adj_matrix[i][j] << " ";
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

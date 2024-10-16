#include <iostream>

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
    int _weight;
  
  public :
    Edge(Node *src, Node *dst, int weight):_src(src), _dst(dst), _weight(weight){
      std::cout <<"Edge constructor with src : " << src->_data << " dst : " << dst->_data << " weight : " << _weight << std::endl;    
    }
  
};

class Graph{
  private :     

  public :
  
    void addNode();
    
    void addEdge();
    
    void printGraph();
    
    void djikstra(){
        
    }
};

int main()
{
    std::cout<<"Hello World\n";
    
    Graph graph;
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
    
    graph.djikstra();
    

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph{
    private :
        vector<vector<int>> _adjListGraph;
        int _nodeCnt;
        bool undirected = true;
    
    public :
        Graph(int nodeCnt) : _nodeCnt(nodeCnt){
            cout << "constructing Graph " << endl;
            _adjListGraph.assign(nodeCnt, {});
        }
        
        ~Graph(){
            cout << "destructing Graph " << endl;    
        }
        
        void setDirectedGraph(){
            undirected = false;
        }
        
        void addEdge(int src, int dst){
            _adjListGraph[src].push_back(dst);
            if(undirected){
                _adjListGraph[dst].push_back(src);
            }
        }
        
        void removeEdge(int src, int dst){
            _adjListGraph[src].erase(find(_adjListGraph[src].begin(), _adjListGraph[src].end(), dst));  
            if(undirected){
                _adjListGraph[dst].erase(find(_adjListGraph[dst].begin(), _adjListGraph[dst].end(), src));    
            }
        }
        
        void printGraph(){
            for(int i=0; i<_adjListGraph.size(); i++){
                for(auto neighbors : _adjListGraph[i]){
                    cout << neighbors << " ";
                }
                cout << endl;
            }    
        }
        
        void bfs(){
            
        }

};

int main() {
    // Write C++ code here
    // graph adjacency list
    int nodeCnt = 7;
    Graph graph(nodeCnt);
    
    graph.addEdge(0,1);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(4,5);
    graph.addEdge(3,4);
    graph.addEdge(5,6);
    
    graph.printGraph();
    
    graph.bfs();
    
    return 0;
}

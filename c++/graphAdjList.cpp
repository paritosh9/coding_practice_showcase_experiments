#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

class Graph{
    private :
        vector<vector<pair<int,int>>> _adjListGraph;
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
        
        void addEdge(int src, int dst, int wt){
            _adjListGraph[src].push_back({dst,wt});
            if(undirected){
                _adjListGraph[dst].push_back({src,wt});
            }
        }
        
        void removeEdge(int src, int dst){
            for(auto it = _adjListGraph[src].begin(); it!=  _adjListGraph[src].end(); ++it){
                if(it->first == dst){
                    _adjListGraph[src].erase(it);    
                }
            }  
            if(undirected){
               for(auto it = _adjListGraph[dst].begin(); it!=  _adjListGraph[dst].end(); ++it){
                    if(it->first == src){
                        _adjListGraph[dst].erase(it);    
                    }
                }       
            }
        }
        
        void printGraph(){
            for(int i=0; i<_adjListGraph.size(); i++){
                for(auto neighbors : _adjListGraph[i]){
                    cout << neighbors.first << "," <<neighbors.second << " || " ;
                }
                cout << endl;
            }    
        }
        
        void bfs(int start){
            cout << "BFS - ";
            vector<bool> visited(_nodeCnt, false);
            queue<int> bfsQ;
            
            bfsQ.push(start);
            while(!bfsQ.empty()){
                int curr = bfsQ.front();
                if(visited[curr] == true){
                    bfsQ.pop();
                    continue;
                }
                bfsQ.pop();
                cout << curr << " ";
                visited[curr] = true;
                
                for(auto[node, wt] : _adjListGraph[curr]){
                    bfsQ.push(node);
                }
                
            }
            cout << endl;
        }

};

int main() {
    // Write C++ code here
    // graph adjacency list
    int nodeCnt = 7;
    Graph graph(nodeCnt);
    
    graph.addEdge(0,1,2);
    graph.addEdge(1,3,3);
    graph.addEdge(2,3,5);
    graph.addEdge(4,5,2);
    graph.addEdge(3,4,9);
    graph.addEdge(5,6,3);
    
    graph.printGraph();
    
    cout << endl;
    graph.bfs(0);
    
    return 0;
}

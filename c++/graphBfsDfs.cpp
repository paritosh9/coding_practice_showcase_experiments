#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Graph{
    private :
        vector<vector<int>> graph;
        int _nodeCnt;
    
    public:
        Graph(int nodeCnt) : _nodeCnt(nodeCnt), graph(nodeCnt, vector<int>(nodeCnt)){
            for(int i=0; i<nodeCnt; i++){
                for(int j=0; j<nodeCnt; j++){
                    if(i != j){
                        graph[i][j] = 0;    
                    }else{
                        graph[i][j] = 1;
                    }
                }
            }     
        }
        
        ~Graph(){
            cout << endl;
            cout << "in destructor "<< endl;
            for(int i=0; i<graph.size(); i++){
                graph[i].clear();    
            }
            graph.clear();
            this->printGraph();
        }
        
        void printGraph(){
            cout << endl;
            if(graph.empty()){
                cout << "graph empty "<< endl;
            }
            
            for(int i=0; i<graph.size(); i++){
                for(int j=0; j<graph[i].size(); j++){
                    cout << graph[i][j] << " ";
                }
                cout << endl;
            }
        }
        
        void addEdge(int src, int dst){
            graph[src][dst] = 1;
            graph[dst][src] = 1;
        }
        
        void removeEdge(int src, int dst){
            graph[src][dst] = 0;
            graph[dst][src] = 1;    
        }
        
        void bfs(){
            queue<int> bfsQ;
            vector<int> visited;
            
            cout << endl << " BFS graph traversal " << endl;
            for(int i=0; i<graph.size(); i++){
                if(find(visited.begin(), visited.end(), i) != visited.end()){
                    continue;
                }
                
                bfsQ.push(i);
                //visited.push_back(i);
                
                while(!bfsQ.empty()){
                   int node = bfsQ.front();
                   bfsQ.pop();
                   if(find(visited.begin(), visited.end(), node) != visited.end()){
                    continue;
                   }
                   visited.push_back(node);
                   cout << node << " ";
                   for(int j=0; j<graph[node].size(); j++){
                       if((node != j) && graph[node][j] == 1){
                           if(find(visited.begin(), visited.end(), j) == visited.end()){
                           bfsQ.push(j);
                           }
                       }
                   }
                }
            }
            
        }
        
        void dfs(){
            stack<int> dfsStack;
            vector<int> visited;
            
            cout << endl << "DFS graph traversal " << endl;
            for(int i=0; i<graph.size(); i++){
                if(find(visited.begin(), visited.end(), i) != visited.end()){
                    continue;
                }
                
                dfsStack.push(i);
                while(!dfsStack.empty()){
                    int node = dfsStack.top();
                    dfsStack.pop();
                    if(find(visited.begin(), visited.end(), node) != visited.end()){
                    continue;
                   }
                   cout << node << " ";
                   visited.push_back(node);
                    
                    for(int j=0; j<graph[node].size(); j++){
                        if(find(visited.begin(), visited.end(), j) != visited.end()){
                            continue;
                        }  
                        if((node != j) && graph[node][j] == 1){
                            dfsStack.push(j);
                        }
                    }
                
                }
            }
            
        }
        
        void hasCycle(){
            
        }
        
        void djikstra(){
            
        }
        
};

int main() {
    
    Graph *graph = new Graph(5);
    graph->printGraph();
    
    graph->addEdge(0,2);
    graph->addEdge(1,2);
    graph->addEdge(1,4);
    graph->addEdge(2,4);
    graph->addEdge(3,1);
    graph->addEdge(4,0);
    graph->addEdge(4,3);
    
    graph->printGraph();
    
    graph->bfs();
    graph->dfs();
    
    delete graph;

    return 0;
}

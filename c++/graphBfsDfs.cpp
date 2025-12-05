#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

class Graph{
    private :
        vector<vector<int>> graph;
        int _nodeCnt;
        
    
    public:
        vector<bool> visited;
        Graph(int nodeCnt) : _nodeCnt(nodeCnt), graph(nodeCnt, vector<int>(nodeCnt)){
            visited.assign(nodeCnt, false);
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
        
        void resetVisitedVec(){
            visited.assign(_nodeCnt, false);
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
        
        void addEdge(int src, int dst, int weight){
            graph[src][dst] = weight;
            graph[dst][src] = weight;
        }
        
        void removeEdge(int src, int dst){
            graph[src][dst] = 0;
            graph[dst][src] = 0;    
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
        
        void dfsRecursion(int src){//, vector<bool> &visited){
            cout << src << " ";
            visited[src] = true;
            
            for(int i=0; i<graph[src].size(); i++){
                if(!visited[i] && graph[src][i] != 0){
                    dfsRecursion(i);
                }
            }
            
        }
        
        bool dfsCycleDetection(int src , int parent, vector<bool> &visited){
            cout << src << " ";
            visited[src] = true;
            
            for(int i=0; i<graph[src].size(); i++){
                if(i == src) continue;
                if(graph[src][i] != 0 && !visited[i]){
                    if(dfsCycleDetection(i,src,visited)){
                        return true;
                    }
                } else if(graph[src][i] != 0 && i != parent){
                    cout <<endl << i << " " << src << endl;
                    return true;
                }    
            }
            
            return false;    
        }
        
        int hasCycle(vector<bool> &visited){
            cout <<endl << "in cycle detection" << endl;
            for(int i=0; i<graph.size(); i++){
                if(visited[i]){
                    continue;
                }
                
                if(dfsCycleDetection(i,-1,visited)){
                    cout << "cycle detected " << endl;
                    return 1;
                }
            }
            
            cout <<endl << " no cycle detected " << endl;
            return 0;
            
        
        }
        
        bool dfsCycleDetectionDirectedGraph(int src, vector<bool> &visited, vector<bool> &recursionVec){
            cout << src << " ";
            visited[src] = true;
            recursionVec[src] = true;
            
            for(int i=0; i<graph[src].size(); i++){
                if(i == src) continue;
                if(graph[src][i] != 0 && !visited[i]){
                    if(dfsCycleDetectionDirectedGraph(i,visited,recursionVec)){
                        return true;
                    }
                } else if(graph[src][i] != 0 && recursionVec[i] == true){
                    cout <<endl << i << " " << src << endl;
                    return true;
                }
            }
            
            return false;
            
        }
        
        int hasCycleDirectedGraph(vector<bool> &visited){
            cout <<endl << "in directed graph cycle detection" << endl;
            vector<bool> recursionVec(_nodeCnt, false);
            for(int i=0; i<graph.size(); i++){
                if(visited[i]){
                    continue;
                }
                
                if(dfsCycleDetectionDirectedGraph(i,visited,recursionVec)){
                    cout << "cycle detected in directed graph  " << endl;
                    return 1;
                }
                
                recursionVec.assign(_nodeCnt, false);
            }
            
            cout <<endl << " no cycle detected in directed graph " << endl;
            return 0;
            
        
        }
        
        vector<int> djikstra(int src){
            cout << "Running dijkstra ... " << endl;
            vector<int> dist(_nodeCnt, 2000);
            vector<bool> visited(_nodeCnt, false);
            priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> pq;
            
            dist[src] = 0;
            
            pq.push({0,src});
            
            while(!pq.empty()){
                auto[wt,node] = pq.top();
                pq.pop();
                
                if(visited[node] == true) continue;
                
                dist[node] = wt;
                visited[node] = true;
                
                for(int i=0; i<graph[node].size(); i++){
                    if(visited[i] == true) continue;
                    if(graph[node][i] > 0){
                        int new_wt = wt + graph[node][i];
                        if(new_wt < dist[i]){
                            pq.push({new_wt,i});
                        }
                    }
                }
            }
            
            return dist;
            
        }
        
};

int main() {
    int nodecnt = 6;
    Graph *graph = new Graph(nodecnt);
    graph->printGraph();
    
    //graph->addEdge(0,2);
    graph->addEdge(1,2,2);
    graph->addEdge(1,4,5);
    graph->addEdge(2,4,4);
    graph->addEdge(4,0,1);
    graph->addEdge(0,1,9);
    graph->addEdge(2,3,11);
    graph->addEdge(0,5,11);
    
    graph->printGraph();
    
    graph->bfs();
    graph->dfs();
    cout << endl << "dfs recursion" << endl;
    graph->dfsRecursion(4);
    graph->resetVisitedVec();
    cout << endl << "dfs recursion" << endl;
    graph->dfsRecursion(0);
    
    //graph->hasCycle();
    vector<bool> visited(nodecnt , false);
    graph->hasCycle(visited);
    
    visited.assign(nodecnt , false);
    graph->hasCycleDirectedGraph(visited);
    
    vector<int> dijkstra_op = graph->djikstra(0);
    cout << endl;
    for(auto i : dijkstra_op){
        cout << i << " ";
    }
    
    delete graph;

    return 0;
}

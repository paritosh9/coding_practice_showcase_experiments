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
        
        bool dfsCycle(int src , int parent, vector<bool> &visited){
            return 0;    
        }
        
        int hasCycle(vector<bool> &visited){
                   
            
            return 0;
            
        
        }
        
        vector<int> djikstra(int src){
            vector<int> dist(_nodeCnt, 2000);
            dist[src] = 0;
            pair<int,int> toppq;
            
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            pq.push({0,src});
            
            vector<bool> visited(_nodeCnt, false);
            
            while(!pq.empty()){
                toppq = pq.top();
                pq.pop();
                
                if(visited[toppq.second]) continue;
                visited[toppq.second] = true;
                
                for(int i=0; i< graph[toppq.second].size(); i++){
                    if(graph[toppq.second][i] == 0){
                        continue;
                    }
                    if(dist[toppq.second] +  graph[toppq.second][i] < dist[i]){
                        dist[i] = dist[toppq.second] + graph[toppq.second][i];
                        pq.push({dist[i], i});
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
    
    //graph->hasCycle();
    vector<bool> visited(nodecnt , false);
    graph->hasCycle(visited);
    
    vector<int> dijkstra_op = graph->djikstra(0);
    cout << endl;
    for(auto i : dijkstra_op){
        cout << i << " ";
    }
    
    delete graph;

    return 0;
}

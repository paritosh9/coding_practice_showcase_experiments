#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

class interconnectGraph{
    private:
        //vector<vector<pair<int,int>>> _adjG; 
        vector<vector<int>> _adjG;
        int _numNodes;
    
    public:
        //interconnectGraph(int numNodes) : _numNodes(numNodes), _adjG(numNodes, vector //<pair<int,int>>(numNodes, {0,0})){
        interconnectGraph(int numNodes) : _numNodes(numNodes), _adjG(numNodes, vector<int>(numNodes,0)){
            //for(int i=0; i<numNodes; i++){
            //    for(int j=0; j<numNodes; j++){    
            //        _adjG[i][j] = {0,0};    
            //    }
            //}                
        }
        
        void addEdge(int src, int dst, int weight){
            _adjG[src][dst] =  weight;
            _adjG[dst][src] = weight;
        }
        
        void removeEdge(int src, int dst){
            _adjG[src][dst] =  0;
            _adjG[dst][src] = 0;    
        }
        
        //dijkstra adj Matrix
        vector<int> minLatencyPathAdjM(int src , int dst){
            const int INF = 10000;
            
            vector<int> parent(_numNodes, -1);
            vector<int> path;
            vector<int> distNodes(_numNodes, INF);
            vector<bool> visited(_numNodes, false);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> dijkstraPQ;
            distNodes[src] = 0;
            dijkstraPQ.push({0,src});
            
            while(!dijkstraPQ.empty()){
                pair<int,int> top = dijkstraPQ.top();
                dijkstraPQ.pop();
                int currNode = top.second;
                
                if(visited[currNode]) continue;
                visited[currNode] = true;
                
                //if(top.first > distNodes[currNode]) continue;
                //distNodes[currNode] = top.first;
                //if(currNode == dst) break;
                
                for(int i=0; i<_numNodes; i++){
                    if(_adjG[currNode][i] != 0 && distNodes[currNode] +_adjG[currNode][i] <  distNodes[i]){
                        distNodes[i] = distNodes[currNode] +_adjG[currNode][i];
                        dijkstraPQ.push({distNodes[i],i}); 
                        parent[i] = currNode;
                    }
                }
                
            }
            
            for(int i : distNodes){
                cout << i << " -- ";
            }
            cout << endl;
            
            return parent;  
        }
        
        //dijkstra adj List
        vector<int> minLatencyPathAdjL(int src , int dst){
              
          return {};  
        }
        
        // bfs
        vector<int> bfs(int src){
            vector<int> result;
            queue<int> bfsQ;
            vector<bool> visited(_numNodes, false);
            
            bfsQ.push(src);
            visited[src] = true;
            
            while(!bfsQ.empty()){
                int v = bfsQ.front();
                bfsQ.pop();
                cout << v << " - ";
                result.push_back(v);
                for(int i=0; i<_adjG[v].size(); i++){
                    if(_adjG[v][i] == 0 || visited[i]){
                        continue;
                    }
                    bfsQ.push(i);
                    visited[i] = true;
                }
            }
            cout << endl;
            return result;
        }
        
        vector<int> dfs(int src){
            vector<int> result;
            stack<int> st;
            vector<bool> visited(_numNodes, false);
            st.push(src);
            
            while(!st.empty()) {
                int v = st.top();
                st.pop();
                
                if(visited[v]) continue;
                result.push_back(v);
                cout << v << " - ";
                visited[v] = true;
                for(int i=0; i<_adjG[v].size(); i++){
                    if(_adjG[v][i] == 0 || visited[i]) continue;
                    st.push(i);
                }
            }
                
            return result; 
        }
        
        void cycleDetection(){
            
        }
    
        vector<int> dfsRecursive(int src){
            vector<int> result;
            return result;
     }
    
};

int main() {
    // Write C++ code here
    interconnectGraph noc(8);
    noc.addEdge(0,1,3);
    noc.addEdge(1,2,5);
    noc.addEdge(2,3,11);
    noc.addEdge(2,4,1);
    noc.addEdge(4,6,3);
    noc.addEdge(5,4,12);
    noc.addEdge(6,7,3);
    noc.addEdge(3,6,11);
    
    int src = 2, dst =7;
    vector<int> parent = noc.minLatencyPathAdjM(src,dst);
    
    vector<int> path;
    
    for(int v=dst; v != -1; v = parent[v]){
        path.push_back(v);
        //cout << v << " - ";
    }
    
    reverse(path.begin(), path.end());
    
    for(int x : path){
        cout << x << " - ";
    }
    cout << endl;
    
    vector<int> bfsresult = noc.bfs(src);
    cout << endl;
    vector<int> dfsresult = noc.dfs(src);
    
    cout << endl;
    return 0;
}

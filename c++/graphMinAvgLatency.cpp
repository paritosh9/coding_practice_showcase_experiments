#include <iostream>
#include <vector>
#include <utility>
#include <queue>
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
            vector<int> path;
            vector<int> distNodes(_numNodes, 10000);
            vector<bool> visited(_numNodes, false);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> dijkstraPQ;
            distNodes[src] = 0;
            dijkstraPQ.push({0,src});
            
            while(!dijkstraPQ.empty()){
                pair<int,int> top = dijkstraPQ.top();
                dijkstraPQ.pop();
                int currNode = top.second;
                
                //if(visited[currNode]) continue;
                //visited[currNode] = true;
                
                if(top.first > distNodes[currNode]) continue;
                //distNodes[currNode] = top.first;
                path.push_back(currNode);
                //if(currNode == dst) break;
                
                for(int i=0; i<_numNodes; i++){
                    if(_adjG[currNode][i] != 0 && distNodes[currNode] +_adjG[currNode][i] <  distNodes[i]){
                        distNodes[i] = distNodes[currNode] +_adjG[currNode][i];
                        dijkstraPQ.push({distNodes[i],i});    
                    }
                }
                
            }
            
            for(int i : distNodes){
                cout << i << " -- ";
            }
            cout << endl;
            
            return path;  
        }
        
        //dijkstra adj List
        vector<int> minLatencyPathAdjL(int src , int dst){
              
          return {};  
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
    
    vector<int> path = noc.minLatencyPathAdjM(2,7);
    
    for(int x : path){
        cout << x << " - ";
    }
    
    cout << endl;
    return 0;
}

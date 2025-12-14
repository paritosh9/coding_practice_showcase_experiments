#include <iostream>
#include <vector>
#include <queue>
#include <memory>
using namespace std;

class LatencyModel{
    public:
        virtual ~LatencyModel() = default;
        virtual float latency() = 0;
};

class throughputModel{
    public:
        virtual ~throughputModel() = default;
        virtual float throughput() = 0;
};

class simpleLatencyModel : public LatencyModel {
    public:
        float latency() override { cout << "in simple latency model \n"; return 5.0;}
};

class simplethroughputModel : public throughputModel {
    public:
        float throughput() override { cout << "in simple tp model \n"; return 5.0;}
};

//flow
class Link;
class Flow;
class Router;
class EndPoint;

class Flow{
    private:
        
    public:
        int _id;
        int _src_ep, _dst_ep;
        
        float _set_traffic;
        float _scaled_traffic;
        
        Flow(int id, int src, int dst, float traffic) : _id(id), _src_ep(src), _dst_ep(dst), _set_traffic(traffic){}
        
        vector<Link*> path;
};

//link
class Link{
    public:
        int _id;
        Router* _src; //non-owning
        Router* _dst; // non-owning
        float _bandwidth;
        float throughput;
        
        Link(int id, Router* src, Router* dst) : _id(id), _src(src), _dst(dst){}
        
        vector<Flow*> flows;
    
};

//router
class Router{
    public:
        int _Rid;
        vector<Link*> out_links;
        vector<EndPoint*> endpoints;
        
        Router(int id) : _Rid(id) {}
    
};

class EndPoint{
    public:
        int _nid;
        Router* attached; // non-owning
        
        EndPoint(int id) : _nid(id){}
};

//noc
class NoC{
    
};

//meshtopology
class MeshTopology{
    public:
        int _rows, _cols;
        
        vector<unique_ptr<Router>> routers;
        vector<unique_ptr<EndPoint>> endpoints;
        vector<unique_ptr<Flow>> flows;
        vector<unique_ptr<Link>> links;
        
        MeshTopology(int r, int c) : _rows(r), _cols(c){
            buildRouters();
            buildLinks();
            
        }
        
        Router* router(int r , int c){
            return routers[r*cols + c].get();
        }
    
    private:
        void buildRouters(){
            for(int i=0; i <_rows * _cols; i++){
                routers.push_back(make_unique<Router>(Router(i)));
            }    
        }
        
        void buildLinks(){
                
        }
        
        void connect(){
            
        }
        
    
};

int main() {
    // Write C++ code here
    MeshTopology meshtopo(2,2);
    

    return 0;
}

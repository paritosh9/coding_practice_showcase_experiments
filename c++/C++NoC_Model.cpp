#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class LatencyModel{
    private:
    
    public:
        LatencyModel(){}
};

class ThroughputModel{
   private:
    
    public:
        ThroughPutModel(){} 
};

class simpleLinkLatencyModel : public LatencyModel{
    private:
        double _latency;
    public:
        simpleLinkLatencyModel(float latency): _latency(latency){}    
};

class simpleLinkThroughputModel : public ThroughputModel{
    private:
        double _tp;
    public:
        simpleLinkThroughputModel(float tp): _tp(tp){}   
};

class advancedLinkLatencyModel : public LatencyModel{
    
};

class advancedLinkThroughPutModel : public ThroughPutModel{
    
};

class simpleRouterLatencyModel : public LatencyModel{
    
};

class endPoints{
    
};

class Router{
    private :
        int _id;
    
    public:
        Router(int id): _id(id){}
};

class Flow{
    
};

class Link{
    private:
        int _id;
        Router* _src;
        Router* _dst;
        unique_ptr<LatencyModel> _lm;
        unique_ptr<ThroughputModel> _tpm;
        
        vector<Flow*> flows;
    
    public:
        Link(int id, Router* src, Router* dst, unique_ptr<LatencyModel> lm,
            unique_ptr<ThroughputModel> tpm) : _id(id), _src(src), _dst(dst), _lm(move(lm), _tpm(move(tpm)));
        
        double latency() const {
            return _lm->latency();
        }
        
        double throughput() const {
            return _tpm->throughput();
        }
};

class MeshTopology{
    private :
        int _rows;
        int _cols;
        
        vector<unique_ptr<Router>> routers;
        vector<unique_ptr<Link>> links;
        vector<unique_ptr<Flow>> flows;
        
    public:
        MeshTopology(int r, int c) : _rows(r), _cols(c){
            buildRouters(r,c);
            buildLinks();
            
        }    
        
        
        void buildRouters(int r, int c){
            for(int i=0; i<r*c; i++){
                //auto ptr = make_unique<Router>(i);
                //Routers.push_back(ptr);
                routers.push_back(make_unique<Router>(i));
            }
        }
        
        Router* router(int r, int c){
            return routers[r*_cols + c].get();    
        }
        
        void buildLinks(){
            int lid=0;
            for(int r=0; r<_rows; r++){
                for(int c=0; c<_cols; c++){
                    Router* curr = router(r,c);
                    if(c+1 < _cols){
                        connect(curr, router(r,c+1),lid++);
                    }
                    if(r+1 < _rows){
                        connect(curr, router(r+1,c), lid++);
                    }
                }
            }
            
        }
        
        void connect(Router* a, Router* b, int lid){
            auto link = make_unique<Link>(
                lid,a,b,
                make_unique<simpleLinkLatencyModel>(1.0),
                make_unique<simpleLinkThroughputModel>(100.0)
                );
            
            a->out_links.push_back(link.get());
            links.push_back(move(link));
        }
        
    
};

int main() {
    
    

    return 0;
}

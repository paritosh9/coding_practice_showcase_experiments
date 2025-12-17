#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class LatencyModel{
    
};

class ThroughPutModel{
    
};

class simpleLinkLatencyModel : public LatencyModel{
    
};

class simpleLinkThroughPutModel : public ThroughPutModel{
    
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
    
};

class MeshTopology{
    private :
        int _rows;
        int _cols;
    public:
        MeshTopology(int r, int c) : _rows(r), _cols(c){
            buildRouters(r,c);
            buildLinks();
            connect();
        }    
        
        void connect(){
            
        }
        
        void buildRouters(int r, int c){
            vector<unique_ptr<Router>> Routers;
            for(int i=0; i<r*c; i++){
                //auto ptr = make_unique<Router>(i);
                //Routers.push_back(ptr);
                Routers.push_back(make_unique<Router>(i));
            }
        }
        
        void buildLinks(){
            vector<unique_ptr<Link>> Links;
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    Links.push_back(make_unique<Link>(i,j))     
                }
            }
            
        }
        
    
};

int main() {
    
    

    return 0;
}

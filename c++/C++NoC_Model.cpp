#include <iostream>
#include <vector>
#include <memory>

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
    
};

class Flows{
    
};

class Links{
    
};

class MeshTopology{
    private :
        int _rows;
        int _cols;
    public:
        MeshTopology(int r, int c) : _rows(r), _cols(c){
            buildRouters();
            buildLinks();
            connect();
        }    
        
        void connect(){
            
        }
        
        void buildRouters(){
            
        }
        
        void buildLinks(){
            
        }
        
    
};

int main() {
    
    

    return 0;
}

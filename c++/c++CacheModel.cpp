#include <iostream>
#include <cstdint>
#include <vector>
#include <cmath>
using namespace std;

struct Node{
    int _data;
    Node *_next;
    //Node *prev;
    
    Node(int data) : _data(data), _next(nullptr){}
};

struct CacheLine{
    bool _valid;
    uint64_t _tag;
    uint64_t _time = 0 ;
    CacheLine(uint64_t tag) : _tag(tag){}
};

class Cache{
    private :
        uint64_t _cacheSize;
        uint64_t _cacheLineSize;
        uint64_t _associativity;
        
        uint64_t _numSets;
        
        uint64_t _hits      =  0;
        uint64_t _misses    = 0;
        uint64_t _accesses  = 0;
        uint64_t time = 0 ;
        
        vector<vector<CacheLine>> _cache;
        
    public:
        Cache(uint64_t C, uint64_t L, uint64_t A ) : _cacheSize(C),_cacheLineSize(L),_associativity(A){
            _numSets = _cacheSize/_cacheLineSize;
            _cache.resize(_numSets,vector<CacheLine>(A,0));
            cout << " Building Cache " << endl;
        } 
        
        
        void access(uint64_t addr){
            _accesses++;
            time++;
            size_t offsetBits   = log2(_cacheLineSize);   
            size_t indexBits    = log2(_numSets);
            
            uint64_t index  = (addr >> offsetBits) & (_numSets-1);
            uint64_t tag    =  addr >> (offsetBits + indexBits);
            
            for(int i=0; i < _cache[index].size(); i++){
                if(_cache[index][i]._tag == tag){
                    _hits++;
                    _cache[index][i]._time = time;
                    return;
                }    
            }
            
            // find victim using LRU
            CacheLine* victim = &_cache[index][0];
            for(int i=0; i < _cache[index].size(); i++){
                if(_cache[index][i]._valid == false){
                    victim = &_cache[index][i];
                    break;
                }else{
                    if(_cache[index][i]._time < victim->_time){
                        victim = &_cache[index][i];        
                    }
                }
            }
            
            victim->_valid  = true;
            victim->_tag    = tag;
            victim->_time   = time;
            
            _misses++;
            
        }
        
        void printStats(){
            
            cout << "Number of access  : " << _accesses << endl;
            cout << "Hits              : " << _hits << endl;
            cout << "Misses            : " << _misses << endl;
            cout << "Miss Rate         : " << _misses/_accesses << endl;
            
        }
    
};

int main() {
    // Write C++ code here
    Cache cache(
        32 * 1024,
        64,
        8
        );
    
    uint64_t address[] = {0x1000, 0x2000, 0x3000, 0x4000};
    
    for(auto addr : address){
        cache.access(addr);
    }
    
    cache.printStats();

    return 0;
}

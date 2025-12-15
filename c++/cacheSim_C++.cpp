#include <iostream>
#include <set>
#include <vector>
#include <cstdint>
#include <cmath>
using namespace std;

struct CacheLine {
    bool valid = false;
    uint64_t tag = 0;
    uint64_t lru = 0;
};

//using Set = vector<CacheLine>;

class Cache {
    size_t cache_size;
    size_t line_size;
    size_t associativity;
    size_t num_sets;
    uint64_t time = 0;
    
    //vector<Set> sets;
    
    vector<vector<CacheLine>> sets;

    public:
        Cache(size_t C, size_t L, size_t A)
            : cache_size(C), line_size(L), associativity(A)
        {
            size_t num_lines = C / L;
            num_sets = num_lines / A;
            //sets.resize(num_sets, Set(A));
            sets.resize(num_sets, vector<CacheLine>(A));
        }
    
        bool access(uint64_t addr) {
            time++;
    
            size_t offset_bits = log2(line_size);
            size_t index_bits  = log2(num_sets);
    
            size_t index = (addr >> offset_bits) & (num_sets - 1);
            uint64_t tag = addr >> (offset_bits + index_bits);
    
            // Hit?
            for (auto& line : sets[index]) {
                if (line.valid && line.tag == tag) {
                    line.lru = time;
                    return true; // HIT
                }
            }
    
            // Miss: choose LRU victim
            CacheLine* victim = &sets[index][0];
            for (auto& line : sets[index]) {
                if (!line.valid) {
                    victim = &line;
                    break;
                }
                if (line.lru < victim->lru)
                    victim = &line;
            }
    
            victim->valid = true;
            victim->tag = tag;
            victim->lru = time;
            return false; // MISS
        }
};

using Set = vector<CacheLine>;

int main() {
    // Write C++ code here
    Cache cache(
        32 * 1024,  // 32KB cache
        64,         // 64B cache line
        8           // 8-way associative
    );

    uint64_t addrs[] = {0x1000, 0x1004, 0x2000, 0x1000};

    for (auto a : addrs) {
        cout << "Access " << hex << a
                  << (cache.access(a) ? " HIT\n" : " MISS\n");
    }

    return 0;
}

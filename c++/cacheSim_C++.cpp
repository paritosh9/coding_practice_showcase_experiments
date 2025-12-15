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
    uint64_t accesses = 0;
    uint64_t hits = 0;
    uint64_t misses = 0;
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
            accesses++;
            time++;
    
            size_t offset_bits = log2(line_size);
            size_t index_bits  = log2(num_sets);
    
            size_t index = (addr >> offset_bits) & (num_sets - 1);
            uint64_t tag = addr >> (offset_bits + index_bits);
    
            // Hit?
            for (auto& line : sets[index]) {
                if (line.valid && line.tag == tag) {
                    hits++;
                    line.lru = time;
                    return true; // HIT
                }
            }
            
            misses++;
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
        
        double missRate() const {
        return accesses ? static_cast<double>(misses) / accesses : 0.0;
    }

    void printStats() const {
        std::cout << "Accesses : " << accesses << "\n";
        std::cout << "Hits     : " << hits << "\n";
        std::cout << "Misses   : " << misses << "\n";
        std::cout << "MissRate : " << missRate() * 100.0 << "%\n";
    }
};

using Set = vector<CacheLine>;

int main() {
    // Write C++ code here
    Cache cache(
        32 * 1024,  // 32 KB
        64,         // 64 B line
        8           // 8-way
    );

    uint64_t addrs[] = {
        0x1000, 0x1004, 0x1008,
        0x2000, 0x1000, 0x3000,
        0x1004, 0x4000
    };

    for (auto a : addrs) {
        cache.access(a);
    }

    cache.printStats();

    return 0;
}

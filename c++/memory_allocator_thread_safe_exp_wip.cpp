#include <iostream>
#include <map>
#include <thread>
#include <mutex>
#include <condition_variable>

class MemoryAllocator{
  private :
    size_t _size;
    //std::vector<std::pair<int, int>> mem_free_list; //start address, size of free contiguous memchunk
    std::map<size_t, void*> _mem_free_map; //size, start address of free contiguous memchunk
    
  public :
    MemoryAllocator(size_t size):_size(size){
        _mem_free_map[size] = nullptr;
    }
    
    void allocate(size_t size){
      for(auto i : _mem_free_map){
        if(size <= i.first){
          size_t tmp_size = i.first;
          void *start_addr = i.second;
          _mem_free_map.erase(i.first);
          
          size_t new_strt_addrs = reinterpret_cast<size_t>(i.second) + size;
          //std::cout << "new_strt_addrs : " << new_strt_addrs << std::endl;
          start_addr = reinterpret_cast<void*> (new_strt_addrs);
          tmp_size = tmp_size - size;
          _mem_free_map[tmp_size] = start_addr;
          return;
        }      
      }
      std::cout << " memory is full , couldn't find a free block of required size\n";
      return;
    }
    
    void deallocate(){
        
    }
    
    void printFreeList(){
      std::cout << "free list\n";
      for(auto i : _mem_free_map){
        std::cout << "size : " << i.first << " " << "start addr : " << i.second << std::endl;
      }    
    }
};

int main()
{
    std::cout<<"Hello World\n";
    
    MemoryAllocator mem_alloc(1024);
    mem_alloc.printFreeList();
    
    mem_alloc.allocate(64);
    mem_alloc.printFreeList();
    
    mem_alloc.allocate(256);
    mem_alloc.printFreeList();
    
    mem_alloc.allocate(256);
    mem_alloc.printFreeList();
    
    mem_alloc.allocate(256);
    mem_alloc.printFreeList();
    
    mem_alloc.allocate(256);
    mem_alloc.printFreeList();
    
    

    return 0;
}

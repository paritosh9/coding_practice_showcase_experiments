#include <iostream>
#include <map>
#include <thread>
#include <mutex>
#include <condition_variable>

class MemoryAllocator{
  private :
    size_t _size;
    //std::vector<std::pair<int, int>> mem_free_list; //start address, size of free contiguous memchunk
    std::map<void*, size_t> _mem_free_map; //size, start address of free contiguous memchunk
    std::map<void*, size_t> _mem_alloc_map; //
    
    std::mutex mtx;
    
  public :
    MemoryAllocator(size_t size):_size(size){
        _mem_free_map[nullptr] = size;
    }
    
    void* allocate(size_t size){
      std::lock_guard<std::mutex> lk_grd(mtx);
      for(auto i : _mem_free_map){
        if(size <= i.second){
          size_t tmp_size = i.second;
          void *start_addr = i.first;
          void *start_addr_to_return = i.first;
          _mem_free_map.erase(i.first);
          
          //we could have used static_cast instead of reinterpret_cast 
          //if we used int instead of size_t for size
          //int new_strt_addrs = static_cast<int>(i.first) + size;
          size_t new_strt_addrs = reinterpret_cast<size_t>(i.first) + size;
          //std::cout << "new_strt_addrs : " << new_strt_addrs << std::endl;
          start_addr = reinterpret_cast<void*> (new_strt_addrs);
          tmp_size = tmp_size - size;
          _mem_free_map[start_addr] = tmp_size;
          _mem_alloc_map[start_addr_to_return] = size;
          return start_addr_to_return;
        }      
      }
      std::cout << " memory is full , couldn't find a free block of required size\n";
      return nullptr;
    }
    
    void deallocate(void* addr){
      std::lock_guard<std::mutex> lk_grd(mtx);
      if(_mem_alloc_map.find(addr) == _mem_alloc_map.end()){
        std::cout << "Trying to deallocate unallocated memory, unsuccessful\n";  
        return;
      } else{
          std::cout << "releasing memory : " << addr << std::endl;
          _mem_free_map[addr] = _mem_alloc_map[addr];
          _mem_alloc_map.erase(addr);  
          return;
      }   
    }
    
    void printFreeList(){
      std::cout << "free list\n";
      for(auto i : _mem_free_map){
        std::cout << "size : " << i.first << " " << "start addr : " << i.second << std::endl;
      }    
    }
    
    void printAllocList(){
      std::cout << "alloc list\n";
      for(auto i : _mem_alloc_map){
        std::cout << "start addr : " << i.first << " " << "size : " << i.second << std::endl;
      }    
    }
};

int main()
{
    std::cout<<"Hello World\n";
    
    MemoryAllocator mem_alloc(1024);
    mem_alloc.printFreeList();
    
    void *ptr = (mem_alloc.allocate(16*sizeof(int)));
    mem_alloc.printFreeList();
    
    ptr = mem_alloc.allocate(256);
    mem_alloc.printFreeList();
    
    ptr = mem_alloc.allocate(256);
    mem_alloc.printFreeList();
    
    ptr = mem_alloc.allocate(256);
    mem_alloc.printFreeList();
    
    int *ptr1 = static_cast<int*>(mem_alloc.allocate(256));
    mem_alloc.printFreeList();
    
    mem_alloc.printAllocList();
    
    ptr = reinterpret_cast<void*> (320);
    mem_alloc.deallocate(ptr);
    mem_alloc.printAllocList();
    mem_alloc.printFreeList();
    
    ptr = reinterpret_cast<void*> (120);
    mem_alloc.deallocate(ptr);
    mem_alloc.printAllocList();
    mem_alloc.printFreeList();
    

    return 0;
}

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class memory_allocator{
  private :
    //std::vector<std::pair<int, int>> mem_free_list; //start address, size of free contiguous memchunk
    std::map<int, int> mem_free_map; //size, start address of free contiguous memchunk
    
  public :
    void allocation(){
        
    }
    
    void deallocate(){
        
    }
};

int main()
{
    std::cout<<"Hello World\n";
    
    

    return 0;
}

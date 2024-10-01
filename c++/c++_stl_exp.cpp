#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>

int main()
{
    std::cout<<"Hello World\n";
    
    // vectors
    std::vector<int> v1 = {1,2,3,4,5,6,7,8} ;
    rotate(v1.begin(), v1.begin()+3, v1.end());
    std::cout<<"vector stl : ";
    for(auto i : v1){
      std::cout << " " << i << " ";
    }
    
    std::cout<<"\nlist stl : ";
    
    // lists
    std::list<int> l1 = {1,3,5,6,7,9};
    for(auto i : l1){
      std::cout << " " << i << " ";
    }
    std::cout<<"\nlist stl : ";
    
    for(auto i = l1.begin(); i!= l1.end(); i++){
      std::cout << " " << *i << " ";
    }
    
    //std::stack<T> ;
    std::stack<int> s;
    s.push(1);s.push(21);s.push(88);
    std::cout<<"\nstack stl : ";
    
    while(!s.empty()){
      std::cout << " " << s.top() << " ";
      s.pop();
    }
    

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <map>
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
    
    //stl std::set<T> ;
    std::cout<<"\nset stl : ";
    std::set<int> set1{1,2,3,3,6,7,88,976};
    for(auto i = set1.begin(); i != set1.end(); i++){
       std::cout << " " << *i << " "; 
    }
    std::cout<<"\nset stl : ";
    for(auto i : set1){
       std::cout << " " << i << " "; 
    }
    
    //stl std::map<Key, T> ;
    std::cout<<"\nmap stl : ";
    std::map<int, std::string> map1{{1,"one"}, {2,"two"}, {22,"twentytwo"}};
    for(auto i = map1.begin(); i != map1.end(); i++){
        std::cout << " \nkey : " << (*i).first << " value : " << (*i).second;
    }
    for(auto i : map1){
        std::cout << " \nkey : " << i.first << " value : " << i.second;
    }

    return 0;
}

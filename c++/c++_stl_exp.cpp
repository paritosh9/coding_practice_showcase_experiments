#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <functional>
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
    
    //copy stl
    // creating vector
    std::vector<int> v_src = { 1, 2, 3, 4, 55 };
    std::vector<int> v_dest(5);
    std::cout<<"\ncopy vector stl : ";
    copy(v_src.begin(), v_src.end(), v_dest.begin());
    for(auto i : v_dest){
      std::cout << " " << i << " ";
    }
    
    auto max_elem = max_element(v_dest.begin(), v_dest.end());
    std::cout << "\nmax element : " << *max_elem << std::endl;
    
    //for_each stl
    std::vector<int> v_fe{1,3,4,5,66,77,88};
    for_each(v_fe.begin(), v_fe.end(), [](int &i){i = i+1;} );
    std::cout<<"\nfor_each stl : ";
    for(auto i : v_fe){
      std::cout << " " << i << " ";
    }
    
    //functional stl
    std::equal_to<int> eq;
    bool flag = eq(10,10);
    std::cout<<"\nfunctional functor stl : " << "flag : " << flag << std::endl;;
    return 0;
}

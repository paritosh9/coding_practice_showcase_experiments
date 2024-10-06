#include <bits/stdc++.h>
#include <iostream>
#include <vector>

int main()
{
   std::cout<<"Hello World\n";
    
    std::vector<int> v1 = {1,2,3,5,62,4,5,555,66,34,23};
    std::sort(v1.begin(), v1.end(),[](int a, int b){return a > b;});
    
    for(auto i : v1){
        std::cout << i << " " ;
    }
    std::cout<< "\n";
    
    v1 = {13,2,33,5,62,4,5,555,66,34,23};
    
    auto custom_cmprtr = [](int a, int b){
        return (a+2 < b);                     
    };
    
    std::sort(v1.begin(), v1.end(), custom_cmprtr);
    
    for(auto i : v1){
        std::cout << i << " " ;
    }
    
    std::cout<< "\n";

    // declaring a vector with size 5
    std::vector<int> vec(55);

    // initializing using iota()
    std::iota(vec.begin(), vec.end(), 1);

    // printing the vector
    for (int i = 0; i < 55; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout<< "\n";
    return 0;
}

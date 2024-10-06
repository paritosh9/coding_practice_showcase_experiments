#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main()
{
    std::cout<<"Hello World\n";
    
    std::vector<int> v1 = {1,3,4,65,45,77};
    std::vector<int> v2 = {2,31,41,625,145,277};
    
    std::vector<int> v12(12);
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(),v12.begin());
    
    for(auto i :v12){
        std::cout << i << " ";
    }
    
    std::cout << "\n";
    
    std::vector<int> v3 = {4,31,41,65};
    
    bool flag = std::includes(v12.begin(), v12.end(), v3.begin(), v3.end());
    std::cout << "flag : " << flag << std::endl;
    
    v3 = {45,4,31,41,65};
    flag = std::includes(v12.begin(), v12.end(), v3.begin(), v3.end());
    std::cout << "flag : " << flag << std::endl;
    
    return 0;
}

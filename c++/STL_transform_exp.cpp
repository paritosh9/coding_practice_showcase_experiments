#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main()
{
    std::cout<<"Hello World\n";
    
    std::vector<int> v_in = {77,212,1,3,5,34,22,11,234};
    std::vector<int> v_out(v_in.size());
    
    // unary op exp
    auto unary_op = [](int a){return a*5;};
    std::transform(v_in.begin(), v_in.end(), v_out.begin(), unary_op);
    
    for(auto i : v_out){
        std::cout << i << " " ;
    }
    
    std::cout <<"\n";
    
    // binary op exp
    std::vector<int> v_in2 = {717,22,12,31,25,314,2,1,34};
    auto binary_op = [](int a, int b){return a+b+5;};
    std::transform(v_in.begin(), v_in.end(), v_in2.begin(), v_out.begin(), binary_op);
    
    for(auto i : v_out){
        std::cout << i << " " ;
    }
    
    std::cout <<"\n";
    
    return 0;
}

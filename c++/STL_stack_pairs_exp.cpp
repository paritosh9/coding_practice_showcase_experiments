#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>

#include <numeric>
#include <algorithm>

int main()
{
    std::cout<<"Hello World\n";
    
    std::stack<std::pair<int, int>> stack_of_pairs;
    stack_of_pairs.push({1,2});
    stack_of_pairs.push(std::make_pair(11,4));
    
    while(!stack_of_pairs.empty()){
        std::pair<int,int> tmp = stack_of_pairs.top();
        std::cout << tmp.first << "," << tmp.second <<"   " ;
        stack_of_pairs.pop();
    }
    
    std::cout << "\n";
    return 0;
}

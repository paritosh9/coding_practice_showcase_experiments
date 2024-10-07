#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>

int main()
{
    std::cout<<"Hello World\n";
    
    std::vector<int> v_in = {77,212,1,3,5,34,22,11,234};
    
    //default priority queue max heap
    std::priority_queue<int> pq;
    for(int i = 0; i< v_in.size(); i++){
        pq.push(v_in[i]);    
    }
    
    while(!pq.empty()){
        std::cout << pq.top() << " " ;   
        pq.pop();
    }
    
    std::cout <<"\n";
    
    //custom priority queue min heap
    std::priority_queue<int,std::vector<int>,std::greater<int>> pq_min_heap;
    for(int i = 0; i< v_in.size(); i++){
        pq_min_heap.push(v_in[i]);    
    }
    
    while(!pq_min_heap.empty()){
        std::cout << pq_min_heap.top() << " ";   
        pq_min_heap.pop();
    }
    
    std::cout <<"\n";
    
    return 0;
}

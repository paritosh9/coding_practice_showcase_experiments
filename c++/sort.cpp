#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Write C++ code here
    // sort search
    
    vector<int> toSort = {22,344,56,1,2,78,1234,24};
    
    cout << "default ascending ... ";
    sort(toSort.begin(), toSort.end());
    
    for(int i : toSort){
        cout << i << " ";
    }
    cout << endl;
    
    cout << "descending ... ";
    sort(toSort.begin(), toSort.end(), greater<int>());
    
    for(int i : toSort){
        cout << i << " ";
    }
    cout << endl;
    
    cout << "custom ... ";
    sort(toSort.begin(), toSort.end(), [](auto a, auto b){
        return true;
        
    });
    
    for(int i : toSort){
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}

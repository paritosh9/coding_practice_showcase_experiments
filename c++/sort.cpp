#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int> &input, int low, int high){
    int pivot = input[high];
    int i = low -1;
    
    for(int j=low ; j<high ; j++){
        if(input[j] < pivot){
            i++;
            swap(input[i], input[j]);
        }
    }
    
    swap(input[i+1], input[high]);
    return i+1;
}

void quickSort(vector<int> &input, int low, int high){
    if(low < high){
        int pi = partition(input , low , high);
        quickSort(input, low, pi-1);
        quickSort(input, pi+1, high);
    }
   
}

int main() {
    // Write C++ code here
    // sort search
    
    vector<int> toSort = {22,344,56,1,2,78,1234,24};
    
    cout << "quicksort ... ";
    quickSort(toSort,0, toSort.size()-1);
    for(int i : toSort){
        cout << i << " ";
    }
    cout << endl;
    
    toSort = {22,344,56,1,2,78,1234,24};
    
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

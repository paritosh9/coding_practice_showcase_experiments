#include <iostream>
#include <vector>

template<typename T>
std::vector<T> bubble_sort(const std::vector<T>& array){
    std::vector<T> sorted_array{};
    for(auto i : array){
        sorted_array.push_back(i);    
    }
    /*for(auto i : sorted_array){
        std::cout << "sorted array : " << i << std::endl;
    }*/
    
    for(int i = 0; i < sorted_array.size(); i++){
        for(int j = 0 ; j < sorted_array.size() - i-1; j++){
            if(sorted_array[j+1] < sorted_array[j]){
               T tmp = sorted_array[j+1];
               sorted_array[j+1] = sorted_array[j];
               sorted_array[j] = tmp;
            }    
        }
    }
    
    return sorted_array;
}

int main()
{
    std::cout<<"Hello World\n";
    std::vector<int> input_array{0,3,22,4,21,56,76,23,0,1,344,55,1234};
    std::vector<int> sorted_array = bubble_sort(input_array);
    
    for(auto i : sorted_array){
        std::cout << "sorted array : " << i << std::endl;
    }
    return 0;
}

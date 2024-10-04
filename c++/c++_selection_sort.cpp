#include <iostream>
#include <vector>

template<typename T>
std::vector<T> selection_sort(const std::vector<T>& array){
    std::vector<T> sorted_array{};
    for(auto i : array){
        sorted_array.push_back(i);    
    }
    /*for(auto i : sorted_array){
        std::cout << "sorted array : " << i << std::endl;
    }*/
    
    for(int i = 0; i < sorted_array.size()-1; i++){
        T smallest_index = i+1;
        for(int j = i+1 ; j < sorted_array.size()-1; j++){
            if(sorted_array[j+1] < sorted_array[smallest_index]){
               smallest_index = j+1;
            }    
        }
        if(sorted_array[smallest_index] < sorted_array[i]){
            T tmp = sorted_array[i];
            sorted_array[i] = sorted_array[smallest_index];
            sorted_array[smallest_index] = tmp;
        }
    }
    
    return sorted_array;
}

int main()
{
    std::cout<<"Hello World\n";
    std::vector<int> input_array{0,3,22,4,21,56,76,23,0,1,344,55,1234};
    std::vector<int> sorted_array = selection_sort(input_array);
    
    for(auto i : sorted_array){
        std::cout << "sorted array : " << i << std::endl;
    }
    return 0;
}

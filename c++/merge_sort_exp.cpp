#include <iostream>
#include <vector>

template<typename T>
void merge(std::vector<T>& array, int left_indx, int mid_indx, int right_indx){
   //std::cout << " now merging \n";
   std::cout << " now merging left indx : " << left_indx <<"  mid_indx : " << mid_indx << "  right_indx : " << right_indx << std::endl;
   
   int nL = mid_indx - left_indx + 1;
   int nR = right_indx - mid_indx;
   std::vector<int> vL(nL), vR(nR);
   int count = 0;
   for(int i = left_indx; i <= mid_indx; i++){
       vL[count++] = array[i];
   }
   count = 0;
   for(int i = mid_indx + 1; i <= right_indx; i++){
       vR[count++] = array[i];
   }
   
   int i =0, j=0;
   count = left_indx;
   while(i<nL && j<nR){
     if(vL[i] <= vR[j]){
         array[count++] = vL[i];
         i++;
     }else{
         array[count++] = vR[j];
         j++;
     }       
   }
   
   while(i<nL){
       array[count++] = vL[i];
       i++;
   }
   while(j<nR){
       array[count++] = vR[j];
       j++;
   }
}

template<typename T>
void merge_sort(std::vector<T>& array, int left_indx, int right_indx){
    if(left_indx >=right_indx){
        //std::cout <<"return\n";
        return;
    }
    
    int mid_indx = left_indx + (right_indx - left_indx)/2 ;
    std::cout << "left indx : " << left_indx <<"  mid_indx : " << mid_indx << "  right_indx : " << right_indx << std::endl;
    
    merge_sort(array, left_indx, mid_indx);
    merge_sort(array, mid_indx+1, right_indx);
    merge(array, left_indx, mid_indx, right_indx);
    
}

int main()
{
    std::cout<<"Hello World\n";
    std::vector<int> input_array{0,3,22,4,21,56,76,23,0,1,344,55,1234};
    merge_sort(input_array, 0, input_array.size()-1);
    
    for(auto i : input_array){
        std::cout << "sorted array : " << i << std::endl;
    }
    return 0;
}

/*
  Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int first_index = 1;
       //auto second_pointer = nums.begin();
       int count = 0;

       for(int i = 1; i < nums.size(); i++){
         if(nums[i-1] != nums[i]){
           nums[first_index] = nums[i];
           first_index++; 
           count = 0;
         } else {
            if(count < 1){
                nums[first_index] = nums[i];
                count++;
                first_index++;
            }
         }
         for(auto i= nums.begin(); i!= nums.end(); i++){
           std::cout << *i ;
         }
         std::cout<<endl;
       }
       std::cout << first_index <<endl;
       return first_index;     
    }
};

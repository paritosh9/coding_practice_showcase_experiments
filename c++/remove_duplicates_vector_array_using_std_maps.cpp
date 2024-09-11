/*Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.
  */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       
       int first_index = 1;
       //auto second_pointer = nums.begin();
     
       for(int i = 1; i < nums.size(); i++){
         if(nums[i-1] != nums[i]){
           nums[first_index] = nums[i];
           first_index++; 
         } 
       }
       return first_index; 
    }
};



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int count = 0;
       map<int,int> vector_map;
       for(auto i = nums.begin(); i != nums.end(); i++){
          if(!vector_map[*i]){
            vector_map[*i] = 1;
            count ++;
          }
       }
       nums.clear();
       for(auto i : vector_map){
         nums.push_back(i.first); 
       }
       return count;
    }
};

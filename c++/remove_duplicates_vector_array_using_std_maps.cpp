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
       int count = 0 ;
       auto first_pointer = nums.begin();
       auto second_pointer = nums.begin();
       std::cout << "here\n";

       while(first_pointer != nums.end() && second_pointer != nums.end()){
         std::cout << "here1\n";
         if(*first_pointer != *(second_pointer+1)){
            std::cout << "here2\n";
            *(first_pointer+1) = *(second_pointer+1);
            first_pointer++, second_pointer++ ;
            count++;
         } else{
             second_pointer++; 
         }
       }
       std::cout << count << endl; 
       return count; 
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

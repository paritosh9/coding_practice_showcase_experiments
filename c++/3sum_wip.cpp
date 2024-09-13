/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets
*/

/*
will start with first 2 indices and loop over rest of the vector to find 3rd number
shift to next 2 indices and loop through rest of vector till i reach end of vector
O(n^2) time complexity and will avoid duplicate triplets (duplicate triplets might not be avoided completely using this approach)
*/
class Solution {
public:
    //vector<vector<int>> twoSum(vector<int>& numbers, int i , int target,  vector<vector<int>>& res) {
    void twoSum(vector<int>& numbers, int i , int target,  vector<vector<int>>& res) {
    vector<vector<int>> result;
    int vec_len = numbers.size();
    int count = 0; 
    int index_1 = i + 1, index_2 = vec_len-1;

    while(index_1 < index_2){
        int sum = numbers[index_1] + numbers[index_2];
        if(sum == target){
            std::cout << "here" << endl;
            result.push_back({numbers[i],numbers[index_1++],numbers[index_2--]});
            while(index_1 < index_2 && numbers[index_1] == numbers[index_1 -1])  index_1++ ;
            for(auto it = result.begin(); it != result.end(); it++){
                for(auto it2 = it->begin(); it2 != it->end(); it2++){
                  std::cout << *it2 << endl; 
                }  
            }
            //count++;
            //return result;
        } else if(numbers[index_1] + numbers[index_2] < target){
            index_1++;
            //count++;
        } else if(numbers[index_1] + numbers[index_2] > target){
            index_2--;
            //count++;
        }  
    }
    //return result; 
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> result;
      sort(nums.begin(), nums.end());
      for(int i = 0; i < nums.size() ; i++){
        int target = -nums[i];
        twoSum(nums, i, target, result);
      } 
      return result;      
    }


};

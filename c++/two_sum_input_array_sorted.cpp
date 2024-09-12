/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space
*/

/*
Will start with 2 indices, one front , one at end
we will use the fact the array is sorted
so if addition is less than target then we should move the front index ahead
if addition is greater than target then we move move end index backwards
and continue till we meet target
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result{};
    int vec_len = numbers.size();
    int count = 0; 
    int index_1 = 0, index_2 = vec_len-1;

    while(count < vec_len){
        if(numbers[index_1] + numbers[index_2] == target){
            result.push_back(index_1+1);
            result.push_back(index_2+1);
            return result;
        } else if(numbers[index_1] + numbers[index_2] < target){
            index_1++;
            count++;
        } else if(numbers[index_1] + numbers[index_2] > target){
            index_2--;
            count++;
        }  
    }
    return result; 
    }
};


/*
will store vector in std::map
will start with first index of vector and find target - vec[first] in map using find function
it seems map find method has average O(constant) time complexity
no need to allocate return vector result , form vector on the fly to return to save on memory
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //vector<int> result{};

        unordered_map<int,int> vec_to_map;
        for(int i = 0 ; i < numbers.size(); i++){
            vec_to_map[numbers[i]] = i;
        }

        for(int i = 0 ; i < numbers.size(); i++){
            int to_find = target - numbers[i];
            auto it = vec_to_map.find(to_find);
            if (it != vec_to_map.end() && it->second != i){
                //result.push_back(i+1);
                //result.push_back(it->second + 1);
                return {i+1, it->second + 1}; 
            }
        }

        return {}; 
        }
};


/*
I will start with 2 index and loop over the array while adding and checking if we meet target
it wil be O(n^2), I will check if number at index one is less than target for some optimization
maybe it can be optimized further
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result{};
    for(int index_1 = 0; index_1 < numbers.size(); index_1++){
      for(int index_2 = index_1+1; index_2 < numbers.size(); index_2++){
          if(numbers[index_1] + numbers[index_2] == target){
            //std::cout << "index 1 : " << index_1 << endl;
            //std::cout << "index 2 : " << index_2 << endl;
            result.push_back(index_1+1);
            result.push_back(index_2+1);
            return result;
          }
      }  
    }
    return result;    
    }
};

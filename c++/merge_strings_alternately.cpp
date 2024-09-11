//leetcode : https://leetcode.com/problems/merge-strings-alternately/?envType=study-plan-v2&envId=programming-skills
/*You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.*/

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

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        std::string merged_str = "";
        if(word1.size() <= word2.size()){
            for(int i =0; i< word1.size(); i++){
                std::cout << word1[i] << word2[i];
                merged_str = merged_str + word1[i] + word2[i];
            }
            std::cout << word2.substr(word1.size(), word2.size()-word1.size());
            merged_str = merged_str + word2.substr(word1.size(), word2.size()-word1.size());

        } else{
            for(int i =0; i< word2.size(); i++){
                std::cout << word1[i] << word2[i];
                merged_str = merged_str + word1[i] + word2[i];
            }
            std::cout << word1.substr(word2.size(), word1.size()-word2.size());
            merged_str = merged_str + word1.substr(word2.size(), word1.size()-word2.size());
        }
    return merged_str;
    }
};

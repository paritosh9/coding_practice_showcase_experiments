/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> combined_vector(nums1) ;
        //combined_vector.insert(combined_vector.end(), nums2.begin(), nums2.end());
        int i=0, j=0;
        while(i < m && j < n ){
            if(nums1[i] <= nums2[j]){
              combined_vector[i+j] = nums1[i];
              i++; 
              std::cout << "i" << i << endl;
            } else {
                combined_vector[i+j] = nums2[j];
                j++;
                std::cout << "j" << j << endl;
            }
        }
        for(auto i = combined_vector.begin(); i != combined_vector.end(); ++i){
            std::cout << "cv : " << *i << endl;
        }
        if(i < m) {
          while(i < m){
            combined_vector[j+i] = nums1[i];
            i++;
          }  
        } else {
            while(j < n){
              combined_vector[j+i] = nums2[j];
              j++;
          }  
        }
        nums1 = combined_vector;
    }
};

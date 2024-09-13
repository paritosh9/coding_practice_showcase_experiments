/*
use sliding window concept
left index and right incex
start both at 0, slide right index to right and compare with everything on left to check any match
if there is a match, store length of substring as right- left
move left index to the location+1 where repeat character was found
slide right index to right by 1 and continue the process till right index reaches end of string
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int left=0, right=1;
      int res = 0;
      int match = 0;

      if(s.size() == 1){
        return 1;
      }

      while(right < s.size()){
        match = 0;
        for(int i = left; i < right ; i++){
            if(s[right] == s[i]){
                match = 1;
                if(res < right - left){
                  res = right - left;
                }
                left = i + 1;
                right = right + 1;
                break;
            }
        }
        if(match == 0){
           if(res < right - left + 1){
             res = right - left + 1; 
           }
           right++;
        }
      }
      return res;    
    }
};

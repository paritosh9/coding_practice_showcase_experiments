/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
*/

/*
will just iterate forward on the original string and match with other string to see if we find match
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
    int length;
    length = t.size();
    int subseq_length;
    subseq_length = s.size();

    size_t subseq_index = 0;
    size_t orig_string_index = 0;

    while(orig_string_index < length && subseq_index < subseq_length ){
      if(t[orig_string_index] == s[subseq_index]){
        orig_string_index++, subseq_index++;
      } else{
        orig_string_index++;
      }
    }
    //std::cout << subseq_index << endl;
    //std::cout << subseq_length << endl;
    if(subseq_index ==  subseq_length){
        return 1;
    } else{
        return 0;
    }      
    }
};

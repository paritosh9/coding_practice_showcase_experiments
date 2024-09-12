/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
*/

class Solution {
public:
    string reverseWords(string s) {
       char *str = new char[s.size()+1];
       string out = "";
       std::strcpy(str,s.c_str());

       char *p = std::strtok(str," ");

       while(p!= nullptr) {
          std::cout << p << endl;
          out = p+out;  
          p = std::strtok(NULL," ");
          if(p != nullptr){
            out = " " + out;
          }
       }
       std::cout << out << endl;
      return out; 
    }
};

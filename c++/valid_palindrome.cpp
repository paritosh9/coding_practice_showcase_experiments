/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*


/*
a simple palindrome check for string without spaces etc is relatively simple i guess, but if we have spaces 
etc and non alphanumeric stuff we need soem more logic to check for that, along with making it case insensitive
*/
class Solution {
public:
    bool isPalindrome(string s) {
      int count = 0;
      size_t str_len = s.size();
      size_t string_forward_index = 0;
      size_t string_reverse_index = str_len - 1 ;
      //std::cout << s[string_reverse_index-1] << endl;

      while(count < str_len){
        if(isalnum(s[string_forward_index]) && isalnum(s[string_reverse_index])){
          if(tolower(s[string_forward_index]) == tolower(s[string_reverse_index])){
            string_forward_index++, count++;
            string_reverse_index--, count++; 
            continue;
          } else {
            return 0;
          }
        } else if(!isalnum(s[string_forward_index])){
           string_forward_index++, count++;
        } else if(!isalnum(s[string_reverse_index])){
           string_reverse_index--, count++; 
        }
      }
      return 1;   
    }
};

include <string>

int main()
{
    bool flag = true;
    //std::string s = "abcd e f r d the is he";
    std::string s = "abcdedcba";
    std::cout << s << std::endl;
    std::cout << "hello world\n";
    
    int s_len = s.size(); 
    std::cout << "string size : " << s_len << std::endl;
    for(int i = 0; i < s_len/2 ; i++){
      if(s[i] != s[s_len-1-i]){
        flag = false;  
        std::cout << "not palindrome\n";
        break;
      }      
    }
    
    if(flag){
      std::cout << "is palindrome\n";    
    }
    
    // string find
    std::string s2 = "cdb";
    std::size_t found = s.find(s2);
    if(found != std::string::npos){
      std::cout << "string found at : " << found << std::endl;    
    }else{
      std::cout << "string not found\n";   
    }
    
    //string substr
    std::string s3 = s.substr(3,4);
    std::cout << "string substr : " << s3 << std::endl;
    
    return 0;
}

#include <iostream>

int main()
{
    std::cout<<"Hello World";

    int **p = new int* [10];
    
    for(int i = 0; i<10; i++){
      p[i] = new int [20];
      for(int j = 0; j < 20 ; j++){
        p[i][j] = i+j;  
      }
    }
    
    for(int i = 0; i<10; i++){
      for(int j = 0; j < 20 ; j++){
        std::cout << "p["<<i<<"]["<<j<<"] : " << p[i][j] << std::endl;
      } 
    }
    
    return 0;
}

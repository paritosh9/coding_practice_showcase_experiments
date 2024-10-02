#include <iostream>

int main()
{
    std::cout<<"Hello World\n\n";

    // using malloc
    int **m_2d = (int**)malloc(10*sizeof(int*));
    for(int i = 0 ; i < 10 ; i++){
      m_2d[i] = (int*)malloc(20*sizeof(int));  
      for(int j = 0; j < 20 ; j++){
        m_2d[i][j] = i*j;  
      }
    }
    
    for(int i = 0; i<10; i++){
      for(int j = 0; j < 20 ; j++){
        std::cout << "m_2d["<<i<<"]["<<j<<"] : " << m_2d[i][j] << std::endl;
      } 
    }
    
    // using new
    int **p_2d = new int* [10];
    
    for(int i = 0; i<10; i++){
      p_2d[i] = new int [20];
      for(int j = 0; j < 20 ; j++){
        p_2d[i][j] = i+j;  
      }
    }
    
    for(int i = 0; i<10; i++){
      for(int j = 0; j < 20 ; j++){
        std::cout << "p_2d["<<i<<"]["<<j<<"] : " << p_2d[i][j] << std::endl;
      } 
    }
    
    return 0;
}

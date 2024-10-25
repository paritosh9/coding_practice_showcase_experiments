#include <iostream>
#include <vector>

void matrix_mult(){
      
}

int main()
{
    std::cout<<"Hello World";
    
    std::vector<std::vector<int>> _matrix_A;
    std::vector<std::vector<int>> _matrix_B;
    
    // matrix A init
    for(int i = 0; i < 6 ; i++){
      std::vector<int> _vec;
      for(int j = 0; j < 5 ; j++){
        _vec.push_back(i*j);  
      }
      _matrix_A.push_back(_vec);
    }
    
    for(int i = 0; i < 6 ; i++){
      for(int j = 0; j < 5 ; j++){
        std::cout << "_matrix_A[" << i << "]" <<"[" << j << "] = " << _matrix_A[i][j] << std::endl; 
      }
    }
    
    std::cout << std::endl;
    
    // matrix B init
    for(int i = 0; i < 5 ; i++){
      std::vector<int> _vec;
      for(int j = 0; j < 6 ; j++){
        _vec.push_back(i+j);  
      }
      _matrix_B.push_back(_vec);
    }
    
    for(int i = 0; i < 5 ; i++){
      for(int j = 0; j < 6 ; j++){
        std::cout << "_matrix_B[" << i << "]" <<"[" << j << "] = " << _matrix_B[i][j] << std::endl; 
      }
    }

    return 0;
}

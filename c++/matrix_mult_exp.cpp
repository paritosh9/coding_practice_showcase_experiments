#include <iostream>
#include <vector>

const int matrix_A_rows = 6;
const int matrix_A_cols = 5;
const int matrix_B_rows = 5;
const int matrix_B_cols = 6;

std::vector<std::vector<int>> _matrix_A;
std::vector<std::vector<int>> _matrix_B;
std::vector<std::vector<int>> _matrix_C;

void matrix_init(int rows, int cols){
    
}

void matrix_mult(){
  for(int i = 0 ; i < matrix_A_rows ; i++){
    std::vector<int> _vec_C;  
    for(int j = 0 ; j < matrix_B_cols ; j++){
      int value = 0;
      for(int k = 0 ; k < matrix_A_cols ; k++){ 
        value += _matrix_A[i][k] * _matrix_B[k][j];  
      }
      _vec_C.push_back(value);
    }
    _matrix_C.push_back(_vec_C);
  }      
}

int main()
{
    std::cout<<"Hello World\n";
    
    /*std::vector<std::vector<int>> _matrix_A;
    std::vector<std::vector<int>> _matrix_B;
    std::vector<std::vector<int>> _matrix_C;
    */
    
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
    
    matrix_mult();
    
    // matrix C display
    for(int i = 0; i < 6 ; i++){
      for(int j = 0; j < 6 ; j++){
        std::cout << "_matrix_C[" << i << "]" <<"[" << j << "] = " << _matrix_C[i][j] << std::endl; 
      }
    }

    return 0;
}

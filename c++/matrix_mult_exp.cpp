#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

const int matrix_A_rows = 1024;
const int matrix_A_cols = 1024;
const int matrix_B_rows = 1024;
const int matrix_B_cols = 1024;

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

void tiled_matrix_mult(){
   const int BLOCK_SIZE = 128; // Adjust based on cache size

   for (int ii = 0; ii < matrix_A_rows; ii += BLOCK_SIZE) {
       for (int jj = 0; jj < matrix_B_cols; jj += BLOCK_SIZE) {
           for (int kk = 0; kk < matrix_A_cols; kk += BLOCK_SIZE) {
               for (int i = ii; i < ii + BLOCK_SIZE; ++i) {
                   std::vector<int> _vec_C;
                   for (int j = jj; j < jj + BLOCK_SIZE; ++j) {
                       int value = 0;
                       for (int k = kk; k < kk + BLOCK_SIZE; ++k) {
                           value += _matrix_A[i][k] * _matrix_B[k][j];
                           //C[i][j] += A[i][k] * B[k][j];
                       }
                       _vec_C.push_back(value);
                   }
                   _matrix_C.push_back(_vec_C);
               }
           }
       }
   }
}

int main()
{
    std::cout<<"Hello World\n";
    
    std::chrono::time_point<std::chrono::system_clock> start, end;
    
    /*std::vector<std::vector<int>> _matrix_A;
    std::vector<std::vector<int>> _matrix_B;
    std::vector<std::vector<int>> _matrix_C;
    */
    
    // matrix A init
    for(int i = 0; i < matrix_A_rows ; i++){
      std::vector<int> _vec;
      for(int j = 0; j < matrix_A_cols ; j++){
        _vec.push_back(i*j);  
      }
      _matrix_A.push_back(_vec);
    }
    
    for(int i = 0; i < matrix_A_rows ; i++){
      for(int j = 0; j < matrix_A_cols ; j++){
        //std::cout << "_matrix_A[" << i << "]" <<"[" << j << "] = " << _matrix_A[i][j] << std::endl; 
      }
    }
    
    std::cout << std::endl;
    
    // matrix B init
    for(int i = 0; i < matrix_B_rows ; i++){
      std::vector<int> _vec;
      for(int j = 0; j < matrix_B_cols ; j++){
        _vec.push_back(i+j);  
      }
      _matrix_B.push_back(_vec);
    }
    
    for(int i = 0; i < matrix_B_rows ; i++){
      for(int j = 0; j < matrix_B_cols ; j++){
        //std::cout << "_matrix_B[" << i << "]" <<"[" << j << "] = " << _matrix_B[i][j] << std::endl; 
      }
    }
    
    start = std::chrono::system_clock::now();
    matrix_mult();
    //tiled_matrix_mult();
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
    
    // matrix C display
    for(int i = 0; i < matrix_A_rows ; i++){
      for(int j = 0; j < matrix_B_cols ; j++){
        //std::cout << "_matrix_C[" << i << "]" <<"[" << j << "] = " << _matrix_C[i][j] << std::endl; 
      }
    }

    return 0;
}

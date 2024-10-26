#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

const int matrix_A_rows = 128;
const int matrix_A_cols = 128;
const int matrix_B_rows = 128;
const int matrix_B_cols = 128;

std::vector<std::vector<int>> _matrix_A(matrix_A_rows, std::vector<int>(matrix_A_cols,0));
std::vector<std::vector<int>> _matrix_B(matrix_B_rows, std::vector<int>(matrix_B_cols,0));
std::vector<std::vector<int>> _matrix_C(matrix_A_rows, std::vector<int>(matrix_B_cols,0));

void matrix_init(int rows, int cols, std::vector<std::vector<int>> &_matrix){
  for(int i = 0; i < rows ; i++){
      for(int j = 0; j < cols ; j++){
        _matrix[i][j] = i*j;
      }
    }
}

void matrix_display(int rows, int cols, std::vector<std::vector<int>> &_matrix){
  for(int i = 0; i < rows ; i++){
      for(int j = 0; j < cols ; j++){
        //std::cout << "_matrix_A[" << i << "]" <<"[" << j << "] = " << _matrix_A[i][j] << std::endl; 
      }
    } 
}

void matrix_mult(){
  for(int i = 0 ; i < matrix_A_rows ; i++){
    //std::vector<int> _vec_C;  
    for(int j = 0 ; j < matrix_B_cols ; j++){
      //int value = 0;
      for(int k = 0 ; k < matrix_A_cols ; k++){ 
        _matrix_C[i][k] += _matrix_A[i][k] * _matrix_B[k][j];  
      }
      //_vec_C.push_back(value);
    }
    //_matrix_C.push_back(_vec_C);
  }      
}

void tiled_matrix_mult(){
   const int BLOCK_SIZE = 128; // Adjust based on cache size

   for (int ii = 0; ii < matrix_A_rows; ii += BLOCK_SIZE) {
       for (int jj = 0; jj < matrix_B_cols; jj += BLOCK_SIZE) {
           for (int kk = 0; kk < matrix_A_cols; kk += BLOCK_SIZE) {
               for (int i = ii; i < ii + BLOCK_SIZE; ++i) {
                   //std::vector<int> _vec_C;
                   for (int j = jj; j < jj + BLOCK_SIZE; ++j) {
                       //int value = 0;
                       for (int k = kk; k < kk + BLOCK_SIZE; ++k) {
                           //value += _matrix_A[i][k] * _matrix_B[k][j];
                           _matrix_C[i][k] += _matrix_A[i][k] * _matrix_B[k][j];
                       }
                       //_vec_C.push_back(value);
                   }
                   //_matrix_C.push_back(_vec_C);
               }
           }
       }
   }
}

int main()
{
    std::cout<<"Hello World\n";
    
    std::chrono::time_point<std::chrono::system_clock> start, end;
    
    /*std::vector<std::vector<int>> _matrix_A(matrix_A_rows, std::vector<int>(matrix_A_cols,0));
    std::vector<std::vector<int>> _matrix_B(matrix_B_rows, std::vector<int>(matrix_B_cols,0));
    std::vector<std::vector<int>> _matrix_C(matrix_A_rows, std::vector<int>(matrix_B_cols,0));*/
    
    
    // matrix A init
    matrix_init(matrix_A_rows, matrix_A_cols, _matrix_A);
    
    std::cout << std::endl;
    
    // matrix B init
    matrix_init(matrix_B_rows, matrix_B_cols, _matrix_B);
    
    start = std::chrono::system_clock::now();
    
    // calling matrix mult
    matrix_mult();
    //tiled_matrix_mult();
    
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
    
    // matrix C display
    matrix_display(matrix_A_rows, matrix_B_cols, _matrix_C);

    return 0;
}

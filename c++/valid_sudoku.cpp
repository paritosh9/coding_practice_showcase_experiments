/*
simple solution first is to go through each row and colomn to make sure its valid 
then through 3X3 matrix to make sure its valid 
time complexity will be 3 X O(n) so O(n)? , n is number of elements in matrix?
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      int row_size = 9, col_size = 9, sub_row_size = 3 , sub_col_size = 3;

      unordered_set<int> sets;
      // loop over all rows
      for(int i = 0; i < row_size; i++){
        sets.clear();
        for(int j = 0; j < col_size; j++){
          if(board[i][j] == '.'){
            continue;
          }
          auto it = sets.find(board[i][j]);
          if(it != sets.end()){
            std::cout << "here 1 " << endl;
            return 0;    
          } else{
              sets.insert(board[i][j]);
          }
        }
      }

      sets.clear();
      // loop over all columns
      for(int j = 0; j < col_size; j++){
        sets.clear();
        for(int i = 0; i < row_size; i++){
          if(board[i][j] == '.'){
            continue;
          }
          auto it = sets.find(board[i][j]);
          if(it != sets.end()){
            std::cout << "here 2 " << endl;
            return 0;    
          } else{
              sets.insert(board[i][j]);
          }
        }
      }

      sets.clear();
      //loop over 3X3 matrix
      for(int a = 0; a < sub_row_size; a++){
        for(int b = 0; b < sub_col_size; b++){
            sets.clear();
            for(int i = a*sub_row_size ; i < (a+1)*sub_row_size; i++){
                for(int j = b*sub_col_size ; j < (b+1)*sub_col_size; j++){
                    if(board[i][j] == '.'){
                        continue;
                    }
                    auto it = sets.find(board[i][j]);
                    if(it != sets.end()){
                        std::cout << "here 3 " << endl;
                        return 0;    
                    } else{
                        sets.insert(board[i][j]);
                    }
                }
            }
        }
      }
      return 1;
    }
};

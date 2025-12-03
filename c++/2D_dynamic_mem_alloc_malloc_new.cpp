#include <iostream>
using namespace std;

int main() {
    // Write C++ code here
    // new , malloc
    // 2D dynamic array allocation and release/delete
    
    // malloc 1D
    size_t n = 10;
    int *memptr = (int*)malloc(n*sizeof(int));
    
    for(int i=0; i<n; i++){
        memptr[i] = i*2;
    }

    cout << endl << "before freeing mem : " << endl;
    for(int i=0; i<n; i++){
        cout << memptr[i] << " ";
    }
    
    // free
    free(memptr);
    if(memptr == nullptr){
        cout << "memptr is nullptr " << endl;
    }
    cout << endl << "after freeing mem : " << endl;
    for(int i=0; i<n; i++){
        //cout << memptr[i] << endl;
    }
    
    
    // new
    int *memptr_usingnew = new int[10];
    for(int i=0; i<n; i++){
        memptr_usingnew[i] = i*3;
    }
    
    cout << endl << "before delete mem : " << endl;
    for(int i=0; i<n; i++){
        cout << memptr[i] << " ";
    }
    
    // delete
    delete[] memptr_usingnew;
    if(memptr_usingnew == nullptr){
        cout << "memptr_usingnew is nullptr " << endl;
    }
    
    //////////////// 2D //////////////
    size_t row = 10;
    size_t col = 20;
    
    int** arr = (int**)malloc(row*sizeof(int*));
    
    for(int i=0; i<row; i++){
        arr[i] = (int*)malloc(col*sizeof(int));
    }
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            arr[i][j] = i+j;
        }
    }
    cout << endl <<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    for(int i=0; i<row; i++){
        free(arr[i]);
        arr[i] = nullptr;
    }
    
    free(arr);
    arr = nullptr;
    
    ///////////// 2D new ////////////////
    int **new2Darr = new int*[row];
    for(int i=0; i<row; i++){
            new2Darr[i] = new int[col];
    }
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            new2Darr[i][j] = i+j;
        }
    }
    
    cout << endl <<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << new2Darr[i][j] << " ";
        }
        cout << endl;
    }
    
    for(int i=0; i<row; i++){
        delete[] new2Darr[i];
        new2Darr[i] = nullptr;
    }
    delete[] new2Darr;
    new2Darr = nullptr;
    
    return 0;
}

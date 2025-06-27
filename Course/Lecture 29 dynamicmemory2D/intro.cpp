#include<iostream>
using namespace std;

int main(){

    int *arr = new int[n];
    // a 1D array is formed by combining blocks of int type from heap
    
    //creating a 2D array with m rows and n columns.
    int **arr2D = new int *[m];
    for (int i = 0; i < m;i++){
        arr2D[i] = new int[n];
    }
    // a 2D array is formed by combining n arrays of int type.
    // n rows of int* created. filling elements in int* will create columns
    // a for loop can define elements of each column (int*) then.

    //releasing memory
    for (int i = 0; i < m;i++){
        delete[] arr2D[i];
    }
    delete[] arr2D;
}
#include<iostream>
using namespace std;

void insertionsort(int arr[],int n){

    for (int i = 1; i < n;i++){
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0;j--){
            if(arr[j]>temp){
                arr[j + 1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}

//very adaptable way to sort an array.
//time complexity = O(n^2). best case O(1).
//space complexity = O(1)

void printarray(int arr[],int n){
    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[7] = {2, 9, 6, 3, 4, 1, 5};
    insertionsort(arr, 7);
    printarray(arr, 7);
}
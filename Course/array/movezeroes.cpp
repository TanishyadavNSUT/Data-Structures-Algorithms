#include<iostream>
using namespace std;

void movezeroes(int arr[],int n){
    int i = 0;
    for (int j = 0; j < n;j++){
        if(arr[j]!=0){
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

void printarray(int arr[],int n){
    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[16] = {2, 0, 1, 3, 0, 9, 0, 1, 1, 0, 0, 3, 1, 0, 0, 0};
    movezeroes(arr, 16);
    printarray(arr, 16);
}
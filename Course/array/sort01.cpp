#include<iostream>
using namespace std;

void sort01(int arr[],int n){
    int i = 0;
    int j = n-1;

    while(i<j){
        while(arr[i]==0&& i<j){
          i++;
    }
        while(arr[j]==1&& i<j){
          j--;
    }
        if(arr[i]==1 && arr[j]==0){
          swap(arr[i], arr[j]);
    }

    }
}

void printarray(int arr[],int n){
    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
}


int main(){
    int arr[9] = {0, 1, 0, 1, 0, 0, 0, 1, 1};
    sort01(arr, 9);

    printarray(arr, 9);
}
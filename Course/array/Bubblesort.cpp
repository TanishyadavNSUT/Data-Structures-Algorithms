#include<iostream>
using namespace std;

void printarray(int arr[],int n){
    for (int i = 0; i < n;i++){
        cout << arr[i]<<" ";
    }
}

void bubblesort(int arr[],int n){
    for (int i = 1; i < n ;i++){
        bool swapped = false;
        for (int j = 0; j < n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(swapped=false){   //this helps in changing best case time complexity from O(n^2) to O(1)
            break;
        }
    }
}

//time complexity = O(n^2)
//space complexity = O(1)

int main(){

    int arr[7] = {9, 4, 6, 7, 2, 1, 3};
    bubblesort(arr, 7);
    printarray(arr, 7);
}
#include<iostream>
using namespace std;

void swap_alt(int arr[],int n){
    
    int i = 0;
    while(i<n-1){
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;

        i = i + 2;
    }
}

void printArray(int arr[],int n){
    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
}

    int main()
{

    int arr[5] = {1, 2, 3, 4, 5};
    int brr[6] = {1, 2, 3, 4, 5, 6};

    swap_alt(arr, 5);
    printArray(arr, 5);
    cout << endl;
    swap_alt(brr, 6);
    printArray(brr, 6);
}
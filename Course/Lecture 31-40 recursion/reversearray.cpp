#include<iostream>
using namespace std;

void printarray(int arr[], int n){
    for (int i = 0; i < n;i++){
        cout << arr[i]<<" ";
    }
}

void reversearray1( int arr[],int s, int e){
    if(s>=e)
        return;
    swap(arr[s], arr[e]);
    reversearray1( arr, s=s+1, e=e-1);
}

void reversearray2(int arr[], int i, int n){
    if(i>=n/2){
        return;
    }
    swap(arr[i], arr[n - i - 1]);
    reversearray2(arr, i = i + 1, n);
}

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    reversearray1(arr, 0, 4);
    printarray(arr, 5);
    reversearray2(arr, 0, 5);
    cout << endl;
    printarray(arr, 5);
    return 0;
}
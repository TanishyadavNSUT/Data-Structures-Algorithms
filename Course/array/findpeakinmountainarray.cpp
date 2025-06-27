#include<iostream>
using namespace std;

int peakinmountain(int arr[],int n){

    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while(start<end){
        if(arr[mid]<arr[mid+1]){
            start = mid+1;
        }

        else if(arr[mid]>arr[mid+1]){
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}

int main(){
    int arr[7] = {1, 4, 5, 3, 2, 1, 0};

    int peak = peakinmountain(arr, 7);
    cout << peak;
}
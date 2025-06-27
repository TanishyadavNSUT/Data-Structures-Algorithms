#include<iostream>
using namespace std;

int findpivot(int arr[],int n){

    int start = 0;
    int end = n - 1;

    int mid = start + (end - start) / 2;
    while(start<end){
        if(arr[mid]>=arr[0]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}

int main(){

    int arr[5] = {4,5,0,1,2};
    int pivot = findpivot(arr, 5);
    cout << pivot;
}
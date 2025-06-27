#include<iostream>
using namespace std;

int get_max(int arr[],int n){

    int max = INT32_MIN;
    for (int i = 0; i < n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int main(){

    int arr[5] = {1, 2, 3, 4, 8};
    int max = get_max(arr, 5);
    cout << max << endl;
}
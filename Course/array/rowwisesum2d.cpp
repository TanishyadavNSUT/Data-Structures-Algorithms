#include<iostream>
using namespace std;

void largestsum(int arr[][4],int m,int n){
    int brr[m];
    int index = 0;
    int sum = 0;
    for (int i = 0; i < m;i++){
        sum = 0;
        for (int j = 0; j < n;j++){
            sum = sum + arr[i][j];
        }
        brr[index++] = sum;
    }
    int max = -1;
    int row = 0;
    for (int i = 0; i < m;i++){
        if(brr[i]>max){
            row = i+1;
            max = brr[i];
        }
    }
    cout << "sum of row "  <<row << " is largest and equal to " << max << endl;
}


int main(){

    int arr[3][4];
    cout << "enter elements ";

    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 4;j++){
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 4;j++){
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }
    largestsum(arr, 3, 4);
}
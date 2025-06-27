#include<iostream>
using namespace std;

void reverse_array(int arr[],int n){

    int start = 0;
    int end = n - 1;

    while(start<=end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void display(int arr[], int n){
    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
}

    int main()
{
    int n;
    cin >> n;
    cout << "enter array elements:" << endl;
    
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }

    reverse_array(arr, n);
    display(arr, n);
}
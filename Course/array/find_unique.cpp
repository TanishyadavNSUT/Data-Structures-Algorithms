#include<iostream>
using namespace std;

int find_unique(int arr[],int n){

    int ans = 0;
    for (int i = 0; i < n;i++){
        ans = ans ^ arr[i];    //XOR with itself return 0 and XOR of any element with 0 return the element itself.
    }
    return ans;
}

int main(){

    int arr[5] = {1, 1, 2, 2, 3};
    cout << find_unique(arr, 5);
}

#include<iostream>
using namespace std;

bool linear_search(int arr[],int n,int key){
    for (int i = 0; i < n;i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}

int main(){

    int arr[5] = {1, 2, 3, 4, 5};
    if(linear_search(arr, 5, 7)==1){
        cout << "element is present";
    }
    else{
        cout << "element not present";
    }
}
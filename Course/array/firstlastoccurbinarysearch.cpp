#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int firstoccur(int arr[],int n,int key){

    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while(start<=end){

        if(arr[mid]==key){
            ans = mid;
            end = mid - 1;

        }
        else if(arr[mid]>key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int lastoccur(int arr[],int n,int key){

    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while(start<=end){

        if(arr[mid]==key){
            ans = mid;
            start = mid +1 ;

        }
        else if(arr[mid]>key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}


int main(){

    int arr[6] = {1, 1, 1, 1, 1, 2};
    //for total no. of occurences

    int total = (lastoccur(arr, 6, 2) - firstoccur(arr, 6, 2)) + 1;
    cout << total;
}
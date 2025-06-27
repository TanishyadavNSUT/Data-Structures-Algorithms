#include <bits/stdc++.h> 

void heapify(vector<int> &arr,int i){
    
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<arr.size() && arr[left]<arr[smallest]){
        smallest=left;
    }
    if(right<arr.size() && arr[right]<arr[smallest]){
        smallest=right;
    }

    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        heapify(arr,smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,i);
    }
    return arr;
}
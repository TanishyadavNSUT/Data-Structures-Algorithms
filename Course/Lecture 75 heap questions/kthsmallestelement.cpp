#include<iostream>
using namespace std;

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        
        
        //step1: making heap using first k elements 
        priority_queue<int> pq;
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        
        //step2: adding remaining elements based on condition 
        for(int i=k;i<=r;i++){
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        return pq.top();
    }
};
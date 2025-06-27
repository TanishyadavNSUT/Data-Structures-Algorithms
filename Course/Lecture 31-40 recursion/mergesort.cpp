#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    int left = low;
    int right = mid+1;
    vector<int> temp;
    while(left<=mid&&right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        if(arr[right]<arr[left]){
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high;i++){
        arr[i] = temp[i-low];
    }
}

void mergesort(vector<int> &arr, int low , int high){
    if(low>=high){
        return;
    }
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

//Time complexity O(Nlog(N))
//Space complexity O(N)

int main(){
    vector<int> s = {6, 3, 9, 1, 8, 7, 4, 6, 2, 5};
    mergesort(s, 0, 9);
    for (int i = 0; i < s.size();i++){
        cout << s[i] << " ";
    }
    return 0;
}

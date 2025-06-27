#include<iostream>
#include<vector>
using namespace std;

int part(vector<int> &arr,int low ,int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<=pivot&&i<=high-1){
            i++;
        }
        while(arr[j]>pivot&&j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quicksort(vector<int> &arr,int low,int high){
    if(low<high){
        int partitionindex = part(arr, low, high);
        quicksort(arr, low, partitionindex - 1);
        quicksort(arr, partitionindex + 1, high);
    }
}

//Time complexity O(NlogN)
//space complexity O(1)

int main(){
    vector<int> s = {6, 3, 9, 1, 8, 7, 4,6, 2, 5};
    quicksort(s, 0, 9);
    for (int i = 0; i < s.size();i++){
        cout << s[i] << " ";
    }
    return 0;
}
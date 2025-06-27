#include<iostream>
using namespace std;

int binarysearch(int arr[], int start,int end,int key){

    int mid = start + (end - start) / 2;    //optimization so that, whenever start and end are equal to 
    while(start<=end){                      //int max then they won't add to a value outside int range.


        if(arr[mid]==key){
            cout << "element found at ";
            return mid;
        }
        else if(arr[mid]<key){
            start = mid + 1;
        }
        else if(arr[mid]>key){
            end = mid - 1;
        }
        
        mid = start + (end - start) / 2;
    }
    cout << "element not found" << endl;
    return -1;
}

int findpivot(int arr[],int n){

    int start = 0;
    int end = n - 1;

    int mid = start + (end - start) / 2;
    while(start<end){
        if(arr[mid]>=arr[0]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}


int main(){

    int arr[5] = {5, 1, 2, 3, 4};
    int pivot = findpivot(arr, 5);
    if(4 >= arr[pivot] && 4<=arr[4]){
        int ans=binarysearch(arr, pivot, 4, 4);
        cout << ans;
    }
    else{
        int ans=binarysearch(arr, 0, pivot - 1, 4);
        cout << ans;
    }

}
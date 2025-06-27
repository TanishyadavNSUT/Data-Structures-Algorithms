#include<iostream>
using namespace std;

int binarysearch(int arr[], int n,int key){

    int start = 0;
    int end = n - 1;
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

int main(){
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int brr[6] = {2, 4, 6, 9,11,13};
    cout << binarysearch(brr, 6,11) << endl;
}
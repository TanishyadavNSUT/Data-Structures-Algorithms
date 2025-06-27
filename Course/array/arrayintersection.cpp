#include<iostream>
#include<vector>
using namespace std;

vector<int> arrayintersection(vector<int> & arr1,int n,vecor<int>){

    vector<int> ans;

    for (int i = 0; i < n;i++){
        int element = arr[i];
        for (int j = 0; j < m;j++){
            if(arr2[j]==element){
                ans.push_back(element);
                arr2[j] = INT_FAST32_MIN;
                break;
            }
        }
    }
    return ans;
}

//the above solution is not an optimized solution and therefore it will give time limit exceeded error.
//we can use the condition that arrrays are in non decreasing order for an optimal solution.

vector<int> arrayintersection(vector<int> & arr1,int n,vecor<int>){

    vector<int> ans;

    for (int i = 0; i < n;i++){
        int element = arr[i];
        for (int j = 0; j < m;j++){

            if(arr[j]>element){
                break;                 //optimization 1, if element is smaller than array 2 element then no need to search further.
            }
            if(arr2[j]==element){
                ans.push_back(element);
                arr2[j] = INT_FAST32_MIN;
                break;
            }
        }
    }
    return ans;
}

//final most optimized solution with only one while loop to reduce time complexity from O(mn) to O(m,n)

vector<int> arrayintersection(vector<int> & arr1,int n,vecor<int>){

    int i = 0, j = 0;
    vector<int> ans;

    while (i < n && j < m)
    {
        if(arr1[i]==arr2[j]){
            ans.push_back(arr2[j]);
            i++;
            j++;
        }
        else if(arr1[i]>arr2[j]){
            j++;
        }
        else{
            i++;
        }
    }
    return ans;
}


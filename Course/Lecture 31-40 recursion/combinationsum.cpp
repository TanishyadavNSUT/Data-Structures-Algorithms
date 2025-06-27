#include<iostream>
#include<vector>
using namespace std;

void findcombination(int index,int target,vector<int> &arr,vector<vector<int>> &ans,vector<int>&ds){
    if(index==arr.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }
    if(arr[index]<=target){
        ds.push_back(arr[index]);
        findcombination(index, target - arr[index], arr, ans, ds);
        ds.pop_back();
    }
    findcombination(index + 1, target, arr, ans, ds);
}

vector<vector<int>> combinationsum(vector<int> &candidates,int target){
    vector<vector<int>> ans;
    vector<int> ds;
    findcombination(0, target, candidates, ans, ds);
    return ans;
}

int main(){

    vector<int> a = {2, 3, 4, 7};
    vector<vector<int>> b = combinationsum(a, 7);
    for (int i = 0; i < b.size();i++){
        cout << "[";
        for (int j = 0; j < b[i].size();j++){
            cout << b[i][j] << ",";
        }
        cout << "]";
        cout << endl;
    }
    return 0;
}
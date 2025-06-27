#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findcombination(int index, int target,vector<int>&arr ,vector<vector<int>> &ans, vector<int>&ds){
    if(target==0){
        ans.push_back(ds);
        return;
    }
    for (int i = index; i < arr.size();i++){
        if(i>index&&arr[i]==arr[i-1])
            continue;
        if(arr[i]>target)
            break;
        ds.push_back(arr[i]);
        findcombination(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}

vector<vector<int>> combinationsum(vector<int> &candidate,int target){
    sort(candidate.begin(), candidate.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findcombination(0, target, candidate, ans, ds);
    return ans;
}

int main(){
    vector<int> a = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> final = combinationsum(a, 8);
    for (int i = 0; i < final.size();i++){
        cout << "[";
        for (int j = 0; j < final[i].size();j++){
            cout << final[i][j];
            if (j < final[i].size()-1)
                cout << ",";
        }
        cout << "]";
        cout << endl;
    }
}


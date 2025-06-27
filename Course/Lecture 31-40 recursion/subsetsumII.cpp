#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findsubsets(int index,vector<int> &nums,vector<int>&ds,vector<vector<int>> &ans){
    ans.push_back(ds);
    for (int i = index; i < nums.size();i++){
        if(i!=index&&nums[i]==nums[i-1]){
            continue;
        }
        ds.push_back(nums[i]);
        findsubsets(i + 1, nums, ds, ans);
        ds.pop_back();
    }
}

    vector<vector<int>> subsetnodup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    findsubsets(0, nums, ds, ans);
    return ans;
}

//time complexity O(2^N(N))

int main(){
    vector<int> a = {1, 2, 2};
    vector<vector<int>> b = subsetnodup(a);
    for (int i = 0; i < b.size();i++){
        cout << "[";
        for (int j = 0; j < b[i].size();j++){
            cout << b[i][j];
            if(j<b[i].size()-1){
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
}
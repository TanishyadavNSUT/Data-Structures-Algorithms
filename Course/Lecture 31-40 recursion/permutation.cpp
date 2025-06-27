#include<iostream>
#include<vector>
using namespace std;

void permutations(vector<int> &ds, vector<int> &nums,vector<vector<int>> &ans, int freq[]){
    if(ds.size()==nums.size()){
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < nums.size();i++){
        if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i] = 1;
            permutations(ds, nums, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

vector<vector<int>> permutation(vector<int> &nums){
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()]={0};
    for (int i = 0; i < nums.size();i++){
        freq[i] = 0;
    }

    permutations(ds, nums, ans, freq);
    return ans;
}

int main(){
    vector<int> v = {1, 2, 3};
    vector<vector<int>> a = permutation(v);
    for (int i = 0; i < a.size();i++){
        cout << "[";
        for (int j = 0; j < a[i].size();j++){
            cout << a[i][j];
            if(j<a[i].size()-1){
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
}
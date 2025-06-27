#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &ans){
    for (int i = 0; i < ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

void permutations(int index, vector<int>&nums, vector<vector<int>> &ans){
    if(index==nums.size()){
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size();i++){
        swap(nums[index], nums[i]);
        permutations(index + 1, nums, ans);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permutation(vector<int> &nums){
    vector<vector<int>> ans;
    permutations(0, nums, ans);
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

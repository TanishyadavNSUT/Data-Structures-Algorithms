#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int> &nums){
    int count = 0;
    for (int i = 1; i < nums.size();i++){
        if(nums[i-1]>nums[i]){
            count++;
        }
    }
    if(nums[0]<nums[nums.size()-1]){
        count++;
    }
    if(count<=1){
        return 1;
    }
    return 0;
}

int main(){
    vector<int> v = {3, 4, 6, 1, 5};
    cout << check(v);
}
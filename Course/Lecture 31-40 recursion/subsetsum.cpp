#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int sum = 0;

void subsetsum(int i, vector<int> &arr, vector<int> &ans,vector <int> &ds,int sum){

    if(i>=arr.size()){
        ans.push_back(sum);
        return;
    }
    ds.push_back(arr[i]);
    sum = sum + arr[i];
    subsetsum(i + 1, arr, ans, ds,sum);
    sum = sum - arr[i];
    ds.pop_back();
    subsetsum(i + 1, arr, ans, ds,sum);
}

vector<int> findsubsetsum(vector<int> &arr){
    vector<int> ans;
    vector<int> ds;
    subsetsum(0, arr, ans, ds,sum);
    return ans;
}

int main(){
    vector<int> a = {1, 2, 3};
    vector<int> sum = findsubsetsum(a);
    sort(sum.begin(), sum.end());
    for (int i = 0; i < sum.size();i++){
        cout << sum[i]<<" ";
    }
}
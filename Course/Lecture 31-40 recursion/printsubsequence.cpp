#include<iostream>
#include<vector>
using namespace std;

vector<int> ans{};

void print(vector<int> &v){
    for (int i = 0; i < v.size();i++){
        cout << v[i] << " ";
    }
}

void subsequence(int i, vector<int> &v){
    if(i>=v.size()){
        print(ans);
        cout << endl;
        return;
    }
    ans.push_back(v[i]);
    subsequence(i + 1, v);
    ans.pop_back();
    subsequence(i + 1, v);
}

//time complexity o(n*(2^n))
//space complexity O(n)

int main(){

    vector<int> v = {1, 2, 3};
    subsequence(0, v);
}
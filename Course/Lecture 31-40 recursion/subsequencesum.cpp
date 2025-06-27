#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
    for (int i = 0; i < v.size();i++){
        cout << v[i] << " ";
    }
}

vector<int> ans = {};
int sum = 0;

void subsequence(int i,vector<int> &v,int n){
    if(i>=v.size()){
        if(sum==n){
            print(ans);
            cout << endl;
        }
        return;
    }
    ans.push_back(v[i]);
    sum = sum + v[i];
    subsequence(i + 1, v,n);
    sum = sum - v[i];
    ans.pop_back();
    subsequence(i + 1, v,n);
}

//technique to print only one subsequence
bool subsequence1(int i,vector<int> &v,int n){
    if(i>=v.size()){
        if(sum==n){
            print(ans);
            cout << endl;
            return true;
        }
        return false;
    }
    ans.push_back(v[i]);
    sum = sum + v[i];
    if(subsequence1(i + 1, v,n))
        return true;
    sum = sum - v[i];
    ans.pop_back();
    if(subsequence1(i + 1, v,n))
        return true;
    return false;
}

//code for count of no. of subsequence
int subsequence2(int i,vector<int> &v,int n){
    if(i>=v.size()){
        if(sum==n){
            return 1;
        }
        return 0;
    }
    ans.push_back(v[i]);
    sum = sum + v[i];
    int l = subsequence2(i + 1, v, n);
    sum = sum - v[i];
    ans.pop_back();
    int s = subsequence2(i + 1, v, n);
    return l+s;
}

int main(){
    vector<int> a = {0, -1, 1,0};
    subsequence(0, a, 0);
    subsequence1(0, a, 0);
    cout << subsequence2(0, a, 0);
    return 0;
}
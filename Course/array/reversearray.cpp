#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){

    for(int i = 0; i < v.size();i++){
        cout << v[i] << " ";
    }
}

vector<int> reverse(vector<int> v, int m){

    int start = m+1;
    int end = v.size() - 1;
    while(start<=end){
        swap(v[start++], v[end--]);
    }
    return v;
}

    int main()
{

    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int> ans = reverse(v,1);
    print(ans);
}

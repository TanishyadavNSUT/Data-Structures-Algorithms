#include<iostream>
using namespace std;

void reverse(vector<int> &v){
    int start = 0;
    int end = v.size() - 1;
    while(start<=end){
        swap(v[start++], v[end--]);
    }
}

vector<int> add2array(vector<int> &a, vector<int> &b){
    int i = a.size() - 1;
    int j = b.size() - 1;
    vector<int> ans;
    int carry = 0;
    
    while(i>=0&&j>=0){
        int val1 = a[i--];
        int val2 = b[j--];
        int sum = (val1 + val2 + carry) % 10;
        carry = (val1 + val2 + carry) / 10;
        ans.push_back(sum);
    }

    while(i>=0){
        int sum = a[i--] + carry;
        sum = sum % 10;
        carry = sum / 10;
        ans.push_back(sum);
    }

    while(j>=0){
        int sum = b[j--] + carry;
        sum = sum % 10;
        carry = sum / 10;
        ans.push_back(sum);
    }

    while(carry!=0){
        int sum = carry % 10;
        carry = carry / 10;
        ans.push_back(sum);
    }
    return reverse(ans);
}




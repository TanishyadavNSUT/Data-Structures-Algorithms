#include<iostream>
#include<string>
using namespace std;

bool checkpalindrome(string s1, int i, int n){
    if(i>=n/2){
        return true;
    }
    if(s1[i]!=s1[n-i-1]){
        return false;
    }
    return checkpalindrome(s1, i + 1, n);
}

int main(){
    string s = "abcdefghgfedcba";
    cout << checkpalindrome(s, 0, 15);
}
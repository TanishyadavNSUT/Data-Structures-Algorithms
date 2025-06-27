#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){

    stack<char> s;

    string str = "tanish";

    for (int i = 0; i < str.length();i++){
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";
    while(!s.empty()){
        char a = s.top();
        ans.push_back(a);
        s.pop();
    }

    cout << "reverse of tanish is " << ans << endl;
}
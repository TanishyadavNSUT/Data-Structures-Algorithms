#include<iostream>
#include<string>
using namespace std;

string remove(string s){
    string temp;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='1'&&s[i]<='9')){
            temp.push_back(s[i]);
        }
    }
    return temp;
}

char tolowercase(char ch){
    if(ch>='a'&&ch<='z'){
        return ch;
    }
    else{
        return ch-'A'+'a';
    }
}
bool checkPalindrome(string s) {
    string final = remove(s);
    int start=0;
    int end=final.length()-1;

    while (start <= end){
        if(tolowercase(final[start++])!=tolowercase(final[end--])){
            return 0;
        }
    }
    return 1;
}

int main(){
    string s = "OP";
    cout << checkPalindrome(s);
}
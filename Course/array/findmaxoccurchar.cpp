#include<iostream>
using namespace std;

char getmaxoccchar(string s){
    int arr[26] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        int number = 0;
        if(ch>='a'&&ch<='z'){
            number = ch - 'a';
        }
        else{
            number = ch - 'A';
        }
        arr[number]++;
    }

    int max = -1;
    int answer = 0;
    for (int i = 0; i < 26;i++){
        if(max<arr[i]){
            answer = i;
            max = arr[i];
        }
    }
    char final = 'a' + answer;
    return final;
}

int main(){
    string s;
    cin >> s;
    cout<<getmaxoccchar(s);
}
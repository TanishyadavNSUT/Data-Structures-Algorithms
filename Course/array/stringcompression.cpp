#include<iostream>
#include<vector>
#include<string>
using namespace std;

int stringcompress(vector<char> &chars){
    int i = 0;
    int answerindex = 0;
    int n = chars.size();
    while(i<n){
        int j = i + 1;
        while(j<n && chars[i]==chars[j] ){
            j++;
        }
        chars[answerindex++] = chars[i];
        int count = j - i;
        if(count>1){
            string cnt = to_string(count);
            for(char ch:cnt){
                chars[answerindex++] = ch;
            }
        }
        i = j;
    }
    return answerindex;
}

int main(){
    vector<char> chars ={ 'a', 'a', 'b', 'b', 'c', 'c', 'c','c','c','d'};
    cout << stringcompress(chars);
    return 0;
}
#include<iostream>
using namespace std;

bool checkequal(int arr[26],int brr[26]){
    for (int i = 0; i < 26;i++){
        if(arr[i]!=brr[i]){
            return 0;
        }
    }
    return 1;
}

bool checkinclusion(string s1, string s2){
    int arr[26] = {0};
    for (int i = 0; i < s1.length();i++){
        int number = s1[i] - 'a';
        arr[number]++;
    }
    int i = 0;
    int windowsize = s1.length();
    int brr[26] = {0};
    while(i<windowsize&&i<s2.length()){
        int number = s2[i] - 'a';
        brr[number]++;
        i++;
    }

    if(checkequal(arr,brr)){
        return 1;
    }

    while(i<s2.length()){
        char newchar = s2[i];
        int number = newchar - 'a';
        brr[number]++;

        char oldchar = s2[i - windowsize];
        number = oldchar - 'a';
        brr[number]--;
        i++;

        if(checkequal(arr,brr)){
            return 1;
        }
    }
    return 0;
}

int main(){
    string s1 = "abc";
    string s2 = "eidbaooo";
    cout<<checkinclusion(s1, s2);
    return 0;
}
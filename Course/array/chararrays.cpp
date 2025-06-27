#include<iostream>
using namespace std;

char tolowercase(char ch){
    if(ch>='a'&&ch<='z'){
        return ch;
    }
    else{
        return ch - 'A' + 'a';
    }
}

bool ispalindrome(char ch[],int n){  //palindrome mean reversed and original should be same. ex. abcba
    int start = 0;
    int end = n - 1;
    while(start<=end){
        if(tolowercase(ch[start])!=tolowercase(ch[end])){
            return 0;
        }
        else{
            start++;
            end--;
        }
    }
    return 1;
}

void reverse(char ch[],int n){
    int start = 0;
    int end = n - 1;
    while(start<=end){
        swap(ch[start++], ch[end--]);
    }
}

int getlength(char ch[]){
    int count = 0;
    for (int i = 0; ch[i] !='\0';i++){
        count++;
    }
    return count;
}

int main(){
    
    char name[20];
    cout << "enter your name ";
    cin >> name;

    cout << "your name is ";
    cout << name << endl;
    int len = getlength(name);
    cout << "length of name is " << len << endl;
    reverse(name, len);
    cout << "reversed name " << name << endl;
    cout << "palindrome or not " << ispalindrome(name, len) << endl;
    cout << "character is " << tolowercase('b') << endl;
    cout << "character is " << tolowercase('B') << endl;

    char stud[20]; 
    cin.getline(stud, 20); // allows us to store character with spaces in a character array.
    cout << stud;  //we can also use a custom delimiter(only read till delimiter) by passing the function a third argument.
    //getline(stud,20,'|') it stops taking input when '|' is encountered 
}
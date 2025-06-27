#include<iostream>
#include<string>
using namespace std;

//when a function calls itself indefinitely until a specified 
//condition is fulfilled.

void print(int i,int n ){
    if(i>n){
        return ;
    }
    cout << "tanish" << " ";
    print(i+1, n);
}

void printno(int i,int n){
    if(i>n){
        return;
    }
    cout << i << " ";
    printno(i + 1, n);
}

void printre(int i,int n){
    if(n<i){
        return;
    }
    cout << n << " ";
    printre(i, n - 1);
}

//backtracking : print statement or code to be executed after recursive 
//function call

void printbt(int i){
    if(i<1){
        return;
    }
    printbt(i - 1);
    cout << i << " ";
}

void printbt2(int i, int n){
    if(i>n){
        return;
    }
    printbt2(i + 1, n);
    cout << i << " ";
}


int main(){
    print(1, 5);
    cout << endl;
    printno(1, 7);
    cout << endl;
    printre(0, 9);
    cout << endl;
    printbt(10);
    cout << endl;
    printbt2(2, 9);

    return 0;
}
#include<iostream>
using namespace std;

int fibonacci(int n){
    if(n<=1){
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// time complexity (2^n)

int main(){
    int n = 7;
    for (int i = 0; i < n;i++){
        cout << fibonacci(i) << " ";
    }
}
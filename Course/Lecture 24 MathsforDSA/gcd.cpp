#include<iostream>
using namespace std;

int gcd(int a,int b){

    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    while(a!=b){
        if(a>b){
            a = a - b;
        }
        else{
            b = b - a;
        }
    }
    return a;
}

// LCM(a,b) * GCD(a,b) =a*b

int main(){
    int a = 24, b = 72;
    cout << gcd(a, b);
}
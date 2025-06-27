#include<iostream>
using namespace std;

int sum = 0;

int sumn(int n){
    if(n==0){
        return n;
    }
    sum = n + sumn(n - 1);
}

//parameterized way

void printsum(int i, int sum1){
    if(i<1){
        cout << sum1;
        return;
    }
    printsum(i - 1, sum1 + i);
}

int factorial(int n){
    if(n==0)
        return 1;
    return n * factorial(n - 1);
}

int main(){
    cout << sumn(5);
    cout << endl;
    printsum(5, 0);
    cout << endl << factorial(5);
}
#include<iostream>
using namespace std;

int modularexponentiation(int x, int n, int m){
    int res = 1;

    while(n>0){
        if(n&1){
            res = (1LL* (res) * (x) % m) % m;
        }
        x = (1LL * (x) % m * (x) % m) % m;
        n = n >> 1;//right shifting n by 1 divides it by 2. it's more feasible 
    }
    return res;
}

int main(){
    int a = 2, b = 8, m = 10;
    cout << modularexponentiation(a, b, m);
}
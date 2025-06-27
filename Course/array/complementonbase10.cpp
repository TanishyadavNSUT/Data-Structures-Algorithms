#include<iostream>
using namespace std;

int complementbase10(int n){

    int mask = 0;
    int m = n;
    
    if(n==0){
        return 1;
    }
    while(m!=0){
        m= m >> 1;
        mask = (mask << 1) | 1;
    }
    int ans = (~n) & mask;
    return ans;
}

int main(){

    int answer = complementbase10(5);
    cout << answer;
}
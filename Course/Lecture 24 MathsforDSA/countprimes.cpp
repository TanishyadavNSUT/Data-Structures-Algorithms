#include<iostream>
using namespace std;

bool isprime(int n){
    if(n<=1){
        return 0;
    }
    for (int i = 2;i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int countPrimes(int n) {
    int count = 0;
    for (int i = 2; i < n;i++){
        if (isprime(i))
        {
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    cout << countPrimes(n);
}

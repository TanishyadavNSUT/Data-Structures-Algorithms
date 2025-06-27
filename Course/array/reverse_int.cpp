#include<iostream>
using namespace std;

int reverse_int(int n){
    int ans = 0;
    while(n!=0){
        int digit = n % 10;

        if((ans>INT_FAST32_MAX/10) ||(ans<INT_FAST32_MIN/10)){
            return 0;
        }
        ans = ans * 10 + digit;
        n = n / 10;
    }
    return ans;
}

int main(){
    
    int n = 5686;
    int answer = reverse_int(n);
    cout << answer << endl;
}
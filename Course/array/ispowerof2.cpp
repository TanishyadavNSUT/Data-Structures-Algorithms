#include<iostream>
using namespace std;

bool ispowerof2(int n){
    
    int ans = 1;
    for (int i = 0; i < 31;i++){
        if(ans==n){
            return 1;
        }
        if(ans<INT32_MAX/2){
        ans = ans * 2;
        }
    }
    return 0;
}

int main(){
    cout << ispowerof2(1023);
}
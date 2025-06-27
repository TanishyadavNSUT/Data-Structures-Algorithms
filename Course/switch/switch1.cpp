#include<iostream>
using namespace std;

int main(){

    while(1){
        int num = 1;

        switch(num){

            case 1:
                cout << "first" << endl;
                break;
            case 2:
                cout << "second" << endl;
                break;
            default:
                cout << "this is default case" << endl;
                break;

        }
        exit(1);
    }
}


#include<iostream>
using namespace std;

int main(){

    int amount;
    cout <<" enter the amount: ";
    cin >> amount;

    int num = 1;
    int note = 0;

    switch(num){

        case 1:{
            note = amount / 100;
            amount = amount - (note * 100);
            cout << "the no. of 100 rs notes are" << note << endl;
        }
        case 2:{
            note = amount / 50;
            amount = amount - (note * 50);
            cout << "the no. of 50 rs notes are" << note << endl;
        }
        case 3:{
            note = amount / 20;
            amount = amount - (note * 20);
            cout << "the no. of 20 rs notes are" << note << endl;
        }
        case 4:{
            cout << "the no. of 100 rs notes are" << amount << endl;
        }

    }
}
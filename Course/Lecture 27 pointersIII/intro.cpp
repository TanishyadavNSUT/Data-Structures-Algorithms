#include<iostream>
using namespace std;

void update(int **p){

    //p = p + 1;
    // nothing will change. passed by value instead of reference.only change inside function

    *p = *p + 1;
    // value changes since passed by reference.

    //**p = **p + 1;
    // value changes since passed by reference.
}

int main(){

    int i = 5;
    int *ptr1 = &i;
    int **ptr2 = &ptr1;
    
    /*cout << ptr1 << endl;
    cout << &ptr1 << endl;
    cout << *ptr2 << endl;

    cout << i << endl;
    cout << *ptr1 << endl;
    cout << **ptr2 << endl;

    cout << &i << endl;
    cout << ptr1 << endl;
    cout << *ptr2 << endl;

    cout << &ptr1 << endl;
    cout << ptr2 << endl;

    cout << i << endl;
    cout << ptr1 << endl;
    cout << ptr2 << endl;*/

    cout << endl<< endl;
    cout << "before " << i << endl;
    cout << "before " << ptr1 << endl;
    cout << "before " << ptr2 << endl;
    update(ptr2);
    cout << "after " << i << endl;
    cout << "after " << ptr1 << endl;
    cout << "after " << ptr2 << endl;
    cout << endl<< endl;

    return 0;
}
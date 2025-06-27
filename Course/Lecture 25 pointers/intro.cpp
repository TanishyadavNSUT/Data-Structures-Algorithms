#include<iostream>
using namespace std;

int main(){
    int num = 5;
    cout << num << endl;
    cout << &num << endl;  //will print address of num.
    int *ptr = &num;       // a pointer created which is pointing at address of num;
    (*ptr)++;
    cout << num << endl;

    // ptr is address of num; while *ptr is value at address ptr.
    cout << *ptr << endl;
    cout << ptr << endl;

    cout << "size of num is " << sizeof(num) << endl;
    cout << "size of pointer is " << sizeof(ptr) << endl;

    //copying a pointer
    int *q = ptr;
    cout << ptr << "-" <<q<< endl;
    cout << *ptr << "-" << *q << endl;

    return 0;
}
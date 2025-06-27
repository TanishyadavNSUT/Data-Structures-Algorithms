#include<iostream>
using namespace std;

int main(){
    int arr[10] = {2,7,9,11};  //arr represents address of first block of array
    cout << "address of first memory block " << arr << endl;
    cout << "address of first memory block " << &arr[0] << endl;
    cout << *arr << endl; // prints value at arr.
    cout << *arr + 1 << endl;
    cout << *(arr + 1) << endl;
    int i = 3;
    cout << arr[i] << endl;
    cout << i[arr] << endl; //arr[i]=*(arr+i)  and i[arr]=*(i+arr)

    int *ptr = arr;
    cout << ptr << endl;
    cout << *ptr << endl;
    ptr++; //ptr starts pointing to next block. each block has size 4. address increment by 4 
    cout << ptr << endl;
    cout << *ptr << endl;

    cout << "character array" << endl;

    int brr[5] = {1, 2, 3, 4, 5};
    char ch[6] = "abcde"; // one extra size for null character at end

    cout << brr << endl;
    cout << ch << endl; //implementation of cout for character arrays is different. therefore it has prints the whole array

    char *c = &ch[0];
    cout << c << endl;
    char temp = 'g';
    char *t = &temp;
    cout << t << endl;//prints till next null character 
}
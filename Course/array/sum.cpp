#include <iostream>
using namespace std;

int sum(int arr[], int size){
    int sum1 = 0;
    for (int i = 0; i < size;i++){
        sum1 = sum1 + arr[i];
    }
    return sum1;
}

    int main()
{

    int size;
    cout << "enter size of array" << endl ;
    cin >> size;

    int arr[100];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "sum of elements of array is " << sum(arr, size);
}
#include<iostream>
using namespace std;

int main(){
    int i = 5;
    //reference variable assigns another name to the same memory bock
    //it is used for passing value by reference to functions.
    int &j = i;
    //i and j are both names for memory block containg 5

    cout << i << endl;
    i++;
    cout << i << endl;
    j++;
    cout << i << endl;
    
    int n;
    //cin >> n;
    int arr[n];
    //bad practice. stack memory is used while creating array like this
    //just in case if n exceeds stack memory than program will crash 
    //we use heap memory(large memory) to create variable size arrays by passing 
    //size at runtime
    //stack memory is static memory allocation
    //heap memory is dynamic memory allocation

    new char; //a character sized memory is allocated in heap
    //this statement will return address of char in heap
    //we can use pointer to use access that address
    char *ch = new char;
    //ch has been created in static memory
    int n;
    int *arr = new int[n];

    //in static memory , it clears itself whenever the function ends or block of code end
    //but we need to do everything ourselves to clear memory in heap 
    //we use delete keyword to free memory from heap

    int *i = new int;
    delete i;
    int *arr = new int[50];
    delete[] arr;

    return 0;



}
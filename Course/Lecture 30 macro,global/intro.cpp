#include<iostream>
using namespace std;

//MACRO

//suppose we have used operations using value 3.14 several times in a 
//program and now we want to update this value to 3.29, at each place 
//it is used. the first way is to define 3.14 in a double value and then
//update that value, but this consumes and assigns some memory.
//the second way is to use macro. 

#define PI 3.14 //macro defined

//GLOBAL AND LOCAL VARIABLE

//a local variable is defined in a particular block only and its memory 
//will be freed as soon as it will leave that block.
//To use the same variable in multiple blocks ,like using the same value 
//of a variable in a function and int main block so that any updates occuring 
//to that variable inside the function will be visibe everywhere, we can either 
//pass the value of variable by reference(passing the address of that variable using &)
//or we can use global variables.

int score = 15; //a global variable defined, now this can be accessed anywhere in the whole code

//INLINE FUNCTIONS

/*they are use to reduce function calls overhead.
In case of macros the value of macro replaces all apperances before compilation
In a similar fashion, we create inline functions which replace the operation
at all function appearances before compilation. this enhances readability of code 
before execution. inline function are used for single line functions with a specific 
operation happening frequently in the code*/

inline int getmax(int &a,int &b){
    return (a > b) ? a : b;
}

//DEFAULT ARGUMENTS

void print(int arr[],int n,int start=0)

//for this function start is an default argument. if the user provide any 
//value for start at time of function call, then that value will be taken 
//into consideration. but if no value is passed , the default value 0 will
//be considered .default argument only starts from rightmost parameter. we 
//cant make n a default argument without making start first. or input n in
//the end only.


int main(){

    int r = 5;
    double area = PI * r * r;
    cout << "area is " << area;

    int a = 2, b = 1;
    int ans = 0;
    if(a>b){
        ans = a;
    }
    else{
        ans = b;
    }
    // to reduce the above if block we can use tertiary form
    //(condition)? value when true: value when false.
    ans = (a > b) ? a : b;
    a++;
    b = b + 9;
    ans = getmax(a, b);
    cout << endl << "ans is " << ans;

    return 0;
}
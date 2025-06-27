#include<iostream>
using namespace std;

class A{
    public:
    void abc(){
        cout << "class A" << endl;
    }
};

class B{
    public:
    void abc(){
        cout << "class B" << endl;
    }
};

class C:public A, public B{
};

//class A and B have one function with same name and it is inherited by class C. we use scope resolution operator(::) to differentiate 
//among which function to use at a particular time. 

int main(){

    C obj;
    obj.A::abc();
    obj.B::abc();

    return 0;
}
#include<iostream>
using namespace std;

// polymorphism: existing in multiple forms
// it is of 2 types: run time(dynamic) and compile time(static)

//compile time polymorphism
//function overloading 

class A{
    public:

    void sayhello(){
        cout << "hello tanish" << endl;
    }

    void sayhello(string name){
        cout << "hello " << name << endl;
    }

    int sayhello(char name, int n){
        cout << "hello " << name << endl;
        return n;
    }
};

//operator overloading 

class B{
    public:
        int a;
        int b;

    public:
    int add(){
        return a + b;
    }

    void operator+ (B &obj){
        int value1 = this->a;
        int value2 = obj.a;
        cout << "output " << value2 - value1 << endl;
    }
};

//Run time polymorphism
//method overriding 

class Animal{
    public:
    void speak(){
        cout << "speaking" << endl;
    }
};

class Dog:public Animal{
    public:
    void speak(){
        cout << "barking" << endl;
    }
};

int main(){

    Dog o;
    o.speak();

    A obj;
    obj.sayhello();
    obj.sayhello("raman");
    cout << obj.sayhello('A', 1) << endl;

    B obj1, obj2;
    obj1.a = 4;
    obj2.a = 7;
    obj2 + obj1;
}
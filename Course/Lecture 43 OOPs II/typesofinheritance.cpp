#include<iostream>
using namespace std;

//single inheritance , multilevel inheritance 

class animal{
    public:
        int age;
        int weight;

    public:
    void bark(){
        cout << "barking" << endl;
    }
};

class dog:public animal{
};

class germanshepherd: public dog{
};

//multiple inheritance.

class human{

    public:
        string color;

    public:
    void speak(){
        cout << "speaking" << endl;
    }
};

class hybrid: public human, public animal{
};

//heirarchical inheritance: one class serves as parent class for more than 1 class.

class A{
    public:
    void func1(){
        cout << "inside function 1" << endl;
    }
};

class D{
    public:
    void func4(){
        cout << "inside function 4" << endl;
    }
};

class B: public A{
    public:
    void func2(){
        cout << "inside function 2" << endl;
    }
};

class C: public A, public D{
    public:
    void func3(){
        cout << "inside function 3" << endl;
    }
};

//hybrid inheritance: combination of more than 1 type of inheritance

int main(){

    dog d;
    d.bark();
    cout << d.age << endl;

    germanshepherd g;
    g.bark();

    cout << endl << "multilevel inheritance" << endl;
    hybrid h;
    h.speak();
    h.bark();

    A o1; 
    o1.func1();

    B o2;
    o2.func1();
    o2.func2();

    C o3;
    o3.func1();
    o3.func3();
    o3.func4();

    return 0;
}

#include<iostream>
using namespace std;

// encapsulation: wrapping up data members and functions in a class.
// fully encapsulated class: all data members private.
// In layman terms, it's data hiding or information hiding.

// inheritance: deriving properties and functions from a parent class.
// private date member of super class can't be inherited.

// protected is similar to private. just one condition that it can be accessed in derived.
// or child class. while private can't be.

class Human{

    public:
        int height;
        int weight;
        int age; 

    public:
    int getage(){
        return this->age;
    }
    int setweight(int w){
        this->weight = w;
    }
};

class Male: public Human{

    public:
        string color;
    
    void sleep(){
        cout << "male sleeping" << endl;
    }
};

int main(){

    Male tan;
    cout << tan.age << endl;
    cout << tan.height << endl;
    cout << tan.weight << endl;
    cout << tan.color << endl;
    tan.setweight(85);
    cout << tan.weight << endl;
    tan.sleep();

    return 0;
}
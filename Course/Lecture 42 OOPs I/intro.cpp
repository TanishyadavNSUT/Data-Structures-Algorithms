#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

// class is a user defined data type.
// empty class is assigned one byte of memory for identification.
// access modifiers- public, private, protected.
// they describe the scope till where accessing properties is allowed.
// by default it is private.
// private properties can be accessed inside class only.

// getter and setter: functions within class to access private properties.
// we can include conditions within a setter.

class Hero{

    //properties
   
    int health;
    public:
    char level;

    char *name;
    static int timetocomplete;

    void print(){
        cout << "name is: " << this->name << endl;
        cout << "level is: " << this->level << endl;
        cout << "health is: " << this->health << endl;
    }

    int gethealth(){          //getter
        return health;
    }

    char getlevel(){          //getter
        return level;
    }

    void sethealth(int h){     //setter
        health = h;
    }

    void setlevel(char ch){    //setter
        level = ch;
    }

    void setname(char name[]){
        strcpy(this->name, name);
    }

    static int random(){    //static function, can only use static memeber values.
        return timetocomplete;
    }

    Hero(){
        cout << "constructor called" << endl;
        name = new char[100];
    }

    //parameterized constructor 
    Hero(int health, char level){
        cout << "value of this: " << this << endl;
        this->level = level;
        this->health = health;
    }

    //copy constructor 
    Hero(Hero &temp){
        char *ch = new char[strlen(temp.name) + 1];  //a new array is created while making a copy.(a deep copy)
        strcpy(ch, temp.name);
        this->name = ch;
        cout << "copy constructor called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    //destructor: used to de-allocate memory
    //automatically called for statically allocated object, while manually done for dynamically 
    //allocated object.

    ~Hero(){
        cout << "destructor called" << endl;
    }
};

int Hero::timetocomplete = 5;  //static keyword initialisation. it doesn't require object creation

//this keyword. it is a pointer pointing towards current object.


int main(){

    cout << Hero::timetocomplete << endl;
    cout << Hero::random() << endl;

    //instance creation
    //static allocation
    Hero jay(20,'Q');
    cout << "address of jay: " << &jay << endl;

    //dynamic allocation
    Hero *a = new Hero;
    a->setlevel('Y');
    a->sethealth(100);

    cout << "level is: " << (*a).level << endl;
    cout << "health is: " << (*a).gethealth() << endl;

    //alternate way
    cout << "level is: " << a->level << endl;
    cout << "health is: " << a->gethealth() << endl;

    //jay.sethealth(70);

    cout << "jay's health is: " << jay.gethealth() << endl;
    //jay.health = 100;
    jay.level = 'X';

    //cout << jay.health << endl;
    cout << "jay's level is: "<<jay.level << endl;

    cout << "size " << sizeof(jay);

    cout << endl<< endl<< "copy constructor" << endl;
    //copy constructor is also automatically made when a class is made.

    Hero M(10, 'A');
    M.print();
    Hero N(M);   //hero N will have same properties as hero M.
    N.print();
    cout << endl;

    Hero Hero1;
    Hero1.sethealth(80);
    Hero1.setlevel('Z');
    char name[7] = "tanish";
    Hero1.setname(name);
    //Hero1.print();

    Hero Hero2(Hero1);
    //Hero2.print();

    Hero1.name[0] = 'J';
    Hero1.print();
    Hero2.print();

    Hero1 = Hero2; //copy assignment operator: hero1 will have all properties of hero2
    Hero1.print();
    Hero2.print();

    delete a;

    //on updating name of one object, same updates are also done in their copies while default copy
    //constructor is used because shallow copy is created using deafault copy constructor. shallow copy 
    //is data at same memory location accessed by different names. like hero 2 has address of hero 1, 
    //the values aren't copied, therefore any change in hero 1 can be seen in hero 2.
    //we can create deep copy using our own copy constructor, where an actual copy of properties is
    //created, therefore changes to original will not affect copies.

    return 0;
}
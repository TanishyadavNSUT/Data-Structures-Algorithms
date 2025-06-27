#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    cout << "size of stack is " << s.size() << endl; 
    s.push(3);
    cout << "top element is " << s.top() << endl;
    s.pop();
    cout << "top element is " << s.top() << endl;
    if(s.empty()){
        cout << "stack is empty" << endl;
    }
    else{
        cout << "stack isn't empty" << endl;
    }
    s.pop();
    s.pop();
    if(s.empty()){
        cout << "stack is empty" << endl;
    }
    else{
        cout << "stack isn't empty" << endl;
    }

}
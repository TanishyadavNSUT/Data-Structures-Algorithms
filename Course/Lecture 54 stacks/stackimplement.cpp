#include<iostream>
using namespace std;

class Stack{
    public:
        int *arr;
        int top;
        int size;


    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size-top>1){
            top++;
            arr[top] = element;
        }
        else{
            cout << "stack overflow" << endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout << "stack underflow" << endl;
        }
    }

    int peek(){
        if(top>=0 && top<size){
            return arr[top];
        }
        else{
            cout << "stack is empty" << endl;
            return -1;
        }
    }

    bool isempty(){
        if(top>=0){
            return 1;
        }
        else{
            return 0;
        }
    }
};

int main(){

    Stack st(5);

    st.push(1);
    st.push(2);

    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
}
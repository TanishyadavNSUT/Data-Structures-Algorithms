#include <bits/stdc++.h> 
class Deque
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int n)
    {
        size=n;
        arr=new int[size];
        front=rear=-1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if(isFull()){
            return false;
        }
        else if(isEmpty()){
            front=rear=0;
        }
        else if(front==0 &&rear!=size-1){
            front=size-1;
        }
        else{
            front--;
        }
        arr[front]=x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if(isFull()){
            return false;
        }
        else if(isEmpty()){
            front=rear=0;
        }
        else if(rear==size-1 &&front!=0){
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(isEmpty()){
            return -1;
        }
        int val=arr[front];
        arr[front]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }

        else{
            front++;
        }
        return val;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if(isEmpty()){
            return -1;
        }
        int val=arr[rear];
        arr[rear]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if(rear==0){
            rear=size-1;
        }

        else{
            rear--;
        }
        return val;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if( front==-1){
            return true;
        }
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if((front==0 && rear==size-1)||(front!=0 && rear==front-1)){
            return true;
        }
        return false;
    }
};
#include <bits/stdc++.h> 
class CircularQueue{
    public:

    int *arr;
    int front;
    int rear;
    int size;

    CircularQueue(int n){
        size=n;
        arr=new int[size];
        front=rear=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if((front==0 && rear==size-1) || (rear==front-1)){
            return false;
        }
        else if(front==-1){
            front=rear=0;
            arr[rear]=value;
            return true;
        }
        else if(rear==size-1 && front!=0){
            rear=0;
            arr[rear]=value;
            return true;
        }
        else{
            rear++;
            arr[rear]=value;
            return true;
        }
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front==-1){
            return -1;
        }
        int val=arr[front];
        arr[front]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if(front==size-1 &&rear!=0){
            front=0;
        }
        else{
            front++;
        }
        return val;
    }
};
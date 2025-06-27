#include<iostream>
#include<queue>
using namespace std;

int main(){

    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    cout << "front is " << q.front() << endl;

    cout << "size of queue is " << q.size() << endl;
    q.pop();
    q.pop();
    cout << "front is " << q.front() << endl;
    cout << "back is " << q.back() << endl;
    cout << "size of queue is " << q.size() << endl;
    q.pop();
    if(q.empty()){
        cout << "queue is empty" << endl;
    }
    else{
        cout << "queue is not empty" << endl;
    }
}
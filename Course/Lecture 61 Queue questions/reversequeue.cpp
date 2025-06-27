#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverse(queue<int> &q){

    if(q.empty()){
        return;
    }

    int num = q.front();
    q.pop();
    reverse(q);
    q.push(num);
}

void reverse2(queue<int> &q){

    stack<int> st;
    while(!q.empty()){
        int val = q.front();
        q.pop();
        st.push(val);
    }
    while(!st.empty()){
        int val = st.top();
        st.pop();
        q.push(val);
    }
}

void print(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    print(q);
    reverse(q);
    print(q);
    reverse2(q);
    print(q);
}
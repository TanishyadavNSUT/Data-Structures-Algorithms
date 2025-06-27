#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            next = NULL;
        }
        cout << "memory free for value " << value << endl;
    }
};

void Insertnode(Node* &tail,int element,int d){
    if(tail==NULL){
        Node *temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else{
        Node *temp = new Node(d);
        Node *curr = tail;
        while(curr->data!=element){
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node* tail){
    Node *temp = tail;

    if(tail==NULL){
        cout << "list is empty" << endl;
        return;
    }

    //we will use do-while loop. this is a while loop which atleast runs once without checking 
    //the condition. since, the condition is checked at the end.

    do{
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

void deletenode(Node* &tail, int value){
    if(tail==NULL){
        cout << "list is empty" << endl;
        return;
    }

    Node *prev = tail;
    Node *curr = prev->next;
    while(curr->data!=value){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    if(curr==prev){
        tail = NULL;}
    else if (tail == curr)
    {
        tail = curr->next;
    }
    curr->next = NULL;
    delete curr;
}

int main(){

    Node *tail = NULL;
    Insertnode(tail, 5, 10);
    print(tail);
    Insertnode(tail, 10, 20);
    print(tail);

    Insertnode(tail, 20, 40);
    Insertnode(tail, 20, 30);
    print(tail);

    deletenode(tail, 10);
    print(tail);
    deletenode(tail, 30);
    print(tail);

    return 0;
}
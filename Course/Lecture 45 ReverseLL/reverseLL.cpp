#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

    public:

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout << "memory freed for value " << value << endl;
    }
};

void Insertathead(Node* &head,int d){
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void Insertattail(Node* &tail, int d){
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void Insertatposition(Node* &head,Node* &tail, int position,int d){
    if(position==1){
        Insertathead(head, d);
        return;
    }
    else{
        Node *temp = new Node(d);

        int count = 1;
        Node *curr = head;
        while(count<position-1){
            curr = curr->next;
            count++;
        }
        if(curr->next==NULL){
            Insertattail(tail, d);
            return;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node* &head){
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteposition(Node* &head,Node* &tail, int position){
    if(position==1){
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while(count<position){
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        if(curr==tail){
            tail = prev;
        }
        delete curr;
    }
}

void reverseLL(Node* &head){

    if(head==NULL || head->next==NULL){
        return;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

void reverseLL2(Node* &head, Node* curr, Node* prev){
    if(curr==NULL){
        head = prev;
        return;
    }

    Node *forward = curr->next;
    reverseLL2(head, forward, curr);
    curr->next = prev;
}

void reverseLL3(Node* &head){
    if(head==NULL ||head->next==NULL){
        return;
    }
    Node *rest = head->next;

    reverseLL3(rest);
    head->next->next = head;
    head->next = NULL;
    head = rest;
}

int main(){
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    Insertattail(tail, 20);
    Insertattail(tail, 30);
    Insertatposition(head,tail, 2, 20);
    Insertatposition(head,tail,3, 30);
    deleteposition(head,tail, 2);
    deleteposition(head,tail, 2);
    Insertattail(tail, 40);
    Insertattail(tail, 50);
    print(head);
    reverseLL(head);
    
    print(head);
    Node *curr = head;
    Node *prev = NULL;
    reverseLL2(head,curr,prev);
    print(head);
    reverseLL3(head);
    print(head);
}
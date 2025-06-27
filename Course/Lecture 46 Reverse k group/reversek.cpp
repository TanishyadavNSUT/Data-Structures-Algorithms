#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

    public:

    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        while(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout << "memory freed for value " << value << endl;
    }
};

void Insertathead(Node* &head,Node* &tail,int d){
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
    if(tail==NULL){
        tail = head;
    }
}

void Insertattail(Node *&head, Node * &tail, int d)
{
    Node *temp = new Node(d);
    if(tail!=NULL){
        tail->next = temp;
        tail = temp;
        return;
    }
    tail = head = temp;
}

void Insertatposition(Node* &head, Node* &tail, int position, int d){
    if(position==1){
        Insertathead(head,tail, d);
        return;
    }
    Node *temp = new Node(d);
    Node *curr = head;
    int count = 1;
    while(count<position-1){
        curr = curr->next;
        count++;
    }
    if(curr->next==NULL){
        Insertattail(head,tail, d);
        return;
    }
    temp->next = curr->next;
    curr->next = temp;
}

void print(Node* head){
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteposition(Node* &head, Node* &tail,int position){
    if(position==1){
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        if(head==NULL){
            tail = NULL;
        }
    }
    else{
        Node *prev = NULL;
        Node *curr = head;
        int count = 1;
        while(count<position){
            prev = curr;
            curr = curr->next;
            count++;
        }
        if(curr->next==NULL){
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

Node* reversek(Node* &head, int k){
    if(head==NULL){
        return NULL;
    }
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;
    while(curr!=NULL && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next!=NULL){
        head->next = reversek(next, k);
    }
    return prev;
}


int main(){
    Node *head = NULL;
    Node *tail = NULL;

    Insertattail(head,tail, 30);
    Insertathead(head, tail, 10);
    Insertatposition(head, tail, 2, 20);
    Insertattail(head, tail, 40);
    Insertattail(head, tail, 50);
    Insertattail(head, tail, 60);
    print(head);
    Node* temp= reversek(head, 2);
    cout << temp->data << endl;
}
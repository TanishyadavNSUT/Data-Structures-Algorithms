#include<iostream>
using namespace std;

class Node{

    public:
        int data;
        Node *prev;
        Node *next;

    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(next!=NULL){
            delete next;
            next = NULL;
        }
        cout << "memory freed for value " << value << endl;
    }
};

void print(Node* &head){
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getlength(Node* &head){
    Node *temp = head;
    int len = 0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void Insertathead(Node* &head,Node* &tail, int d){

    if(head==NULL){
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void Insertattail(Node* &head, Node* &tail, int d){
    if(tail==NULL){
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void Insertatposition(Node* &head,Node* &tail, int position, int d){
    if(position==1){
        Insertathead(head,tail, d);
        return;
    }
    int count = 1;
    Node *temp = head;
    Node *toadd = new Node(d);

    while(count<position-1){
        temp = temp->next;
        count++;
    }

    if(temp->next==NULL){
        Insertattail(head,tail, d);
        return;
    }
    toadd->next = temp->next;
    temp->next->prev = toadd;
    temp->next = toadd;
    toadd->prev = temp; 
}

void deleteatposition(Node* &head,int position){
    if(position==1){
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
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
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main(){

    //Node *node1 = new Node(10);
    Node *head = NULL;
    Node *tail = NULL;
    print(head);

    Insertattail(head,tail, 20);
    Insertattail(head,tail, 30);
    Insertattail(head,tail, 40);
    print(head);

    Insertathead(head,tail, 20);
    print(head);
    Insertathead(head,tail, 30);
    Insertathead(head, tail,40);
    print(head);

    Insertatposition(head, tail, 2, 35);
    print(head);
    Insertatposition(head, tail, 1, 45);
    Insertatposition(head, tail, 9, 45);
    print(head);

    cout << "tail: " << tail->data << endl;

    deleteatposition(head, 1);
    deleteatposition(head, 4);
    deleteatposition(head, 7);
    print(head);
    cout << "tail: " << tail->data << endl;

    cout << getlength(head) << endl;

    return 0;
}
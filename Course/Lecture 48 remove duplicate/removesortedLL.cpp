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
        cout << "memory freed for value " << this->data << endl;
    }
};

void Insertathead(Node* &head, int d){
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void Insertattail(Node* &tail,int d){
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void Insertatposition(Node *&head, Node *&tail, int d, int position){
    if(position==1){
        Insertathead(head, d);
        return;
    }
    else{
        Node *temp = new Node(d);
        Node *curr = head;
        int count = 1;
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
        prev->next = curr->next;
        if(curr->next==NULL){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

Node* removeduplicate(Node* &head,Node* &tail){
    if(head==NULL){
        return NULL;
    }
    Node *curr = head;
    while(curr!=NULL){
        if((curr->next!=NULL) && curr->data==curr->next->data){
            Node *next_next = curr->next->next;
            Node *todelete = curr->next;
            if(next_next==NULL){
                tail = curr;
            }
            delete todelete;

            curr->next = next_next;
        }
        else{
            curr = curr->next;
        }
    }
    return head;
}

int main(){
    Node *node1 = new Node(20);
    Node *head = node1;
    Node *tail = node1;
    Insertathead(head, 10);
    Insertattail(tail, 40);
    Insertattail(tail, 50);
    
    Insertattail(tail, 50);
    Insertattail(tail, 50);
    Insertattail(tail, 60);
    Insertattail(tail, 60); 
    Insertatposition(head, tail, 30, 3);
    print(head);
    Insertatposition(head, tail, 13, 3);
    deleteposition(head, tail, 3);
    print(head);
    cout << "head is " << head->data << endl;
    cout << "tail is " << tail->data << endl;
    removeduplicate(head,tail);
    print(head);
    
    cout << "head is " << head->data << endl;
    cout << "tail is " << tail->data << endl;
}
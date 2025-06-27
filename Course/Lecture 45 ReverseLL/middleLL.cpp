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
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout << "memory freed for value" << value << endl;
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
    int count = 1;
    while(temp->next!=NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

Node* getmiddle(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    

    Node *slow = head;
    Node *fast = head->next;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}


int main(){

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    Insertattail(tail, 20);
    Insertattail(tail, 30);
    Insertattail(tail, 40);
    Insertattail(tail, 50);
    Insertattail(tail, 60);
    int len = getlength(head);

    Node *temp = head;
    int mid = (len / 2) + 1;
    while(mid!=1){
        temp = temp->next;
        mid--;
    }
    cout <<"mid element is "<< temp->data << endl;

    print(head);

    Node *midN = getmiddle(head);
    cout << "mid element is " << midN->data << endl;
}
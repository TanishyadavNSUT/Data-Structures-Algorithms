#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
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

void Insertatposition(Node* &tail,Node* &head, int position, int d){
    if(position==1){
        Insertathead(head, d);
        return;
    }
    Node *temp = head;
    Node *toadd = new Node(d);

    int pos = 1;
    while(pos<position-1){
        temp = temp->next;
        pos++;
    }
    if(temp->next==NULL){
        Insertattail(tail, d);
        return;
    }
    toadd->next = temp->next;
    temp->next = toadd;
}

void print(Node* &head){
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteposition(int position, Node* &head,Node*&tail){

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

Node* sortLL(Node* head){
    int zero = 0;
    int one = 0;
    int two = 0;
    Node *temp = head;
    while(temp!=NULL){
        if(temp->data==0){
            zero++;
        }
        else if(temp->data==1){
            one++;
        }
        else if(temp->data==2){
            two++;
        }
        temp = temp->next;
    }
    Node *call = head;
    while(call!=NULL){
        if(zero!=0){
            call->data = 0;
            zero--;
        }
        else if(one!=0){
            call->data = 1;
            one--;
        }
        else if(two!=0){
            call->data = 2;
            two--;
        }
        call = call->next;
    }
    return head;
}

void populate(Node* &tail,Node* temp){
    tail->next = temp;
    tail = temp;
}

Node* sort012(Node* &head){
    Node *zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *temp = head;
    while(temp!=NULL){
        int value = temp->data;
        if(value==0){
            populate(zeroTail, temp);
        }
        else if(value==1){
            populate(oneTail, temp);
        }
        else if(value==2){
            populate(twoTail, temp);
        }
        temp = temp->next;
    }
    if(oneHead->next==NULL){
        zeroTail->next = twoHead->next;
    }
    else{
        zeroTail->next = oneHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}


int main(){

    Node *node1 = new Node(1);

    Node *head = node1;
    Node *tail = node1;
    Insertattail(tail, 0);
    Insertattail(tail, 2);
    Insertattail(tail, 0);
    Insertattail(tail, 0);
    Insertattail(tail, 2);
    Insertattail(tail, 1);
    Insertattail(tail, 1);

    print(head);
    Node *t = sort012(head);
    print(head);

    return 0;
}
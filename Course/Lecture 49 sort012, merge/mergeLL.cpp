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

Node* solve(Node* &first,Node* &second){

    if(first->next==NULL){
        first->next = second;
        return first;
    }
    Node *curr1 = first;
    Node *next1 = curr1->next;
    Node *curr2 = second;
    Node *next2 = curr2->next;

    while(curr2!=NULL && next1!=NULL){
        if((curr2->data<=next1->data)&&(curr2->data>=curr1->data)){
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1 = next1->next;
            if(next1==NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;

}

Node* mergeLL(Node* &first,Node*&second){
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }
    if((first->data)<=(second->data)){
        return solve(first, second);
    }
    else{
        return solve(second, first);
    }
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


int main(){

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);

    Node *head1 = node1;
    Node *tail1 = node1;
    Node *head2 = node2;
    Node *tail2 = node2;
    Insertattail(tail1, 3);
    Insertattail(tail1, 5);
    Insertattail(tail1, 7);
    Insertattail(tail1, 9);
    Insertattail(tail2, 4);
    Insertattail(tail2, 5);
    Insertattail(tail2, 8);

    print(head1);
    print(head2);
    Node *t = mergeLL(head2, head1);
    print(head1);

    return 0;
}
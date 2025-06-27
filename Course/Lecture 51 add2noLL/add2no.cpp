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

Node* reverse(Node* &head){

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void Insert(Node* &head, Node* &tail,int d){
    Node *temp = new Node(d);
    if(head==NULL){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

Node* add(Node* &first, Node* &second){
    int carry = 0;
    int sum = 0;
    int digit = 0;

    Node *anshead = NULL;
    Node *anstail = NULL;

    while(first!=NULL || second!=NULL || carry!=0){

        int val1 = 0;
        if(first!=NULL){
            val1 = first->data;
        }
        int val2 = 0;
        if(second!=NULL){
            val2 = second->data;
        }
        sum = carry + val1 + val2;
        digit = sum % 10;
        carry = sum / 10;
        Insert(anshead, anstail, digit);
        if(first!=NULL){
            first = first->next;
        }
        if(second!=NULL){
            second = second->next;
         }

    }
    return anshead;
}


int main(){

    Node *node1 = new Node(1);

    Node *head = node1;
    Node *tail = node1;
    Insertattail(tail, 9);
    Insertattail(tail,9);
    Insertattail(tail, 9);

    Node *node2 = new Node(3);
    Node *head2 = node2;
    Node *tail2 = node2;
    Insertattail(tail2, 4);
    Insertattail(tail2, 5);

    print(head);
    print(head2);

    head = reverse(head);
    head2 = reverse(head2);

    Node *ans = add(head, head2);
    ans = reverse(ans);
    print(ans);

    return 0;
}
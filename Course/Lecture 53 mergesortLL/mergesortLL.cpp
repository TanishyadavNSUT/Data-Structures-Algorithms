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

Node* findmid(Node* &head){
    
    Node *slow = head;
    Node *fast = head->next;
    
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

Node* merge(Node* &left, Node* &right){

    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }

    Node *ans = new Node(-1);
    Node *temp = ans;

    while(left!=NULL && right!=NULL){
        if(left->data>right->data){
            temp->next = right;
            temp = right;
            right = right->next;
        }
        else{
            temp->next = left;
            temp = left;
            left = left->next;
        }
    }

    while(left!=NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right!=NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }

    return ans->next;
}



Node* mergesortLL(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node *mid = findmid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergesortLL(left);
    right = mergesortLL(right);

    Node *result = merge(left, right);
    return result;
}


int main(){

    Node *node1 = new Node(5);

    Node *head = node1;
    Node *tail = node1;
    Insertattail(tail, 2);
    Insertattail(tail, 9);
    Insertattail(tail, 6);
    Insertattail(tail, 3);
    Insertattail(tail, 1);
    Insertattail(tail, 5);


    print(head);

    Node *result = mergesortLL(head);
    print(result);

    return 0;
}
#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
    
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

void deleteByValue(int value, Node* &head) {
    // If the list is empty, there's nothing to delete
    if (head == NULL) {
        return;
    }

    // If the head node holds the value to be deleted
    if (head->data == value) {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    // Traverse the list to find the node with the given value
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    // If the node with the given value was not found
    if (curr == NULL) {
        return;
    }

    // Unlink the node from the linked list
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

bool floyddetect(Node* head){
    if(head==NULL){
        return false;
    }

    Node *slow = head;
    Node *fast = head;
    while(slow!=NULL && fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}


int main(){

    Node *node1 = new Node(10);

    Node *head = node1;
    Node *tail = node1;
    Insertattail(tail, 20);
    Insertattail(tail, 30);
    Insertatposition(tail,head,2, 9);
    Insertatposition(tail,head, 1, 8);
    Insertatposition(tail,head, 6, 7);
    

    print(head);

    Insertathead(head, 20);
    print(head);
    Node *temp = head;
    tail->next = temp->next->next->next;
    cout << floyddetect(head) << endl;

    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    

    return 0;
}


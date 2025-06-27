#include<iostream>
#include<vector>
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

bool validpalindrome(vector<int> &v){
    int start = 0;
    int end = v.size() - 1;

    while(start<=end){
        if(v[start]==v[end]){
            start++;
            end--;
        }
        else{
            return false;
        }
    }
    return true;
}

Node* getmid(Node* &head){
    Node *slow = head;
    Node *fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* reverseLL(Node* &head){

    if(head==NULL || head->next==NULL){
        return head;
    }

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

bool ispalindrome2(Node* &head){

    if(head->next==NULL){
        return true;
    }

    Node *middle = getmid(head);
    Node *temp = middle->next;
    middle->next = reverseLL(temp);

    Node *head1 = head;
    Node *head2 = middle->next;

    while(head2!=NULL){
        if(head1->data!=head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;

    }

    temp = middle->next;
    middle->next = reverseLL(temp);
    return true;
}

bool ispalindrome(Node* &head){
    vector<int> arr;

    Node *temp = head;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    return validpalindrome(arr);
}



int main(){

    Node *node1 = new Node(1);

    Node *head = node1;
    Node *tail = node1;
    Insertattail(tail, 2);
    Insertattail(tail, 3);
    Insertattail(tail, 4);
    Insertattail(tail, 3);
    Insertattail(tail, 2);
    Insertattail(tail, 1);
    
    print(head);


    cout << ispalindrome(head) << endl;
    cout << ispalindrome2(head) << endl;

    return 0;
}
//linked list is a dynamic data structure. in case of arrays we weren't able to change 
//size of array at run time but using linked list we can. 
//size of a linked list can be grown or shrinked according to need at run time,
//without any memory wastage.
//Insertion and deletion in a linked list is more efficient since no shift is required.
//linked list is a collection of nodes.
//each node contains some data and address of next node.

#include<iostream>
using namespace std;


//creation of node

class Node{
    public:
        int data;
        Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

int main(){

    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;
    return 0;
}
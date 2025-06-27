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

    deleteposition(1, head,tail);
    print(head);

    deleteposition(5, head,tail);
    print(head);

    deleteposition(2, head,tail);
    print(head);

    Insertathead(head, 20);
    print(head);


    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;



    return 0;
}
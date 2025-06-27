class Solution
{
    private: 
    
    void Insertattail(Node*&head,Node*&tail,int d){
        if(head==NULL){
            Node* node=new Node(d);
            head=node;
            tail=node;
        }
        else{
            Node* node= new Node(d);
            tail->next=node;
            tail=node;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        Node* clonehead=NULL;
        Node* clonetail=NULL;
        
        Node*temp=head;
        
        while(temp!=NULL){
            Insertattail(clonehead,clonetail,temp->data);
            temp=temp->next;
        }
        
        unordered_map <Node*,Node*> oldtonew;
        Node* originalnode=head;
        Node* clonenode=clonehead;
        while(originalnode!=NULL){
            oldtonew[originalnode]=clonenode;
            originalnode=originalnode->next;
            clonenode=clonenode->next;
        }
        
        originalnode=head;
        clonenode=clonehead;
        while(originalnode!=NULL){
            clonenode->arb=oldtonew[originalnode->arb];
            originalnode=originalnode->next;
            clonenode=clonenode->next;
        }
        return clonehead;
        
    }


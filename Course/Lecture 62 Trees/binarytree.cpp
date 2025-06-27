#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
    
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildtree(Node* root){

    cout << "enter the data " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if(data==-1){
        return NULL;
    }

    cout << "enter data to insert at left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "enter data to insert at right of " << data << endl;
    root->right = buildtree(root->right);

    return root;
}

void levelordertraversal(Node* root){

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        if(temp==NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout << temp->data << " ";
            if(temp->left){
            q.push(temp->left);
            }
            if(temp->right){
            q.push(temp->right); 
            }
        }
    }
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node*root){
    if(root==NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void buildtreelevelorder(Node* &root){

    queue<Node *> q;
    cout << "enter data " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        cout << "enter left node for " << temp->data << endl;
        int leftdata;
        cin >> leftdata;

        if(leftdata!=-1){
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        cout << "enter right node for " << temp->data << endl;
        int rightdata;
        cin >> rightdata;

        if(rightdata!=-1){
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }
}

int main(){
    Node *root = NULL;
    root = buildtree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelordertraversal(root);
    cout << "inorder traversal is ";
    inorder(root);
    cout << endl;
    cout << "preorder traversal is ";
    preorder(root);
    cout << endl;
    cout <<"postorder traversal is ";
    postorder(root);

    Node *root2 = NULL;
    buildtreelevelorder(root2);
    levelordertraversal(root2);
}
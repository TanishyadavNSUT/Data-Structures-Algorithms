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

Node* insertintobst(Node* root, int data){
    if(root==NULL){
        root = new Node(data);
        return root;
    }

    if(data<(root->data)){
        root->left = insertintobst(root->left, data);
    }
    else{
        root->right = insertintobst(root->right, data);
    }

    return root;
}

void takeinput(Node* &root){

    int data;
    cin >> data;

    while(data!=-1){
        root = insertintobst(root, data);
        cin >> data;
    }
}

void getmax(Node* root){
    Node *temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    cout << "max value is " << temp->data << endl;
}

int getmin(Node* root){
    Node *temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp->data;
}

Node* inordersuccessor(Node* root, int d){
    Node *succ = NULL;

    while(root!=NULL){
        if(d>=root->data){
            root = root->right;
        }
        else{
            succ = root;
            root = root->left;
        }
    }
    return succ;
}

Node* deletefrombst(Node* root, int val){

    if(root==NULL){
        return root;
    }
    if(root->data==val){

        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        if(root->left!=NULL && root->right==NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }

        if (root->left==NULL && root->right!=NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }

        if(root->left!=NULL && root->right!=NULL){
            int mini = getmin(root->right);
            root->data = mini;
            root->right = deletefrombst(root->right, mini);
            return root;
        }
    }
    else if(root->data>val){
        root->left = deletefrombst(root->left, val);
        return root;
    }
    else{
        root->right = deletefrombst(root->right, val);
        return root;
    }
}

int main(){

    Node *root = NULL;

    cout << "enter data to create BST " << endl;
    takeinput(root);

    cout << "printing levelordertraversal" << endl;
    levelordertraversal(root);

    cout<<endl<<"printing inorder"<<endl;
    inorder(root);

    cout<<endl<<"printing postorder"<<endl;
    postorder(root);

    cout << endl << "printing preorder" << endl;
    preorder(root);
    cout << endl;

    getmax(root);

    cout << "inorder successor is " << inordersuccessor(root, 5)->data << endl;

    root = deletefrombst(root, 6);
    root = deletefrombst(root, 10);

    cout << "printing levelordertraversal" << endl;
    levelordertraversal(root);



    return 0;
}
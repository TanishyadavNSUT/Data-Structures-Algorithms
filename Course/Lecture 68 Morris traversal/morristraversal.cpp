#include<iostream>
using namespace std;

vector<int> getinorder(Node* root){

    vector<int> inorder;
    Node *curr = root;

    while(curr!=NULL){
        
        if (curr->left==NULL){
            inorder.push_back(curr->val);
            curr = curr->right;
        }

        else{
            
            Node *prev = curr->left;
            while(prev->right&&prev->right!=curr){
                prev = prev->right;
            }

            if(prev->right==NULL){
                prev->right = curr;
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return inorder;
}
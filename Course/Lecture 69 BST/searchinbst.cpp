bool searchInBST(BinaryTreeNode<int> *root, int x) {
    
    BinaryTreeNode<int> *temp=root;

    while(temp!=NULL){
        if(temp->data==x){
            return true;
        }
        if(temp->data<x){
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
    }
    return false;
}
bool solve(BinaryTreeNode<int> *root,int max, int min){
    if(root==NULL){
        return true;
    }
    if(root->data>=min && root->data<=max){
        bool val1=solve(root->left,root->data,min);
        bool val2=solve(root->right,max,root->data);

        return (val1 && val2);
    }
    return false;
}

bool validateBST(BinaryTreeNode<int> *root) {

    return solve(root,INT_MAX,INT_MIN);
}
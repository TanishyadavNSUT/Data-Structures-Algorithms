BinaryTreeNode<int>* solve(vector<int> &preorder,int m,int n,int &i){
    if(i>=preorder.size()){
        return NULL;
    }
    int current =preorder[i];
    if(current<n ||current>m){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(current);
    i++;
    root->left=solve(preorder,root->data,n,i);
    root->right=solve(preorder,m,root->data,i);
    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {

    int i=0;
    return solve(preorder,INT_MAX,INT_MIN,i);
}
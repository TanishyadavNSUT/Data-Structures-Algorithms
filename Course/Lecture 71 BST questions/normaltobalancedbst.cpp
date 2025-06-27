void inorder(TreeNode<int>* root, vector<int> &v){
    if(root==NULL){
        return;
    }

    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

TreeNode<int>* solve(vector<int> v,int start, int end){

    if(start>end){
        return NULL;
    }

    int mid=(start+end)/2;

    TreeNode<int>* newroot=new TreeNode<int>(v[mid]);
    newroot->left=solve(v,start,mid-1);
    newroot->right=solve(v,mid+1,end);
    return newroot;

}
TreeNode<int>* balancedBst(TreeNode<int>* root) {


    vector<int> v;
    inorder(root,v);

    TreeNode<int>* newroot=solve(v,0,v.size()-1);
    return newroot;
}
void inorder(TreeNode<int>* root,vector<int> &v){
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);

}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    if(root==NULL){
        return NULL;
    }
    vector<int> vect;
    inorder(root,vect);

    int n=vect.size();
    TreeNode<int>* newroot=new TreeNode<int>(vect[0]);
    TreeNode<int>* curr=newroot;

    for(int i=1;i<n;i++){
        TreeNode<int>* temp=new TreeNode<int>(vect[i]);
        curr->right=temp;
        curr->left=NULL;
        curr=temp;
    }
    curr->right=NULL;
    curr->left=NULL;

    return newroot;


}
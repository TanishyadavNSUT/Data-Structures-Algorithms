class info{
    public:
    int maxi;
    int mini;
    bool isbst;
    int size;
};

info solve(TreeNode * root, int &ans){
    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0};
    }

    info left=solve(root->left,ans);
    info right=solve(root->right,ans);

    info currnode;

    currnode.size=left.size+right.size+1;
    currnode.maxi=max(root->data,right.maxi);
    currnode.mini=min(root->data,left.mini);

    if(left.isbst && right.isbst && (root->data>left.maxi && root->data<right.mini)){
        currnode.isbst=true;
    }
    else{
        currnode.isbst=false;
    }

    if(currnode.isbst){
        ans=max(ans,currnode.size);
    }
    return currnode;

    
}

int largestBST(TreeNode * root){
    int maxsize=0;
    info temp=solve(root,maxsize);
    return maxsize;
}
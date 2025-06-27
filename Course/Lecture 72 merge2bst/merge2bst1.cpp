void inorder(TreeNode *root,vector<int> &v){
    if(root==NULL){
        return;
    }

    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

vector<int> merge(vector<int> &v1, vector<int> &v2){
    vector<int> ans(v1.size()+v2.size());

    int i=0;
    int j=0;
    int k=0;
    
    while(i<v1.size() && j<v2.size()){
        if(v1[i]>v2[j]){
            ans[k++]=v2[j++];
        }
        else{
            ans[k++]=v1[i++];
        }
    }

    while(i<v1.size()){
        ans[k++]=v1[i++];
    }

    while(j<v2.size()){
        ans[k++]=v2[j++];
    }
    
    return ans;
}

TreeNode *inordertobst(vector<int> &v, int start, int end){
    if(start>end){
        return NULL;
    }

    int mid=(start+end)/2;
    TreeNode *root=new TreeNode(v[mid]);
    root->left=inordertobst(v,start,mid-1);
    root->right=inordertobst(v,mid+1,end);
    return root;
}


vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> bst1 , bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);

    vector<int> mergedarray=merge(bst1,bst2);

    return mergedarray;
}
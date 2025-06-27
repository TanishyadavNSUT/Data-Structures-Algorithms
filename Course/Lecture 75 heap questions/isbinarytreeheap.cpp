int countnode(struct Node* tree){
    if(tree==NULL){
        return 0;
    }
    
    int ans=1+countnode(tree->left)+countnode(tree->right);
    return ans;
}

bool iscbt(struct Node* root, int index, int count){
    if(root==NULL){
        return true;
    }
    
    if(index>=count){
        return false;
    }
    else{
        bool left=iscbt(root->left,2*index+1,count);
        bool right=iscbt(root->right,2*index+2,count);
        return (left && right);
    }
}

bool ismaxheap(struct Node* root){
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    
    if(root->right==NULL){
        return (root->data > root->left->data);
    }
    else{
        bool left=ismaxheap(root->left);
        bool right=ismaxheap(root->right);
        return (left && right &&
        (root->data > root->left->data && root->data > root->right->data));
    }
}




class Solution {
  public:
    bool isHeap(struct Node* tree) {
        int count=countnode(tree);
        int index=0;
        if(iscbt(tree,index,count) && ismaxheap(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};
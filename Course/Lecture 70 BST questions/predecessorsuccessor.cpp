pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    TreeNode *temp=root;
    int pre=-1;
    int succ=-1;

    while(temp!=NULL && temp->data!=key){
        if(temp->data>key){
            succ=temp->data;
            temp=temp->left;
        }
        else{
            pre=temp->data;
            temp=temp->right;
        }
    }

    if(temp==NULL){
        return {pre,succ};
    }

    TreeNode *lefttree=temp->left;
    while(lefttree!=NULL){
        pre=lefttree->data;
        lefttree=lefttree->right;
    }

    TreeNode *righttree=temp->right;
    while(righttree!=NULL){
        succ=righttree->data;
        righttree=righttree->left;
    }

    pair<int,int> ans=make_pair(pre,succ);
    return ans;
}
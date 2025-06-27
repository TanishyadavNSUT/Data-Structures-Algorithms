void convertintoDLL(TreeNode *root,TreeNode * &head){
    if(root==NULL){
        return;
    }
    convertintoDLL(root->right, head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    convertintoDLL(root->left, head);
}

TreeNode* mergeLL(TreeNode * head1 ,TreeNode * head2){
    TreeNode *head=NULL;
    TreeNode *tail=NULL;

    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            if(head==NULL){
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }
        else{
            if(head==NULL){
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
            }
        }
    }

    while(head1!=NULL){
        tail->right=head1;
        head1->left=tail;
        tail=head1;
        head1=head1->right;
    }

    while(head2!=NULL){
        tail->right=head2;
        head2->left=tail;
        tail=head2;
        head2=head2->right;
    }
    return head;
}

int countnode(TreeNode *&head){
    int count=0;
    TreeNode *temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->right;
    }
    return count;
}

TreeNode * sortedLLtobst(TreeNode * &head, int n){
    if(n<=0 || head==NULL){
        return NULL;
    }

    TreeNode *left=sortedLLtobst(head, n/2);
    TreeNode *root=head;
    root->left=left;
    head=head->right;

    root->right=sortedLLtobst(head, (n-n/2)-1);
    return root;


}

void inorder(TreeNode *root,vector<int> &v){
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}


vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    //step1: convert into sortedDLL in-place
    TreeNode *head1=NULL;
    convertintoDLL(root1,head1);
    head1->left=NULL;

    TreeNode *head2=NULL;
    convertintoDLL(root2,head2);
    head2->left=NULL;

    //step2: merge sorted LL
    TreeNode* head=mergeLL(head1,head2);

    //step3: sorted LL to BST
    TreeNode *root=sortedLLtobst(head, countnode(head));

    vector<int> v;
    inorder(root,v);
    return v;

}
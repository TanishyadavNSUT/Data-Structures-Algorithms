void inorder(BinaryTreeNode<int>* root,vector<int> &v){
    if(root==NULL){
        return;
    }

    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> vect;
    inorder(root,vect);

    int i=0;
    int j=vect.size()-1;
    int sum=0;

    while(i<j){
        sum=vect[i]+vect[j];

        if(sum==target){
            return true;
        }
        else if(sum>target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}
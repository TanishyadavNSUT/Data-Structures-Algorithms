
    pair<int,int> diameterfast(Node* root){
        if(root==NULL){
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        
        pair<int,int> left=diameterfast(root->left);
        pair<int,int> right=diameterfast(root->right);
        
        int op1=left.first;
        int op2=right.first;
        int op3= left.second + right.second +1;
        
        pair<int,int> ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;;
        return ans;
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        return diameterfast(root).first;
    }
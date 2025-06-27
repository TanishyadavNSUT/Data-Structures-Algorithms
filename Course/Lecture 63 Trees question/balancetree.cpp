class Solution{
    private:
    
    pair<bool,int> isbalance(Node* root){
        if(root==NULL){
            pair<bool,int> p= make_pair(true,0);
            return p;
        }
        
        pair<bool,int> left=isbalance(root->left);
        pair<bool,int> right=isbalance(root->right);
        
        bool val1=left.first;
        bool val2=right.first;
        int ans =max(left.second,right.second) +1;
        
        bool val3= abs(left.second-right.second)<=1;
        if(val1 && val2 && val3){
            pair<bool,int> s=make_pair(true,ans);
            return s;
        }
        else{
            pair<bool,int> s=make_pair(false,ans);
            return s;
        }
    }
    
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return isbalance(root).first;
    }
};
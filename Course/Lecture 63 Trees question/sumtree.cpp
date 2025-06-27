class Solution
{
    public:
    
    pair<bool,int> sum(Node* root){
        
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        
        if(root->left==NULL && root->right==NULL){
            pair<bool,int> p=make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int> left=sum(root->left);
        pair<bool,int> right=sum(root->right);
        
        bool val1=left.first;
        bool val2=right.first;
       
        int ans=left.second+right.second+1;
        
        bool val3=(left.second+right.second)==root->data;
        
        
        pair<bool,int> p;
        
        if(val1 && val2 && val3){
            p.first=true;
            p.second=2*root->data;
        }
        else{
            p.first=false;
        }
        
        return p;
        
    }
    bool isSumTree(Node* root)
    {
        return sum(root).first;
    }
};
class Solution{
  public:
    void solve(Node* root, vector<int> &path,int &count,int k){
        if(root==NULL){
            return;
        }
        
        path.push_back(root->data);
        
        solve(root->left,path,count,k);
        solve(root->right,path,count,k);
        
        int size=path.size();
        int sum=0;
        for(int i=size-1;i>=0;i--){
            sum=sum+path[i];
            if(sum==k){
                count++;
            }
        }
        path.pop_back();
    }
  
    int sumK(Node *root,int k)
    {
        vector<int> path;
        int count=0;
        solve(root,path,count,k);
        return count;
    }
};
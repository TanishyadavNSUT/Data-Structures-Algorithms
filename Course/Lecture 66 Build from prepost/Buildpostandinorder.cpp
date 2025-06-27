class Solution {
  public:
    void mapping(int in[], int n, map<int,int> &nodetoindex){
        for(int i=0;i<n;i++){
            nodetoindex[in[i]]=i;
        }
    }
    
    Node* solve(int in[], int post[], int &index, int start,int end,int n,map<int,int> &nodetoindex){
        
        if(index<0 || start>end){
            return NULL;
        }
        
        int element=post[index--];
        Node* root=new Node(element);
        int position=nodetoindex[element];
        
        
        root->right=solve(in,post,index,position+1,end,n,nodetoindex);
        root->left=solve(in,post,index,start,position-1,n,nodetoindex);
        
        
        return root;
        
    }
    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int n, int in[], int post[]) {
        // Your code here
        
        int postorderindex=n-1;
        int startofinorder=0;
        int endofinorder=n-1;
        
        map<int,int> nodetoindex;
        mapping(in,n,nodetoindex);
        
        Node* root=solve(in,post,postorderindex,startofinorder,endofinorder,n,nodetoindex);
        return root;
    }
};
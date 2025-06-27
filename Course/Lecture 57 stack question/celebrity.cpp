class Solution 
{
    private:
    
    bool knows(vector<vector<int>> & M, int a , int b){
        if(M[a][b]==1){
            return true;
        }
        return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        while(st.size()>1){
            
            int a=st.top();
            st.pop();
            
            int b=st.top();
            st.pop();
            
            if(knows(M,a,b)){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        
        int ans=st.top();
        int rowcount=0;
        
        for(int i=0;i<n;i++){
            if(M[ans][i]==0){
                rowcount++;
            }
        }
        int colcount=0;
        
        for(int i=0; i<n; i++){
            if(M[i][ans]==1){
                colcount++;
            }
        }
        
        if(rowcount!=n){
            return -1;
        }
        if(colcount!=n-1){
            return -1;
        }
        return ans;
    }
};
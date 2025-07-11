class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> st;
        for(int i=0;i<k;i++){
            int val=q.front();
            q.pop();
            st.push(val);
        }
        while(!st.empty()){
            int val=st.top();
            st.pop();
            q.push(val);
        }
        int n=q.size();
        
        for(int i=0;i<n-k;i++){
            int val=q.front();
            q.pop();
            q.push(val);
        }
        return q;
    }
};
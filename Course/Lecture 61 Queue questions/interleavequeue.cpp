class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        queue<int> q2;
        int n=q.size();
        
        for(int i=0;i<n/2;i++){
            int val=q.front();
            q.pop();
            q2.push(val);
        }
        
        while(!q2.empty()){
            int val=q2.front();
            q2.pop();
            int val2=q.front();
            q.pop();
            q.push(val);
            q.push(val2);
        }
        vector<int> ans;
        while(!q.empty()){
            int val=q.front();
            q.pop();
            ans.push_back(val);
            
        }
        return ans;
    }
};
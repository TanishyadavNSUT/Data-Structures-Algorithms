class Solution {
	public:
		string FirstNonRepeating(string A){
		    map<char,int> m;
		    queue<char> q;
		    string s="";
		    
		    for(int i=0;i<A.size();i++){
		        char ch= A[i];
		        q.push(ch);
		        m[ch]++;
		        
		        while(!q.empty()){
		            if(m[q.front()]>1){
		                q.pop();
		            }
		            else{
		                s.push_back(q.front());
		                break;
		            }
		        }
		        
		        if(q.empty()){
		            s.push_back('#');
		        }
		        
		        
		    }
		    return s;
		}

};
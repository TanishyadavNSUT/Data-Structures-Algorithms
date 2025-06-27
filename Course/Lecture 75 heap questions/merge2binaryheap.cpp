class Solution{
    public:
    
    void heapify(vector<int> &arr , int count, int index){
        
        int largest=index;
        int left=2*index+1;
        int right=2*index+2;
        
        if(left<count && arr[left]>arr[largest]){
            largest=left;
        }
        
        if(right<count && arr[right]>arr[largest]){
            largest=right;
        }
        
        if(largest!=index){
            swap(arr[largest],arr[index]);
            heapify(arr,count,largest);
        }
    }
    
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        
        for(auto i: a){
            ans.push_back(i);
        }
        for(auto i: b){
            ans.push_back(i);
        }
        
        int count=ans.size();
        for(int i=count/2-1; i>=0; i--){
            heapify(ans,count,i);
        }
        
        
        return ans;
    }
};
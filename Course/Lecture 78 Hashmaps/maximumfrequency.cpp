int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> map1;

    int maxfreq=0;
    int ans=0;

    for(int i=0;i<arr.size();i++){
        map1[arr[i]]++;
        maxfreq=max(maxfreq,map1[arr[i]]);
    }


    for(int i=0;i<arr.size();i++){
        if(maxfreq==map1[arr[i]]){
            ans=arr[i];
            break;
        }
    }
    // In case of unordered map, elements are randomly accesses so the first element having maxfreq is found in this way.

    return ans;
}
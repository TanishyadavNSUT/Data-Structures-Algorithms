#include<iostream>
#include<vector>
using namespace std;

void DFS(int node, vector<int> adj[],int vis[], vector<int> &ans){
    vis[node] = 1;
    ans.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]){
            DFS(it, adj, vis, ans);
        }
    }
}

vector<int> DFSOrder(int v, vector<int> adj[], int start){
    int vis[v + 1] = {0};
    vector<int> ans;
    DFS(start, adj, vis, ans);
    return ans;
}

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> list[n + 1];
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);
    }

    vector<int> traversal = DFSOrder(n, list, 1);
    for (int i = 0; i < traversal.size();i++){
        cout << traversal[i] << " ";
    }

    return 0;
}
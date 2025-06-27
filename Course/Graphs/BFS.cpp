#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> BFS(int v, vector<int> adj[],int start){
    int vis[v+1] = {0};
    vis[start] = 1;
    queue<int> q;
    q.push(start);
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> traversal = BFS(n, adj, 6);
    for (int i = 0; i < traversal.size();i++){
        cout << traversal[i] << " ";
    }
    cout << endl;
    vector<int> traversal2 = BFS(n, adj, 1);
    for (int i = 0; i < traversal2.size();i++){
        cout << traversal2[i] << " ";
    }
    return 0;
}

#include <iostream>
#include<vector>
using namespace std;

int main(){
    // Graph representation

    // Adjacency matrix
    int n, m;
    cin >> n >> m;
    int adj[n + 1][n + 1];
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Adjacency list
    int a, b;
    cin >> a >> b;
    vector<int> adj1[a + 1];
    for (int i = 0; i < b; i++){
        int c, d;
        cin >> c >> d;
        adj1[c].push_back(d);
        adj1[d].push_back(c);
    }

    return 0;
}
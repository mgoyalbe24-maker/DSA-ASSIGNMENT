#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for(int x : adj[node]) {
        if(!visited[x]) dfs(x, adj, visited);
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj(n);
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cin >> start;

    vector<bool> visited(n, false);
    dfs(start, adj, visited);
}
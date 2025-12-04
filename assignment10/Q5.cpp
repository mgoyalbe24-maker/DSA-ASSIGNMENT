#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<bool> visited(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, 0});
    int total = 0;

    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int w = p.first;
        int node = p.second;

        if(visited[node]) continue;
        visited[node] = true;
        total += w;

        for(auto x : adj[node]) {
            if(!visited[x.first]) {
                pq.push({x.second, x.first});
            }
        }
    }

    cout << total;
}
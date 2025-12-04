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

    int start;
    cin >> start;

    vector<int> dist(n, 1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int d = p.first;
        int node = p.second;

        if(d > dist[node]) continue;

        for(auto x : adj[node]) {
            int next = x.first;
            int w = x.second;
            if(dist[node] + w < dist[next]) {
                dist[next] = dist[node] + w;
                pq.push({dist[next], next});
            }
        }
    }

    for(int i = 0; i < n; i++) cout << dist[i] << " ";
}
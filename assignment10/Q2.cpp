#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    // adjacency list
    vector<vector<int>> adj(n);

    // read edges
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        // ensure u, v are valid
        if (u < 0 || v < 0 || u >= n || v >= n) {
            cout << "Invalid edge input.\n";
            return 0;
        }

        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    int start;
    cin >> start;

    if (start < 0 || start >= n) {
        cout << "Invalid start node.\n";
        return 0;
    }

    vector<bool> visited(n, false);
    queue<int> q;

    // BFS initialization
    visited[start] = true;
    q.push(start);

    // BFS traversal
    cout << "BFS traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        // explore neighbors
        for (int x : adj[node]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }

    cout << endl;
    return 0;
}

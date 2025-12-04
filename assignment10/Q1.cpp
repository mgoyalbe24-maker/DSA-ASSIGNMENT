#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int n;
    vector<vector<int>> matrix;
    vector<vector<int>> adj;

public:
    Graph(int n) : n(n) {
        matrix.assign(n, vector<int>(n, 0));
        adj.assign(n, vector<int>());
    }

    void addEdge(int u, int v, bool directed) {
        matrix[u][v] = 1;
        adj[u].push_back(v);
        if (!directed) {
            matrix[v][u] = 1;
            adj[v].push_back(u);
        }
    }

    int degree(int v) {
        return adj[v].size();
    }

    int outDegree(int v) {
        int c = 0;
        for (int i = 0; i < n; i++)
            if (matrix[v][i]) c++;
        return c;
    }

    int inDegree(int v) {
        int c = 0;
        for (int i = 0; i < n; i++)
            if (matrix[i][v]) c++;
        return c;
    }

    void adjacentVertices(int v) {
        for (int x : adj[v]) cout << x << " ";
        cout << endl;
    }

    int numberOfEdges(bool directed) {
        int c = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j]) c++;
        return directed ? c : c / 2;
    }
};

int main() {
    int n;
    cin >> n;

    Graph g(n);

    int e, directed;
    cin >> e >> directed;

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, directed);
    }

    int v;
    cin >> v;

    cout << g.degree(v) << endl;
    cout << g.inDegree(v) << endl;
    cout << g.outDegree(v) << endl;
    g.adjacentVertices(v);
    cout << g.numberOfEdges(directed) << endl;
}
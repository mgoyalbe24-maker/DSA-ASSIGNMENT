#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int findParent(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x], parent);
}

void unite(int a, int b, vector<int>& parent, vector<int>& rankv) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b) {
        if (rankv[a] < rankv[b]) parent[a] = b;
        else if (rankv[b] < rankv[a]) parent[b] = a;
        else parent[b] = a, rankv[a]++;
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<Edge> edges(e);
    for (int i = 0; i < e; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), [](Edge a, Edge b){ return a.w < b.w; });

    vector<int> parent(n), rankv(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    int mstWeight = 0;
    for (auto& ed : edges) {
        int pu = findParent(ed.u, parent);
        int pv = findParent(ed.v, parent);
        if (pu != pv) {
            unite(pu, pv, parent, rankv);
            cout << ed.u << " " << ed.v << " " << ed.w << "\n";
            mstWeight += ed.w;
        }
    }
    cout << mstWeight;
}
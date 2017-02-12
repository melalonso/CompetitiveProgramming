#include <bits/stdc++.h>

#define MAXV 1002

// ACC

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<iii> graph;
vector<int> cycleEdges;
int n, m, parent[MAXV];

int unionfind(int x) {
    if (x != parent[x])
        parent[x] = unionfind(parent[x]);
    return parent[x];
}

void kruskal() {
    int u, v, pu, pv;
    sort(graph.begin(), graph.end());
    for (int i = 0; i < graph.size(); i++) {
        u = graph[i].second.first;
        v = graph[i].second.second;
        pu = unionfind(u);
        pv = unionfind(v); // Find parents - subtree.
        if (pu != pv) { // Add if are in a different subtree.
            parent[pu] = parent[pv]; // Union
        } else {
            cycleEdges.push_back(graph[i].first);
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int u, v, w;
    while (cin >> n >> m, n || m) {

        for (int i = 0; i < n; i++) parent[i] = i;

        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            graph.push_back({w, {u, v}});
        }

        kruskal();

        if (cycleEdges.empty()) cout << "forest\n";
        else {
            int ssize = (int) cycleEdges.size();
            sort(cycleEdges.begin(), cycleEdges.end());
            for (int i = 0; i < ssize; i++) {
                cout << cycleEdges[i];
                if (i < ssize - 1) cout << " ";
            }
            cout << "\n";
        }

        graph.clear();
        cycleEdges.clear();

    }

    return 0;
}
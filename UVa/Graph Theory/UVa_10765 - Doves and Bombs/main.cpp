#include <bits/stdc++.h>

#define MAXN 10002
using namespace std;

typedef pair<int, int> ii;

int n, m, cnt;
vector<int> graph[MAXN];
int disc[MAXN], low[MAXN];
int children[MAXN], parent[MAXN];

// ACC

void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void AP(int u) {
    low[u] = disc[u] = ++cnt;
    for (int j = 0; j < graph[u].size(); j++) {
        int v = graph[u][j];
        if (!disc[v]) {
            parent[v] = u;
            AP(v);

            if (low[v] >= disc[u]) children[u]++;
            low[u] = min(low[u], low[v]); // propagate low[v] up

        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]); // update low[u] based on discover time of ancestor
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int u, v;
    while (cin >> n >> m && (n || m)) {

        for (int i = 0; i < n; i++) graph[i].clear();
        while (cin >> u >> v && u != -1) addEdge(u, v);

        for (int i = 0; i < n; i++) {
            children[i] = 0;
            disc[i] = 0;
            parent[i] = -1;
        }

        cnt = 0, AP(0);

        vector<ii> targets;
        targets.push_back({children[0], 0});
        for (int i = 1; i < n; i++) {
            targets.push_back({children[i] + 1, -i}); // Adding 1 cause of the subtree left from parent up
        }

        sort(targets.rbegin(), targets.rend());
        for (int i = 0; i < m; i++){
            cout << -targets[i].second << " "<<targets[i].first << "\n";
        }
        cout << "\n";
    }
    return 0;
}
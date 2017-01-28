#include <bits/stdc++.h>

#define MAXN 105
using namespace std;


// ACC

int root = 1, n, cnt, rootChildren;
vector<int> graph[MAXN];
int disc[MAXN], low[MAXN], parent[MAXN];
bool art_vertex[MAXN];

void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void AP(int u) {
    low[u] = disc[u]  = ++cnt;
    for (int j = 0; j < graph[u].size(); j++) {
        int v = graph[u][j];
        if (!disc[v]) {
            parent[v] = u;
            if (u == root) rootChildren++;

            AP(v);

            if (low[v] >= disc[u]) art_vertex[u] = true;
            low[u] = min(low[u], low[v]); // propagate low[v] up

        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]); // update low[u] based on discover time of ancestor
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    string line;
    int from, to;
    while (cin >> n && n) {
        for (int i = 0; i <= n; i++) graph[i].clear();

        getline(cin, line);
        while (getline(cin, line) && line != "0") {
            stringstream s(line);
            s >> from;
            while (s >> to) addEdge(from, to);
        }

        for (int i = 1; i <= n; i++) {
            art_vertex[i] = false;
            disc[i] = 0;
            parent[i] = -1;
        }

        rootChildren = cnt = 0;
        AP(1);
        art_vertex[root] = (rootChildren > 1);

        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (art_vertex[i]) res++;
        }
        cout << res << "\n";
    }
    return 0;
}
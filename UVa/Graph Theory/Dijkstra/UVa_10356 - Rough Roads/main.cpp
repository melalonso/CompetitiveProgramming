#include <bits/stdc++.h>

#define INF 252645135
#define MAXN 505
using namespace std;

// ACC

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<ii> graph[MAXN];
int n, r;

void addEdge(int u, int v, int w) {
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}

int dijkstra(int o, int d) {
    int distance[MAXN][2];
    memset(distance, 9999, sizeof distance);
    distance[o][0] = 0;
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push({0, {o, 0}});
    ii node;
    int u, cost, mode, v, len, nextMode;
    while (!pq.empty()) {
        tie(cost, node) = pq.top(), tie(u, mode) = node;
        pq.pop();
        if (cost > distance[u][mode]) continue;
        for (int i = 0; i < graph[u].size(); i++) {
            tie(v, len) = graph[u][i];
            nextMode = !mode;
            if (distance[v][nextMode] > distance[u][mode] + len) {
                distance[v][nextMode] = distance[u][mode] + len;
                pq.push({distance[v][nextMode], {v, nextMode}});
            }
        }
    }
    return distance[d][0];
}

void clear() {
    for (int i = 0; i < MAXN; i++) graph[i].clear();
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    int u, v, w, idx = 1;
    while (cin >> n >> r) {
        while (r--) {
            cin >> u >> v >> w;
            addEdge(u, v, w);
        }
        cout << "Set #" << idx++ << "\n";
        int res = dijkstra(0, n - 1);
        (res == INF) ? cout << "?\n" : cout << res << "\n";
        clear();
    }
    return 0;
}
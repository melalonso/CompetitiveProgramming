#include <bits/stdc++.h>

#define MAXN 1005
#define INF 252645135

using namespace std;

// ACC

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, m, u, v, d, q;
int fuelPrice[MAXN];
vector<ii> graph[4005];


void addEdge(int u, int v, int len) {
    graph[u].push_back({v, len});
    graph[v].push_back({u, len});
}

int dijkstra(int s, int d, int c) {
    int distances[MAXN][102];
    memset(distances, 9999, sizeof distances);
    distances[s][0] = 0;
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push({0, {s, 0}});
    ii node;
    int u, cost, v, len, fuel;

    while (!pq.empty()) {
        tie(cost, node) = pq.top(), tie(u, fuel) = node;
        pq.pop();

        if (u == d) return cost;

        if (cost > distances[u][fuel]) continue;
        if (fuel + 1 <= c) { // Not enough so need to refill tank in current city
            int tmp = fuel + 1;
            if (distances[u][tmp] > cost + fuelPrice[u]) {
                distances[u][tmp] = cost + fuelPrice[u];
                pq.push({distances[u][tmp], {u, tmp}});
            }
        }
        for (int i = 0; i < graph[u].size(); i++) {
            tie(v, len) = graph[u][i];
            if (fuel >= len) { // Enough for road
                int tmp = fuel - len;
                if (distances[v][tmp] > cost) {
                    distances[v][tmp] = cost;
                    pq.push({distances[v][tmp], {v, tmp}});
                }
            }
        }
    }
    return INF;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, s, e;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> fuelPrice[i];
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> d;
        addEdge(u, v, d);
    }
    cin >> q;
    while (q--) {
        cin >> c >> s >> e;
        int res = dijkstra(s, e, c);
        res == INF ? cout << "impossible\n" : cout << res << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>

#define INF 999999
using namespace std;

typedef pair<int, int> ii;

vector<ii> graph[105];
int cases, n, exitt, timee, m;
int a, b, cost;

// ACC

void addEdge(int u, int v, int w) {
    graph[u].push_back({v, w});
}

int dijkstra(int o) {
    vector<int> distance(n + 2, INF);
    distance[o] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, o});
    int node, cost;
    while (!pq.empty()) {
        tie(cost, node) = pq.top();
        pq.pop();
        if (distance[node] < cost) continue;
        for (int i = 0; i < graph[node].size(); i++) {
            ii e = graph[node][i];
            if (distance[e.first] > distance[node] + e.second) {
                distance[e.first] = distance[node] + e.second;
                pq.push({distance[e.first], e.first});
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (distance[i] <= timee) res++;
    }
    return res;
}

void clear() {
    for (int i = 0; i < 105; i++) graph[i].clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> cases;
    while (cases--) {
        cin >> n >> exitt >> timee;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> cost;
            addEdge(b - 1, a - 1, cost);
        }
        int res = dijkstra(exitt - 1);
        cout << res << "\n";
        if (cases > 0) cout << "\n";
        clear();
    }
    return 0;
}
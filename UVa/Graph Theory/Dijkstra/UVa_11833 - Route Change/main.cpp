#include <bits/stdc++.h>

#define INF 999999
#define MAXN 255
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

int n, m, c, k, a, b, cost;

vector<ii> graph[MAXN];

// ACC

void addEdge(int u, int v, int weight) {
    graph[u].push_back({v, weight});
}

int dijkstra(int o, int d) {
    vi distance(n+5, INF);
    distance[o] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push({0, o});
    int node, w;
    while (!pq.empty()) {
        tie(w, node) = pq.top();
        pq.pop();
        if (w > distance[node]) continue;
        for (int i = 0; i < graph[node].size(); i++) {
            ii v = graph[node][i];
            if (node >= d) {
                if (distance[v.first] > distance[node] + v.second) {
                    distance[v.first] = distance[node] + v.second;
                    pq.push({distance[v.first], v.first});
                }
            } else if (v.first == node+1){
                if (distance[v.first] > distance[node] + v.second) {
                    distance[v.first] = distance[node] + v.second;
                    pq.push({distance[v.first], v.first});
                }
            }
        }
    }
    return distance[d];
}

void clear() {
    for (int i = 0; i < MAXN; i++) graph[i].clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    while (cin >> n >> m >> c >> k, n||m||c||k) {
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> cost;
            addEdge(a, b, cost);
            addEdge(b, a, cost);
        }
        cout << dijkstra(k, c - 1) << "\n";
        clear();
    }
    return 0;
}
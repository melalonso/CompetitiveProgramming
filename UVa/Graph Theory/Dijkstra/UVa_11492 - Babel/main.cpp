#include <bits/stdc++.h>

#define INF 252645135
using namespace std;

// ACC

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<iii> graph[4005];
map<string, int> map1;
string o, d;
int n;

void addEdge(int u, int v, string w) {
    int ssize = (int) w.size();
    int initial = w[0] - 'a';
    graph[u].push_back({v, {ssize, initial}});
    graph[v].push_back({u, {ssize, initial}});
}

int dijkstra(int o, int d) {
    int distance[4005][28];
    memset(distance, 9999, sizeof distance);
    fill(distance[o], distance[o] + 28, 0);

    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push({0, {o, -1}});
    ii nodeini;
    int node, iniU, cost;
    int v, size, iniV;
    while (!pq.empty()) {
        tie(cost, nodeini) = pq.top(), tie(node, iniU) = nodeini;
        pq.pop();
        if (cost > distance[node][iniU]) continue;
        for (int i = 0; i < graph[node].size(); i++) {
            tie(v, nodeini) = graph[node][i];
            tie(size, iniV) = nodeini;
            if (distance[v][iniV] > cost + size && iniU != iniV) {
                distance[v][iniV] = cost + size;
                pq.push({distance[v][iniV], {v, iniV} });
            }
        }
    }
    int res = INF;
    for (int i = 0; i < 28; i++) res = min(res, distance[d][i]);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    string l1, l2, word;
    int idx;
    while (cin >> n, n) {
        cin >> o >> d;
        idx = 0;
        for (int i = 0; i < n; i++) {
            cin >> l1 >> l2 >> word;
            if (map1.find(l1) == map1.end()) {
                map1[l1] = idx++;
                graph[map1[l1]].clear();
            }
            if (map1.find(l2) == map1.end()) {
                map1[l2] = idx++;
                graph[map1[l2]].clear();
            }
            addEdge(map1[l1], map1[l2], word);
        }
        if (map1.find(o) == map1.end() || map1.find(d) == map1.end()) {
            cout << "impossivel\n";
        } else {
            int res = dijkstra(map1[o], map1[d]);
            (res == INF || !res) ? cout << "impossivel\n" : cout << res << "\n";
        }
        map1.clear();
    }
    return 0;
}
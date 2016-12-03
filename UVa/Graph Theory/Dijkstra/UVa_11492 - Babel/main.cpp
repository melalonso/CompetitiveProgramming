#include <bits/stdc++.h>

#define INF 252645135
using namespace std;

struct edge {
    int to, weight, ini_char;
    edge() {};
    edge(int to, int w, int ini) : to(to), weight(w), ini_char(ini) {};
    bool operator<(const edge &E) const {
        return weight > E.weight;
    }
};

vector<edge> graph[4005];
map<string, int> map1;
string o, d;
int n;

void addEdge(int u, int v, string w) {
    int ssize = w.size();
    int initial = w[0] - 'a';
    graph[u].push_back(edge(v, ssize, initial));
    graph[v].push_back(edge(u, ssize, initial));
}

int dijkstra(int o, int d) {
    int distance[4005][28];
    memset(distance, 9999, sizeof distance);
    fill(distance[o], distance[o] + 28, 0);

    priority_queue<edge> pq;
    pq.push(edge(o, 0, -1));
    edge u, v;
    while (!pq.empty()) {
        u = pq.top();
        pq.pop();
        if (u.weight > distance[u.to][u.ini_char]) continue;
        for (int i = 0; i < graph[u.to].size(); i++) {
            v = graph[u.to][i];
            if (distance[v.to][v.ini_char] > u.weight + v.weight
                && u.ini_char != v.ini_char) {
                distance[v.to][v.ini_char] = u.weight + v.weight;
                pq.push(edge(v.to, distance[v.to][v.ini_char], v.ini_char));
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
#include <bits/stdc++.h>
#define MAXN 505
#define INF INT32_MAX
using namespace std;

typedef pair<int, int> ii;

// ACC

vector<ii> graph[MAXN];
int fi, in, station;
int u, v, w;
set<int> stations;

void addEdge(int u, int v, int w) {
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}

void removeEdge(int u, int v){
    graph[u].pop_back();
    graph[v].pop_back();
}

int dijkstra() {
    int distance[in+5];
    fill(distance, distance+in+5, INF);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    distance[0] = 0;
    pq.push({0, 0});
    int u, v, cost, weight;
    while (!pq.empty()) {
        tie(cost, u) = pq.top();
        pq.pop();
        if (cost > distance[u]) continue;
        for (int i = 0; i < graph[u].size(); i++) {
            tie(v, weight) = graph[u][i];
            if (distance[v] > cost + weight) {
                distance[v] = cost + weight;
                pq.push({distance[v], v});
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= in; i++) res = max(res, distance[i]);
    return res;
}

void clear() {
    stations.clear();
    for (int i=0; i<MAXN; i++) graph[i].clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases, res, minMaxDistance, dist;
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    string line;
    cin >> cases;
    getline(cin, line);
    getline(cin, line);
    while (cases--) {
        cin >> fi >> in;
        for (int i = 0; i < fi; i++) {
            cin >> station;
            stations.insert(station);
        }
        getline(cin, line);
        while (getline(cin, line) && line != "") {
            stringstream s(line);
            s >> u >> v >> w;
            addEdge(u, v, w);
        }

        for (auto st: stations) addEdge(0, st, 0);

        minMaxDistance = INF, res = 0;
        for (int i = 1; i <= in; i++) {
            addEdge(0, i, 0);
            dist = dijkstra();
            if (dist < minMaxDistance){
                minMaxDistance = dist;
                res = i;
            }
            removeEdge(0, i);
        }

        cout << res << "\n";
        if (cases) cout << "\n";
        clear();
    }
    return 0;
}
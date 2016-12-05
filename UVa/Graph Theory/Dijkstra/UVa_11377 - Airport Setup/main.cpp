#include <bits/stdc++.h>
#define INF 999999

using namespace std;

typedef pair<int, int> ii;

int cases, u, v;
int n, m, k, x, q;
set<int> ap;
vector<ii> graph[2010];

// ACC

void addEdge(int u, int v, int w){
    graph[u].push_back({v, w});
}

int dijkstra(int o, int d) {
    vector<int> distance(n + 5, INF);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    if (ap.find(o)==ap.end()){
        pq.push({1, o});
        distance[o] = 1;
    } else {
        pq.push({0, o});
        distance[o] = 0;
    }

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
    return distance[d];
}

void clear(){
    for(int i=0;i<2010; i++) graph[i].clear();
    ap.clear();
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> cases;
    for (int i=1; i<=cases; i++) {
        cin >> n >> m >> k;
        for (int l=0; l<k; l++){
            cin >> x;
            ap.insert(x);
        }
        for (int j=0; j<m; j++){
            cin >> u >> v;
            if (ap.find(v) == ap.end()) addEdge(u, v, 1);
            else addEdge(u, v, 0);
            if (ap.find(u) == ap.end()) addEdge(v, u, 1);
            else addEdge(v, u, 0);
        }
        cin >> q;
        cout << "Case "<<i<<":\n";
        while(q--){
            cin >> u >> v;
            if (u==v) cout << "0\n";
            else {
                int res = dijkstra(u, v);
                res==INF ? cout << "-1" << "\n": cout << res << "\n";
            }
        }
        cout << "\n";
        clear();
    }
    return 0;
}
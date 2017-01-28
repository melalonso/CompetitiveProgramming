#include <bits/stdc++.h>

using namespace std;

// ACC

typedef pair<int, int> ii;

int n, cnt;
vector<int> *graph;
int *disc, *low, *parent;
vector<ii> bridges;

void addEdge(int u, int v) {
    graph[u].push_back(v);
}

void AP(int u) {
    low[u] = disc[u] = ++cnt;
    for (int j = 0; j < graph[u].size(); j++) {
        int v = graph[u][j];
        if (!disc[v]) {
            parent[v] = u;

            AP(v);

            if (low[v] > disc[u]){
                if (u > v) bridges.push_back({v, u});
                else bridges.push_back({u, v});
            }

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
    while (cin >> n) {

        graph = new vector<int>[n+2];
        disc = new int[n+2];
        low = new int[n+2];
        parent = new int[n+2];

        char b1{}, b2{};
        int amt{};
        for (int i = 0; i < n; i++) {
            cin >> u;
            cin >> b1 >> amt >> b2;
            while (amt--) {
                cin >> v;
                addEdge(u, v);
            }
        }

        for (int i = 0; i < n; i++) {
            disc[i] = 0;
            parent[i] = -1;
        }

        cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!disc[i]) AP(i);
        }

        int total = (int) bridges.size();
        sort(bridges.begin(), bridges.end());

        cout << total << " critical links\n";
        for (int i = 0; i < total; i++) {
            cout << bridges[i].first << " - " << bridges[i].second << "\n";
        }
        cout << "\n";
        bridges.clear();

    }
    return 0;
}
#include <bits/stdc++.h>
#define MAXN 102
#define INMST 1

using namespace std;

// ACC

struct edge {
    int cost, state, u, v;
    edge() {};
    edge(int c, int mu, int mv) {
        cost = c;
        state = 0;
        u = mu;
        v = mv;
    }

    bool operator<(const edge &a) const {
        return cost < a.cost;
    }
};

int n, m, skip;
bool lookingMST;
vector<edge> graph;
int parent[MAXN];
int minimum;

void addEdge(int u, int v, int cost) {
    graph.push_back(edge(cost, u, v));
}

int unionfind(int x) {
    if (x != parent[x])
        parent[x] = unionfind(parent[x]);
    return parent[x];
}

void kruskal() {
    int u, v, pu, pv;
    int ssize = (int) graph.size();
    for (int i = 1; i <= n; i++) parent[i] = i;
    minimum = 0;
    for (int i = 0; i < ssize; i++) {
        if (i == skip) continue;
        u = graph[i].u;
        v = graph[i].v;
        pu = unionfind(u);
        pv = unionfind(v); // Find parents - subtree.
        if (pu != pv) { // Add if are in a different subtree.
            minimum += graph[i].cost;
            if (lookingMST) graph[i].state = INMST;
            parent[pu] = parent[pv]; // Union
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases, a, b, c;
    int min1, min2;
    cin >> cases;
    while (cases--) {
        min2 = INT32_MAX;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            addEdge(a, b, c);
        }

        // Prepare for kruskal
        skip = -1;
        lookingMST = true;
        sort(graph.begin(), graph.end());
        kruskal(), min1 = minimum;
        lookingMST = false;

        for (int i = 0; i < graph.size(); i++) {
            if (graph[i].state == INMST) {
                skip = i;
                kruskal();
                if (minimum >= min1) min2 = min(min2, minimum);
            }
        }

        cout << min1 << " " << min2 << "\n";
        graph.clear();

    }

    return 0;
}
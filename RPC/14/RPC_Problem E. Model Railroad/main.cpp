#include <bits/stdc++.h>

#define edge pair<int, int>
#define MAXV 50010

using namespace std;

// NOT ACCEPTED

vector<pair<int, edge > > graph;
int parent[MAXV];

long long minimun, sum;
long long n, m, l, a, b, c;

int unionfind(int x) {
    if (x != parent[x])
        parent[x] = unionfind(parent[x]);
    return parent[x];
}


void kruskal() {
    int u, v, pu, pv;
    sort(graph.begin(), graph.end());
    for (int i = 0; i < m; i++) {
        u = graph[i].second.first;
        v = graph[i].second.second;
        pu = unionfind(u);
        pv = unionfind(v); // Find parents - subtree.
        if (pu != pv) { // Add if are in a different subtree.
            minimun += graph[i].first;
            parent[pu] = parent[pv]; // Union
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m >> l){
        for (int i=0;i<n; i++)  parent[i] = i;
        graph.clear();
        sum = minimun = 0;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            graph.push_back(pair<int, edge >(c, edge(a-1, b-1)));
            if (i < l) sum += c;
        }

        kruskal();
        if (minimun <= sum) cout << "possible\n";
        else cout << "impossible\n";
    }

    return 0;
}
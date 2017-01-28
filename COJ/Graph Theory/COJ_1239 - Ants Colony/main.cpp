#include <bits/stdc++.h>

#define MAXN 100005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, ll> iii;

vector<ii> graph[MAXN];
bool visited[MAXN];
int euler[2 * MAXN], level[2 * MAXN], n;
int firstOcc[MAXN];
ll distances[MAXN];

// ACC

// For Segment Tree
const int N = 1e5;  // limit for array size
int idx;  // array size
ii t[4 * N];

void build() {  // build the tree
    for (int i = idx - 1; i > 0; --i) t[i] = min(t[i << 1], t[i << 1 | 1]);
}

int query(int l, int r) {  // sum on interval [l, r)
    ii res = {INT_MAX, 0};
    for (l += idx, r += idx; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, t[l++]);
        if (r & 1) res = min(res, t[--r]);
    }
    return res.second; // index of minimum
}


void addEdge(int u, int v, int w) {
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}

void doEuler() {
    memset(firstOcc, -1, sizeof firstOcc);
    fill(visited, visited+MAXN, false);
    stack<iii> q;
    q.push({{0, 0}, 0});
    int u, v, lev, len;
    ll dis;
    ii nodelev;
    idx = 0;
    while (!q.empty()) {
        tie(nodelev, dis) = q.top(), q.pop();
        tie(u, lev) = nodelev;

        euler[idx] = u;
        level[idx++] = lev;

        if (firstOcc[u] == -1) {
            firstOcc[u] = idx - 1;
            distances[u] = dis;
        }

        if (!visited[u]) {
            for (int i = 0; i < graph[u].size(); i++) {
                tie(v, len) = graph[u][i];
                if (!visited[v]) {
                    q.push({{u, lev}, dis});
                    q.push({{v, lev + 1}, dis + len});
                }
            }
        }
        visited[u] = true;
    }
}

int getLCA(int a, int b) {
    int minimum = query(min(firstOcc[a], firstOcc[b]), max(firstOcc[a], firstOcc[b]));
    return euler[minimum];
}

// Reduce LCA to RMQ
// - Do an Euler tour
//      * Calc levels array
//      * Calc firstOcc array
//      * Calc distances array
// - Based on the firstOcc array calc range to RMQ on levels
// - Do RMQ using Segment Tree for minimum (index of LCA of 'u' and 'v')
// - Use LCA, u and v to calculate distance through distances array
int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int to, len, q;
    int o, d, lca;
    ll res;
    while (cin >> n && n) {
        for (int i = 1; i < n; i++) {
            cin >> to >> len;
            addEdge(i, to, len);
        }

        doEuler();
        for (int i=0; i<idx; i++) t[i+idx] = {level[i], i};
        build();

        cin >> q;
        while (q--) {
            cin >> o >> d;
            lca = getLCA(o, d);
            res = distances[o] + distances[d] - (2 * distances[lca]);
            cout << res;
            cout << (q ? " " : "\n");
        }

        for (int i=0; i<MAXN; i++) graph[i].clear();
    }
    return 0;
}
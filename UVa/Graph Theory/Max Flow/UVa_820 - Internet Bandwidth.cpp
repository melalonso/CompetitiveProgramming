#include <bits/stdc++.h>

#define MAX_V 102
#define INF INT_MAX

using namespace std;

// ACC

typedef vector<int> vi;

int res[MAX_V][MAX_V], f, s, t;
vi p;

// p stores the BFS spanning tree from s
void augment(int v, int minEdge) { // traverse BFS spanning tree from s->t
    if (v == s) {
        f = minEdge;
        return;
    } // record minEdge in a global var f
    else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

int process() {
    int mf = 0;
    while (1) {
        f = 0;
        vi dist(MAX_V, INF);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        p.assign(MAX_V, -1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == t) break; // immediately stop BFS if we already reach sink t
            for (int v = 0; v < MAX_V; v++) // this part is slow
                if (res[u][v] > 0 && dist[v] == INF)
                    dist[v] = dist[u] + 1, q.push(v), p[v] = u;
        }
        augment(t, INF);
        // find the min edge weight ‘f’ in this path, if any
        if (f == 0) break; // we cannot send any more flow (‘f’ = 0), terminate
        mf += f; // we can still send a flow, increase the max flow!
    }

    return mf;
}


int main() {
    ios::sync_with_stdio(false);
    // cin.tie(0);
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    int n, c, u, v, w, idx = 1;
    while (cin >> n && n) {
        cin >> s >> t >> c;
        memset(res, 0, sizeof res);
        for (int i=0; i<c; i++) {
            cin >> u >> v >> w;
            res[u][v] += w;
            res[v][u] += w;
        }
        cout << "Network "<< idx++ << "\n";
        cout << "The bandwidth is "<< process() << ".\n\n";
    }

    return 0;
}

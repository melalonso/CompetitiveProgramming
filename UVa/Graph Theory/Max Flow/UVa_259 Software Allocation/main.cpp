#include <bits/stdc++.h>

#define MAX_V 40
#define INF INT_MAX

using namespace std;

// ACC

typedef vector<int> vi;

int res[MAX_V][MAX_V], mf, f, s, t, total;
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

void process() {
    // connect computers to sink;
    for (int i = 27; i < 37; i++) res[i][37] = 1; // one computer can only run one app
    s = 0, t = 37;
    mf = 0;
    while (1) { // O(VE^2) (actually O(V^3 E) Edmonds Karp’s algorithm
        f = 0;
        vi dist(MAX_V, INF);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        p.assign(MAX_V, -1);
        // record the BFS spanning tree, from s to t!
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

    if (mf == total) {
        for (int i = 27; i < 37; i++) {
            bool found = false;
            for (int j = 1; j < 27; j++) {
                if (res[i][j] == 1) {
                    found = true;
                    cout << char(j + 'A' - 1);
                }
            }
            if (!found) cout << "_";
        }
        cout << "\n";
    } else {
        cout << "!\n";
    }

    // Reset structures
    total = 0;
    memset(res, 0, sizeof res);
}


int main() {
    ios::sync_with_stdio(false);
    // cin.tie(0);
    int amtUsers;
    char app;
    string computers, line;
    // freopen("input", "r", stdin);

    while (getline(cin, line)) {
        stringstream ss(line);
        if (line != "") {
            ss >> app >> amtUsers;
            total += amtUsers;
            ss >> computers;
            res[0][app - 'A' + 1] = amtUsers; // edge from source to app with weight = amtUsers

            for (int i = 0; i < computers.size() - 1; i++) {
                int pos = 27 + (computers[i] - '0');
                // Could also be set to 1, but chose INF for a overall impl.
                res[app - 'A' + 1][pos] = INF; // edge from app to computers on which app can run
            }
        } else {
            process();
        }
    }
    process(); // Process last case
    return 0;
}
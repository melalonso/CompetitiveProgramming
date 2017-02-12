#include <bits/stdc++.h>

#define MAXV 1002

using namespace std;

typedef pair<int, int> ii;

// ACC

vector<pair<double, ii> > graph;
pair<double, double> points[MAXV];
int E, n, railRoads;
int parent[MAXV];
double minRoads, minRails, r;

int unionfind(int x) {
    if (x != parent[x])
        parent[x] = unionfind(parent[x]);
    return parent[x];
}

void kruskal() {
    int u, v, pu, pv, edges = 0;
    double dist;
    sort(graph.begin(), graph.end());
    for (int i = 0; i < E; i++) {
        if (edges == n - 1) break;
        u = graph[i].second.first;
        v = graph[i].second.second;
        dist = graph[i].first;
        if (dist <= r) {
            pu = unionfind(u);
            pv = unionfind(v); // Find parents - subtree.
            if (pu != pv) { // Add if are in a different subtree.
                minRoads += dist;
                edges++;
                parent[pu] = parent[pv]; // Union
            }
        } else {
            pu = unionfind(u);
            pv = unionfind(v); // Find parents - subtree.
            if (pu != pv) { // Add if are in a different subtree.
                minRails += dist;
                edges++, railRoads++;
                parent[pu] = parent[pv]; // Union
            }
        }
    }
    minRoads = round(minRoads);
    minRails = round(minRails);
}


int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases;
    double distance, x, y;
    cin >> cases;
    for (int caso = 1; caso <= cases; caso++) {

        cin >> n >> r;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            cin >> x >> y;
            points[i] = {x, y};
        }

        E = (n * (n - 1)) / 2; // Max edges on a complete graph.

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                distance = hypot(points[i].first - points[j].first,
                                 points[i].second - points[j].second); // Distance between points.
                graph.push_back(pair<double, ii>(distance, {i, j}));
            }
        }

        kruskal();

        cout << "Case #" << caso << ": " << railRoads + 1 << " " << minRoads << " " << minRails << "\n";

        graph.clear();
        minRoads = minRails = railRoads = 0;

    }

    return 0;
}
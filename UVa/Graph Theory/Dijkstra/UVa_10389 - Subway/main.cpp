#include <bits/stdc++.h>

#define MAXV 210

using namespace std;

// ACC

typedef pair<double, int> di;
typedef pair<int, double> ido;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<double> vdo;
typedef vector<pair<dd, int> > vddi;

vector<ido> graph[MAXV];

void addEdge(int u, int v, double weight) {
    graph[u].push_back({v, weight});
    graph[v].push_back({u, weight});
}

double dijkstra(int s, int d) {
    vdo dist(MAXV, 99999.0);
    dist[s] = 0.0;
    priority_queue<di, vector<di>, greater<di> > pq;
    pq.push({0.0, s});
    double weight;
    int node;
    while (!pq.empty()) {
        di front = pq.top();
        pq.pop();
        weight = front.first, node = front.second;
        if (weight > dist[node]) continue;
        for (int i = 0; i < graph[node].size(); i++) {
            ido v = graph[node][i];
            if (dist[node] + v.second < dist[v.first]) {
                dist[v.first] = dist[node] + v.second;
                pq.push(di(dist[v.first], v.first));
            }
        }
    }
    return dist[d];
}

void clear() { for (int i = 0; i < MAXV; i++) graph[i].clear(); }

int main() {
    ios::sync_with_stdio(0); //cin.tie(0);
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int cases, idx;
    double xhome, yhome, xschool, yschool, x, y;
    double weight, distance;
    dd coords;
    string subwayStops;

    cin >> cases;
    while (cases--) {
        vector<vddi> subways;
        int last_node = 1;
        cin >> xhome >> yhome >> xschool >> yschool;

        getline(cin, subwayStops);
        while (getline(cin, subwayStops) && subwayStops != "") {
            stringstream ss(subwayStops);
            vddi stops;
            while (ss >> x, ss >> y && x != -1 && y != -1) {
                stops.push_back({{x, y}, last_node++});
            }
            subways.push_back(stops);
        }

        // Walking from home to every other point
        // and from every point to school
        for (int i = 0; i < subways.size(); i++) {
            for (int j = 0; j < subways[i].size(); j++) {
                tie(coords, idx) = subways[i][j];
                distance = hypot(xhome - coords.first, yhome - coords.second);
                weight = distance * 3 / 500.0;
                addEdge(0, idx, weight);

                distance = hypot(xschool - coords.first, yschool - coords.second);
                weight = distance * 3 / 500.0;
                addEdge(idx, last_node, weight);
            }
        }

        distance = hypot(xhome - xschool, yhome - yschool);
        weight = distance * 3 / 500.0;
        addEdge(0, last_node, weight);


        // Between stops in same subway 40km/h
        ii coords2; int idx2;
        for (int i = 0; i < subways.size(); i++) {
            for (int j = 0; j < subways[i].size() - 1; j++) {
                tie(coords, idx) = subways[i][j];
                tie(coords2, idx2) = subways[i][j + 1];
                distance = hypot(coords.first - coords2.first, coords.second - coords2.second);
                weight = distance * 3 / 2000.0;
                addEdge(idx, idx2, weight);
            }
        }


        // WALKING between stops in same subway 10km/h
        for (int i = 0; i < subways.size(); i++) {
            for (int j = 0; j < subways[i].size() - 1; j++) {
                for (int k = j+1; k < subways[i].size(); k++) {
                    tie(coords, idx) = subways[i][j];
                    tie(coords2, idx2) = subways[i][k];
                    distance = hypot(coords.first - coords2.first, coords.second - coords2.second);
                    weight = distance * 3 / 500.0;
                    addEdge(idx, idx2, weight);
                }
            }
        }


        // Walking from every stop to another
        for (int i = 0; i < subways.size() - 1; i++) {
            for (int j = 0; j < subways[i].size(); j++) {
                for (int k = i + 1; k < subways.size(); k++) {
                    for (int l = 0; l < subways[k].size(); l++) {
                        tie(coords, idx) = subways[i][j];
                        tie(coords2, idx2) = subways[k][l];
                        distance = hypot(coords.first - coords2.first, coords.second - coords2.second);
                        weight = distance * 3 / 500.0;
                        addEdge(idx, idx2, weight);
                    }
                }
            }
        }

        cout << fixed << setprecision(0) << dijkstra(0, last_node) << "\n";
        if (cases > 0) cout << "\n";
        clear();
    }
    return 0;
}
#include <bits/stdc++.h>

#define INF 999999
#define MAXN 510

using namespace std;

// ACC

typedef pair<int, int> ii;
typedef vector<int> vi;

int n, k, pfloor, cfloor;

vector<ii> graph[MAXN];
bool isPresent[5][105];
int times[5];

void addEdge(int u, int v, int weight) {
    graph[u].push_back({v, weight});
    graph[v].push_back({u, weight});
}

int dijkstra(int d) {
    vi distance(MAXN, INF);
    priority_queue<ii, vector<ii>, greater<ii> > pq;

    for (int i = 0; i < n; i++)
        if (isPresent[i][0]) {
            distance[100 * i] = 0;
            pq.push({0, 100 * i});
        }

    int node, w;
    while (!pq.empty()) {
        tie(w, node) = pq.top();
        pq.pop();
        if (w > distance[node]) continue;
        for (int i = 0; i < graph[node].size(); i++) {
            ii v = graph[node][i];
            if (distance[v.first] > distance[node] + v.second) {
                distance[v.first] = distance[node] + v.second;
                pq.push({distance[v.first], v.first});
            }
        }
    }

    int result = INF;
    for (int i = 0; i < n; i++) {
        result = min(result, distance[d + (100 * i)]);
    }
    return result;
}

void clear() {
    for (int i = 0; i < MAXN; i++) graph[i].clear();
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 100; j++)
            isPresent[i][j] = false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string floors;
    while (cin >> n >> k) {
        for (int i = 0; i < n; i++) cin >> times[i];
        getline(cin, floors);
        for (int i = 0; i < n; i++) {
            getline(cin, floors);
            stringstream ss(floors);
            ss >> pfloor;
            isPresent[i][pfloor] = true;
            while (ss >> cfloor) {
                addEdge(pfloor + (100 * i), cfloor + (100 * i), (cfloor - pfloor) * times[i]);
                isPresent[i][cfloor] = true;
                pfloor = cfloor;
            }
        }

        // Add edges between same floor numbers
        // at different elevators.
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < n-1; j++)
                if (isPresent[j][i])
                    for (int l = j + 1; l < n; l++)
                        if (isPresent[l][i])
                            addEdge(i + (100 * j), i + (100 * l), 60);

        int res = dijkstra(k);
        res == INF ? cout << "IMPOSSIBLE\n" : cout << res << "\n";
        clear();
    }

    return 0;
}
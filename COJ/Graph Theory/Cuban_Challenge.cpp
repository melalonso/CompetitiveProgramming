#include <bits/stdc++.h>

#define MAX 100001
#define NIL 0
#define INF (1<<28)

using namespace std;

char arr[22][1002];

vector<int> graph[MAX];
int n, m, match[MAX], dist[MAX];

void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

bool bfs() {
    int i, u, v, len;
    queue<int> Q;
    for (i = 1; i <= n; i++) {
        if (match[i] == NIL) {
            dist[i] = 0;
            Q.push(i);
        } else dist[i] = INF;
    }
    dist[NIL] = INF;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        if (u != NIL) {
            len = graph[u].size();
            for (i = 0; i < len; i++) {
                v = graph[u][i];
                if (dist[match[v]] == INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL] != INF); // Was possible to arrive to dummy node
}

bool dfs(int u) {
    int i, v, len;
    if (u != NIL) {
        len = graph[u].size();
        for (i = 0; i < len; i++) {
            v = graph[u][i];
            if (dist[match[v]] == dist[u] + 1) {
                if (dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in graph
    while (bfs()) // there is a augmenting path
        for (i = 1; i <= n; i++)
            if (match[i] == NIL && dfs(i))
                matching++;
    return matching;
}


int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int x, y;
    while(cin >> x >> y && x || y) {
        for (int i=0; i<x; i++) {
            cin >> arr[i];
        }
    }


    return 0;
}

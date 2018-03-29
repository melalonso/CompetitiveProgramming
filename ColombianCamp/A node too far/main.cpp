#include <bits/stdc++.h>
#include <utility>

#define forr(i, a, b) for(int i=(a); i<(b); i++)
#define forn(i, n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define dforn(i, n) for(int i=n-1; i>=0; i--)

// ACC

using namespace std;

typedef pair<int, int> ii;
map<int, vector<int>> graph;
map<int, bool> visited;
int reached;

void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void bfs(int start, int ttl) {
    queue<ii> q;
    q.push(ii(start, 0));
    int currNode, level;
    reached = 0;
    visited.clear();
    visited[start] = true;
    while (!q.empty()) {
        tie(currNode, level) = q.front(), q.pop();
        reached++;
        if (level == ttl) continue;
        forn(i, graph[currNode].size()) {
            int v = graph[currNode][i];
            if (!visited[v]) {
                visited[v] = true;
                q.push(ii(v, level + 1));
            }

        }
    }
}

void clean() {
    graph.clear();
}

int main() {
    ios::sync_with_stdio(false);
    //cin.tie(0);
    int connections, u, v;
    int currCase = 1;
    while (cin >> connections && connections) {
        clean();
        forn(i, connections) {
            cin >> u >> v;
            addEdge(u, v);
        }
        int start, ttl;
        int notReacheable, ssize = (int) graph.size();
        while (cin >> start >> ttl && (start || ttl)) {
            if (graph[start].empty()){
                notReacheable = ssize;
            }else{
                bfs(start, ttl);
                notReacheable = ssize - reached;
                //cout << "size es "<<ssize<<" and alcance "<<reached<<"\n";
            }
            cout << "Case " << currCase++ << ": " << notReacheable << " nodes not reachable from ";
            cout << "node " << start << " with TTL = " << ttl << ".\n";

        }
        string line;
        getline(cin, line);
    }
    return 0;
}

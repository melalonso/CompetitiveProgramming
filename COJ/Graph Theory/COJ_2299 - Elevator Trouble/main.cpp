#include <bits/stdc++.h>

#define MAXN 1000005
using namespace std;

// ACC

typedef pair<int, int> ii;
int u, d, f;
int visited[MAXN];

int bfs(int o, int g) {
    queue<ii> q;
    q.push({o, 0});
    visited[o] = true;
    int node, len, up, down;
    while (!q.empty()) {
        tie(node, len) = q.front(), q.pop();
        if (node == g) return len;
        up = node + u;
        down = node - d;
        if (up <= f && !visited[up]) {
            visited[up] = true;
            q.push({up, len + 1});
        }
        if (down > 0 && !visited[down]) {
            visited[down] = true;
            q.push({down, len + 1});
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int s, g;
    cin >> f >> s >> g >> u >> d;
    int res = bfs(s, g);
    res == -1 ? cout << "use the stairs\n" : cout << res << "\n";
    return 0;
}
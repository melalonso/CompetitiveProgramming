#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1005];
int memo[1005][1005];

void addEdge(int u, int v) {
    graph[u].push_back(v);
}

int dp(int a, int b) {
    if (a == b) return 0;
    if (a == 1 || b == 1) return 1;
    if (memo[a][b] != -1)return memo[a][b];

    int res = 0, o;
    for (int i = 0; i < graph[b].size(); i++) {
        o = graph[b][i];
        if (dp(min(a, o), max(a, o))) {
            res = 1;
            break;
        }
    }

    return memo[a][b] = res;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int c, p, u, v;
    cin >> c >> p;
    while (p--) {
        cin >> u >> v;
        addEdge(v, u);
    }
    memset(memo, -1, sizeof memo);
    int ans = c - 1;
    for (int i = 2; i <= c; i++) {
        for (int j = i + 1; j <= c; j++) {
            ans += dp(i, j);
        }
    }

    cout << ans << "\n";
    return 0;
}
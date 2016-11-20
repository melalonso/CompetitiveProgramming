#include <bits/stdc++.h>

#define MAXN 102
#define oo -100000000
using namespace std;

/*
 * ACCEPTED
 */

typedef pair<int, int> pii;
typedef vector<pii> vii;

int D, P, R, B;
int weight, cntP, total;
int Da[MAXN], Pa[MAXN];
vector<int> graph[2 * MAXN];

int memo[2 * MAXN][10005];
bool visited[2 * MAXN];
vii items;

void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int DP(int i, int budget) {
    if (budget < 0) return oo;
    if (i == items.size()) return 0;
    if (memo[i][budget] != -1) return memo[i][budget];
    int ans = 0;
    ans = max(items[i].first + DP(i + 1, budget - items[i].second), DP(i + 1, budget));
    return memo[i][budget] = ans;
}

void DFS_aux(int o) {
    stack<int> s;
    s.push(o);
    visited[o] = true;
    int u, v;
    while (s.size()) {
        u = s.top();
        s.pop();

        if (u <= D) {
            weight += Da[u - 1];
            cntP++;
        } else {
            weight += Pa[u - D - 1];
        }
        total++;

        for (int i = 0; i < graph[u].size(); i++) {
            v = graph[u][i];
            if (!visited[v]) {
                visited[v] = true;
                s.push(v);
            }
        }
    }
}

void DFS() {
    memset(visited, false, sizeof visited);
    for (int i = 1; i <= D + P; i++) {
        if (!visited[i]) {
            total = cntP = weight = 0;
            DFS_aux(i);
            if (i <= D) {
                items.push_back({(total - cntP - cntP), weight});
            } else {
                items.push_back({1, weight});
            }
        }
    }
}

void solve(int n, bool last) {
    memset(memo, -1, sizeof memo);
    cout << n + DP(0, B);
    cout << (last ? "\n" : " ");
}

void clear() {
    items.clear();
    for (auto &v : graph) {
        v.clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v;
    while (cin >> D >> P >> R >> B) {
        clear();
        for (int i = 0; i < D; i++) cin >> Da[i];
        for (int i = 0; i < P; i++) cin >> Pa[i];

        for (int i = 0; i < R; i++) {
            cin >> u >> v;
            addEdge(u, D + v);
        }

        DFS();

        solve(D, false);
        for (int i = 0; i < items.size(); i++) {
            items[i].first = -items[i].first;
        }
        solve(P, true);

    }
    return 0;
}
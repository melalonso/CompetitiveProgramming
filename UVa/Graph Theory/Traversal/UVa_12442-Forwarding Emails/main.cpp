#include <bits/stdc++.h>

#define MAXN 50005

using namespace std;

int graph[MAXN], maxComp[MAXN], n;
int loopFrom = -1;
bool visited[MAXN];
vector<int> nodes;

// ACC

int dfs(int o) {
    int u, v, totNodes = 1;
    stack<int> st;
    st.push(o);
    visited[o] = true;
    nodes.push_back(o);
    while (!st.empty()) {
        u = st.top(), st.pop();
        v = graph[u];
        if (!visited[v]) {
            visited[v] = true;
            nodes.push_back(v);
            totNodes++;
            st.push(v);
        } else if (maxComp[v] == 0) {
            loopFrom = v;
        } else {
            totNodes += maxComp[v];
        }
    }
    return totNodes;
}

int solve() {
    int res, maxx = 0, bestI = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            res = dfs(i);
            if (res > maxx) {
                maxx = res, bestI = i;
            }
            bool found = false;
            for (int j = 0; j < nodes.size(); j++) {
                if (nodes[j] == loopFrom) found = true;
                if (!found) maxComp[nodes[j]] = res--;
                else maxComp[nodes[j]] = res;
            }
            loopFrom = -1;
            nodes.clear();
        }
    }
    return bestI;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases, a, b;
    cin >> cases;
    for (int ci = 1; ci <= cases; ci++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            graph[a] = b;
        }
        int res = solve();
        cout << "Case " << ci << ": " << res << "\n";
        fill(maxComp, maxComp + MAXN, 0);
        fill(visited, visited + MAXN, false);
    }
    return 0;
}
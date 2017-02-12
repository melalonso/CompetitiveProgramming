#include <bits/stdc++.h>

#define MAXV 2002

// ACC

using namespace std;

vector<int> graph[MAXV];
int disc[MAXV], low[MAXV];
bool stackMember[MAXV];
vector<int> st(MAXV, 0);
int n, m, cnt, numSCC;

void addEdge(int u, int v) {
    graph[u].push_back(v);
}

void SCC(int u) {
    disc[u] = low[u] = ++cnt;
    st.push_back(u);
    stackMember[u] = true;

    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (disc[v] == -1)
            SCC(v);
        if (stackMember[v])
            low[u] = min(low[u], low[v]);
    }

    int w = 0;
    if (low[u] == disc[u]) {
        numSCC++;
        while (1) {
            w = st.back();
            st.pop_back();
            stackMember[w] = false;
            if (w == u) break;
        }
    }
}

void clear_graph() {
    for (int i = 1; i <= MAXV; i++) graph[i].clear();
}

int main() {
    ios::sync_with_stdio(0);
    // cin.tie(0);
    int u, v, p;
    while (cin >> n >> m, n || m) {
        clear_graph();
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> p;
            addEdge(u, v);
            if (p == 2) addEdge(v, u);
        }

        for (int i = 1; i <= n; i++) {
            low[i] = disc[i] = -1;
            stackMember[i] = false;
        }

        cnt = numSCC = 0;
        for (int i = 1; i <= n; i++)
            if (disc[i] == -1) SCC(i);

        numSCC == 1 ? cout << "1\n" : cout << "0\n";
    }
    return 0;
}

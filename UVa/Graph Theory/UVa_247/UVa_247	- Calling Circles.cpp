#include <bits/stdc++.h>

#define MAXN 27
using namespace std;

// ACC

map<string, int> names;
int n, m, cnt;

vector<int> graph[MAXN];
string idxToName[MAXN];
vector<int> st;
int disc[MAXN], low[MAXN];
bool visited[MAXN];

void addEdge(int u, int v) {
    graph[u].push_back(v);
}

void SCC(int u) {
    low[u] = disc[u]  = ++cnt;
    st.push_back(u);
    visited[u] = true;
    for (int j = 0; j < graph[u].size(); j++) {
        int v = graph[u][j];
        if (!disc[v]) SCC(v);
        if (visited[v]) low[u] = min(low[u], low[v]); // propagate low[v] up
    }

    if (disc[u] == low[u]) {
        int v = st.back();
        st.pop_back();
        visited[v] = false;
        cout << idxToName[v];
        while(1){
            if (u == v) break;
            v = st.back(); st.pop_back();
            //cout << "V es "<<v<<"\n";
            visited[v] = false;
            cout << ", " << idxToName[v];
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int dataset = 1, idx;
    bool flag = false;
    string a, b;
    while (cin >> n >> m, n || m) {
        idx = 0;
        for (int i=0; i<m; i++) {
            cin >> a >> b;
            if (names.find(a) == names.end()){
                names[a] = idx++;
                idxToName[idx-1] = a;
            }
            if (names.find(b) == names.end()){
                names[b] = idx++;
                idxToName[idx-1] = b;
            }
            addEdge(names[a], names[b]);
        }
        if (flag) cout << "\n";
        flag = true;
        cnt = 0;
        cout << "Calling circles for data set "<<dataset++<<":\n";
        for (int i=0; i<n; i++) if (!disc[i]) SCC(i);

        names.clear();
        fill(idxToName, idxToName+MAXN, "");
        for (int i = 0 ;i < n; i++) {
            disc[i] = low[i] = visited[i] = 0;
            graph[i].clear();
        }


    }
    return 0;
}

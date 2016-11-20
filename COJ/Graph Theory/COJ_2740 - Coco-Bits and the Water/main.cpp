#include <bits/stdc++.h>

using namespace std;

// ACC

vector<vector<int> > graph;
vector<int> times;

int dfsAux(int u, int outgoing){
    int maxx = 0;
    times[u] = outgoing;
    for (int i=0; i<graph[u].size(); i++){
        maxx = max(maxx, dfsAux(graph[u][i], times[u]+graph[u].size()));
    }
    return max(maxx, times[u]);
}

int dfs(int o) {
    int maxx=0;
    int size = graph[o].size();
    for (int i=0; i<size; i++){
        maxx = max(maxx, dfsAux(graph[o][i], size));
    }
    return maxx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tanks, pipes, a, b, root;
    cin >> tanks >> pipes;
    graph.assign(tanks, vector<int>());
    times.assign(tanks, 0);
    for (int i = 0; i < pipes; i++) {
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }
    cin >> root;
    root--;
    times[root] = 0;
    int res = dfs(root);
    cout << res << "\n";
    string str = "";
    for (int i=0; i<times.size(); i++){
        if (times[i]==res) str = str + to_string(i+1) + " ";
    }
    cout << str.substr(0,str.size()-1);
    return 0;
}
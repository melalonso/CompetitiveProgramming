#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1005];
int memo[1005][1005];

/*
 * ACCEPTED
 */

void addEdge(int u, int v){
    graph[v].push_back(u);
}


int dp(int a, int b){
    if (a == b) return 0;
    if (a==1 || b==1) return 1;
    if (memo[a][b] != -1) return memo[a][b];
    int res = 0, v, tmp;
    for (int i=0; i<graph[b].size(); i++){
        v = graph[b][i];
        if (dp(min(a, v), max(a, v))){
            res = 1; break;
        }
    }
    return memo[a][b] = res;
}

void clear(){
    for (int i=0; i<1005; i++) graph[i].clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int C, P, u, v;
    while (cin >> C >> P) {
        clear();
        for (int i=0; i<P; i++){
            cin >> u >> v;
            addEdge(u, v);
        }
        int res = C - 1;
        memset(memo, -1, sizeof memo);
        for (int i=2; i<=C; i++) {
            for (int j=i+1; j<=C; j++) {
                res += dp(i, j);
            }
        }
        cout << res << "\n";
    }
    return 0;
}
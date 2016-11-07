#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <limits.h>

#define MAXV 10000
#define INF 99999
using namespace std;

int n, m;
vector<int> grafo[MAXV];
bool visited[MAXV];

void DFS(int u){
    visited[u] = true;
    for (int i=0; i<grafo[u].size(); i++){
        int v = grafo[u][i];
        if (!visited[v]) DFS(v);
    }
}

void addEdge(int u, int v){
    grafo[u].push_back(v);
}

int solve(){
    memset(visited, false, sizeof visited);
    int res = 0;
    for(int i=0; i<n; i++){
        if (!visited[i]){
            DFS(i);
            res++;
        }
    }
    return res;
}

int main()
{
    int T;
    int a, b;
    freopen("input","r",stdin);
    cin >> T;
    while(T--){
        cin >> n >> m;
        memset(grafo, 0, sizeof grafo);
        for(int i=0; i<m; i++){
            cin >> a >> b;
            addEdge(a-1,b-1);
            addEdge(b-1,a-1);
        }

        int res = solve();
        cout << ((res * (res + 1)) / 2) - res << "\n";
    }
    return 0;
}

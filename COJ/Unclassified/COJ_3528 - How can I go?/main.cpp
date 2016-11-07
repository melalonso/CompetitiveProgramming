#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <limits.h>

using namespace std;

#define V 52
#define MOD 1000000007

typedef long long ll;
int graph[V][V];

ll pathswalks( int u, int v, int k){
    ll paths[V][V][k+1];

    for (int e = 0; e <= k; e++){
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                paths[i][j][e] = 0;

                if (e == 0 && i == j)
                    paths[i][j][e] = 1;
                if (e == 1 && graph[i][j])
                    paths[i][j][e] = 1;

                if (e > 1){
                    for (int a = 0; a < V; a++)
                        if (graph[i][a])
                            paths[i][j][e] = (paths[i][j][e]%MOD + paths[a][j][e-1]%MOD)%MOD;
                }
           }
        }
    }
    return paths[u][v][k];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, Q, v, w;
    freopen("input", "r", stdin);
    cin >> N >> M;
    while(M--){
        cin >> v >> w;
        graph[v-1][w-1] = 1;
    }
    cin >> Q;
    cout << pathswalks(0, N-1, Q);
    return 0;
}

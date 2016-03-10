#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <string.h>

#define MAXV 202

/*
    ACCEPTED.
*/

using namespace std;

vector<int> grafo[MAXV];
vector<int> color(MAXV);
int V, E;

void addEdge(int u, int v){
    grafo[u].push_back(v);
    grafo[v].push_back(u);
}

bool BFS(int s){
    fill(color.begin(),color.end(), -1);
    queue<int> q; q.push(s);
    color[s] = 0;
    bool bicolorable = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < grafo[u].size(); j++) {
            int v = grafo[u][j];
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            } else if (color[v] == color[u]) {
                bicolorable = false; break;
            }
        }
    }
    return bicolorable;
}

void clean(){
    for(int i=0; i<MAXV;i++) grafo[i].clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    int u, v;
    freopen("input","r",stdin);
    while(cin >>V && V){
        cin >> E;
        clean();
        for(int i=0; i<E; i++){
            cin >> u >> v;
            addEdge(u,v);
        }
        bool posible = BFS(0);
        cout << ( posible ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");
    }
    return 0;
}

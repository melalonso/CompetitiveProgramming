#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <string.h>

#define MAXV 202

using namespace std;

vector<int> grafo[MAXV];
vector<int> color(MAXV);
int V, E;

void addEdge(int u, int v){
    grafo[u].push_back(v);
    grafo[v].push_back(u);
}

int checkAux(int s){
    queue<int> q; q.push(s);
    color[s] = 0; int res=0, total=0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        total++;
        if (!color[u]) res++;
        for (int j = 0; j < grafo[u].size(); j++) {
            int v = grafo[u][j];
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            } else if (color[v] == color[u]) {
                return -1;
            }
        }
    }
    if (total==1) return 1;
    return min(res, total-res);
}

int check(){
    fill(color.begin(),color.end(), -1);
    int total=0, res;
    for(int i=0; i<V; i++){
		if(color[i] == -1){
            res = checkAux(i);
            if (res==-1) return -1;
            else total += res;
        }
	}
	return total;
}

void clean(){
    for(int i=0; i<MAXV;i++) grafo[i].clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    int T;
    int u, v;
    freopen("input","r",stdin);
    cin >> T;
    while(T--){
        cin >>V>>E;
        clean();
        for(int i=0; i<E; i++){
            cin >> u >> v;
            addEdge(u,v);
        }
        int res = check();
        cout << res << "\n";
    }
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <limits.h>

#define MAXV 20000
#define INF 99999

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

/*
    ACCEPTED
*/

vector<ii> adjList[MAXV];

void addEdge(int u, int v, int weight){
    adjList[u].push_back(ii(v, weight));
}

int dijstra(int s, int d){
    vi dist(MAXV, INF); dist[s] = 0;
    priority_queue< ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0,s));
    while(!pq.empty()){
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;
        for(int i=0; i<adjList[u].size(); i++){
            ii v = adjList[u][i];
            if (dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
    return dist[d];
}

void clear(){
    for(int i=0;i<MAXV;i++) adjList[i].clear();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, n, m, S, T;
    int u,v,latency;
    //freopen("input", "r", stdin);
    cin >> N;
    for (int ncase=0; ncase<N; ncase++){
        cin >>n>>m>>S>>T;
        for(int i=0;i<m;i++){
            cin >>u>>v>>latency;
            addEdge(u, v, latency);
            addEdge(v, u, latency);
        }
        int res = dijstra(S,T);
        cout << "Case #"<< ncase+1 <<": ";
        if (res==INF) cout <<"unreachable\n";
        else cout << res << "\n";
        clear();
    }
    return 0;
}

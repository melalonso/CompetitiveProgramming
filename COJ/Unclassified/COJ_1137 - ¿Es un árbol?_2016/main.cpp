#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <stack>

#define MAXV 10002
#define INF 99999
using namespace std;


vector<int> grafo[MAXV];
bool visited[V];

void addEdge(int u, int v){
    grafo[u].push_back(v);
}


// Works only if its a single component.
void BFS_iter(int o){
    queue<int> q;
    q.push(o);
    int u;
    while(!q.empty()){
        u = q.front();
        cout << u << " ";
        if (visited[u]) return false;
        visited[u] = true;
        q.pop();
        for (int i=0; i<grafo[u].size(); i++){
            int v = grafo[u][i];
            if (!visited[v]){
                q.push(v);
            }
        }
    }
    return true;
}




int main(){
    int u, v, caso = 1;
    while(scanf("%d %d",&u, &v),u!=-1){
        if(!u){
            // Process
            bool is_tree = BFS_iter();
            if (!is_tree) printf("Case %d is not a tree.\n",caso++);
            else{
                total
            }
            string s;
            getline(cin,s);
        }else{
            addEdge(u, v);
        }
    }
    return 0;
}

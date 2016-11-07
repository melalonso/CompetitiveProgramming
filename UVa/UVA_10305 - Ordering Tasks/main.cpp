#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>

#define MAX 102
using namespace std;

int V;    // No. of vertices'
vector<int> *adj;
bool visited[MAX];

/*
    ACCEPTED
*/

void addEdge(int v, int w){
    adj[v].push_back(w);
}

void topoSortUtil(int v, bool visited[], stack<int> &s){
    visited[v] = true;

    vector<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topoSortUtil(*i, visited, s);

    s.push(v);
}

void topoSort(){
    stack<int> s;

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
        if (visited[i] == false){
            topoSortUtil(i, visited, s);
        }

    while (s.empty() == false){
        printf("%d ", s.top()+1) ; s.pop();
    }
    printf("\n");
}

int main()
{
    int n, m;
    int i, j;
    freopen("input", "r", stdin);
    while(scanf("%d %d", &n, &m), n || m){
        V = n;
        adj = new vector<int>[V];
        while(m--){
            scanf("%d %d", &i, &j);
            addEdge(i-1, j-1);
        }
        topoSort();

    }
    return 0;
}

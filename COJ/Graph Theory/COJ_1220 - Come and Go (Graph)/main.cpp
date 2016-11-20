#include <iostream>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cstring>

#define MAXV 2001

/*
    ACCEPTED
*/

using namespace std;

vector<int> grafo[MAXV];
int belonging_vertex;
int V;

void addEdge(int u, int v){
    grafo[u].push_back(v);
}


// Tarjan algorithm to find Strongly Connected Components (SCC)
// Runs on linear time O(V+E).
// One DFS pass.
void SCCUtil(int u, int disc[], int low[], stack<int> *st, bool stackMember[]){
    static int time = 0;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
    st->push(u);
    stackMember[u] = true;

    // Go through all vertices adjacent to this
    for (int i = 0; i < grafo[u].size(); i++){
        int v = grafo[u][i];
        if (disc[v] == -1){ // not discovered
            SCCUtil(v, disc, low, st, stackMember);

            // Check if the subtree rooted with 'v' has a
            // connection to one of the ancestors of 'u'
            // and update ancestors.
            low[u]  = min(low[u], low[v]);
        }

        // Update low value of 'u' only of 'v' is still in stack
        // (i.e. it's a back edge, not cross edge).
        else if (stackMember[v] == true)
            low[u]  = min(low[u], disc[v]);
    }

    // head node found, pop the stack and print an SCC
    int w = 0;  // To store stack extracted vertices
    if (low[u] == disc[u]){
        while (st->top() != u){
            w = (int) st->top();
            belonging_vertex++;
            stackMember[w] = false;
            st->pop();
        }
        w = (int) st->top(); // Head node
        stackMember[w] = false;
        st->pop();
    }
}

// The function to do DFS traversal. It uses SCCUtil()
void SCC(){
    int *disc = new int[V];
    int *low = new int[V];
    bool *stackMember = new bool[V];
    stack<int> *st = new stack<int>();

    // Initialize disc and low, and stackMember arrays
    for (int i = 0; i < V; i++){
        disc[i] = -1; low[i] = -1;
        stackMember[i] = false;
    }

    // Call the recursive helper function to find strongly
    // connected components in DFS tree with vertex 'i'
    for (int i = 0; i < V; i++)
        if (disc[i] == -1)
            SCCUtil(i, disc, low, st, stackMember);
}

void clear_graph(){
    for (int i=0; i<MAXV; i++) grafo[i].clear();
}

int main()
{
    int E, u, v, p;
    while(scanf("%d %d",&V, &E), V | E){
        belonging_vertex = 0;
        clear_graph();
        for (int i=0; i<E; i++){
            scanf("%d %d %d",&u, &v, &p);
            addEdge(u-1, v-1);
            if (p==2) addEdge(v-1, u-1);
        }
        SCC();
        V==belonging_vertex+1 ? printf("1") : printf("0");
        printf("\n");
    }
    return 0;
}

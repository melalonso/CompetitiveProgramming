#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <limits.h>

#define MAXV 1000
#define INF 99999
using namespace std;


const int V = 4; // 9 for Dijkstra
vector<int> grafo[V];
bool visited[V];

// pair<int, int> vecino-peso del indice i.
typedef pair<int, int> neighbor;
vector< neighbor > weightedGrafo[V];
int dist[V]; // For dijkstra.


void DFS(int u){
    visited[u] = true;
    cout << u << endl;
    for (int i=0; i<grafo[u].size(); i++){
        int v = grafo[u][i];
        if (!visited[v]) DFS(v);
    }
}

void addEdge(int u, int v){
    grafo[u].push_back(v);
}

void addWeightedEdge(int u, int v, double weight){
    weightedGrafo[u].push_back(neighbor(v, weight));
}

void DFS_iter(int o){
    stack<int> s;
    s.push(o);
    visited[o] = true;
    int u;
    while(!s.empty()){
        u = s.top();
        cout << u << " ";
        s.pop();
        for (int i=0; i<grafo[u].size(); i++){
            int v = grafo[u][i];
            if (!visited[v]){
                visited[v] = true; s.push(v);
            }
        }
    }
    cout << endl;
}


// Works only if its a single component.
void BFS_iter(int o){
    queue<int> q;
    q.push(o);
    visited[o] = true;
    int u;
    while(!q.empty()){
        u = q.front();
        cout << u << " ";
        q.pop();
        for (int i=0; i<grafo[u].size(); i++){
            int v = grafo[u][i];
            if (!visited[v]){
                visited[v] = true; q.push(v);
            }
        }
    }
    cout << endl;
}


int next_vertex(){
    int index;
    int minimun = INT_MAX;
    for (int i=0; i<V; i++)
        if (!visited[i] && dist[i]<minimun)
            minimun = dist[i], index = i;
    return index;
}

void print_solution(){
    for (int i=0; i<V; i++){
        printf("Distancia al nodo %d: %d\n", i, dist[i]);
    }
}

void dijkstra(int o){

    // Initial distance to all vertices if INF
    for (int i=0; i<V; i++) dist[i] = INT_MAX;
    dist[o] = 0; // Except for the source node.

    for (int i=0; i<V-1; i++){
        int u = next_vertex(); // vertex with minimun distance.
        visited[u] = true; // Add to sptSet

        for (int j=0; j<weightedGrafo[u].size(); j++){
            int v = weightedGrafo[u][j].first;

            int weight = weightedGrafo[u][j].second;
            if (!visited[v] && ( (weight+dist[u]) < dist[v]) ) {
                dist[v] = weight + dist[u]; // Update distance to all adjacent vertices.
            }
        }

    }
    print_solution();
}



/* A utility function to print solution */
void printSolution(int dist[][V]){
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            if (dist[i][j] == INF) printf("%7s", "INF");
            else printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}


void floydWarshall (int graph[][V]){

    int dist[V][V], i, j, k; // Final distances array.

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++)
        for (i = 0; i < V; i++) // Pick all vertices as source one by one
            for (j = 0; j < V; j++) // Pick all vertices as destination.
                if (dist[i][k] + dist[k][j] < dist[i][j]) // If vertex k is on the shortest path
                    dist[i][j] = dist[i][k] + dist[k][j]; // update the value of dist[i][j]

    printSolution(dist);
}




int main(){

    // Ways to allocate an array
    int arr[MAXV];
    int * arr2 = (int *) malloc(MAXV * sizeof(int));
    int * arr3 = new int[MAXV];
    // End

    /*
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(1, 3);
    addEdge(3, 3);
    BFS_iter(1);
    */

    /*
    addWeightedEdge(0, 1, 4);
    addWeightedEdge(0, 7, 8);
    addWeightedEdge(1, 7, 11);
    addWeightedEdge(1, 2, 8);
    addWeightedEdge(7, 6, 1);
    addWeightedEdge(7, 8, 7);
    addWeightedEdge(2, 3, 7);
    addWeightedEdge(6, 5, 2);
    addWeightedEdge(2, 8, 2);
    addWeightedEdge(8, 6, 6);
    addWeightedEdge(2, 5, 4);
    addWeightedEdge(3, 4, 9);
    addWeightedEdge(5, 4, 10);
    addWeightedEdge(3, 5, 14);

    dijkstra(0);
    */

    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };

    floydWarshall(graph);

    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <iomanip>

#define edge pair<int, int>
#define MAXV 102

/*
    ACCEPTED
    Same code as Freckles.
*/

using namespace std;

vector<pair<double, edge> > graph;
pair<double, double> points[MAXV];
int E;
int parent[MAXV];
double minimun = 0;

int unionfind(int x){
    if (x != parent[x])
        parent[x] = unionfind(parent[x]);
    return parent[x];
}

void kruskal(){
    int u, v, pu, pv;
    sort(graph.begin(), graph.end());
    for(int i=0; i<E; i++){
        u = graph[i].second.first;
        v = graph[i].second.second;
        pu = unionfind(u); pv = unionfind(v); // Find parents - subtree.
        if (pu != pv){ // Add if are in a different subtree.
            minimun += graph[i].first;
            parent[pu] = parent[pv]; // Union
        }
    }
}

int main()
{
    int n; // Amount of points
    double x, y, distance;
    freopen("input","r",stdin);
    cin >> n;

    // Create forest for each vertex.
    // Each node is its own parent.
    // Disjoint set.
    for (int i=0; i<n; i++){
        parent[i] = i; cin >> x >> y;
        points[i] = make_pair(x, y);
    }

    E = (n*(n-1)) / 2; // Max edges on a complete graph.

    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            distance = hypot(points[i].first-points[j].first, points[i].second-points[j].second); // Distance between points.
            graph.push_back(pair<double,edge>(distance, edge(i, j)));
            //graph.push_back(pair<double,edge>(distance, edge(i, j)));
        }
    }

    kruskal(); // Find minimun spanning tree.

    cout << setprecision(2) << fixed << minimun*5 << endl;

    return 0;
}

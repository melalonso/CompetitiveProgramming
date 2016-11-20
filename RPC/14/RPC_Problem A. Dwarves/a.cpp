#include <bits/stdc++.h>

#define PI 3.14159265358979323846
#define E 2.71828182845904523536
#define MOD 1000000007
#define EPSILON 0.000000001
#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define MAX_N 100001
#define INF 100000000

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vector<vi> graph;

map<string, int> names;

void add_edge(int u, int v) {
    graph[u].push_back(v);
}

enum Color {WHITE, GRAY, BLACK};
int *color;

bool dfs(int u) {
    color[u] = GRAY;

    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];  // An adjacent of u

        // If there is
        if (color[v] == GRAY)
            return true;

        // If v is not processed and there is a back
        // edge in subtree rooted with v
        if (color[v] == WHITE && dfs(v))
            return true;
    }

    // Mark this vertex as processed
    color[u] = BLACK;

    return false;
}

// Returns true if there is a cycle in graph
bool isCyclic(int V)
{
    // Initialize color of all vertices as WHITE
    color = new int[V];
    for (int i = 0; i < V; i++)
        color[i] = WHITE;

    // Do a DFS traversal beginning with all
    // vertices
    for (int i = 0; i < V; i++)
        if (color[i] == WHITE)
            if (dfs(i)) return true;

    return false;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, index;
    string n1, n2, op;
    while(cin >> n) {
        index = 1;
        graph.assign(10002, vi());
        names.clear();

        for(int i = 0; i < n; i++) {
            cin >> n1 >> op >> n2;

            if (names[n1] == 0) {
                names[n1] = index;
                index++;
            }
            if(names[n2] == 0) {
                names[n2] = index;
                index++;
            }

            if(op == ">") {
                add_edge(names[n1]-1, names[n2]-1);
            } else {
                add_edge(names[n2]-1, names[n1]-1);
            }
        }

        index--;


        if(isCyclic(index)) cout << "impossible\n";
        else cout << "possible\n";

    }

}
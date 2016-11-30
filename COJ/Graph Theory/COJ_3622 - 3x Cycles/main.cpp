#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1000005];
int n, m, a, b, cnt;
bool visited[1000005];
int used[1000005];
bool found, no;

/*
 * ACCEPTED
 */

void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void DFS_aux(int u, int level, int parent)
{
    used[u] = level;
    visited[u] = true;

    for(int i = 0; i <graph[u].size(); i++)
    {
        int v = graph[u][i];

        if(!visited[v])
            DFS_aux(v, level + 1, u);

        if(v != parent && used[v] != 0){
            found = true;
            cnt = level - used[v] + 1;
            break;
        }
    }

    used[u] = 0;
}


void DFS() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS_aux(i, 1, -1);
            if (found && cnt % 3) {
                no = true;
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        addEdge(a, b);
    }
    DFS();
    if (no) cout << "no";
    else cout << "yes";

    return 0;
}
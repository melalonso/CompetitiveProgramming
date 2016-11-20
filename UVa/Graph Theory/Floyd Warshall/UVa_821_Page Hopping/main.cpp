#include <bits/stdc++.h>

#define MAXN 105
#define INF 252645135
using namespace std;

// ACC

int graph[MAXN][MAXN], maxx;
set<int> myset;

int floydWarshall() {
    int res = 0;
    for (int i = 1; i <= maxx; i++) graph[i][i] = 0;

    for (int k = 1; k <= maxx; k++)
        for (int i = 1; i <= maxx; i++)
            for (int j = 1; j <= maxx; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    for (int i = 1; i <= maxx; i++){
        for (int j = 1; j <= maxx; j++) if (graph[i][j]<INF)
        res += graph[i][j];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int a, b, casenumber = 1;
    bool flag = false;
    memset(graph, 9999, sizeof graph);
    while (cin >> a >> b) {
        if (a && b) {
            flag = false;
            graph[a][b] = 1;
            myset.insert(a);
            myset.insert(b);
            maxx = max(maxx, max(a, b));
        }
        if (!a && !b && flag){
            break;
        }
        if (!a && !b && !flag) {
            flag = true;
            int res = floydWarshall();
            int mysize = myset.size();
            cout << "Case " << casenumber++ << ": average length between pages = ";
            cout << fixed << setprecision(3) << res / (mysize * (mysize - 1.0)) << " clicks\n";
            memset(graph, 9999, sizeof graph);
            myset.clear();
            maxx = 0;
        }
    }
    return 0;
}
#include <bits/stdc++.h>

#define INF 252645135
#define MAXN 205
#define WALL 9999
#define DOOR 1

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int maxX, maxY;
int graph[MAXN][MAXN][4];
int mx[] = {-1, 0, 1, 0};
int my[] = {0, 1, 0, -1};

bool valid(int x, int y) {
    return x >= 0 && x <= maxX+1 && y >= 0 && y <= maxY+1;
}

int dijkstra(int xd, int yd) {
    ii node;
    int cost, nextX, nextY, cx, cy;
    int distance[MAXN][MAXN];

    memset(distance, 9999, sizeof distance);
    distance[0][0] = 0;
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push({0, {0, 0}});

    while (!pq.empty()) {
        tie(cost, node) = pq.top(), tie(cx, cy) = node;
        pq.pop();
        if (cost > distance[cx][cy]) continue;
        for (int i = 0; i < 4; i++) {
            nextX = cx + mx[i], nextY = cy + my[i];
            if (valid(nextX, nextY) && graph[cx][cy][i] != WALL &&
                    distance[nextX][nextY] > distance[cx][cy] + graph[cx][cy][i]) {
                distance[nextX][nextY] = distance[cx][cy] + graph[cx][cy][i];
                pq.push({distance[nextX][nextY], {nextX, nextY}});
            }
        }
    }

    return distance[xd][yd];
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int m, n, x, y, d, t, xnemo, ynemo;
    double xn, yn;
    while (cin >> m >> n && m != -1) {
        maxY = maxX = 0;
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> d >> t;
            maxX = max(maxX, x);
            maxY = max(maxY, y);
            if (d) {
                for (int j = y; j < y + t; j++) {
                    graph[x][j][0] = graph[x-1][j][2] = WALL;
                }
            } else {
                for (int j = x; j < x + t; j++) {
                    graph[j][y][3] = graph[j][y - 1][1] = WALL;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            cin >> x >> y >> d;
            if (d) graph[x][y][0] = graph[x-1][y][2] = DOOR;
            else   graph[x][y][3] = graph[x][y-1][1] = DOOR;
        }

        cin >> xn >> yn;
        xnemo = (int) xn, ynemo = (int) yn;

        if (xnemo < 0 || xnemo > maxX || ynemo < 0 || ynemo > maxY
                || (!m && !n) ) {
            cout << "0\n";
        } else {
            int res = dijkstra(xnemo, ynemo);
            (res == INF) ? cout << "-1\n" : cout << res << "\n";
        }

        memset(graph, 0, sizeof graph);
    }
    return 0;
}
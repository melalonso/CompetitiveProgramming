#include <bits/stdc++.h>

#define MAXN 1001
using namespace std;

// ACC

typedef pair<int, pair<int, int> > iii;
short maze[MAXN][MAXN];
int cases, a, b;
int mi[] = {-1, 0, 1, 0};
int mj[] = {0, 1, 0, -1};

bool valid(int x, int y){
    return x>=0 && x<a && y>=0 && y<b;
}

int dijkstra() {
    int distance[a][b];
    memset(distance, 9999, sizeof distance);
    distance[0][0] = maze[0][0];
    priority_queue<iii, vector<iii>, greater<iii> > pq;
    pq.push({maze[0][0], {0, 0}});
    int cost, x, y, newx, newy;
    while (!pq.empty()) {
        iii node = pq.top();
        pq.pop();
        cost = node.first;
        tie(x, y) = node.second;
        if (distance[x][y] < cost) continue;
        for (int i = 0; i < 4; i++) {
            newx = x + mi[i];
            newy = y + mj[i];
            if (valid(newx, newy)) {
                if (distance[newx][newy] > cost + maze[newx][newy]) {
                    distance[newx][newy] = cost + maze[newx][newy];
                    pq.push({distance[newx][newy], {newx, newy}});
                }
            }
        }
    }
    return distance[a - 1][b - 1];
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> cases;
    while (cases--) {
        cin >> a >> b;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                cin >> maze[i][j];
            }
        }
        cout << dijkstra() << "\n";
    }
    return 0;
}
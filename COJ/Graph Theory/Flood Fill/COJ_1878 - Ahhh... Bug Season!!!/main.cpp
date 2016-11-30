#include <bits/stdc++.h>

using namespace std;

typedef  pair<int, int> ii;
char picture[3245][4325];

// ACC


int w, h;
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
int newx, newy;

bool valid(int a, int b) {
    return a >= 0 && a < h && b >= 0 && b < w;
}

void dfsAux(int i, int j) {
    queue<ii> q;
    picture[i][j] = 1;
    q.push({i, j});
    int x, y;
    while(!q.empty()){
        tie(x, y) = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            newx = x + di[k];
            newy = y + dj[k];
            if (valid(newx, newy) && !picture[newx][newy]) {
                picture[newx][newy] = 1;
                q.push({newx, newy});
            }
        }
    }
}

int dfs() {
    int res = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!picture[i][j]) {
                res++; dfsAux(i, j);
            }
        }
    }
    return res;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        cin >> s;
        for (int j = 0; j < w; j++) {
            picture[i][j] = s[j]-'0';
        }
    }

    cout << dfs() << "\n";
    return 0;
}
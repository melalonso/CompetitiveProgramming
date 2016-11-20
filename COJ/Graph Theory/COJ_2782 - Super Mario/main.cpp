#include <bits/stdc++.h>

using namespace std;


// ACC

typedef pair<int, pair<int, int>> piii;
char game[12][12];
bool visited[12][12];
int n, mx, my, gx, gy;


int mi[] = {-1, 0, 1, 0};
int mj[] = {0, 1, 0, -1};

bool isValid(int x, int y){
    return x>=0 && x<n && y>=0 && y<n && (game[x][y]=='.' || game[x][y]=='#');
}

int bfs(int a, int b){
    queue<piii> q;
    q.push({0,{a, b}});
    visited[a][b] = true;
    piii u;
    while(!q.empty()){
        u = q.front(); q.pop();
        if (u.second.first==gx && u.second.second==gy) return u.first;
        for (int i=0; i<4; i++){
            int ni = u.second.first+mi[i];
            int nj = u.second.second+mj[i];
            if (isValid(ni, nj) && !visited[ni][nj]){
                visited[ni][nj] = true;
                q.push({u.first+1, {ni, nj}});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    string line;
    for (int i = 0; i < n; i++) {
        cin >> line;
        for (int j = 0; j < n; j++) {
            game[i][j] = line[j];
            if (game[i][j] == 'm') {
                mx = i;
                my = j;
            } else if (game[i][j] == '#') {
                gx = i;
                gy = j;
            }
        }
    }
    cout << bfs(mx, my) << "\n";
    return 0;
}
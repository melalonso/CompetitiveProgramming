#include <bits/stdc++.h>

using namespace std;

// ACC

int mat[102][102];
int mi[] = {-1, 0, 1, 0};
int mj[] = {0, 1, 0, -1};
int n, m, k;

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && mat[i][j] == 1;
}

int floodfill(int x, int y) {
    int res = 1;
    mat[x][y] = 0;
    for(int i = 0; i < 4; i++) {
        int ni = x + mi[i];
        int nj = y + mj[i];
        if (isValid(ni, nj)) {
            res += floodfill(ni, nj);
        }
    }
    return res;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        cin >> x >> y;
        x--;
        y--;
        mat[x][y] = 1;
    }

    int maxx = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (mat[i][j] == 1) {
                maxx = max(maxx, floodfill(i, j));
            }
        }
    }
    cout << maxx << "\n";
}
